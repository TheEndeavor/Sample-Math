#pragma once

#include "Math.h"

namespace CommonObjectRepository
{
	template <typename TYPE>
	class Normalized
	{
	protected:
		TYPE& value;

	public:
		Normalized(TYPE& value);
		~Normalized();

		Normalized<TYPE>& operator=(const TYPE& operand);

		const TYPE& get() const;
		TYPE get();

		operator const TYPE&() const;
		operator TYPE() const;
	};

}

#include "Normalized.hpp"
