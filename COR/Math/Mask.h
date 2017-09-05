#pragma once

#include "COR\Types.h"

#include "COR\Math\Numbers.h"

namespace CommonObjectRepository
{

	template <typename TYPE, typename SUB_TYPE = TYPE>
	class Mask
	{
	protected:
		const TYPE mask;
		const uint offset;

	public:
		Mask(uint bitLength, uint bitOffset);
		Mask(const Mask<TYPE, SUB_TYPE>& toCopy);
		~Mask();

		Mask& operator=(const Mask<TYPE, SUB_TYPE>& toAssign);

		TYPE getMask();

		SUB_TYPE get(const TYPE& from);
		void set(TYPE& into, SUB_TYPE value);
	};


	template <typename TYPE, typename SUB_TYPE>
	class Masked
	{
	protected:
		const Mask<TYPE, SUB_TYPE> mask;
		const TYPE* dataAddress;

	public:
		Masked(const Mask<TYPE, SUB_TYPE>& mask, TYPE* dataAddress);
		Masked(uint bitLength, uint bitOffset, TYPE* dataAddress);
		Masked(const Masked<TYPE, SUB_TYPE>& toCopy);
		~Masked(void);

		Masked<TYPE, SUB_TYPE>& operator=(const Masked<TYPE, SUB_TYPE>& toAssign);

		Masked<TYPE, SUB_TYPE>& operator=(SUB_TYPE);
		operator SUB_TYPE() const;


	};

}

#include "Mask.hpp"
