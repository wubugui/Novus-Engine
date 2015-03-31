//================================================================
// Copyright (c) 2015 Leif Erkenbrach
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
// http://opensource.org/licenses/MIT)
//================================================================

#pragma once

#ifndef NOVUS_SHADOW_MAP_RENDER_TARGET_H
#define NOVUS_SHADOW_MAP_RENDER_TARGET_H

#include "Application/Common.h"
#include "Math/Math.h"
#include "IRenderTarget.h"

namespace novus
{

class Texture2D;
class D3DRenderer;
class Actor;

class ShadowMapRenderTarget : public IRenderTarget
{
public:
	ShadowMapRenderTarget();
	~ShadowMapRenderTarget();

	void Init(int width, int height);

	void BindTarget(D3DRenderer* renderer) override; 
	void UnbindTarget(D3DRenderer* renderer) override;

	RenderPass::Type GetRenderPass() const override;

	bool ShouldRenderActor(const Actor* actor) const override;

	void setPosition(const Vector3& position);
	void setDirection(const Vector3& direction);

	void setVolumePerspectiveBounds(float fovAngleY, float aspectHByW, float nearZ, float farZ);
	void setVolumeOrthographicBounds(float width, float height, float depth);

	Matrix4 getRenderTransform() const;

	Matrix4 getSampleTransform() const;

	Texture2D* getTexture() const { return mpRenderTarget; }

private:
	Vector3 mPosition;
	Vector3 mDirection;

	Texture2D* mpRenderTarget;
	ID3D11DepthStencilView* mpDepthView;

	mutable bool mTransformDirty;

	Matrix4 mProjectionMatrix;
	mutable Matrix4 mViewMatrix;
	mutable Matrix4 mTransform;
	mutable Matrix4 mSampleTransform;
};

}


#endif