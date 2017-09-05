#pragma once

#include <assert.h>

#include "COR\Math\Math.h"
#include "COR\Common\Range.h"

#include "Vector2D.h"
#include "Vector3D.h"

namespace CommonObjectRepository
{
	template <typename TYPE>
	class Vector4D
	{
		//	Befriend Thyself!
		template <typename T>
		friend class Vector4D;

		template <typename TYPE>
		friend class Vector3D;

	protected:
		TYPE xComponent;
		TYPE yComponent;
		TYPE zComponent;
		TYPE wComponent;

	public:
		Vector4D();
		Vector4D(TYPE x, TYPE y, TYPE z, TYPE w);
		Vector4D(const Vector2D<TYPE>& xy, TYPE z, TYPE w);
		Vector4D(const Vector3D<TYPE>& xyz, TYPE w);
		Vector4D(const Vector4D<TYPE>& toCopy) = default;
		Vector4D(Vector4D<TYPE>&& toMove) = default;
		template <typename T>
		explicit Vector4D(const Vector4D<T>& toCopy);
		~Vector4D(void) = default;

		Vector2D<TYPE> toVector2D() const;
		Vector3D<TYPE> toVector3D() const;

		Vector4D<TYPE>& operator=(const Vector4D<TYPE>& toCopy) = default;
		Vector4D<TYPE>& operator=(Vector4D<TYPE>&& toCopy) = default;

		Vector4D<TYPE>& set(TYPE x, TYPE y, TYPE z, TYPE w);

		bool operator==(const Vector4D<TYPE>& toCompare) const;
		bool operator!=(const Vector4D<TYPE>& toCompare) const;

		TYPE& x();
		TYPE& y();
		TYPE& z();
		TYPE& w();

		TYPE x() const;
		TYPE y() const;
		TYPE z() const;
		TYPE w() const;

		TYPE& operator[](int operand);
		TYPE operator[](int operand) const;

		Vector4D<TYPE> operator+(const TYPE operand) const;
		Vector4D<TYPE> operator-(const TYPE operand) const;
		Vector4D<TYPE> operator*(const TYPE operand) const;
		Vector4D<TYPE> operator/(const TYPE operand) const;

		Vector4D<TYPE>& operator+=(const TYPE operand);
		Vector4D<TYPE>& operator-=(const TYPE operand);
		Vector4D<TYPE>& operator*=(const TYPE operand);
		Vector4D<TYPE>& operator/=(const TYPE operand);

		Vector4D<TYPE> operator+(const Vector4D<TYPE>& operand) const;
		Vector4D<TYPE> operator-(const Vector4D<TYPE>& operand) const;

		Vector4D<TYPE>& operator+=(const Vector4D<TYPE>& operand);
		Vector4D<TYPE>& operator-=(const Vector4D<TYPE>& operand);

		Vector4D<TYPE> operator-() const;
		
		Vector4D<TYPE>& scale(const Vector4D<TYPE>& scalar);
		Vector4D<TYPE> scaled(const Vector4D<TYPE>& scalar) const;

		TYPE getMagnitudeSquared() const;
		TYPE getMagnitude() const;
		Vector4D<TYPE>& normalize();
		Vector4D<TYPE> normalized() const;
		
		Vector4D<TYPE>& negate();
		Vector4D<TYPE> negated() const;

		Vector4D<TYPE>& homogeneousDivide();
		Vector4D<TYPE> homogeneousDivided() const;
		
		TYPE dotProduct(const Vector4D<TYPE>& operand) const;
		Vector4D<TYPE> crossProduct(const Vector4D<TYPE>& u, const Vector4D<TYPE>& v, const Vector4D<TYPE>& w) const;

		TYPE getDistanceSquared(const Vector4D<TYPE>& point) const;
		TYPE getDistance(const Vector4D<TYPE>& point) const;
		
	};

	


	
	template <typename TYPE>
	Vector4D<TYPE> operator+(const TYPE operand1, const Vector4D<TYPE>& operand2);

	template <typename TYPE>
	Vector4D<TYPE> operator-(const TYPE operand1, const Vector4D<TYPE>& operand2);

	template <typename TYPE>
	Vector4D<TYPE> operator*(const TYPE operand1, const Vector4D<TYPE>& operand2);

	template <typename TYPE>
	Vector4D<TYPE> operator/(const TYPE operand1, const Vector4D<TYPE>& operand2);


	template <typename TYPE>
	struct VectorTraits;

	template <typename TYPE>
	struct VectorTraits<Vector4D<TYPE>>
	{
		static const uint depth = 4;
		using type = TYPE;
	};




	template <typename TYPE>
	class Range<Vector4D<TYPE>> : public NumericRange<Vector4D<TYPE>>
	{
	public:
		Range() : NumericRange(Vector4D<TYPE>(0, 0, 0, 0), Vector4D<TYPE>(0, 0, 0, 0)) {}
		Range(const Vector4D<TYPE>& start, const Vector4D<TYPE>& end) : NumericRange(star, end) {}
		Range(const Range<Vector4D<TYPE>>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {}

		Range<Vector4D<TYPE>>& operator=(const NumericRange<Vector4D<TYPE>>& toAssign)
		{
			RangeBase::operator=(toAssign);
			return *this;
		}

		Vector4D<TYPE> clamp(const Vector4D<TYPE>& value) const
		{
			return Vector4D<TYPE>(Math::clamp(value.x(), start().x(), end().x()),
								  Math::clamp(value.y(), start().y(), end().y()),
								  Math::clamp(value.z(), start().z(), end().z()),
								  Math::clamp(value.w(), start().w(), end().w()));
		}

		Range<Vector4D<TYPE>> clamp(const NumericRange<Vector4D<TYPE>>& value) const
		{
			return Range<Vector4D<TYPE>>(Vector4D<TYPE>(Math::clampMin(value.start().x(), start().x()), 
														Math::clampMin(value.start().y(), start().y()),
														Math::clampMin(value.start().z(), start().z()),
														Math::clampMin(value.start().w(), start().w())),
										 Vector4D<TYPE>(Math::clampMax(value.end().x(), end().x()), 
														Math::clampMax(value.end().y(), end().y()),
														Math::clampMax(value.end().z(), end().z()),
														Math::clampMax(value.end().w(), end().w())));
		}
	};

}

#include "Vector4D.hpp"


