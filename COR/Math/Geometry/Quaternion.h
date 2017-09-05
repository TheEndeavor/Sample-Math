#pragma once

#include <assert.h>

#include "COR\Types.h"

#include "Vector3D.h"
#include "Vector4D.h"
#include "Matrix4D.h"

namespace CommonObjectRepository
{

	template <typename TYPE>
	class Quaternion
	{
	public:

		static Quaternion<TYPE> identity();

		static Quaternion<TYPE> rotate(const Vector3D<TYPE>& vector, TYPE angle);
		static Quaternion<TYPE> getRotation(const Vector3D<TYPE>& source, const Vector3D<TYPE>& target);

	protected:
		TYPE xComponent;
		TYPE yComponent;
		TYPE zComponent;
		TYPE wComponent;

	public:
		Quaternion(void);
		Quaternion(TYPE x, TYPE y, TYPE z, TYPE w);
		Quaternion(TYPE x, TYPE y, TYPE z);
		Quaternion(const Quaternion<TYPE>& toCopy) = default;
		Quaternion(Quaternion<TYPE>&& toMove) = default;
		~Quaternion(void) = default;

		Quaternion<TYPE>& operator=(const Quaternion<TYPE>& toAssign) = default;
		Quaternion<TYPE>& operator=(Quaternion<TYPE>&& toAssign) = default;

		TYPE& x();
		TYPE& y();
		TYPE& z();
		TYPE& w();

		TYPE x() const;
		TYPE y() const;
		TYPE z() const;
		TYPE w() const;

		TYPE operator[](uint index) const;
		
		Quaternion<TYPE> operator*(TYPE operand) const;
		Quaternion<TYPE> operator*(const Quaternion<TYPE>& operand) const;

		Quaternion<TYPE>& operator*=(TYPE operand);
		Quaternion<TYPE>& operator*=(const Quaternion<TYPE>& operand);

		TYPE getMagnitude() const;
		TYPE getMagnitudeSquared() const;

		Quaternion<TYPE>& normalize();
		Quaternion<TYPE> normalized() const;

		Quaternion<TYPE>& invert();
		Quaternion<TYPE> inverted() const;

		Vector3D<TYPE> getEulerAngles() const;

		Vector3D<TYPE> rotate(const Vector3D<TYPE>& toRotate) const;

		Matrix4D<TYPE> getMatrix() const;
	};


}

#include "Quaternion.hpp"
