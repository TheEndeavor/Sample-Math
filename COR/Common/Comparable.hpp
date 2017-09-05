#include "StdAfx.h"
#include "Comparable.h"


namespace CommonObjectRepository
{

	

	template <typename TYPE>
	template <typename COMPARE>
	bool Comparable<TYPE>::operator==(const COMPARE& toCompare) const
	{
		return compareReferred(toCompare) == 0;
	}
	
	template <typename TYPE>
	template <typename COMPARE>
	bool Comparable<TYPE>::operator!=(const COMPARE& toCompare) const
	{
		return compareReferred(toCompare) != 0;
	}
	
	template <typename TYPE>
	template <typename COMPARE>
	bool Comparable<TYPE>::operator<(const COMPARE& toCompare) const
	{
		return compareReferred(toCompare) < 0;
	}
	
	template <typename TYPE>
	template <typename COMPARE>
	bool Comparable<TYPE>::operator<=(const COMPARE& toCompare) const
	{
		return compareReferred(toCompare) <= 0;
	}
	
	template <typename TYPE>
	template <typename COMPARE>
	bool Comparable<TYPE>::operator>=(const COMPARE& toCompare) const
	{
		return compareReferred(toCompare) >= 0;
	}
	
	template <typename TYPE>
	template <typename COMPARE>
	bool Comparable<TYPE>::operator>(const COMPARE& toCompare) const
	{
		return compareReferred(toCompare) > 0;
	}

	template <typename TYPE>
	template <typename COMPARE>
	int Comparable<TYPE>::compareReferred(const COMPARE& toCompare) const
	{
		return reinterpret_cast<const TYPE*>(this)->compareTo(toCompare);
	}
}
