#include "StdAfx.h"
#include "Random.h"


namespace CommonObjectRepository
{
	Xorshift64Star Random::defaultXorshift64Star(time(nullptr));
	Xorshift1024Star Random::defaultXorshift1024Star(&(Random::defaultXorshift64Star));
	Xorshift128Plus Random::defaultXorshift128Plus(&(Random::defaultXorshift64Star));


	Random::Random()
	{

	}

	Random::~Random()
	{

	}

	uint32 Random::nextBits32()
	{
		return nextBits64() & 0xFFFFFFFF;
	}

	uint64 Random::nextBits64()
	{
		return (((uint64)nextBits32()) << 32) | nextBits32();
	}

	uint32 Random::nextBits32(uint bitCount)
	{
		return nextBits32() & Numbers::makeBitMask<uint32>(bitCount);
	}

	uint64 Random::nextBits64(uint bitCount)
	{
		return nextBits64() & Numbers::makeBitMask<uint64>(bitCount);
	}

	uint32 Random::nextInt32(uint32 max)
	{
		if (Numbers::isPowerOf2(max))
			return nextBits32() & (max - 1);

		uint32 threshold = -max % max;

		uint32 toReturn;
		do
		{
			toReturn = nextBits32();
		} while (toReturn < threshold);

		return toReturn % max;
	}

	uint64 Random::nextInt64(uint64 max)
	{
		if (Numbers::isPowerOf2(max))
			return nextBits32() & (max - 1);

		uint64 threshold = -max % max;

		uint64 toReturn;
		do
		{
			toReturn = nextBits64();
		} while (toReturn < threshold);

		return toReturn % max;
	}


	float32 Random::nextFloat32()
	{
		return nextBits32(24) / ((float32)(1 << 24));
	}

	float64 Random::nextFloat64()
	{
		return nextBits64(53) / ((float64)(1ULL << 53));
	}

	int Random::next(const Range<int>& range)
	{
		return range.start() + nextInt32(range.size());
	}

	uint Random::next(const Range<uint>& range)
	{
		return range.start() + nextInt32(range.size());
	}

	float32 Random::next(const Range<float32>& range)
	{
		return range.start() + (range.size() * nextFloat32());
	}

	float64 Random::next(const Range<float64>& range)
	{
		return range.start() + (range.size() * nextFloat64());
	}




	Xorshift64Star::Xorshift64Star(uint64 seed)
	{
		state = seed;
	}

	Xorshift64Star::Xorshift64Star(Random* seeder)
	{
		state = seeder->nextInt64();
	}

	Xorshift64Star::~Xorshift64Star()
	{

	}

	uint64 Xorshift64Star::nextBits64()
	{
		state ^= state >> 12;
		state ^= state << 25;
		state ^= state >> 27;
		return state * 2685821657736338717ULL;
	}


	Xorshift1024Star::Xorshift1024Star(uint64 seed)
	{
		for (int i=0; i<16; i++)
		{
			state[i + 0] = seed;
			state[i + 1] = ~seed;
			state[i + 2] = seed;
			state[i + 3] = ~seed;
		}
	}

	Xorshift1024Star::Xorshift1024Star(Random* seeder)
	{
		for (int i=0; i<16; i+=4)
		{
			state[i + 0] = seeder->nextInt64();
			state[i + 1] = seeder->nextInt64();
			state[i + 2] = seeder->nextInt64();
			state[i + 3] = seeder->nextInt64();
		}
	}

	Xorshift1024Star::~Xorshift1024Star()
	{

	}

	uint64 Xorshift1024Star::nextBits64()
	{
		uint64 value1 = state[position];
		uint64 value2 = state[position = (position + 1) & 15];
		value1 ^= value1 << 31;
		value1 ^= value1 >> 11;
		value2 ^= value2 >> 30;

		return (state[position] = value2 ^ value1) * 1181783497276652981ULL;
	}


	Xorshift128Plus::Xorshift128Plus(uint64 seed)
	{
		state[0] = seed;
		state[1] = ~seed;
	}

	Xorshift128Plus::Xorshift128Plus(Random* seeder)
	{
		state[0] = seeder->nextInt64();
		state[1] = seeder->nextInt64();
	}

	Xorshift128Plus::~Xorshift128Plus()
	{

	}

	uint64 Xorshift128Plus::nextBits64()
	{
		uint64 value1 = state[0];
		const uint64 value2 = state[1];

		state[0] = value2;

		value1 ^= value1 << 23; // a
		value1 ^= value1 >> 17; // b
		value1 ^= value2 ^ (value2 >> 26); // c
		state[1] = value1;

		return (value1 + value2);
	}







	Pcg32::Pcg32(uint64 initState, uint64 initSequence)
	{
		state = 0U;
		increment = (initSequence << 1U) | 1ULL;
		nextBits32();
		state += initState;
		nextBits32();
	}

	Pcg32::Pcg32(Random* seeder) : Pcg32(seeder->nextBits32(), seeder->nextBits32())
	{
		
	}

	Pcg32::~Pcg32()
	{

	}

	uint32 Pcg32::nextBits32()
	{
		uint64 oldState = state;
		state = oldState * 6364136223846793005ULL + increment;
		uint32 xorShifted = ((oldState >> 18u) ^ oldState) >> 27u;
		uint32 rot = oldState >> 59u;
		return (xorShifted >> rot) | (xorShifted << ((-rot) & 31));
	}

}