#include "StdAfx.h"
#include "Math.h"


namespace CommonObjectRepository
{
	template <typename TYPE>
	TYPE Math::min(TYPE value1, TYPE value2)
	{
		return value1 < value2 ? value1 : value2;
	}
		
	template <typename TYPE>
	TYPE Math::max(TYPE value1, TYPE value2)
	{
		return value1 > value2 ? value1 : value2;
	}

	template <typename TYPE>
	TYPE Math::clamp(TYPE value, TYPE minValue, TYPE maxValue)
	{
		assert(minValue <= maxValue);

		return clampMax(clampMin(value, minValue), maxValue);
//		return max(min(value, maxValue), minValue);
	}

	template <typename TYPE>
	TYPE Math::clampMin(TYPE value, TYPE min)
	{
		return max(value, min);
	}

	template <typename TYPE>
	TYPE Math::clampMax(TYPE value, TYPE max)
	{
		return min(value, max);
	}
}

