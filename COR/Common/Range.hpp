#include "StdAfx.h"
#include "Range.h"


namespace CommonObjectRepository
{

	template <typename TYPE>
	RangeBase<TYPE>::RangeBase(const TYPE& start, const TYPE& end) : startPoint(start), endPoint(end)
	{

	}

	template <typename TYPE>
	RangeBase<TYPE>::RangeBase(const RangeBase<TYPE>& toCopy) : startPoint(toCopy.startPoint), endPoint(toCopy.endPoint)
	{

	}

	template <typename TYPE>
	RangeBase<TYPE>::~RangeBase(void)
	{

	}

	template <typename TYPE>
	RangeBase<TYPE>& RangeBase<TYPE>::operator=(const RangeBase<TYPE>& toAssign)
	{
		startPoint = toAssign.startPoint;
		endPoint = toAssign.endPoint;

		return *this;
	}

	template <typename TYPE>
	TYPE& RangeBase<TYPE>::start()
	{
		return startPoint;
	}

	template <typename TYPE>
	const TYPE& RangeBase<TYPE>::start() const
	{
		return startPoint;
	}

	template <typename TYPE>
	TYPE& RangeBase<TYPE>::end()
	{
		return endPoint;
	}

	template <typename TYPE>
	const TYPE& RangeBase<TYPE>::end() const
	{
		return endPoint;
	}
/*
	template <typename TYPE>
	TYPE RangeBase<TYPE>::size() const
	{
		return endPoint - startPoint;
	}
*/




	
	template <>
	class Range<uint8> : public NumericRange<uint8>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const uint8& start, const uint8& end) : NumericRange(start, end) {}
		Range(const NumericRange<uint8>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<uint8>& operator=(const NumericRange<uint8>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};

	template <>
	class Range<int8> : public NumericRange<int8>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const int8& start, const int8& end) : NumericRange(start, end) {}
		Range(const NumericRange<int8>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<int8>& operator=(const NumericRange<int8>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};

	template <>
	class Range<uint16> : public NumericRange<uint16>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const uint16& start, const uint16& end) : NumericRange(start, end) {}
		Range(const NumericRange<uint16>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<uint16>& operator=(const NumericRange<uint16>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};

	template <>
	class Range<int16> : public NumericRange<int16>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const int16& start, const int16& end) : NumericRange(start, end) {}
		Range(const NumericRange<int16>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<int16>& operator=(const NumericRange<int16>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};

	template <>
	class Range<uint32> : public NumericRange<uint32>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const uint32& start, const uint32& end) : NumericRange(start, end) {}
		Range(const NumericRange<uint32>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<uint32>& operator=(const NumericRange<uint32>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};

	template <>
	class Range<int32> : public NumericRange<int32>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const int32& start, const int32& end) : NumericRange(start, end) {}
		Range(const NumericRange<int32>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<int32>& operator=(const NumericRange<int32>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};

	template <>
	class Range<uint64> : public NumericRange<uint64>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const uint64& start, const uint64& end) : NumericRange(start, end) {}
		Range(const NumericRange<uint64>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<uint64>& operator=(const NumericRange<uint64>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};

	template <>
	class Range<int64> : public NumericRange<int64>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const int64& start, const int64& end) : NumericRange(start, end) {}
		Range(const NumericRange<int64>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<int64>& operator=(const NumericRange<int64>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};

	template <>
	class Range<float32> : public NumericRange<float32>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const float32& start, const float32& end) : NumericRange(start, end) {}
		Range(const NumericRange<float32>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<float32>& operator=(const NumericRange<float32>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};

	template <>
	class Range<float64> : public NumericRange<float64>
	{
	public:
		Range() : NumericRange(0, 0) {}
		Range(const float64& start, const float64& end) : NumericRange(start, end) {}
		Range(const NumericRange<float64>& toCopy) : NumericRange(toCopy) {}
		~Range(void) {};

		Range<float64>& operator=(const NumericRange<float64>& toAssign)
		{
			NumericRange::operator=(toAssign);
			return *this;
		}
	};
}
