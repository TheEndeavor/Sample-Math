#include "StdAfx.h"
#include "Quaternion.h"


namespace CommonObjectRepository
{

	template <typename TYPE>
	Quaternion<TYPE> Quaternion<TYPE>::identity()
	{
		return Quaternion<TYPE>(0, 0, 0, 1);
	}

	template <typename TYPE>
	Quaternion<TYPE> Quaternion<TYPE>::rotate(const Vector3D<TYPE>& axis, TYPE angle)
	{
		//	Left Handed Rotation
		angle = -angle;

		TYPE halfAngle = angle / 2;
		TYPE sin = Math::sin(halfAngle);

		return Quaternion(axis.x() * sin, axis.y() * sin, axis.z() * sin, Math::cos(halfAngle));
	}

	template <typename TYPE>
	Quaternion<TYPE> Quaternion<TYPE>::getRotation(const Vector3D<TYPE>& source, const Vector3D<TYPE>& target)
	{
/*
		float cosAngle = vector1.dotProduct(vector2);
		Vector3D<TYPE> axis = vector1.crossProduct(vector2);

		return rotate(axis, cosAngle);
*/

		Vector3D<TYPE> cross = source.crossProduct(target);
		Quaternion<TYPE> toReturn = Quaternion<TYPE>(cross.x(), cross.y(), cross.z(), source.dotProduct(target));
		toReturn.w() += toReturn.getMagnitude();
		toReturn.normalize();

		return toReturn;
	}



	template <typename TYPE>
	Quaternion<TYPE>::Quaternion(void) : xComponent(0), yComponent(0), zComponent(0), wComponent(1)
	{

	}

	template <typename TYPE>
	Quaternion<TYPE>::Quaternion(TYPE x, TYPE y, TYPE z, TYPE w) : xComponent(x), yComponent(y), zComponent(z), wComponent(w)
	{

	}

	template <typename TYPE>
	Quaternion<TYPE>::Quaternion(TYPE x, TYPE y, TYPE z) : 
	{
		TYPE sinX = Math::sin(x / 2);
		TYPE cosX = Math::cos(x / 2);

		TYPE sinY = Math::sin(y / 2);
		TYPE cosY = Math::cos(y / 2);

		TYPE sinZ = Math::sin(z / 2);
		TYPE cosZ = Math::cos(z / 2);

		TYPE cosYcosZ = cosY * cosZ;
		TYPE sinYcosZ = sinY * cosZ;
		TYPE cosYsinZ = cosY * sinZ;
		TYPE sinYsinZ = sinY * sinZ;

		xComponent = sinX * cosYcosZ - cosX * sinYsinZ;
		yComponent = cosX * sinYcosZ + sinX * cosYsinZ;
		zComponent = cosX * cosYsinZ - sinX * sinYcosZ;
		wComponent = cosX * cosYcosZ + sinX * sinYsinZ;

		normalize();
	}

	
	template <typename TYPE>
	TYPE& Quaternion<TYPE>::x()
	{
		return xComponent;
	}

	template <typename TYPE>
	TYPE& Quaternion<TYPE>::y()
	{
		return yComponent;
	}

	template <typename TYPE>
	TYPE& Quaternion<TYPE>::z()
	{
		return zComponent;
	}

	template <typename TYPE>
	TYPE& Quaternion<TYPE>::w()
	{
		return wComponent;
	}

	template <typename TYPE>
	TYPE Quaternion<TYPE>::x() const
	{
		return xComponent;
	}

	template <typename TYPE>
	TYPE Quaternion<TYPE>::y() const
	{
		return yComponent;
	}

	template <typename TYPE>
	TYPE Quaternion<TYPE>::z() const
	{
		return zComponent;
	}

	template <typename TYPE>
	TYPE Quaternion<TYPE>::w() const
	{
		return wComponent;
	}
	
	template <typename TYPE>
	TYPE Quaternion<TYPE>::operator[](uint index) const
	{
		assert(index < 4);

		return (&xComponent)[index];
	}

	template <typename TYPE>
	Quaternion<TYPE> Quaternion<TYPE>::operator*(TYPE operand) const
	{
		return Quaternion<TYPE>(x() * operand, y() * operand, z() * operand, w() * operand);
	}

