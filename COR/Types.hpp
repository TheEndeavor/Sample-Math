#include "StdAfx.h"
#include "Types.h"

namespace CommonObjectRepository
{
	template <typename TYPE>
	void Common::swap(TYPE& first, TYPE& second)
	{
		TYPE temp = std::move(first);
		first = std::move(second);
		second = std::move(temp);
	}

	template <typename TYPE>
	typename std::enable_if<std::is_trivially_copyable<TYPE>::value>::type* Common::copy(TYPE* destination, const TYPE* source, size_t count)
	{
		if (std::is_trivially_copyable<TYPE>())
			Common::copyBytes(reinterpret_cast<uint8*>(destination), reinterpret_cast<const uint8*>(source), sizeof(TYPE) * count);

		return destination;
	}

	template <typename TYPE>
	typename std::enable_if<!std::is_trivially_copyable<TYPE>::value>::type* Common::copy(TYPE* destination, const TYPE* source, size_t count)
	{
		for (size_t i = 0; i < count; i++)
			destination[i] = source[i];

		return destination;
	}

	template <typename TYPE>
	typename std::enable_if<std::is_trivially_copyable<TYPE>::value>::type* Common::move(TYPE* destination, TYPE* source, size_t count)
	{
		Common::copyBytes(reinterpret_cast<uint8*>(destination), reinterpret_cast<const uint8*>(source), sizeof(TYPE) * count);
//		Common::fill<uint8>(reinterpret_cast<uint8*>(source), 0, sizeof(TYPE) * count);
		
		return destination;
	}

	template <typename TYPE>
	typename std::enable_if<!std::is_trivially_copyable<TYPE>::value>::type* Common::move(TYPE* destination, TYPE* source, size_t count)
	{
		for (size_t i = 0; i < count; i++)
		{
			new (&destination[i]) TYPE(std::move(source[i]));
		}
		
		return destination;
	}

	
	template <typename TYPE>
	TYPE* Common::fill(TYPE* destination, const TYPE& source, size_t count)
	{
		for (size_t i=0; i<count; i++)
			*(destination + i) = source;

		return destination;
	}

}
