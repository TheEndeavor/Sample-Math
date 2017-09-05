#include "StdAfx.h"
#include "Types.h"

namespace CommonObjectRepository
{

	ByteOrder calculateMachineByteOrder()
	{
		static union
		{
			uint32 i;
			uint8 c[4];
		} bytes = {0x01020304};

		return (ByteOrder)((bytes.c[0] == 1) + 1);
	}

	const ByteOrder MachineByteOrder = calculateMachineByteOrder();



	const uint Common::copyWordSize = sizeof(Common::copyWord);
	const uint Common::copyWordMask = Common::copyWordSize - 1;


	template <>
	void* Common::copy<void>(void* destination, const void* source, size_t count)
	{
		return copyBytes((uint8*)destination, (const uint8*)source, count);
	}

	void* Common::copyBytes(void* destination, const void* source, size_t count)
	{
		return copyBytes((uint8*)destination, (const uint8*)source, count);
	}

	uint8* Common::copyBytes(uint8* destination, const uint8* source, size_t count)
	{
		//	Needs optimization for small count counts, and known compile time counts.

//		uint8* destinationBytes = reinterpret_cast<uint8*>(destination);
//		const uint8* sourceBytes = reinterpret_cast<const uint8*>(source);

		if (destination < source)
		{
			//	Destination before Source. Copy forward.
			uint8* end = destination + count;

			//	Copy bytes until Destination is aligned on a Word boundry.
			uint8* stop = destination + (copyWordSize - ((uint)destination & copyWordMask));
			stop = (count < 16) || (stop > end) ? end : stop;
			while(destination < stop - 3)
			{
				*(uint32*)destination = *(uint32*)source;
				destination += 4;
				source += 4;
			}
			while(destination < stop)
				*(destination++) = *(source++);

			if (stop == end)
				return destination;

			//	Copy Words for performance.
			stop = end - copyWordMask;
			if (((uint)source & copyWordMask) == 0)
				while (destination < stop)
				{
					_mm_store_si128((copyWord*)destination, _mm_load_si128((copyWord*)source));
					source += copyWordSize;
					destination += copyWordSize;
				}
			else
				while (destination < stop)
				{
					_mm_store_si128((copyWord*)destination, _mm_loadu_si128((copyWord*)source));
					source += copyWordSize;
					destination += copyWordSize;
				}

			//	Copy any trailing bytes.
			while(destination < end - 3)
			{
				*(uint32*)destination = *(uint32*)source;
				destination += 4;
				source += 4;
			}
			while(destination < end)
				*(destination++) = *(source++);
		}
		else
		{
			//	Source before Destination. Copy backward.
			uint8* end = destination;
			destination += count;
			source += count;

			//	Copy bytes until Destination is aligned on a Word boundry.
			uint8* stop = destination - ((uint)destination & copyWordMask);
			stop = (count < 16) || (stop < end) ? end : stop;
			while (destination > stop + 3)
			{
				destination -= 4;
				source -= 4;
				*(uint32*)destination = *(uint32*)source;
			}
			while(destination > stop)
				*(--destination) = *(--source);

			if (stop == end)
				return destination;

			//	Copy Words for performance.
			stop = end + copyWordMask;
			if (((uint)source & copyWordMask) == 0)
				while (destination > stop)
				{
					source -= copyWordSize;
					destination -= copyWordSize;
					_mm_store_si128((copyWord*)destination, _mm_load_si128((copyWord*)source));
				}
			else
				while (destination > stop)
				{
					source -= copyWordSize;
					destination -= copyWordSize;
					_mm_store_si128((copyWord*)destination, _mm_loadu_si128((copyWord*)source));
				}

			//	Copy any trailing bytes.
			while (destination > end + 3)
			{
				destination -= 4;
				source -= 4;
				*(uint32*)destination = *(uint32*)source;
			}
			while(destination > end)
				*(--destination) = *(--source);
		}

		return destination;
	}


	
}
