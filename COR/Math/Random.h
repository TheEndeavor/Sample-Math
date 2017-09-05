#pragma once

#include <assert.h>
#include <ctime>

#include "COR\Types.h"
#include "COR\Math\Numbers.h"
#include "COR\Common\Range.h"


namespace CommonObjectRepository
{
	class Xorshift64Star;
	class Xorshift1024Star;
	class Xorshift128Plus;

	class Random
	{
	public:
		static Xorshift64Star defaultXorshift64Star;
		static Xorshift1024Star defaultXorshift1024Star;
		static Xorshift128Plus defaultXorshift128Plus;


	protected:
		Random();
		
	public:
		~Random();

		virtual uint32 nextBits32();
		virtual uint64 nextBits64();

		uint32 nextBits32(uint bitCount);
		uint64 nextBits64(uint bitCount);
		
		uint32 nextInt32(uint32 max = Numbers::int32Max);
		uint64 nextInt64(uint64 max = Numbers::int64Max);

		float32 nextFloat32();
		float64 nextFloat64();

		int next(const Range<int>& range);
		uint next(const Range<uint>& range);
		float32 next(const Range<float32>& range);
		float64 next(const Range<float64>& range);
	};


	class Xorshift64Star : public Random
	{
	protected:
		uint64 state;

	public:
		Xorshift64Star(uint64 seed);
		Xorshift64Star(Random* seeder);

		~Xorshift64Star();

		uint64 nextBits64();
	};

	class Xorshift1024Star : public Random
	{
	protected:
		uint64 state[16];
		uint position;

	public:
		Xorshift1024Star(uint64 seed);
		Xorshift1024Star(Random* seeder);
		~Xorshift1024Star();

		uint64 nextBits64();
	};

	class Xorshift128Plus : public Random
	{
	protected:
		uint64 state[2];

	public:
		Xorshift128Plus(uint64 seed);
		Xorshift128Plus(Random* seeder);
		~Xorshift128Plus();

		uint64 nextBits64();
	};





	/**
		Reference Pcg32 Implementation.
		Todo: Expand and add Pcg64.
	**/
	class Pcg32 : public Random
	{
	protected:
		uint64 state;
		uint64 increment;

	public:
		Pcg32(uint64 initstate, uint64 initseq);
		Pcg32(Random* seeder);
		~Pcg32();

		uint32 nextBits32();
	};



}