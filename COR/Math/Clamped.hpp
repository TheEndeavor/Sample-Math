#include "StdAfx.h"
#include "Clamped.h"


namespace CommonObjectRepository
{
	template <typename TYPE>
	Clamped<TYPE>::Clamped(TYPE value, TYPE min, TYPE max) : value(value), (min)(min), (max)(max)
	{
		assert(min <= max);
	}

	template <typename TYPE>
	Clamped<TYPE>::~Clamped()
	{

	}

	template <typename TYPE>
	TYPE Clamped<TYPE>::get() const
	{
		return value;
	}

	template <typename TYPE>
	Clamped<TYPE>::operator TYPE() const
	{
		return value;
	}

	template <typename TYPE>
	Clamped<TYPE>& Clamped<TYPE>::operator=(TYPE operand)
	{
		value = Math::clamp(operand, min, max);
		return *this;
	}
		
	template <typename TYPE>
	Clamped<TYPE>& Clamped<TYPE>::operator+=(TYPE operand)
	{
		value = Math::clamp(value + operand, min, max);
		return *this;
	}
		
	template <typename TYPE>
	Clamped<TYPE>& Clamped<TYPE>::operator-=(TYPE operand)
	{
		value = Math::clamp(value - operand, min, max);
		return *this;
	}
		
	template <typename TYPE>
	Clamped<TYPE>& Clamped<TYPE>::operator*=(TYPE operand)
	{
		value = Math::clamp(value * operand, min, max);
		return *this;
	}
		
	template <typename TYPE>
	Clamped<TYPE>& Clamped<TYPE>::operator/=(TYPE operand)
	{
		value = Math::clamp(value / operand, min, max);
		return *this;
	}
	
		
	template <typename TYPE>
	TYPE Clamped<TYPE>::operator+(TYPE operand) const
	{
		return value + operand;
	}
		
	template <typename TYPE>
	TYPE Clamped<TYPE>::operator-(TYPE operand) const
	{
		return value - operand;
	}
		
	template <typename TYPE>
	TYPE Clamped<TYPE>::operator*(TYPE operand) const
	{
		return value * operand;
	}

	template <typename TYPE>
	TYPE Clamped<TYPE>::operator/(TYPE operand) const
	{
		return value / operand;
	}

	
		
	template <typename TYPE>
	Clamped<TYPE&>::Clamped(TYPE& value, TYPE min, TYPE max) : value(value), min(min), max(max)
	{
		assert(min <= max);
	}
		
	template <typename TYPE>
	Clamped<TYPE&>::~Clamped()
	{

	}
	
		
	template <typename TYPE>
	TYPE& Clamped<TYPE&>::get() const
	{
		return value;
	}
		
	template <typename TYPE>
	Clamped<TYPE&>::operator TYPE&()
	{
		return value;
	}
	
	
	template <typename TYPE>
	Clamped<TYPE&>& Clamped<TYPE&>::operator=(TYPE operand)
	{
		value = Math::clamp(operand, min, max);
		return *this;
	}
	
	template <typename TYPE>
	Clamped<TYPE&>& Clamped<TYPE&>::operator+=(TYPE operand)
	{
		value = Math::clamp(value + operand, min, max);
		return *this;
	}
		
	template <typename TYPE>
	Clamped<TYPE&>& Clamped<TYPE&>::operator-=(TYPE operand)
	{
		value = Math::clamp(value - operand, min, max);
		return *this;
	}
		
	template <typename TYPE>
	Clamped<TYPE&>& Clamped<TYPE&>::operator*=(TYPE operand)
	{
		value = Math::clamp(value * operand, min, max);
		return *this;
	}
		
	template <typename TYPE>
	Clamped<TYPE&>& Clamped<TYPE&>::operator/=(TYPE operand)
	{
		value = Math::clamp(value / operand, min, max);
		return *this;
	}
	
		
	template <typename TYPE>
	TYPE Clamped<TYPE&>::operator+(TYPE operand) const
	{
		return value + operand;
	}
		
	template <typename TYPE>
	TYPE Clamped<TYPE&>::operator-(TYPE operand) const
	{
		return value - operand;
	}
		
	template <typename TYPE>
	TYPE Clamped<TYPE&>::operator*(TYPE operand) const
	{
		return value * operand;
	}
		
	template <typename TYPE>
	TYPE Clamped<TYPE&>::operator/(TYPE operand) const
	{
		return value / operand;
	}

}