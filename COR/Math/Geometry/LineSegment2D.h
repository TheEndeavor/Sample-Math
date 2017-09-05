#pragma once

#include "Vector2D.h"
#include "Normalized.h"

namespace CommonObjectRepository
{

	template <typename TYPE>
	class LineSegment2D
	{
	protected:
		Vector2D<TYPE> originComponent;
		Vector2D<TYPE> destinationComponent;
		
	public:
		LineSegment2D(const Vector2D<TYPE>& origin, const Vector2D<TYPE>& destination);
		LineSegment2D(const LineSegment2D<TYPE>& toCopy) = default;
		LineSegment2D(LineSegment2D<TYPE>&& toMove) = default;
		~LineSegment2D() = default;

		LineSegment2D<TYPE>& operator=(const LineSegment2D<TYPE>& toAssign) = default;
		LineSegment2D<TYPE>& operator=(LineSegment2D<TYPE>&& toAssign) = default;

		Vector2D<TYPE> origin() const;
		Vector2D<TYPE>& origin();

		Vector2D<TYPE> destination() const;
		Vector2D<TYPE>& destination();

		Vector2D<TYPE> getVector() const;
		TYPE getLengthSquared() const;
		TYPE getLength() const;
	};


}

#include "LineSegment2D.hpp"
