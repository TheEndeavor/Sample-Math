#include "StdAfx.h"
#include "Sphere3D.h"


namespace CommonObjectRepository
{
	template <typename TYPE>
	Sphere3D<TYPE>::Sphere3D(void) : centerComponent(), radius(0)
	{

	}

	template <typename TYPE>
	Sphere3D<TYPE>::Sphere3D(Vector3D<TYPE> center, TYPE radius) : centerComponent(center), radiusComponent(radius)
	{

	}

	template <typename TYPE>
	Sphere3D<TYPE>::Sphere3D(const Sphere3D<TYPE>& toCopy) : centerComponent(toCopy.centerComponent), radiusComponent(toCopy.radiusComponent)
	{

	}
	

	template <typename TYPE>
	Sphere3D<TYPE>::~Sphere3D(void)
	{

	}

	template <typename TYPE>
	Sphere3D<TYPE>& Sphere3D<TYPE>::operator=(const Sphere3D<TYPE>& toAssign)
	{
		center() = toAssign.center();
		radius() = toAssign.radius();
	}

	template <typename TYPE>
	Vector3D<TYPE>& Sphere3D<TYPE>::center()
	{
		return centerComponent;
	}

	template <typename TYPE>
	Vector3D<TYPE> Sphere3D<TYPE>::center() const
	{
		return centerComponent;
	}

	template <typename TYPE>
	TYPE Sphere3D<TYPE>::radius() const
	{
		return radiusComponent;
	}

	template <typename TYPE>
	TYPE Sphere3D<TYPE>::getDistance(Vector3D<TYPE> point) const
	{
		return Math::sqrt(getDisanceSquared());
	}

	template <typename TYPE>
	TYPE Sphere3D<TYPE>::getDistanceSquared(Vector3D<TYPE> point) const
	{
		return (point - center()).getDistanceSquared() - (radius() * radius());
	}
}

