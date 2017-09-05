#pragma once

#include "COR\Types.h"

#include "COR\Math\Math.h"

#include "Vector3D.h"

namespace CommonObjectRepository
{
	template <typename TYPE>
	class Sphere3D
	{
	protected:
		Vector3D<TYPE> centerComponent;
		TYPE radiusComponent;

	public:
		Sphere3D(void);
		Sphere3D(Vector3D<TYPE> center, TYPE radius);
		Sphere3D(const Sphere3D<TYPE>& toCopy);
		~Sphere3D(void);

		Sphere3D<TYPE>& operator=(const Sphere3D<TYPE>& toAssign);

		Vector3D<TYPE>& center();
		Vector3D<TYPE> center() const;

		TYPE radius() const;

		TYPE getDistance(Vector3D<TYPE> point) const;
		TYPE getDistanceSquared(Vector3D<TYPE> point) const;

	};


}

#include "Sphere3D.hpp"
