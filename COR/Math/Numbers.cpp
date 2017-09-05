#include "StdAfx.h"
#include "Numbers.h"


namespace CommonObjectRepository
{
	



	
	bool Numbers::isValidNumber(float32 value)
	{
		return value == value;
	}

	bool Numbers::isValidNumber(float64 value)
	{
		return value == value;
	}


	bool Numbers::isNan(float32 value)
	{
		return value != value;
	}

	bool Numbers::isNan(float64 value)
	{
		return value != value;
	}


	bool Numbers::isInfinity(float32 value)
	{
		return isPositiveInfinity(value) || isNegativeInfinity(value);
	}

	bool Numbers::isInfinity(float64 value)
	{
		return isPositiveInfinity(value) || isNegativeInfinity(value);
	}


	bool Numbers::isPositiveInfinity(float32 value)
	{
		uint64* valueAsInt = reinterpret_cast<uint64*>(&value);
		return *valueAsInt == 0x7F800000;
	}

	bool Numbers::isPositiveInfinity(float64 value)
	{
		uint64* valueAsInt = reinterpret_cast<uint64*>(&value);
		return *valueAsInt == 0x7FF0000000000000;
	}


	bool Numbers::isNegativeInfinity(float32 value)
	{
		uint64* valueAsInt = reinterpret_cast<uint64*>(&value);
		return *valueAsInt == 0xFF800000;
	}

	bool Numbers::isNegativeInfinity(float64 value)
	{
		uint64* valueAsInt = reinterpret_cast<uint64*>(&value);
		return *valueAsInt == 0xFFF0000000000000;
	}


	bool Numbers::almostEqualsZero(float32 value)
	{
		return almostEqualsZero(value, maxUnitsInLastPlace);
	}

	bool Numbers::almostEqualsZero(float64 value)
	{
		return almostEqualsZero(value, (uint64)maxUnitsInLastPlace);
	}

	bool Numbers::almostEqualsZero(float32 value, uint32 maxUlps)
	{
		if (Numbers::isNan(value))
			return false;

		uint32 bits = *reinterpret_cast<uint32*>(&value);
		bits = signAndMagnitudeToBiased(bits);

		return bits < maxUlps;
	}

	bool Numbers::almostEqualsZero(float64 value, uint64 maxUlps)
	{
		if (Numbers::isNan(value))
			return false;

		uint64 bits = *reinterpret_cast<uint64*>(&value);
		bits = signAndMagnitudeToBiased(bits);

		return bits < maxUlps;
	}

	bool Numbers::almostEquals(float32 first, float32 second)
	{
		return almostEquals(first, second, maxUnitsInLastPlace);
	}
	
	bool Numbers::almostEquals(float64 first, float64 second)
	{
		return almostEquals(first, second, (uint64)maxUnitsInLastPlace);
	}

	bool Numbers::almostEquals(float32 first, float32 second, uint32 maxUlps)
	{
		if (Numbers::isNan(first) || Numbers::isNan(second))
			return false;

		uint32 bitsFirst = *reinterpret_cast<uint32*>(&first);
		uint32 bitsSecond = *reinterpret_cast<uint32*>(&second);

		return distanceBetweenSignAndMagnitude(bitsFirst, bitsSecond) < maxUlps;
	}

	bool Numbers::almostEquals(float64 first, float64 second, uint64 maxUlps)
	{
		if (Numbers::isNan(first) || Numbers::isNan(second))
			return false;

		uint64 bitsFirst = *reinterpret_cast<uint64*>(&first);
		uint64 bitsSecond = *reinterpret_cast<uint64*>(&second);

		return distanceBetweenSignAndMagnitude(bitsFirst, bitsSecond) < maxUlps;
	}

	uint32 Numbers::distanceBetweenSignAndMagnitude(uint32 bitsFirst, uint32 bitsSecond)
	{
		bitsFirst = signAndMagnitudeToBiased(bitsFirst);
		bitsSecond = signAndMagnitudeToBiased(bitsSecond);

		return (bitsFirst >= bitsSecond) ? (bitsFirst - bitsSecond) : (bitsSecond - bitsFirst);
	}

	uint64 Numbers::distanceBetweenSignAndMagnitude(uint64 bitsFirst, uint64 bitsSecond)
	{
		bitsFirst = signAndMagnitudeToBiased(bitsFirst);
		bitsSecond = signAndMagnitudeToBiased(bitsSecond);

		return (bitsFirst >= bitsSecond) ? (bitsFirst - bitsSecond) : (bitsSecond - bitsFirst);
	}

	uint32 Numbers::signAndMagnitudeToBiased(uint32 bits)
	{
		if (signMaskFloat32 & bits)
			return ~bits + 1;
		else
			return signMaskFloat32 | bits;
	}

	uint64 Numbers::signAndMagnitudeToBiased(uint64 bits)
	{
		if (signMaskFloat64 & bits)
			return ~bits + 1;
		else
			return signMaskFloat64 | bits;
	}



	uint16 Numbers::reverseBytes(uint16 bytes)
	{
		return ((bytes & 0xFF00) >> 8) | ((bytes & 0x00FF) << 8);
	}

	uint32 Numbers::reverseBytes(uint32 bytes)
	{
		return ((bytes & 0xFF000000) >> 24) |
			   ((bytes & 0x00FF0000) >> 8) |
			   ((bytes & 0x0000FF00) << 8) |
			   ((bytes & 0x000000FF) << 24);
	}

