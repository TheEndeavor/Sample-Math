#pragma once

#include <limits.h>
#include <emmintrin.h>
#include <cstdint>
#include <utility>

namespace CommonObjectRepository
{
	using char8 = char;
	using char16 = char16_t;
	using char32 = char32_t;

	using int8 = int8_t;
	using uint8 = uint8_t;

	using int16 = int16_t;
	using uint16 = uint16_t;

	using int32 = int32_t;
	using uint32 = uint32_t;

	using int64 = int64_t;
	using uint64 = uint64_t;

	using byte = uint8;
	using uint = unsigned int;

	using float32 = float;
	using float64 = double;




	
	enum class ByteOrder
	{
		LittleEndian = 1,
		BigEndian = 2,
	};

	ByteOrder calculateMachineByteOrder();

	extern const ByteOrder MachineByteOrder;

	
	
	enum class BitOrder
	{
		MostSignificantFirst,
		LeastSignificantFirst,
	};
	


	class Common
	{
	protected:
		using copyWord = __m128i;

		static const uint copyWordSize;
		static const uint copyWordMask;

	public:

		template <typename TYPE>
		static void swap(TYPE& first, TYPE& second);

		template <typename TYPE>
		static typename std::enable_if<std::is_trivially_copyable<TYPE>::value>::type* copy(TYPE* destination, const TYPE* source, size_t count = 1);

		template <typename TYPE>
		static typename std::enable_if<!std::is_trivially_copyable<TYPE>::value>::type* copy(TYPE* destination, const TYPE* source, size_t count = 1);

		template <typename TYPE>
		static typename std::enable_if<std::is_trivially_copyable<TYPE>::value>::type* move(TYPE* destination, TYPE* source, size_t count = 1);

		template <typename TYPE>
		static typename std::enable_if<!std::is_trivially_copyable<TYPE>::value>::type* move(TYPE* destination, TYPE* source, size_t count = 1);
		
		static void* copyBytes(void* destination, const void* source, size_t count);
		static uint8* copyBytes(uint8* destination, const uint8* source, size_t count);


		template <typename TYPE>
		static TYPE* fill(TYPE* destination, const TYPE& source, size_t count);

	protected:

	};

}

#include "Types.hpp"

namespace COR = CommonObjectRepository;


