//================================================================
// Copyright (c) 2015 Leif Erkenbrach
// Distributed under the terms of the MIT License.
// (See accompanying file LICENSE or copy at
// http://opensource.org/licenses/MIT)
//================================================================

//Based off GLM's architecture

#pragma once

#ifndef NOVUS_VECTOR2_T_H
#define NOVUS_VECTOR2_T_H

#include "Vector_t.h"

namespace novus
{
namespace math
{
	template <typename T>
	struct Vector2_t
	{
		union { T x, r; };
		union { T y, g; };

		Vector2_t();


		Vector2_t(const Vector2_t<T>& v);

		explicit Vector2_t(const T& s);

		Vector2_t(const T& a, const T& b);

		//Conversion constructors
		template <typename B>
		Vector2_t(const Vector2_t<B>& v);

		template <typename A, typename B>
		Vector2_t(const A& a, const B& b);

		size_t size() const;

		T& operator[] (size_t i);
		const T& operator[] (size_t i) const;

		//Arithmetic operators
		template <typename U>
		Vector2_t<T>& operator= (const Vector2_t<U>& v);

		template <typename U>
		Vector2_t<T>& operator+= (const Vector2_t<U>& v);

		template <typename U>
		Vector2_t<T>& operator-= (const Vector2_t<U>& v);

		template <typename U>
		Vector2_t<T>& operator*= (const Vector2_t<U>& v);

		template <typename U>
		Vector2_t<T>& operator/= (const Vector2_t<U>& v);


		template <typename U>
		Vector2_t<T>& operator+= (const U& s);

		template <typename U>
		Vector2_t<T>& operator-= (const U& s);

		template <typename U>
		Vector2_t<T>& operator*= (const U& s);

		template <typename U>
		Vector2_t<T>& operator/= (const U& s);
	};

	template <typename T>
	Vector2_t<T> operator+ (const Vector2_t<T>& a, const Vector2_t<T>& b);
	template <typename T>
	Vector2_t<T> operator- (const Vector2_t<T>& a, const Vector2_t<T>& b);
	template <typename T>
	Vector2_t<T> operator* (const Vector2_t<T>& a, const Vector2_t<T>& b);
	template <typename T>
	Vector2_t<T> operator/ (const Vector2_t<T>& a, const Vector2_t<T>& b);

	template <typename T>
	Vector2_t<T> operator+ (const Vector2_t<T>& v, const T& s);
	template <typename T>
	Vector2_t<T> operator- (const Vector2_t<T>& v, const T& s);
	template <typename T>
	Vector2_t<T> operator* (const Vector2_t<T>& v, const T& s);
	template <typename T>
	Vector2_t<T> operator/ (const Vector2_t<T>& v, const T& s);
}
}

#include "Vector2_t.inl"

#endif