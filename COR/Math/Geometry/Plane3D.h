#pragma once

#include "COR\Types.h"

#include "Normalized.h"
#include "Vector3D.h"

namespace CommonObjectRepository
{

	template <typename TYPE>
	class Plane3D
	{
	protected:
		Vector3D<TYPE> centerComponent;
		Vector3D<TYPE> normalComponent;

	public:
		Plane3D(void);
		Plane3D(Vector3D<TYPE> center, Vector3D<TYPE> normal);
		Plane3D(const Plane3D& toCopy);
		~Plane3D(void);

		Plane3D<TYPE>& operator=(const Plane3D<TYPE>& operand);

		Plane3D<TYPE>& set(Vector3D<TYPE> center, Vector3D<TYPE> normal);

		Vector3D<TYPE>& center();
		Normalized<Vector3D<TYPE>> normal();

		Vector3D<TYPE> center() const;
		Vector3D<TYPE> normal() const;

		TYPE getDistance(Vector3D<TYPE> point) const;
		TYPE getSignedDistance(Vector3D<TYPE> point) const;
		Vector3D<TYPE> nearestPoint(Vector3D<TYPE> point) const;
	};


}

#include "Plane3D.hpp"
