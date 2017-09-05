#pragma once

#include <cmath>

#include "COR\Types.h"
#include "COR\Math\Numbers.h"

namespace CommonObjectRepository
{
	class Math
	{
	protected:
		static const uint maxUnitsInLastPlace = 4;

		static const uint32 signMaskFloat32 = ((uint32)0x01) << (sizeof(float32) - 1);
		static const uint64 signMaskFloat64 = ((uint64)0x01) << (sizeof(float64) - 1);

	public:

		static const float64 E;
		static const float64 Log2E;
		static const float64 Log10E;
		static const float64 LogNatural2;
		static const float64 LogNatural10;
		static const float64 Pi;
		static const float64 PiHalf;
		static const float64 PiQuarter;
		static const float64 PiReciprocal;
		static const float64 PiReciprocal2;
		static const float64 SquareRoot2;
		static const float64 SquareRootHalf;


		static int32 abs(int32 value);
		static int64 abs(int64 value);

		static uint32 abs(uint32 value);
		static uint64 abs(uint64 value);

		static float32 abs(float32 value);
		static float64 abs(float64 value);

		static float32 round(float32 value);
		static float64 round(float64 value);

		static float32 ceil(float32 value);
		static float64 ceil(float64 value);

		static float32 floor(float32 value);
		static float64 floor(float64 value);


		static float32 mod(float32 numerator, float32 denominator);
		static float64 mod(float64 numerator, float64 denominator);

		static float32 pow(float32 value, float32 exponent);
		static float64 pow(float64 value, float64 exponent);

		static float32 log(float32 value);
		static float64 log(float64 value);

		static float32 log(float32 value, float32 base);
		static float64 log(float64 value, float64 base);

		static float32 log2(float32 value);
		static float64 log2(float64 value);

		static float32 log10(float32 value);
		static float64 log10(float64 value);



		static float32 sqrt(float32 value);
		static float64 sqrt(float64 value);

		static float32 invSqrt(float32 value);
		static float64 invSqrt(float64 value);

		static float32 cos(float32 value);
		static float64 cos(float64 value);

		static float32 sin(float32 value);
		static float64 sin(float64 value);

		static float32 tan(float32 value);
		static float64 tan(float64 value);


		static float32 acos(float32 value);
		static float64 acos(float64 value);

		static float32 asin(float32 value);
		static float64 asin(float64 value);

		static float32 atan(float32 value);
		static float64 atan(float64 value);

		static float32 Math::atan(float32 value1, float32 value2);
		static float64 Math::atan(float64 value1, float64 value2);


		static uint8 nextPowerOf2(uint8 value);
		static uint16 nextPowerOf2(uint16 value);
		static uint32 nextPowerOf2(uint32 value);
		static uint64 nextPowerOf2(uint64 value);


		template <typename TYPE>
		static TYPE min(TYPE value1, TYPE value2);
		
		template <typename TYPE>
		static TYPE max(TYPE value1, TYPE value2);

		template <typename TYPE>
		static TYPE clamp(TYPE value, TYPE min, TYPE max);

		template <typename TYPE>
		static TYPE clampMin(TYPE value, TYPE min);

		template <typename TYPE>
		static TYPE clampMax(TYPE value, TYPE max);


		static float32 radiansToDegrees(float32 radians);
		static float64 radiansToDegrees(float64 radians);

		static float32 degreesToRadians(float32 degrees);
		static float64 degreesToRadians(float64 degrees);
	};
}

#include "Math.hpp"
