#pragma once

namespace CommonObjectRepository
{

	template <typename TYPE>
	class Comparable
	{
	public:
		constexpr Comparable() = default;
		~Comparable() = default;

		template <typename COMPARE>
		bool operator==(const COMPARE& toCompare) const;

		template <typename COMPARE>
		bool operator!=(const COMPARE& toCompare) const;

		template <typename COMPARE>
		bool operator<(const COMPARE& toCompare) const;

		template <typename COMPARE>
		bool operator<=(const COMPARE& toCompare) const;

		template <typename COMPARE>
		bool operator>=(const COMPARE& toCompare) const;

		template <typename COMPARE>
		bool operator>(const COMPARE& toCompare) const;

		template <typename COMPARE>
		int compareReferred(const COMPARE& toCompare) const;
	};

}

#include "Comparable.hpp"
