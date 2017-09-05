#pragma once

namespace CommonObjectRepository
{
	template <typename TYPE>
	Vector3D<TYPE>::Vector3D() : Vector3D(0, 0, 0)
	{

	}

	template <typename TYPE>
	Vector3D<TYPE>::Vector3D(TYPE x, TYPE y, TYPE z) : xComponent(x), yComponent(y), zComponent(z)
	{

	}

	template <typename TYPE>
	Vector3D<TYPE>::Vector3D(const Vector2D<TYPE>& xy, TYPE z) : Vector3D(xy.x(), xy.y(), z)
	{

	}

	template <typename TYPE>
	template <typename T>
	Vector3D<TYPE>::Vector3D(const Vector3D<T>& toCopy) : Vector3D(toCopy.xComponent, toCopy.yComponent, toCopy.zComponent)
	{

	}

	template <typename TYPE>
	Vector3D<TYPE>::Vector3D(const Vector4D<TYPE>& toAssign) : Vector3D(toAssign.xComponent, toAssign.yComponent, toAssign.zComponent)
	{

	}


	template <typename TYPE>
	Vector2D<TYPE> Vector3D<TYPE>::toVector2D() const
	{
		return Vector2D<TYPE>(x(), y());
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector3D<TYPE>::toVector4D(TYPE wComponent) const
	{
		return Vector4D<TYPE>(xComponent, yComponent, zComponent, wComponent);
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector3D<TYPE>::toVertexVector4D() const
	{
		return Vector4D<TYPE>(xComponent, yComponent, zComponent, 1);
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector3D<TYPE>::toNormalVector4D() const
	{
		return Vector4D<TYPE>(xComponent, yComponent, zComponent, 0);
	}

	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::set(TYPE x, TYPE y, TYPE z)
	{
		x() = x;
		y() = y;
		z() = z;

		return *this;
	}

	template <typename TYPE>
	bool Vector3D<TYPE>::operator==(const Vector3D<TYPE>& toCompare) const
	{
		return (x() == toCompare.x()) &&
			   (y() == toCompare.y()) &&
			   (z() == toCompare.y());
	}

	template <typename TYPE>
	bool Vector3D<TYPE>::operator!=(const Vector3D<TYPE>& toCompare) const
	{
		return !(operator==(toCompare));
	}

	template <typename TYPE>
	TYPE& Vector3D<TYPE>::x()
	{
		return this->xComponent;
	}

	template <typename TYPE>
	TYPE& Vector3D<TYPE>::y()
	{
		return this->yComponent;
	}

	template <typename TYPE>
	TYPE& Vector3D<TYPE>::z()
	{
		return this->zComponent;
	}

	
	template <typename TYPE>
	TYPE Vector3D<TYPE>::x() const
	{
		return this->xComponent;
	}

	template <typename TYPE>
	TYPE Vector3D<TYPE>::y() const
	{
		return this->yComponent;
	}

	template <typename TYPE>
	TYPE Vector3D<TYPE>::z() const
	{
		return this->zComponent;
	}

	template <typename TYPE>
	TYPE& Vector3D<TYPE>::operator[](int operand)
	{
		assert(0 <= operand && operand <= 2);
		return (&xComponent)[operand];
	}

	template <typename TYPE>
	TYPE Vector3D<TYPE>::operator[](int operand) const
	{
		assert(0 <= operand && operand <= 2);
		return (&xComponent)[operand];
	}
	
	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::operator+(const TYPE operand) const
	{
		return Vector3D<TYPE>(x() + operand, y() + operand, z() + operand);
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::operator-(const TYPE operand) const
	{
		return Vector3D<TYPE>(x() - operand, y() - operand, z() - operand);
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::operator*(const TYPE operand) const
	{
		return Vector3D<TYPE>(x() * operand, y() * operand, z() * operand);
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::operator/(const TYPE operand) const
	{
		return Vector3D<TYPE>(x() / operand, y() / operand, z() / operand);
	}


	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::operator+=(const TYPE operand)
	{
		x() += operand;
		y() += operand;
		z() += operand;

		return *this;
	}

	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::operator-=(const TYPE operand)
	{
		x() -= operand;
		y() -= operand;
		z() -= operand;

		return *this;
	}

	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::operator*=(const TYPE operand)
	{
		x() *= operand;
		y() *= operand;
		z() *= operand;

		return *this;
	}

	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::operator/=(const TYPE operand)
	{
		x() /= operand;
		y() /= operand;
		z() /= operand;

		return *this;
	}


	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::operator+(const Vector3D<TYPE>& operand) const
	{
		return Vector3D<TYPE>(x() + operand.x(), y() + operand.y(), z() + operand.z());
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::operator-(const Vector3D<TYPE>& operand) const
	{
		return Vector3D<TYPE>(x() - operand.x(), y() - operand.y(), z() - operand.z());
	}


	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::operator+=(const Vector3D<TYPE>& operand)
	{
		x() += operand.x();
		y() += operand.y();
		z() += operand.z();
		return *this;
	}

	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::operator-=(const Vector3D<TYPE>& operand)
	{
		x() -= operand.x();
		y() -= operand.y();
		z() -= operand.z();
		return *this;
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::operator-() const
	{
		return negated();
	}

	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::scale(const Vector3D<TYPE>& scalar)
	{
		x() *= scalar.x();
		y() *= scalar.y();
		z() *= scalar.z();

		return *this;
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::scaled(const Vector3D<TYPE>& scalar) const
	{
		return Vector3D<TYPE>(x() * scalar.x(), y() * scalar.y(), z() * scalar.z());
	}

	template <typename TYPE>
	TYPE Vector3D<TYPE>::getMagnitudeSquared() const
	{
		return x() * x() + y() * y() + z() * z();
	}

	template <typename TYPE>
	TYPE Vector3D<TYPE>::getMagnitude() const
	{
		return Math::sqrt(getMagnitudeSquared());
	}
	
	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::normalize()
	{
		TYPE magnitude = getMagnitude();
		
		return (*this) /= magnitude;
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::normalized() const
	{
		TYPE magnitude = getMagnitude();
		
		return Vector3D<TYPE>(x() / magnitude, y() / magnitude, z() / magnitude);
	}

	template <typename TYPE>
	Vector3D<TYPE>& Vector3D<TYPE>::negate()
	{
		x() = -x();
		y() = -y();
		z() = -z();

		return *this;
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::negated() const
	{
		return Vector3D<TYPE>(-x(), -y(), -z());
	}

	template <typename TYPE>
	TYPE Vector3D<TYPE>::dotProduct(const Vector3D<TYPE>& operand) const
	{
		return (x() * operand.x()) + (y() * operand.y()) + (z() * operand.z());
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector3D<TYPE>::crossProduct(const Vector3D<TYPE>& operand) const
	{
		return Vector3D<TYPE>((y() * operand.z()) - (z() * operand.y()),
							  (z() * operand.x()) - (x() * operand.z()),
							  (x() * operand.y()) - (y() * operand.x()));
	}
	
	template <typename TYPE>
	TYPE Vector3D<TYPE>::getDistanceSquared(const Vector3D<TYPE>& point) const
	{
		return (point - *this).getMagnitudeSquared();
	}

	template <typename TYPE>
	TYPE Vector3D<TYPE>::getDistance(const Vector3D<TYPE>& point) const
	{
		return (point - *this).getMagnitude();
	}




	template <typename TYPE>
	Vector3D<TYPE> operator+(const TYPE operand1, const Vector3D<TYPE>& operand2)
	{
		return Vector3D<TYPE>(operand1 + operand2.x(), operand1 + operand2.y(), operand1 + operand2.z());
	}

	template <typename TYPE>
	Vector3D<TYPE> operator-(const TYPE operand1, const Vector3D<TYPE>& operand2)
	{
		return Vector3D<TYPE>(operand1 - operand2.x(), operand1 - operand2.y(), operand1 - operand2.z());
	}

	template <typename TYPE>
	Vector3D<TYPE> operator*(const TYPE operand1, const Vector3D<TYPE>& operand2)
	{
		return Vector3D<TYPE>(operand1 * operand2.x(), operand1 * operand2.y(), operand1 * operand2.z());
	}

	template <typename TYPE>
	Vector3D<TYPE> operator/(const TYPE operand1, const Vector3D<TYPE>& operand2)
	{
		return Vector3D<TYPE>(operand1 / operand2.x(), operand1 / operand2.y(), operand1 / operand2.z());
	}



}