	uint64 Numbers::reverseBytes(uint64 bytes)
	{
		return ((bytes & 0xFF00000000000000) >> 56) |
			   ((bytes & 0x00FF000000000000) >> 40) |
			   ((bytes & 0x0000FF0000000000) >> 24) |
			   ((bytes & 0x000000FF00000000) >> 8) |
			   ((bytes & 0x00000000FF000000) << 8) |
			   ((bytes & 0x0000000000FF0000) << 24) |
			   ((bytes & 0x000000000000FF00) << 40) |
			   ((bytes & 0x00000000000000FF) << 56);
	}

	void Numbers::reverseBytes(uint8* bytes, uint length)
	{
		uint start = 0;
		uint end = length - 1;

		for (; start<end; start++, end--)
		{
			Common::swap(bytes[start], bytes[end]);
		}
	}

	uint8 Numbers::getFullBitMask(uint8 bits)
	{
		bits |= bits >> 1;
		bits |= bits >> 2;
		bits |= bits >> 4;

		return bits;
	}

	uint16 Numbers::getFullBitMask(uint16 bits)
	{
		bits |= bits >> 1;
		bits |= bits >> 2;
		bits |= bits >> 4;
		bits |= bits >> 8;

		return bits;
	}
	
	uint32 Numbers::getFullBitMask(uint32 bits)
	{
		bits |= bits >> 1;
		bits |= bits >> 2;
		bits |= bits >> 4;
		bits |= bits >> 8;
		bits |= bits >> 16;

		return bits;
	}

	uint64 Numbers::getFullBitMask(uint64 bits)
	{
		bits |= bits >> 1;
		bits |= bits >> 2;
		bits |= bits >> 4;
		bits |= bits >> 8;
		bits |= bits >> 16;
		bits |= bits >> 32;

		return bits;
	}

	uint8 Numbers::reverseBits(uint8 bits)
	{
		bits = ((bits & 0xF0) >> 4) | ((bits & 0x0F) << 4);
		bits = ((bits & 0xCC) >> 2) | ((bits & 0x33) << 2);
		bits = ((bits & 0xAA) >> 1) | ((bits & 0x55) << 1);

		return bits;
	}

	uint16 Numbers::reverseBits(uint16 bits)
	{
		bits = ((bits & 0xFF00) >> 8) | ((bits & 0x00FF) << 8);
		bits = ((bits & 0xF0F0) >> 4) | ((bits & 0x0F0F) << 4);
		bits = ((bits & 0xCCCC) >> 2) | ((bits & 0x3333) << 2);
		bits = ((bits & 0xAAAA) >> 1) | ((bits & 0x5555) << 1);

		return bits;
	}

	uint32 Numbers::reverseBits(uint32 bits)
	{
		bits = ((bits & 0xFFFF0000) >> 16) | ((bits & 0x0000FFFF) << 16);
		bits = ((bits & 0xFF00FF00) >> 8) | ((bits & 0x00FF00FF) << 8);
		bits = ((bits & 0xF0F0F0F0) >> 4) | ((bits & 0x0F0F0F0F) << 4);
		bits = ((bits & 0xCCCCCCCC) >> 2) | ((bits & 0x33333333) << 2);
		bits = ((bits & 0xAAAAAAAA) >> 1) | ((bits & 0x55555555) << 1);

		return bits;
	}

	uint64 Numbers::reverseBits(uint64 bits)
	{
		bits = ((bits & 0xFFFFFFFF00000000) >> 32) | ((bits & 0x00000000FFFFFFFF) << 32);	
		bits = ((bits & 0xFFFF0000FFFF0000) >> 16) | ((bits & 0x0000FFFF0000FFFF) << 16);
		bits = ((bits & 0xFF00FF00FF00FF00) >> 8) | ((bits & 0x00FF00FF00FF00FF) << 8);
		bits = ((bits & 0xF0F0F0F0F0F0F0F0) >> 4) | ((bits & 0x0F0F0F0F0F0F0F0F) << 4);
		bits = ((bits & 0xCCCCCCCCCCCCCCCC) >> 2) | ((bits & 0x3333333333333333) << 2);
		bits = ((bits & 0xAAAAAAAAAAAAAAAA) >> 1) | ((bits & 0x5555555555555555) << 1);

		return bits;
	}

	void Numbers::reverseBits(uint8* bits, uint length)
	{
		while (length >= 8)
		{
			*reinterpret_cast<uint64*>(bits) = reverseBits(*reinterpret_cast<uint64*>(bits));
			length += 8;
			bits += 8;
		}
		if (length >= 4)
		{
			*reinterpret_cast<uint32*>(bits) = reverseBits(*reinterpret_cast<uint32*>(bits));
			length += 4;
			bits += 4;
		}
		if (length >= 2)
		{
			*reinterpret_cast<uint16*>(bits) = reverseBits(*reinterpret_cast<uint16*>(bits));
			length += 2;
			bits += 2;
		}
		if (length >= 2)
		{
			*(bits) = reverseBits(*(bits));
		}
	}
	
	uint32 Numbers::hash(uint32 toHash)
	{
		uint32 toReturn = toHash;
		toReturn = toReturn ^ (toReturn >> 4);
		toReturn = (toReturn ^ 0xdeadbeef) + (toReturn << 5);
		toReturn = toReturn ^ (toReturn >> 11);
		return toReturn;
	}


	Numbers::Numbers(void)
	{

	}

	Numbers::~Numbers(void)
	{

	}

}