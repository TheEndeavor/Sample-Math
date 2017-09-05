#pragma once

#include <assert.h>

#include "COR\Math\Math.h"
#include "COR\Common\Range.h"

#include "Vector3D.h"

namespace CommonObjectRepository
{
	template <typename TYPE>
	class Vector3D;

	template <typename TYPE>
	class Vector4D;


	template <typename TYPE>
	class Area2D;

	template <typename TYPE>
	class Vector2D
	{
		//	Befriend Thyself!
		template <typename T>
		friend class Vector2D;

	protected:
		TYPE xComponent;
		TYPE yComponent;

	public:
		Vector2D();
		Vector2D(TYPE x, TYPE y);
		Vector2D(const Vector2D<TYPE>& toCopy) = default;
		Vector2D(Vector2D<TYPE>&& toMove) = default;
		Vector2D(const Area2D<TYPE>& toCopy);
		template <typename T>
		explicit Vector2D(const Vector2D<T>& toCopy);
		~Vector2D(void) = default;

		Vector3D<TYPE> toVector3D(TYPE zComponent);
		Vector4D<TYPE> toVector4D(TYPE zComponent, TYPE wComponent);

		Vector2D<TYPE>& operator=(const Vector2D<TYPE>& toCopy) = default;
		Vector2D<TYPE>& operator=(Vector2D<TYPE>&& toMove) = default;

		Vector2D<TYPE>& set(TYPE x, TYPE y);

		bool operator==(const Vector2D<TYPE>& toCompare) const;
		bool operator!=(const Vector2D<TYPE>& toCompare) const;

		TYPE& x();
		TYPE& y();

		TYPE x() const;
		TYPE y() const;

		TYPE& operator[](int operand);
		TYPE operator[](int operand) const;

		Vector2D<TYPE> operator+(const TYPE operand) const;
		Vector2D<TYPE> operator-(const TYPE operand) const;
		Vector2D<TYPE> operator*(const TYPE operand) const;
		Vector2D<TYPE> operator/(const TYPE operand) const;

		Vector2D<TYPE>& operator+=(const TYPE operand);
		Vector2D<TYPE>& operator-=(const TYPE operand);
		Vector2D<TYPE>& operator*=(const TYPE operand);
		Vector2D<TYPE>& operator/=(const TYPE operand);

		Vector2D<TYPE> operator+(const Vector2D<TYPE>& operand) const;
		Vector2D<TYPE> operator-(const Vector2D<TYPE>& operand) const;
		Vector2D<TYPE> operator*(const Vector2D<TYPE>& operand) const;

		Vector2D<TYPE>& operator+=(const Vector2D<TYPE>& operand);
		Vector2D<TYPE>& operator-=(const Vector2D<TYPE>& operand);
		Vector2D<TYPE>& operator*=(const Vector2D<TYPE>& operand);

		Vector2D<TYPE> operator-() const;

		Vector2D<TYPE>& scale(const Vector2D<TYPE>& scalar);
		Vector2D<TYPE> scaled(const Vector2D<TYPE>& scalar) const;
		
		TYPE getMagnitudeSquared() const;
		TYPE getMagnitude() const;
		Vector2D<TYPE>& normalize();
		Vector2D<TYPE> normalized() const;
		
		Vector2D<TYPE>& negate();
		Vector2D<TYPE> negated() const;

		TYPE dotProduct(const Vector2D<TYPE>& operand) const;
		TYPE crossProduct(const Vector2D<TYPE>& operand) const;



		Vector2D<TYPE>& rotate(TYPE angle);
		Vector2D<TYPE> rotated(TYPE angle) const;

		Vector2D<TYPE>& rotate(TYPE angle, const Vector2D<TYPE>& center);
		Vector2D<TYPE> rotated(TYPE angle, const Vector2D<TYPE>& center) const;

		TYPE getDistanceSquared(const Vector2D<TYPE>& point) const;
		TYPE getDistance(const Vector2D<TYPE>& point) const;
		
	};




	template <typename TYPE>
	Vector2D<TYPE> operator+(const TYPE operand1, const Vector2D<TYPE>& operand2);

	template <typename TYPE>
	Vector2D<TYPE> operator-(const TYPE operand1, const Vector2D<TYPE>& operand2);

	template <typename TYPE>
	Vector2D<TYPE> operator*(const TYPE operand1, const Vector2D<TYPE>& operand2);

	template <typename TYPE>
	Vector2D<TYPE> operator/(const TYPE operand1, const Vector2D<TYPE>& operand2);



	template <typename TYPE>
	struct VectorTraits;

	template <typename TYPE>
	struct VectorTraits<Vector2D<TYPE>>
	{
		static const uint depth = 2;
		using type = TYPE;
	};




	template <typename TYPE>
	class Range<Vector2D<TYPE>> : public NumericRange<Vector2D<TYPE>>
	{
	public:
		Range() : NumericRange(Vector2D<TYPE>(0, 0), Vector2D<TYPE>(0, 0)) {}
		Range(const Vector2D<TYPE>& start, const Vector2D<TYPE>& end) : NumericRange(start, end) {}
		Range(const Range<Vector2D<TYPE>>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {}

		Range<Vector2D<TYPE>>& operator=(const NumericRange<Vector2D<TYPE>>& toAssign)
		{
			RangeBase::operator=(toAssign);
			return *this;
		}

		Vector2D<TYPE> clamp(const Vector2D<TYPE>& value) const
		{
			return Vector2D<TYPE>(Math::clamp(value.x(), start().x(), end().x()),
								  Math::clamp(value.y(), start().y(), end().y()));
		}

		Range<Vector2D<TYPE>> clamp(const NumericRange<Vector2D<TYPE>>& value) const
		{
			return Range<Vector2D<TYPE>>(Vector2D<TYPE>(Math::clampMin(value.start().x(), start().x()), 
														Math::clampMin(value.start().y(), start().y())),
										 Vector2D<TYPE>(Math::clampMax(value.end().x(), end().x()), 
														Math::clampMax(value.end().y(), end().y())));
		}
	};
}





#include "Vector2D.hpp"


