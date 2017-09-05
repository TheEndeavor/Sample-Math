#pragma once

#include <assert.h>
#include <algorithm>

#include "Math.h"
#include "Vector2D.h"

namespace CommonObjectRepository
{

	template <typename TYPE>
	class Matrix2D
	{
	public:
		static Matrix2D<TYPE> identity();
		static Matrix2D<TYPE> rotation(TYPE angle);

	protected:
		TYPE matrix[4];

	public:
		Matrix2D();
		Matrix2D(TYPE x0y0, TYPE x1y0, TYPE x0y1, TYPE x1y1);
		Matrix2D(const Matrix2D<TYPE>& toCopy) = default;
		Matrix2D(Matrix2D<TYPE>&& toMove) = default;
		~Matrix2D(void) = default;

		Matrix2D<TYPE>& operator=(const Matrix2D<TYPE>& toAssign) = default;
		Matrix2D<TYPE>& operator=(Matrix2D<TYPE>&& toMove) = default;

		TYPE& get(int x, int y);
		TYPE get(int x, int y) const;

		Vector2D<TYPE>& operator[](int y);

		bool isIdentity();

		Matrix2D<TYPE> operator+(TYPE operand) const;
		Matrix2D<TYPE> operator-(TYPE operand) const;
		Matrix2D<TYPE> operator*(TYPE operand) const;
		Matrix2D<TYPE> operator/(TYPE operand) const;

		Matrix2D<TYPE>& operator+=(TYPE operand);
		Matrix2D<TYPE>& operator-=(TYPE operand);
		Matrix2D<TYPE>& operator*=(TYPE operand);
		Matrix2D<TYPE>& operator/=(TYPE operand);

		Matrix2D<TYPE> operator+(const Matrix2D<TYPE>& operand) const;
		Matrix2D<TYPE> operator-(const Matrix2D<TYPE>& operand) const;
		Matrix2D<TYPE> operator*(const Matrix2D<TYPE>& operand) const;
		Matrix2D<TYPE> operator/(const Matrix2D<TYPE>& operand) const;

		Vector2D<TYPE> operator*(const Vector2D<TYPE>& operand) const;
		Vector2D<TYPE> operator/(const Vector2D<TYPE>& operand) const;

		Matrix2D<TYPE>& operator+=(const Matrix2D<TYPE>& operand);
		Matrix2D<TYPE>& operator-=(const Matrix2D<TYPE>& operand);
		Matrix2D<TYPE>& operator*=(const Matrix2D<TYPE>& operand);
		Matrix2D<TYPE>& operator/=(const Matrix2D<TYPE>& operand);

		TYPE getDeterminant() const;

		Matrix2D<TYPE>& transpose();
		Matrix2D<TYPE> transposed() const;

		Matrix2D<TYPE>& invert();
		Matrix2D<TYPE> inverted() const;

		Matrix2D<TYPE>& affineInvert();
		Matrix2D<TYPE> affineInverted() const;
	};


}


#include "Matrix2D.hpp"
