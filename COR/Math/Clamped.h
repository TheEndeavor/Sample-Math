#pragma once

#include <assert.h>

#include "COR\Types.h"

#include "COR\Math\Math.h"


namespace CommonObjectRepository
{
	template <typename TYPE>
	class Clamped
	{
	protected:
		TYPE value;
		TYPE min;
		TYPE max;

	public:
		Clamped(TYPE value, TYPE min, TYPE max);
		~Clamped();

		TYPE get() const;
		operator TYPE() const;

		Clamped<TYPE>& operator=(TYPE value);
		
		Clamped<TYPE>& operator+=(TYPE value);
		Clamped<TYPE>& operator-=(TYPE value);
		Clamped<TYPE>& operator*=(TYPE value);
		Clamped<TYPE>& operator/=(TYPE value);

		TYPE operator+(TYPE value) const;
		TYPE operator-(TYPE value) const;
		TYPE operator*(TYPE value) const;
		TYPE operator/(TYPE value) const;
	};


	template <typename TYPE>
	class Clamped<TYPE&>
	{
	protected:
		TYPE& value;
		TYPE min;
		TYPE max;

	public:
		Clamped(TYPE& value, TYPE min, TYPE max);
		~Clamped();

		TYPE& get() const;
		operator TYPE&();

		Clamped<TYPE&>& operator=(TYPE value);
		
		Clamped<TYPE&>& operator+=(TYPE value);
		Clamped<TYPE&>& operator-=(TYPE value);
		Clamped<TYPE&>& operator*=(TYPE value);
		Clamped<TYPE&>& operator/=(TYPE value);

		TYPE operator+(TYPE value) const;
		TYPE operator-(TYPE value) const;
		TYPE operator*(TYPE value) const;
		TYPE operator/(TYPE value) const;
	};
}

#include "Clamped.hpp"
