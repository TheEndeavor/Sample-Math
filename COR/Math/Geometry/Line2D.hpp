

namespace CommonObjectRepository
{
	template <typename TYPE>
	Line2D<TYPE>::Line2D(const Vector2D<TYPE>& origin, const Vector2D<TYPE>& direction) :originComponent(origin), directionComponent(direction)
	{
		directionComponent.normalize();
	}


	template <typename TYPE>
	Vector2D<TYPE>& Line2D<TYPE>::origin()
	{
		return originComponent;
	}

	template <typename TYPE>
	Normalized<Vector2D<TYPE>> Line2D<TYPE>::direction()
	{
		return Normalized<Vector2D<TYPE>>(directionComponent);
	}

	template <typename TYPE>
	Vector2D<TYPE> Line2D<TYPE>::origin() const
	{
		return originComponent;
	}

	template <typename TYPE>
	Vector2D<TYPE> Line2D<TYPE>::direction() const
	{
		return directionComponent;
	}

	template <typename TYPE>
	Vector2D<TYPE> Line2D<TYPE>::getPoint(TYPE distance) const
	{
		return origin() + (direction() * distance);
	}

	template <typename TYPE>
	Vector2D<TYPE> Line2D<TYPE>::getNearestPoint(const Vector2D<TYPE>& point) const
	{
		return origin() + (point - origin()).dotProduct(direction()) * direction();
	}

	template <typename TYPE>
	TYPE Line2D<TYPE>::getDistance(const Vector2D<TYPE>& point) const
	{
		return (point - getNearestPoint()).getMagnitude();
	}

	template <typename TYPE>
	TYPE Line2D<TYPE>::getDistanceSquared(const Vector2D<TYPE>& point) const
	{
		return (point - getNearestPoint()).getMagnitudeSquared();
	}

}