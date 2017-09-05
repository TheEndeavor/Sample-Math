#pragma once

#include <assert.h>
#include <algorithm>

#include "Math.h"
#include "Vector2D.h"
#include "Vector3D.h"

namespace CommonObjectRepository
{

	template <typename TYPE>
	class Matrix3D
	{
	public:
		static Matrix3D<TYPE> identity();

		static Matrix3D<TYPE> translate(TYPE x, TYPE y);
		static Matrix3D<TYPE> translate(const Vector2D<TYPE>& translation);

		static Matrix3D<TYPE> scale(TYPE x, TYPE y);
		static Matrix3D<TYPE> scale(const Vector2D<TYPE>& scale);
		static Matrix3D<TYPE> scale(TYPE x, TYPE y, TYPE z);
		static Matrix3D<TYPE> scale(const Vector3D<TYPE>& scale);

		static Matrix3D<TYPE> rotate(TYPE angle);
		static Matrix3D<TYPE> rotateX(TYPE angle);
		static Matrix3D<TYPE> rotateY(TYPE angle);
		static Matrix3D<TYPE> rotateZ(TYPE angle);

		static Matrix3D<TYPE> rotate(const Vector3D<TYPE>& axis, TYPE angle);
		static Matrix3D<TYPE> rotateNormalized(const Vector3D<TYPE>& axis, TYPE angle);
		

	protected:
		TYPE matrix[9];

	public:
		Matrix3D();
		Matrix3D(TYPE x0y0, TYPE x1y0, TYPE x2y0,
				 TYPE x0y1, TYPE x1y1, TYPE x2y1,
				 TYPE x0y2, TYPE x1y2, TYPE x2y2);
		Matrix3D(const Matrix3D<TYPE>& toCopy) = default;
		Matrix3D(Matrix3D<TYPE>&& toMove) = default;
		~Matrix3D(void) = default;

		Matrix3D<TYPE>& operator=(const Matrix3D<TYPE>& toAssign) = default;
		Matrix3D<TYPE>& operator=(Matrix3D<TYPE>&& toMove) = default;

		TYPE& get(int x, int y);
		TYPE get(int x, int y) const;

		Vector3D<TYPE>& operator[](int y);

		bool isIdentity();

		Matrix3D<TYPE> operator+(TYPE operand) const;
		Matrix3D<TYPE> operator-(TYPE operand) const;
		Matrix3D<TYPE> operator*(TYPE operand) const;
		Matrix3D<TYPE> operator/(TYPE operand) const;

		Matrix3D<TYPE>& operator+=(TYPE operand);
		Matrix3D<TYPE>& operator-=(TYPE operand);
		Matrix3D<TYPE>& operator*=(TYPE operand);
		Matrix3D<TYPE>& operator/=(TYPE operand);


		Matrix3D<TYPE> operator+(const Matrix3D<TYPE>& operand) const;
		Matrix3D<TYPE> operator-(const Matrix3D<TYPE>& operand) const;
		Matrix3D<TYPE> operator*(const Matrix3D<TYPE>& operand) const;
		Matrix3D<TYPE> operator/(const Matrix3D<TYPE>& operand) const;

		Vector3D<TYPE> operator*(const Vector3D<TYPE>& operand) const;
		Vector3D<TYPE> operator/(const Vector3D<TYPE>& operand) const;

		Matrix3D<TYPE>& operator+=(const Matrix3D<TYPE>& operand);
		Matrix3D<TYPE>& operator-=(const Matrix3D<TYPE>& operand);
		Matrix3D<TYPE>& operator*=(const Matrix3D<TYPE>& operand);
		Matrix3D<TYPE>& operator/=(const Matrix3D<TYPE>& operand);

		TYPE getDeterminant() const;

		Matrix3D<TYPE>& transpose();
		Matrix3D<TYPE> transposed();

		Matrix3D<TYPE>& invert();
		Matrix3D<TYPE> inverted() const;

		Matrix3D<TYPE>& affineInvert();
		Matrix3D<TYPE> affineInverted() const;

		

	};


}


#include "Matrix3D.hpp"
