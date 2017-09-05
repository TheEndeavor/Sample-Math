#include "StdAfx.h"
#include "Numbers.h"


namespace CommonObjectRepository
{

	template <>
	constexpr uint8 Numbers::min<uint8>() { return uint8Min; }
	template <>
	constexpr uint8 Numbers::max<uint8>() { return uint8Max; }

	template <>
	constexpr int8 Numbers::min<int8>() { return int8Min; }
	template <>
	constexpr int8 Numbers::max<int8>() { return int8Max; }

	template <>
	constexpr uint16 Numbers::min<uint16>() { return uint16Min; }
	template <>
	constexpr uint16 Numbers::max<uint16>() { return uint16Max; }

	template <>
	constexpr int16 Numbers::min<int16>() { return int16Min; }
	template <>
	constexpr int16 Numbers::max<int16>() { return int16Max; }

	template <>
	constexpr uint32 Numbers::min<uint32>() { return uint32Min; }
	template <>
	constexpr uint32 Numbers::max<uint32>() { return uint32Max; }

	template <>
	constexpr int32 Numbers::min<int32>() { return int32Min; }
	template <>
	constexpr int32 Numbers::max<int32>() { return int32Max; }

	template <>
	constexpr uint64 Numbers::min<uint64>() { return uint64Min; }
	template <>
	constexpr uint64 Numbers::max<uint64>() { return uint64Max; }

	template <>
	constexpr int64 Numbers::min<int64>() { return int64Min; }
	template <>
	constexpr int64 Numbers::max<int64>() { return int64Max; }

	template <>
	constexpr float32 Numbers::min<float32>() { return float32Min; }
	template <>
	constexpr float32 Numbers::max<float32>() { return float32Max; }

	template <>
	constexpr float64 Numbers::min<float64>() { return float64Min; }
	template <>
	constexpr float64 Numbers::max<float64>() { return float64Max; }





	template <typename TYPE>
	TYPE Numbers::makeBitMask(uint bits)
	{
		return (static_cast<TYPE>(1) << bits) - static_cast<TYPE>(1);
	}

	template <typename TYPE>
	uint Numbers::countHighestBit(TYPE bits)
	{
		uint toReturn = 0;
		while (bits >>= 1)
		{
			toReturn++;
		}

		return toReturn;
	}

	template <typename TYPE>
	uint Numbers::countSetBits(TYPE bits)
	{
		uint toReturn = bits & 0x01;
		while (bits >>= 1)
		{
			toReturn += bits & 0x01 ? 1 : 0;
		}

		return toReturn;
	}

	template <typename TYPE>
	bool Numbers::isPowerOf2(TYPE toCheck)
	{
		return toCheck && !(toCheck & (toCheck - 1));
	}

}