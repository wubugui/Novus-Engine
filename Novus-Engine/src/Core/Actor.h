//================================================================
// Copyright (c) 2015 Leif Erkenbrach
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
// http://opensource.org/licenses/MIT)
//================================================================

#pragma once

#ifndef NOVUS_ACTOR_H
#define NOVUS_ACTOR_H

#include <map>
#include <vector>
#include "Math/Transform.h"
#include "Object.h"

typedef unsigned ComponentTypeId;
typedef unsigned long long ActorId;

namespace novus
{
class ActorComponent;
class D3DRenderer;

class Actor : public Object
{
	NOVUS_OBJECT_DECL(Actor);

	friend class World;
public:
	Actor();
	virtual ~Actor();

	virtual void Destroy();

	virtual void Init() {};

	virtual void Update(float dt);
	virtual void PostUpdate(float dt);

	virtual void PreRender(D3DRenderer* renderer);
	virtual void Render(D3DRenderer* renderer);
	virtual void PostRender(D3DRenderer* renderer);

	void AddChildActor(Actor* actor);

	void AddComponent(ActorComponent* component);
	void RemoveComponent(ActorComponent* component);

	template <class ComponentT>
	ComponentT* getComponent(unsigned index = 0);

	template <class ComponentT>
	std::vector<ComponentT*>& getComponents();

	bool IsDestroyed() const { return mDestroyed; }

	ActorId getId() const { return mId; }

	bool getCastShadow() const { return mCastShadow; }
	void setCastShadow(bool castShadow) { mCastShadow = castShadow; }

	void setDisplayName(const std::string& name);
	std::string getDisplayName() const;

	/*template <class T>
	T* getComponent(const char *name);*/

public:
	Transform transform;

protected:
	void UpdateComponents(float dt);
	void UpdateChildren(float dt);

	void RenderComponents(D3DRenderer* renderer);
	void RenderChildren(D3DRenderer* renderer);

private:
	void CleanupDestroyedActors();
	void CleanupDestroyedComponents();

private:
	ActorId mId;
	bool mDestroyed;

	bool mCastShadow;

	Actor* mpParentActor;

	std::multimap<const Type*, ActorComponent*> mComponents;

	std::vector<Actor*> mChildActors;

	std::string mDisplayName;
};


NOVUS_OBJECT_DEF(Actor);

}

#endif