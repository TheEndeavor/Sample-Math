#pragma once

#include <assert.h>
#include <algorithm>
#include <xmmintrin.h>

#include "Math.h"
#include "Vector2D.h"
#include "Vector3D.h"
#include "Line2D.h"

namespace CommonObjectRepository
{
	template <typename TYPE>
	class __declspec(align(16)) Matrix4D
	{
	public:
		static const Matrix4D<TYPE>& identity();

		static Matrix4D<TYPE> translate(TYPE x = 0, TYPE y = 0, TYPE z = 0);
		static Matrix4D<TYPE> translate(const Vector2D<TYPE>& translation);
		static Matrix4D<TYPE> translate(const Vector3D<TYPE>& translation);
		static Matrix4D<TYPE> translate(const Vector4D<TYPE>& translation);

		static Matrix4D<TYPE> scale(TYPE scalar);
		static Matrix4D<TYPE> scale(TYPE x, TYPE y, TYPE z = 1);
		static Matrix4D<TYPE> scale(const Vector2D<TYPE>& scalar);
		static Matrix4D<TYPE> scale(const Vector3D<TYPE>& scalar);
		static Matrix4D<TYPE> scale(const Vector4D<TYPE>& scalar);

		static Matrix4D<TYPE> rotateX(TYPE angle);
		static Matrix4D<TYPE> rotateY(TYPE angle);
		static Matrix4D<TYPE> rotateZ(TYPE angle);

		static Matrix4D<TYPE> rotate(const Vector3D<TYPE>& axis, TYPE angle);
		static Matrix4D<TYPE> rotateNormalized(const Vector3D<TYPE>& axis, TYPE angle);
//		static Matrix4D<TYPE> rotate(const Line3D<TYPE>& line, TYPE angle);
		

		static Matrix4D<TYPE> orthographicProjection(TYPE left, TYPE right, TYPE top, TYPE bottom, TYPE near, TYPE far);
		static Matrix4D<TYPE> orthographicProjection(TYPE width, TYPE height, TYPE near, TYPE far);
		static Matrix4D<TYPE> orthographicProjection(TYPE aspectRatio, TYPE near, TYPE far);
		static Matrix4D<TYPE> obliqueProjection(TYPE left, TYPE right, TYPE top, TYPE bottom, TYPE near, TYPE far);
		static Matrix4D<TYPE> obliqueProjection(TYPE width, TYPE height, TYPE near, TYPE far);
		static Matrix4D<TYPE> perspectiveProjection(TYPE viewingAngle, TYPE aspectRatio, TYPE near, TYPE far);

		

	protected:
		TYPE matrix[16];

	public:
		Matrix4D();
		Matrix4D(TYPE x0y0, TYPE x1y0, TYPE x2y0, TYPE x3y0,
				 TYPE x0y1, TYPE x1y1, TYPE x2y1, TYPE x3y1,
				 TYPE x0y2, TYPE x1y2, TYPE x2y2, TYPE x3y2,
				 TYPE x0y3, TYPE x1y3, TYPE x2y3, TYPE x3y3);
		Matrix4D(const Matrix4D<TYPE>& toCopy) = default;
		Matrix4D(Matrix4D<TYPE>&& toMove) = default;
		~Matrix4D(void) = default;

		Matrix4D<TYPE>& operator=(const Matrix4D<TYPE>& toAssign) = default;
		Matrix4D<TYPE>& operator=(Matrix4D<TYPE>&& toMove) = default;

		TYPE& get(int x, int y);
		TYPE get(int x, int y) const;

		Vector4D<TYPE>& operator[](int y);

		bool isIdentity();

		Matrix4D<TYPE> operator+(TYPE operand) const;
		Matrix4D<TYPE> operator-(TYPE operand) const;
		Matrix4D<TYPE> operator*(TYPE operand) const;
		Matrix4D<TYPE> operator/(TYPE operand) const;

		Matrix4D<TYPE>& operator+=(TYPE operand);
		Matrix4D<TYPE>& operator-=(TYPE operand);
		Matrix4D<TYPE>& operator*=(TYPE operand);
		Matrix4D<TYPE>& operator/=(TYPE operand);


		Matrix4D<TYPE> operator+(const Matrix4D<TYPE>& operand) const;
		Matrix4D<TYPE> operator-(const Matrix4D<TYPE>& operand) const;
		Matrix4D<TYPE> operator*(const Matrix4D<TYPE>& operand) const;
		Matrix4D<TYPE> operator/(const Matrix4D<TYPE>& operand) const;

		Vector4D<TYPE> operator*(const Vector4D<TYPE>& operand) const;
		Vector4D<TYPE> operator/(const Vector4D<TYPE>& operand) const;

		Matrix4D<TYPE>& operator+=(const Matrix4D<TYPE>& operand);
		Matrix4D<TYPE>& operator-=(const Matrix4D<TYPE>& operand);
		Matrix4D<TYPE>& operator*=(const Matrix4D<TYPE>& operand);
		Matrix4D<TYPE>& operator/=(const Matrix4D<TYPE>& operand);

		TYPE getCofactor(TYPE x0y0, TYPE x1y0, TYPE x2y0, TYPE x0y1, TYPE x1y1, TYPE x2y1, TYPE x0y2, TYPE x1y2, TYPE x2y2) const;

		TYPE getDeterminant() const;

		Matrix4D<TYPE>& transpose();
		Matrix4D<TYPE> transposed() const;

		Matrix4D<TYPE>& invert();
		Matrix4D<TYPE> inverted() const;

		Matrix4D<TYPE>& affineInvert();
		Matrix4D<TYPE> affineInverted() const;
	};


}


#include "Matrix4D.hpp"
