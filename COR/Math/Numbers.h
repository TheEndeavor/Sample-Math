#pragma once

#include <assert.h>

#include "COR\Types.h"


namespace CommonObjectRepository
{
	class Numbers
	{
	protected:

		/**
			Relative Error
			32Bit Floats ~(1 / 250,000,000)
			64Bit Floats ~(1 / 550,000,000,000,000)
		**/
		static const uint maxUnitsInLastPlace = 0x00000010;

		static const uint32 signMaskFloat32 = ((uint32)0x01) << (sizeof(float32) - 1);
		static const uint64 signMaskFloat64 = ((uint64)0x01) << (sizeof(float64) - 1);


	public:

		template <typename TYPE>
		struct ByteMap;


		static constexpr uint8 uint8Min = 0U;
		static constexpr uint8 uint8Max = 255U;

		static constexpr int8 int8Min = -128;
		static constexpr int8 int8Max = 127;
		
		static constexpr uint16 uint16Min = 0U;
		static constexpr uint16 uint16Max = 65535U;

		static constexpr int16 int16Min = -32768;
		static constexpr int16 int16Max = 32767;
		
		static constexpr uint32 uint32Min = 0U;
		static constexpr uint32 uint32Max = 4294967295U;
		
		static constexpr int32 int32Min = (-2147483647) - 1;
		static constexpr int32 int32Max = 2147483647;

		static constexpr uint64 uint64Min = 0U;
		static constexpr uint64 uint64Max = 18446744073709551615ULL;
		
		static constexpr int64 int64Min = (-9223372036854775807LL) - 1;
		static constexpr int64 int64Max = 9223372036854775807LL;


		static constexpr float32 float32Min = 1.17549435e-38F;
		static constexpr float32 float32Max = 3.40282346e+38F;

		static constexpr float64 float64Min = 2.2250738585072014e-308;
		static constexpr float64 float64Max = 1.7976931348623157e+308;




		template <typename TYPE>
		static constexpr TYPE min();
		
		template <typename TYPE>
		static constexpr TYPE max();


		static bool isValidNumber(float32 value);
		static bool isValidNumber(float64 value);

		static bool isNan(float32 value);
		static bool isNan(float64 value);

		static bool isInfinity(float32 value);
		static bool isInfinity(float64 value);

		static bool isPositiveInfinity(float32 value);
		static bool isPositiveInfinity(float64 value);

		static bool isNegativeInfinity(float32 value);
		static bool isNegativeInfinity(float64 value);

		static bool almostEqualsZero(float32 value);
		static bool almostEqualsZero(float64 value);

		static bool almostEqualsZero(float32 value, uint32 maxUlps);
		static bool almostEqualsZero(float64 value, uint64 maxUlps);

		static bool almostEquals(float32 first, float32 second);
		static bool almostEquals(float64 first, float64 second);

		static bool almostEquals(float32 first, float32 second, uint32 maxUlps);
		static bool almostEquals(float64 first, float64 second, uint64 maxUlps);

		static uint32 distanceBetweenSignAndMagnitude(uint32 bitsFirst, uint32 bitsSecond);
		static uint64 distanceBetweenSignAndMagnitude(uint64 bitsFirst, uint64 bitsSecond);

		static uint32 signAndMagnitudeToBiased(uint32 bits);
		static uint64 signAndMagnitudeToBiased(uint64 bits);



		static uint16 reverseBytes(uint16 bytes);
		static uint32 reverseBytes(uint32 bytes);
		static uint64 reverseBytes(uint64 bytes);
		static void reverseBytes(uint8* bytes, uint length);

		template <typename TYPE>
		static TYPE makeBitMask(uint bits);

		static uint8 getFullBitMask(uint8 bits);
		static uint16 getFullBitMask(uint16 bits);
		static uint32 getFullBitMask(uint32 bits);
		static uint64 getFullBitMask(uint64 bits);

		template <typename TYPE>
		static uint countHighestBit(TYPE bits);

		template <typename TYPE>
		static uint countSetBits(TYPE bits);

		static uint8 reverseBits(uint8 bits);
		static uint16 reverseBits(uint16 bits);
		static uint32 reverseBits(uint32 bits);
		static uint64 reverseBits(uint64 bits);
		static void reverseBits(uint8* bits, uint length);

		template <typename TYPE>
		static bool isPowerOf2(TYPE toCheck);

		static uint32 hash(uint32 toHash);

	protected:
		Numbers(void);
		~Numbers(void);
	};

}

#include "Numbers.hpp"
