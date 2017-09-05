#include "StdAfx.h"

#include "Math.h"


namespace CommonObjectRepository
{
	const float64 Math::E =					2.71828182845904523536;
	const float64 Math::Log2E =				1.44269504088896340736;
	const float64 Math::Log10E =			0.434294481903251827651;
	const float64 Math::LogNatural2 =		0.693147180559945309417;
	const float64 Math::LogNatural10 =		2.30258509299404568402;
	const float64 Math::Pi =				3.14159265358979323846;
	const float64 Math::PiHalf =			1.57079632679489661923;
	const float64 Math::PiQuarter =			0.785398163397448309616;
	const float64 Math::PiReciprocal =		0.318309886183790671538;
	const float64 Math::PiReciprocal2 =		0.636619772367581343076;
	const float64 Math::SquareRoot2 =		1.41421356237309504880;
	const float64 Math::SquareRootHalf =	0.707106781186547524401;


	int32 Math::abs(int32 value)
	{
		return ::abs(value);
	}

	int64 Math::abs(int64 value)
	{
		return ::llabs(value);
	}

	uint32 Math::abs(uint32 value)
	{
		return value;
	}

	uint64 Math::abs(uint64 value)
	{
		return value;
	}

	float32 Math::abs(float32 value)
	{
		return ::fabs(value);
	}

	float64 Math::abs(float64 value)
	{
		return ::fabs(value);
	}


	float32 Math::round(float32 value)
	{
		return value >= 0.0f ? Math::floor(value + 0.5f) : Math::ceil(value - 0.5f);
	}

	float64 Math::round(float64 value)
	{
		return value >= 0.0f ? Math::floor(value + 0.5f) : Math::ceil(value - 0.5f);
	}


	float32 Math::ceil(float32 value)
	{
		return ::ceilf(value);
	}

	float64 Math::ceil(float64 value)
	{
		return ::ceil(value);
	}

	float32 Math::floor(float32 value)
	{
		return ::floorf(value);
	}

	float64 Math::floor(float64 value)
	{
		return ::floor(value);
	}

	float32 Math::mod(float32 numerator, float32 denominator)
	{
		return ::fmod(numerator, denominator);
	}

	float64 Math::mod(float64 numerator, float64 denominator)
	{
		return ::fmod(numerator, denominator);
	}

	float32 Math::pow(float32 value, float32 exponent)
	{
		return ::powf(value, exponent);
	}

	float64 Math::pow(float64 value, float64 exponent)
	{
		return ::pow(value, exponent);
	}

	float32 Math::log(float32 value)
	{
		return ::logf(value);
	}

	float64 Math::log(float64 value)
	{
		return ::log(value);
	}

	float32 Math::log(float32 value, float32 base)
	{
		return logf(value) / logf(base);
	}

	float64 Math::log(float64 value, float64 base)
	{
		return log(value) / log(base);
	}

	float32 Math::log2(float32 value)
	{
		return (float32)(logf(value) / Math::LogNatural2);
	}

	float64 Math::log2(float64 value)
	{
		return log(value) / Math::LogNatural2;
	}

	float32 Math::log10(float32 value)
	{
		return ::log10f(value);
	}

	float64 Math::log10(float64 value)
	{
		return ::log10(value);
	}



	float32 Math::sqrt(float32 value)
	{
		return ::sqrtf(value);
	}

	float64 Math::sqrt(float64 value)
	{
		return ::sqrt(value);
	}

	float32 Math::invSqrt(float32 value)
	{
		return 1.0f / sqrt(value);
	}

	float64 Math::invSqrt(float64 value)
	{
		return 1.0 / sqrt(value);
	}

	float32 Math::cos(float32 value)
	{
		return ::cosf(value);
	}

	float64 Math::cos(float64 value)
	{
		return ::cos(value);
	}

	float32 Math::sin(float32 value)
	{
		return ::sinf(value);
	}

	float64 Math::sin(float64 value)
	{
		return ::sin(value);
	}

	float32 Math::tan(float32 value)
	{
		return ::tanf(value);
	}

	float64 Math::tan(float64 value)
	{
		return ::tan(value);
	}


	float32 Math::acos(float32 value)
	{
		return ::acosf(value);
	}

	float64 Math::acos(float64 value)
	{
		return ::acos(value);
	}

	float32 Math::asin(float32 value)
	{
		return ::asinf(value);
	}

	float64 Math::asin(float64 value)
	{
		return ::asin(value);
	}

	float32 Math::atan(float32 value)
	{
		return ::atanf(value);
	}

	float64 Math::atan(float64 value)
	{
		return ::atan(value);
	}

	float32 Math::atan(float32 value1, float32 value2)
	{
		return ::atan2f(value1, value2);
	}

	float64 Math::atan(float64 value1, float64 value2)
	{
		return ::atan2(value1, value2);
	}





	uint8 Math::nextPowerOf2(uint8 value)
	{
		value--;
		value |= value >> 1;
		value |= value >> 2;
		value |= value >> 4;
		value++;

		return value;
	}

	uint16 Math::nextPowerOf2(uint16 value)
	{
		value--;
		value |= value >> 1;
		value |= value >> 2;
		value |= value >> 4;
		value |= value >> 8;
		value++;

		return value;
	}

	uint32 Math::nextPowerOf2(uint32 value)
	{
		value--;
		value |= value >> 1;
		value |= value >> 2;
		value |= value >> 4;
		value |= value >> 8;
		value |= value >> 16;
		value++;

		return value;
	}

	uint64 Math::nextPowerOf2(uint64 value)
	{
		value--;
		value |= value >> 1;
		value |= value >> 2;
		value |= value >> 4;
		value |= value >> 8;
		value |= value >> 16;
		value |= value >> 32;
		value++;

		return value;
	}

	float32 Math::radiansToDegrees(float32 radians)
	{
		return (float32)(radians * 180 / Pi);
	}

	float64 Math::radiansToDegrees(float64 radians)
	{
		return radians * 180 / Pi;
	}

	float32 Math::degreesToRadians(float32 degrees)
	{
		return (float32)(degrees * Pi / 180);
	}

	float64 Math::degreesToRadians(float64 degrees)
	{
		return degrees * Pi / 180;
	}

}