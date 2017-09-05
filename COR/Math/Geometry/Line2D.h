#pragma once

#include "Vector2D.h"
#include "Normalized.h"

namespace CommonObjectRepository
{

	template <typename TYPE>
	class Line2D
	{
	protected:
		Vector2D<TYPE> originComponent;
		Vector2D<TYPE> directionComponent;

	public:
		Line2D(const Vector2D<TYPE>& origin, const Vector2D<TYPE>& direction);
		Line2D(const Line2D<TYPE>& toCopy) = default;
		Line2D(Line2D<TYPE>&& toMove) = default;
		~Line2D(void) = default;

		Line2D<TYPE>& operator=(const Line2D<TYPE>& toAssign) = default;
		Line2D<TYPE>& operator=(Line2D<TYPE>&& toMove) = default;

		Vector2D<TYPE>& origin();
		Normalized<Vector2D<TYPE>> direction();

		Vector2D<TYPE> origin() const;
		Vector2D<TYPE> direction() const;


		Vector2D<TYPE> getPoint(TYPE distance) const;

		Vector2D<TYPE> getNearestPoint(const Vector2D<TYPE>& point) const;

		TYPE getDistance(const Vector2D<TYPE>& point) const;
		TYPE getDistanceSquared(const Vector2D<TYPE>& point) const;

	};



}

#include "Line2D.hpp"
