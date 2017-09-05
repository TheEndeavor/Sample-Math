#include "StdAfx.h"
#include "Plane3D.h"


namespace CommonObjectRepository
{
	template <typename TYPE>
	Plane3D<TYPE>::Plane3D(void) : centerComponent(), normalComponent()
	{

	}

	template <typename TYPE>
	Plane3D<TYPE>::Plane3D(Vector3D<TYPE> center, Vector3D<TYPE> normal) : centerComponent(centerComponent), normalComponent(normal.normalize())
	{

	}

	template <typename TYPE>
	Plane3D<TYPE>::Plane3D(const Plane3D& toCopy) : centerComponent(toCopy.centerComponent), normalComponent(toCopy.normalComponent)
	{

	}

	template <typename TYPE>
	Plane3D<TYPE>::~Plane3D(void)
	{

	}

	
	template <typename TYPE>
	Plane3D<TYPE>& Plane3D<TYPE>::operator=(const Plane3D<TYPE>& operand)
	{
		centerComponent = operand.centerComponent;
		normalComponent = operand.normalComponent;

		return *this;
	}

	
	template <typename TYPE>
	Plane3D<TYPE>& Plane3D<TYPE>::set(Vector3D<TYPE> center, Vector3D<TYPE> normal)
	{
		centerComponent = center;
		normalComponent = normal.normalize();
	}

	
	template <typename TYPE>
	Vector3D<TYPE>& Plane3D<TYPE>::center()
	{
		return centerComponent;
	}

	template <typename TYPE>
	Normalized<Vector3D<TYPE>> Plane3D<TYPE>::normal()
	{
		return Normalized<Vector3D<TYPE>>(normalComponent);
	}

	
	template <typename TYPE>
	Vector3D<TYPE> Plane3D<TYPE>::center() const
	{
		return centerComponent;
	}

	template <typename TYPE>
	Vector3D<TYPE> Plane3D<TYPE>::normal() const
	{
		return normalComponent;
	}

	template <typename TYPE>
	TYPE Plane3D<TYPE>::getDistance(Vector3D<TYPE> point) const
	{
		return Math::abs(getSignedDistance());
	}

	template <typename TYPE>
	TYPE Plane3D<TYPE>::getSignedDistance(Vector3D<TYPE> point) const
	{
		return normal().dotProduct(point - center());
	}

	template <typename TYPE>
	Vector3D<TYPE> Plane3D<TYPE>::nearestPoint(Vector3D<TYPE> point) const
	{
		return point - (getSignedDistance(point) * normal());
	}

}