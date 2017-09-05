#include "StdAfx.h"
#include "Mask.h"



namespace CommonObjectRepository
{


	template <typename TYPE, typename SUB_TYPE>
	Mask<TYPE, SUB_TYPE>::Mask(uint bitLength, uint bitOffset) : mask(Numbers::makeBitMask<TYPE>(bitLength) << bitOffset), offset(bitOffset)
	{

	}

	template <typename TYPE, typename SUB_TYPE>
	Mask<TYPE, SUB_TYPE>::Mask(const Mask<TYPE, SUB_TYPE>& toCopy) : mask(toCopy.mask), offset(toCopy.offset)
	{

	}

	template <typename TYPE, typename SUB_TYPE>
	Mask<TYPE, SUB_TYPE>::~Mask()
	{

	}

	template <typename TYPE, typename SUB_TYPE>
	Mask<TYPE, SUB_TYPE>& Mask<TYPE, SUB_TYPE>::operator=(const Mask<TYPE, SUB_TYPE>& toAssign)
	{

	}

	template <typename TYPE, typename SUB_TYPE>
	TYPE Mask<TYPE, SUB_TYPE>::getMask()
	{
		return mask;
	}

	template <typename TYPE, typename SUB_TYPE>
	SUB_TYPE Mask<TYPE, SUB_TYPE>::get(const TYPE& from)
	{
		return (mask & from) >> offset;
	}

	template <typename TYPE, typename SUB_TYPE>
	void Mask<TYPE, SUB_TYPE>::set(TYPE& into, SUB_TYPE value)
	{
		TYPE data = value;
		data = (data << offset) & mask;
		into = (into & ~mask) | data;
	}





	template <typename TYPE, typename SUB_TYPE>
	Masked<TYPE, SUB_TYPE>::Masked(const Mask<TYPE, SUB_TYPE>& mask, TYPE* dataAddress) : mask(mask), dataAddress(dataAddress)
	{

	}

	template <typename TYPE, typename SUB_TYPE>
	Masked<TYPE, SUB_TYPE>::Masked(uint bitLength, uint bitOffset, TYPE* dataAddress) : mask(bitLength, bitOffset), dataAddress(dataAddress)
	{

	}

	template <typename TYPE, typename SUB_TYPE>
	Masked<TYPE, SUB_TYPE>::Masked(const Masked<TYPE, SUB_TYPE>& toCopy) : mask(toCopy.mask), dataAddress(toCopy.dataAddress)
	{

	}

	template <typename TYPE, typename SUB_TYPE>
	Masked<TYPE, SUB_TYPE>::~Masked(void)
	{

	}

	template <typename TYPE, typename SUB_TYPE>
	Masked<TYPE, SUB_TYPE>& Masked<TYPE, SUB_TYPE>::operator=(const Masked<TYPE, SUB_TYPE>& toAssign)
	{
		mask = toAssign.mask;
		dataAddress = toAssign.dataAddress;

		return *this;
	}

	template <typename TYPE, typename SUB_TYPE>
	Masked<TYPE, SUB_TYPE>& Masked<TYPE, SUB_TYPE>::operator=(SUB_TYPE value)
	{
		mask.set(dataAddress, value);

		return *this;
	}

	template <typename TYPE, typename SUB_TYPE>
	Masked<TYPE, SUB_TYPE>::operator SUB_TYPE() const
	{
		return mask.get(dataAddress);
	}
}
