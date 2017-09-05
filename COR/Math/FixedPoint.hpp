#include "StdAfx.h"
#include "FixedPoint.h"



namespace CommonObjectRepository
{


	template <typename TYPE, uint PRECISION>
	const TYPE FixedPoint<TYPE, PRECISION>::One = ((TYPE)0x01 << PRECISION);
	template <typename TYPE, uint PRECISION>
	const bool FixedPoint<TYPE, PRECISION>::AssignValue = true;

	
	template <typename TYPE, uint PRECISION>
	static FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::abs(const FixedPoint<TYPE, PRECISION>& value)
	{
		return FixedPoint<TYPE, PRECISION>(value.value < One ? -value.value : value, AssignValue);
	}

	template <typename TYPE, uint PRECISION>
	static FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::floor(const FixedPoint<TYPE, PRECISION>& value)
	{
		return FixedPoint<TYPE, PRECISION>((value.value >> PRECISION) << PRECISION, AssignValue);
	}

	template <typename TYPE, uint PRECISION>
	static FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::ceil(const FixedPoint<TYPE, PRECISION>& value)
	{
		return FixedPoint<TYPE, PRECISION>(((value + (One - 1)) >> PRECISION) << PRECISION, AssignValue);
	}

	template <typename TYPE, uint PRECISION>
	static FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::mod(const FixedPoint<TYPE, PRECISION>& value)
	{
		//	TODO: Implement...
	}

	
	template <typename TYPE, uint PRECISION>
	static FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::cos(const FixedPoint<TYPE, PRECISION>& value)
	{
		//	TODO: Implement...
	}

	template <typename TYPE, uint PRECISION>
	static FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::sin(const FixedPoint<TYPE, PRECISION>& value)
	{
		//	TODO: Implement...
	}

	template <typename TYPE, uint PRECISION>
	static FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::sqrt(const FixedPoint<TYPE, PRECISION>& value)
	{
		//	TODO: Implement...
	}





	
	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::FixedPoint(TYPE value, bool assignValue) : value(value)
	{

	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::FixedPoint(void) : value(0)
	{

	}
	
	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::FixedPoint(TYPE value) : value(value << PRECISION)
	{

	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::FixedPoint(float32 value) : value(value * One)
	{

	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::FixedPoint(float64 value) : value(value * One)
	{

	}


	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::FixedPoint(const FixedPoint<TYPE, PRECISION>& toCopy) : value(toCopy.value)
	{

	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::~FixedPoint(void)
	{

	}
	
	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>& FixedPoint<TYPE, PRECISION>::operator=(const FixedPoint<TYPE, PRECISION>& toAssign)
	{
		value = toAssign.value;

		return *this;
	}
	
	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::operator TYPE() const
	{
		return value >> PRECISION;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::operator float32() const
	{
		return value / (float32)One;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>::operator float64() const
	{
		return value / (float64)One;
	}
	
	template <typename TYPE, uint PRECISION>
	int FixedPoint<TYPE, PRECISION>::compareTo(const FixedPoint<TYPE, PRECISION>& operand)
	{
		return value - operand.value;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::operator-() const
	{
		return FixedPoint<TYPE, PREVISION>(-value, AssignValue);
	}
	
	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>& FixedPoint<TYPE, PRECISION>::operator++()
	{
		value += One;

		return *this;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>& FixedPoint<TYPE, PRECISION>::operator--()
	{
		value -= One;

		return *this;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::operator++(int) const
	{
		FixedPoint<TYPE, PREVISION> toReturn = *this;

		value += One;

		return toReturn;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::operator--(int) const
	{
		FixedPoint<TYPE, PREVISION> toReturn = *this;

		value -= One;

		return toReturn;
	}
	
	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>& FixedPoint<TYPE, PRECISION>::operator>>=(uint bits)
	{
		value >>= bits;

		return *this;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>& FixedPoint<TYPE, PRECISION>::operator<<=(uint bits)
	{
		value <<= bits;

		return *this;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::operator>>(uint bits)
	{
		return FixedPoint<TYPE, PREVISION>(value >> bits, AssignValue);
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::operator<<(uint bits)
	{
		return FixedPoint<TYPE, PREVISION>(value << bits, AssignValue);
	}
	
	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>& FixedPoint<TYPE, PRECISION>::operator+=(FixedPoint<TYPE, PRECISION>& operand)
	{
		value += operand.value;

		return *this;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>& FixedPoint<TYPE, PRECISION>::operator-=(FixedPoint<TYPE, PRECISION>& operand)
	{
		value -= operand.value;

		return *this;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>& FixedPoint<TYPE, PRECISION>::operator*=(FixedPoint<TYPE, PRECISION>& operand)
	{
		value = (value * (int64)operand.value) >> PRECISION;
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION>& FixedPoint<TYPE, PRECISION>::operator/=(FixedPoint<TYPE, PRECISION>& operand)
	{
		value = ((int64)value << PRECISION) / operand.value;
	}
	
	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::operator+(FixedPoint<TYPE, PRECISION>& operand) const
	{
		return FixedPoint<TYPE, PRECISION>(value + operand.value, AssignValue);
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::operator-(FixedPoint<TYPE, PRECISION>& operand) const
	{
		return FixedPoint<TYPE, PRECISION>(value - operand.value, AssignValue);
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::operator*(FixedPoint<TYPE, PRECISION>& operand) const
	{
		return FixedPoint<TYPE, PRECISION>((value * (int64)operand.value) >> PRECISION, AssignValue);
	}

	template <typename TYPE, uint PRECISION>
	FixedPoint<TYPE, PRECISION> FixedPoint<TYPE, PRECISION>::operator/(FixedPoint<TYPE, PRECISION>& operand) const
	{
		return FixedPoint<TYPE, PRECISION>(((int64)value << PRECISION) / operand.value, AssignValue);
	}


}
