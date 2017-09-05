#pragma once


namespace CommonObjectRepository
{

	template <typename TYPE>
	LineSegment2D<TYPE>::LineSegment2D(const Vector2D<TYPE>& origin, const Vector2D<TYPE>& destination) : originComponent(origin), destinationComponent(destination)
	{
		
	}


	template <typename TYPE>
	Vector2D<TYPE> LineSegment2D<TYPE>::origin() const
	{
		return originComponent;
	}

	template <typename TYPE>
	Vector2D<TYPE>& LineSegment2D<TYPE>::origin()
	{
		return originComponent;
	}

	template <typename TYPE>
	Vector2D<TYPE> LineSegment2D<TYPE>::destination() const
	{
		return destinationComponent;
	}

	template <typename TYPE>
	Vector2D<TYPE>& LineSegment2D<TYPE>::destination()
	{
		return destinationComponent;
	}

	template <typename TYPE>
	Vector2D<TYPE> LineSegment2D<TYPE>::getVector() const
	{
		return destination() - origin();
	}

	template <typename TYPE>
	TYPE LineSegment2D<TYPE>::getLength() const
	{
		return (destination() - origin()).getMagnitude();
	}

	template <typename TYPE>
	TYPE LineSegment2D<TYPE>::getLengthSquared() const
	{
		return (destination() - origin()).getMagnitudeSquared();
	}

}
