#pragma once

namespace CommonObjectRepository
{
	
	template <typename TYPE>
	Normalized<TYPE>::Normalized(TYPE& value) : value(value)
	{

	}

	template <typename TYPE>
	Normalized<TYPE>::~Normalized()
	{

	}

	template <typename TYPE>
	Normalized<TYPE>& Normalized<TYPE>::operator=(const TYPE& operand)
	{
		value = operand;
		value.normalize();

		return *this;
	}

	template <typename TYPE>
	const TYPE& Normalized<TYPE>::get() const
	{
		return value;
	}

	template <typename TYPE>
	TYPE Normalized<TYPE>::get()
	{
		return value;
	}

	template <typename TYPE>
	Normalized<TYPE>::operator const TYPE&() const
	{
		return value;
	}

	template <typename TYPE>
	Normalized<TYPE>::operator TYPE() const
	{
		return value;
	}

}
