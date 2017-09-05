#pragma once

#include "COR\Types.h"

#include "COR\Common\Comparable.h"

#include "COR\Math\Math.h"


namespace CommonObjectRepository
{

	template <typename TYPE, uint PRECISION>
	class FixedPoint : public Comparable<FixedPoint<TYPE, PRECISION>>
	{

	protected:
		static const TYPE One;
		static const bool AssignValue;

	public:
		static FixedPoint<TYPE, PRECISION> abs(const FixedPoint<TYPE, PRECISION>& value);
		static FixedPoint<TYPE, PRECISION> floor(const FixedPoint<TYPE, PRECISION>& value);
		static FixedPoint<TYPE, PRECISION> ceil(const FixedPoint<TYPE, PRECISION>& value);
		static FixedPoint<TYPE, PRECISION> mod(const FixedPoint<TYPE, PRECISION>& value);

		static FixedPoint<TYPE, PRECISION> cos(const FixedPoint<TYPE, PRECISION>& value);
		static FixedPoint<TYPE, PRECISION> sin(const FixedPoint<TYPE, PRECISION>& value);
		static FixedPoint<TYPE, PRECISION> sqrt(const FixedPoint<TYPE, PRECISION>& value);

	protected:
		TYPE value;

		FixedPoint(TYPE value, bool assignValue);
	public:
		FixedPoint(void);
		FixedPoint(TYPE value);
		FixedPoint(float32 value);
		FixedPoint(float64 value);
		FixedPoint(const FixedPoint<TYPE, PRECISION>& toCopy);
		~FixedPoint(void);

		FixedPoint<TYPE, PRECISION>& operator=(const FixedPoint<TYPE, PRECISION>& toAssign);

		operator TYPE() const;
		operator float32() const;
		operator float64() const;

		int compareTo(const FixedPoint<TYPE, PRECISION>& operand);

		FixedPoint<TYPE, PRECISION> operator-() const;

		FixedPoint<TYPE, PRECISION>& operator++();
		FixedPoint<TYPE, PRECISION>& operator--();
		FixedPoint<TYPE, PRECISION> operator++(int) const;
		FixedPoint<TYPE, PRECISION> operator--(int) const;

		FixedPoint<TYPE, PRECISION>& operator>>=(uint bits);
		FixedPoint<TYPE, PRECISION>& operator<<=(uint bits);
		FixedPoint<TYPE, PRECISION> operator>>(uint bits);
		FixedPoint<TYPE, PRECISION> operator<<(uint bits);

		FixedPoint<TYPE, PRECISION>& operator+=(FixedPoint<TYPE, PRECISION>& operand);
		FixedPoint<TYPE, PRECISION>& operator-=(FixedPoint<TYPE, PRECISION>& operand);
		FixedPoint<TYPE, PRECISION>& operator*=(FixedPoint<TYPE, PRECISION>& operand);
		FixedPoint<TYPE, PRECISION>& operator/=(FixedPoint<TYPE, PRECISION>& operand);

		FixedPoint<TYPE, PRECISION> operator+(FixedPoint<TYPE, PRECISION>& operand) const;
		FixedPoint<TYPE, PRECISION> operator-(FixedPoint<TYPE, PRECISION>& operand) const;
		FixedPoint<TYPE, PRECISION> operator*(FixedPoint<TYPE, PRECISION>& operand) const;
		FixedPoint<TYPE, PRECISION> operator/(FixedPoint<TYPE, PRECISION>& operand) const;




	};

}

#include "FixedPoint.hpp"
