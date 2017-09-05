#pragma once

#include <assert.h>

#include "COR\Math\Math.h"
#include "COR\Common\Range.h"

#include "Vector2D.h"




namespace CommonObjectRepository
{
	template <typename TYPE>
	class Vector4D;

	template <typename TYPE>
	class Vector3D
	{
		//	Befriend Thyself!
		template <typename T>
		friend class Vector3D;

		template <typename TYPE>
		friend class Vector2D;

	protected:
		TYPE xComponent;
		TYPE yComponent;
		TYPE zComponent;

	public:
		Vector3D();
		Vector3D(TYPE x, TYPE y, TYPE z);
		Vector3D(const Vector2D<TYPE>& xy, TYPE z);
		Vector3D(const Vector3D<TYPE>& toCopy) = default;
		Vector3D(Vector3D<TYPE>&& toMove) = default;
		template <typename T>
		explicit Vector3D(const Vector3D<T>& toCopy);
		Vector3D(const Vector4D<TYPE>& toAssign);
		~Vector3D(void) = default;

		Vector2D<TYPE> toVector2D() const;
		Vector4D<TYPE> toVector4D(TYPE w) const;
		Vector4D<TYPE> toVertexVector4D() const;
		Vector4D<TYPE> toNormalVector4D() const;

		Vector3D<TYPE>& operator=(const Vector3D<TYPE>& toCopy) = default;
		Vector3D<TYPE>& operator=(Vector3D<TYPE>&& toMove) = default;

		Vector3D<TYPE>& set(TYPE x, TYPE y, TYPE z);

		bool operator==(const Vector3D<TYPE>& toCompare) const;
		bool operator!=(const Vector3D<TYPE>& toCompare) const;

		TYPE& x();
		TYPE& y();
		TYPE& z();

		TYPE x() const;
		TYPE y() const;
		TYPE z() const;

		TYPE& operator[](int operand);
		TYPE operator[](int operand) const;

		Vector3D<TYPE> operator+(const TYPE operand) const;
		Vector3D<TYPE> operator-(const TYPE operand) const;
		Vector3D<TYPE> operator*(const TYPE operand) const;
		Vector3D<TYPE> operator/(const TYPE operand) const;

		Vector3D<TYPE>& operator+=(const TYPE operand);
		Vector3D<TYPE>& operator-=(const TYPE operand);
		Vector3D<TYPE>& operator*=(const TYPE operand);
		Vector3D<TYPE>& operator/=(const TYPE operand);

		Vector3D<TYPE> operator+(const Vector3D<TYPE>& operand) const;
		Vector3D<TYPE> operator-(const Vector3D<TYPE>& operand) const;

		Vector3D<TYPE>& operator+=(const Vector3D<TYPE>& operand);
		Vector3D<TYPE>& operator-=(const Vector3D<TYPE>& operand);

		Vector3D<TYPE> operator-() const;

		Vector3D<TYPE>& scale(const Vector3D<TYPE>& scalar);
		Vector3D<TYPE> scaled(const Vector3D<TYPE>& scalar) const;
		
		TYPE getMagnitudeSquared() const;
		TYPE getMagnitude() const;
		Vector3D<TYPE>& normalize();
		Vector3D<TYPE> normalized() const;
		
		Vector3D<TYPE>& negate();
		Vector3D<TYPE> negated() const;
		
		TYPE dotProduct(const Vector3D<TYPE>& operand) const;
		Vector3D<TYPE> crossProduct(const Vector3D<TYPE>& operand) const;

		TYPE getDistanceSquared(const Vector3D<TYPE>& point) const;
		TYPE getDistance(const Vector3D<TYPE>& point) const;
		
	};



	
	template <typename TYPE>
	Vector3D<TYPE> operator+(const TYPE operand1, const Vector3D<TYPE>& operand2);

	template <typename TYPE>
	Vector3D<TYPE> operator-(const TYPE operand1, const Vector3D<TYPE>& operand2);

	template <typename TYPE>
	Vector3D<TYPE> operator*(const TYPE operand1, const Vector3D<TYPE>& operand2);

	template <typename TYPE>
	Vector3D<TYPE> operator/(const TYPE operand1, const Vector3D<TYPE>& operand2);



	template <typename TYPE>
	struct VectorTraits;

	template <typename TYPE>
	struct VectorTraits<Vector3D<TYPE>>
	{
		static const uint depth = 3;
		using type = TYPE;
	};




	template <typename TYPE>
	class Range<Vector3D<TYPE>> : public NumericRange<Vector3D<TYPE>>
	{
	public:
		Range() : NumericRange(Vector3D<TYPE>(0, 0, 0), Vector3D<TYPE>(0, 0, 0)) {}
		Range(const Vector3D<TYPE>& start, const Vector3D<TYPE>& end) : NumericRange(start, end) {}
		Range(const Range<Vector3D<TYPE>>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {}

		Range<Vector3D<TYPE>>& operator=(const NumericRange<Vector3D<TYPE>>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}

		Vector3D<TYPE> clamp(const Vector3D<TYPE>& value) const
		{
			return Vector3D<TYPE>(Math::clamp(value.x(), start().x(), end().x()),
								  Math::clamp(value.y(), start().y(), end().y()),
								  Math::clamp(value.z(), start().z(), end().z()));
		}

		Range<Vector3D<TYPE>> clamp(const NumericRange<Vector3D<TYPE>>& value) const
		{
			return Range<Vector3D<TYPE>>(Vector3D<TYPE>(Math::clampMin(value.start().x(), start().x()), 
														Math::clampMin(value.start().y(), start().y()),
														Math::clampMin(value.start().z(), start().z())),
										 Vector3D<TYPE>(Math::clampMax(value.end().x(), end().x()), 
														Math::clampMax(value.end().y(), end().y()),
														Math::clampMax(value.end().z(), end().z())));
		}
	};
}

#include "Vector4D.h"

#include "Vector3D.hpp"


