#pragma once

#include "COR\Types.h"

#include "COR\Math\Math.h"

namespace CommonObjectRepository
{

	template <typename TYPE>
	class RangeBase
	{
	protected:
		TYPE startPoint;
		TYPE endPoint;

		RangeBase(const TYPE& start, const TYPE& end);
		RangeBase(const RangeBase<TYPE>& toCopy);
		RangeBase<TYPE>& operator=(const RangeBase<TYPE>& toAssign);
	public:
		~RangeBase(void);

		TYPE& start();
		const TYPE& start() const;

		TYPE& end();
		const TYPE& end() const;
	};


	template <typename TYPE>
	class Range : public RangeBase<TYPE>
	{
	public:
		Range() : RangeBase(0, 0) {}
		Range(const TYPE& start, const TYPE& end) : RangeBase(start, end) {}
		Range(const Range<TYPE>& toCopy) : RangeBase(toCopy) {}
		~Range(void) {};

		Range<TYPE>& operator=(const Range<TYPE>& toAssign)
		{
			RangeBase::operator=(toAssign);
			return *this;
		}
	};





	template <typename TYPE>
	class NumericRange : public RangeBase<TYPE>
	{
	protected:

	public:
		NumericRange() : RangeBase(0, 0) {}
		NumericRange(const TYPE& start, const TYPE& end) : RangeBase(start, end) {}
		NumericRange(const Range<TYPE>& toCopy) : RangeBase(toCopy) {}
		~NumericRange(void) {};

		NumericRange<TYPE>& operator=(const RangeBase<TYPE>& toAssign)
		{
			RangeBase::operator=(toAssign);
			return *this;
		}

		TYPE size() const
		{
			return endPoint - startPoint;
		}

		TYPE clamp(const TYPE& value) const
		{
			return Math::clamp(value, start(), end());
		}

		NumericRange<TYPE> clamp(const RangeBase<TYPE>& value) const
		{
			return Range<TYPE>(Math::clampMin(value.start(), start()), Math::clampMax(value.end(), end()));
		}
	};



	


/*
	template <typename TYPE>
	class IteratorRange : public RangeBase<TYPE>
	{
	public:
		IteratorRange() : RangeBase(0, 0) {}
		IteratorRange(const TYPE& start, const TYPE& end) : RangeBase(start, end) {}
		IteratorRange(const IteratorRange<TYPE>& toCopy) : RangeBase(toCopy) {}
		~IteratorRange(void) {};

		IteratorRange<TYPE>& operator=(const IteratorRange<TYPE>& toAssign)
		{
			RangeBase::operator=(toAssign);
			return *this;
		}
	};
*/
}

#include "Range.hpp"
