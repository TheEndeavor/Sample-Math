#pragma once

namespace CommonObjectRepository
{
	template <typename TYPE>
	Vector2D<TYPE>::Vector2D() : Vector2D(0, 0)
	{

	}

	template <typename TYPE>
	Vector2D<TYPE>::Vector2D(TYPE x, TYPE y) : xComponent(x), yComponent(y)
	{

	}

	template <typename TYPE>
	Vector2D<TYPE>::Vector2D(const Area2D<TYPE>& toCopy) : Vector2D(toCopy.width(), toCopy.height())
	{

	}

	template <typename TYPE>
	template <typename T>
	Vector2D<TYPE>::Vector2D(const Vector2D<T>& toCopy) : Vector2D((TYPE)toCopy.xComponent, (TYPE)toCopy.yComponent)
	{

	}


	template <typename TYPE>
	Vector3D<TYPE> Vector2D<TYPE>::toVector3D(TYPE zComponent)
	{
		return Vector3D<TYPE>(xComponent, yComponent, zComponent);
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector2D<TYPE>::toVector4D(TYPE zComponent, TYPE wComponent)
	{
		return Vector4D<TYPE>(xComponent, yComponent, zComponent, wComponent);
	}

	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::set(TYPE x, TYPE y)
	{
		xComponent = x;
		yComponent = y;

		return *this;
	}

	template <typename TYPE>
	bool Vector2D<TYPE>::operator==(const Vector2D<TYPE>& toCompare) const
	{
		return (x() == toCompare.x()) && (y() == toCompare.y());
	}

	template <typename TYPE>
	bool Vector2D<TYPE>::operator!=(const Vector2D<TYPE>& toCompare) const
	{
		return !(operator==(toCompare));
	}
	
	template <typename TYPE>
	TYPE& Vector2D<TYPE>::x()
	{
		return this->xComponent;
	}

	template <typename TYPE>
	TYPE& Vector2D<TYPE>::y()
	{
		return this->yComponent;
	}

	
	template <typename TYPE>
	TYPE Vector2D<TYPE>::x() const
	{
		return this->xComponent;
	}

	template <typename TYPE>
	TYPE Vector2D<TYPE>::y() const
	{
		return this->yComponent;
	}

	template <typename TYPE>
	TYPE& Vector2D<TYPE>::operator[](int operand)
	{
		assert(0 <= operand && operand <= 1);
		return (&xComponent)[operand];
	}

	template <typename TYPE>
	TYPE Vector2D<TYPE>::operator[](int operand) const
	{
		assert(0 <= operand && operand <= 1);
		return (&xComponent)[operand];
	}
	
	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::operator+(const TYPE operand) const
	{
		return Vector2D<TYPE>(x() + operand, y() + operand);
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::operator-(const TYPE operand) const
	{
		return Vector2D<TYPE>(x() - operand, y() - operand);
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::operator*(const TYPE operand) const
	{
		return Vector2D<TYPE>(x() * operand, y() * operand);
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::operator/(const TYPE operand) const
	{
		return Vector2D<TYPE>(x() / operand, y() / operand);
	}


	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::operator+=(const TYPE operand)
	{
		x() += operand;
		y() += operand;

		return *this;
	}

	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::operator-=(const TYPE operand)
	{
		x() -= operand;
		y() -= operand;

		return *this;
	}

	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::operator*=(const TYPE operand)
	{
		x() *= operand;
		y() *= operand;

		return *this;
	}

	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::operator/=(const TYPE operand)
	{
		x() /= operand;
		y() /= operand;

		return *this;
	}


	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::operator+(const Vector2D<TYPE>& operand) const
	{
		return Vector2D<TYPE>(x() + operand.x(), y() + operand.y());
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::operator-(const Vector2D<TYPE>& operand) const
	{
		return Vector2D<TYPE>(x() - operand.x(), y() - operand.y());
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::operator*(const Vector2D<TYPE>& operand) const
	{
		return Vector2D<TYPE>(x() * operand.x(), y() * operand.y());
	}


	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::operator+=(const Vector2D<TYPE>& operand)
	{
		x() += operand.x();
		y() += operand.y();
		return *this;
	}

	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::operator-=(const Vector2D<TYPE>& operand)
	{
		x() -= operand.x();
		y() -= operand.y();
		return *this;
	}

	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::operator*=(const Vector2D<TYPE>& operand)
	{
		x() *= operand.x();
		y() *= operand.y();
		return *this;
	}
	
	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::operator-() const
	{
		return negated();
	}
	
	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::scale(const Vector2D<TYPE>& scalar)
	{
		x() *= scalar.x();
		y() *= scalar.y();

		return *this;
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::scaled(const Vector2D<TYPE>& scalar) const
	{
		return Vector2D<TYPE>(x() * scalar.x(), y() * scalar.y());
	}

	template <typename TYPE>
	TYPE Vector2D<TYPE>::getMagnitudeSquared() const
	{
		return x() * x() + y() * y();
	}

	template <typename TYPE>
	TYPE Vector2D<TYPE>::getMagnitude() const
	{
		return Math::sqrt(getMagnitudeSquared());
	}
	
	
	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::normalize()
	{
		TYPE magnitude = getMagnitude();
		
		return (*this) /= magnitude;
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::normalized() const
	{
		TYPE magnitude = getMagnitude();
		
		return Vector2D<TYPE>(x() / magnitude, y() / magnitude);
	}

	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::negate()
	{
		x() = -x();
		y() = -y();

		return *this;
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::negated() const
	{
		return Vector2D<TYPE>(-x(), -y());
	}

	template <typename TYPE>
	TYPE Vector2D<TYPE>::dotProduct(const Vector2D<TYPE>& operand) const
	{
		return (x() * operand.x()) + (y() * operand.y());
	}

	template <typename TYPE>
	TYPE Vector2D<TYPE>::crossProduct(const Vector2D<TYPE>& operand) const
	{
		return (x() * operand.y()) - (y() * operand.x());
	}


	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::rotate(TYPE angle)
	{
		TYPE sin = Math::sin(angle);
		TYPE cos = Math::cos(angle);

		return set(x() * cos - y() * sin, x() * sin + y() * cos);
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::rotated(TYPE angle) const
	{
		TYPE sin = Math::sin(angle);
		TYPE cos = Math::cos(angle);

		return Vector2D<>(x() * cos - y() * sin, x() * sin + y() * cos);
	}

	template <typename TYPE>
	Vector2D<TYPE>& Vector2D<TYPE>::rotate(TYPE angle, const Vector2D<TYPE>& center)
	{
		*this -= center;

		rotate(angle);

		return *this += center;
	}

	template <typename TYPE>
	Vector2D<TYPE> Vector2D<TYPE>::rotated(TYPE angle, const Vector2D<TYPE>& center) const
	{
		return rotated(*this - center) + center;
	}

	template <typename TYPE>
	TYPE Vector2D<TYPE>::getDistanceSquared(const Vector2D<TYPE>& point) const
	{
		return (point - *this).getMagnitudeSquared();
	}

	template <typename TYPE>
	TYPE Vector2D<TYPE>::getDistance(const Vector2D<TYPE>& point) const
	{
		return (point - *this).getMagnitude();
	}



	template <typename TYPE>
	Vector2D<TYPE> operator+(const TYPE operand1, const Vector2D<TYPE>& operand2)
	{
		return Vector2D<TYPE>(operand1 + operand2.x(), operand1 + operand2.y());
	}

	template <typename TYPE>
	Vector2D<TYPE> operator-(const TYPE operand1, const Vector2D<TYPE>& operand2)
	{
		return Vector2D<TYPE>(operand1 - operand2.x(), operand1 - operand2.y());
	}

	template <typename TYPE>
	Vector2D<TYPE> operator*(const TYPE operand1, const Vector2D<TYPE>& operand2)
	{
		return Vector2D<TYPE>(operand1 * operand2.x(), operand1 * operand2.y());
	}

	template <typename TYPE>
	Vector2D<TYPE> operator/(const TYPE operand1, const Vector2D<TYPE>& operand2)
	{
		return Vector2D<TYPE>(operand1 / operand2.x(), operand1 / operand2.y());
	}


}