	template <typename TYPE>
	Quaternion<TYPE> Quaternion<TYPE>::operator*(const Quaternion<TYPE>& operand) const
	{
		return Quaternion<TYPE>((x() * operand.w()) + (w() * operand.x()) + (z() * operand.y()) - (y() * operand.z()),
								(y() * operand.w()) + (w() * operand.y()) + (x() * operand.z()) - (z() * operand.x()),
								(z() * operand.w()) + (w() * operand.z()) + (y() * operand.x()) - (x() * operand.y()),
								(w() * operand.w()) - (x() * operand.x()) - (y() * operand.y()) - (z() * operand.z()));
	}

	template <typename TYPE>
	Quaternion<TYPE>& Quaternion<TYPE>::operator*=(TYPE operand)
	{
		xComponent *= operand;
		yComponent *= operand;
		zComponent *= operand;
		wComponent *= operand;

		return *this;
	}

	template <typename TYPE>
	Quaternion<TYPE>& Quaternion<TYPE>::operator*=(const Quaternion<TYPE>& operand)
	{
		return this->operator=(*this * operand);
	}

	template <typename TYPE>
	TYPE Quaternion<TYPE>::getMagnitude() const
	{
		return Math::sqrt(getMagnitudeSquared());
	}

	template <typename TYPE>
	TYPE Quaternion<TYPE>::getMagnitudeSquared() const
	{
		return x() * x() + y() * y() + z() * z() + w() * w();
	}

	template <typename TYPE>
	Quaternion<TYPE>& Quaternion<TYPE>::normalize()
	{
		TYPE magnitude = getMagnitude();

		xComponent /= magnitude;
		yComponent /= magnitude;
		zComponent /= magnitude;
		wComponent /= magnitude;
		
		return *this;
	}

	template <typename TYPE>
	Quaternion<TYPE> Quaternion<TYPE>::normalized() const
	{
		TYPE magnitude = getMagnitude();
		
		return Quaternion<TYPE>(x() / magnitude, y() / magnitude, z() / magnitude, w() / magnitude);
	}

	template <typename TYPE>
	Quaternion<TYPE>& Quaternion<TYPE>::invert()
	{
		xComponent = -x();
		yComponent = -y();
		zComponent = -z();

		return *this;
	}

	template <typename TYPE>
	Quaternion<TYPE> Quaternion<TYPE>::inverted() const
	{
		return Quaternion<TYPE>(-x(), -y(), -z(), w());
	}

	template <typename TYPE>
	Vector3D<TYPE> Quaternion<TYPE>::getEulerAngles() const
	{
		return Vector3D<TYPE>(Math::atan(2 * (x() * y() + z() * w()), 1 - 2 * (y() * y() + z() * z)),
							  Math::asin(2 * (x() * z() - w() * y())),
							  Math::atan(2 * (x() * w() + y() * z()), 1 - 2 * (z() * z() + w() * w())));
	}

	template <typename TYPE>
	Vector3D<TYPE> Quaternion<TYPE>::rotate(const Vector3D<TYPE>& toRotate) const
	{
		Vector3D<TYPE> vector(x(), y(), z());

		TYPE scalar = w();

		return 2.0f * vector.dotProduct(toRotate) * vector +
			   (scalar * scalar - vector.dotProduct(vector)) * toRotate +
			   2.0f * scalar * vector.crossProduct(toRotate);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Quaternion<TYPE>::getMatrix() const
	{
		TYPE x2 = x() + x();
		TYPE y2 = y() + y();
		TYPE z2 = z() + z();
		TYPE w2 = w() + w();

		TYPE xx2 = x2 * x();
		TYPE xy2 = x2 * y();
		TYPE xz2 = x2 * z();
		TYPE xw2 = x2 * w();

		TYPE yy2 = y2 * y();
		TYPE yz2 = y2 * z();
		TYPE yw2 = y2 * w();

		TYPE zz2 = z2 * z();
		TYPE zw2 = z2 * w();

		return Matrix4D<TYPE>((1 - yy2 - zz2),		(xy2 - zw2),		(xz2 + yw2),		0,
							  (xy2 + zw2),			(1 - xx2 - zz2),	(yz2 - xw2),		0,
							  (xz2 - yw2),			(yz2 + xw2),		(1 - xx2 - yy2),	0,
							  0, 0, 0, 1);
	}

}