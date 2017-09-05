#pragma once

namespace CommonObjectRepository
{
	template <typename TYPE>
	Vector4D<TYPE>::Vector4D() : Vector4D(0, 0, 0, 0)
	{

	}

	template <typename TYPE>
	Vector4D<TYPE>::Vector4D(TYPE x, TYPE y, TYPE z, TYPE w) : xComponent(x), yComponent(y), zComponent(z), wComponent(w)
	{

	}

	template <typename TYPE>
	Vector4D<TYPE>::Vector4D(const Vector2D<TYPE>& xy, TYPE z, TYPE w) : Vector4D(xy.x(), xy.y(), z, w)
	{

	}

	template <typename TYPE>
	Vector4D<TYPE>::Vector4D(const Vector3D<TYPE>& xyz, TYPE w) : Vector4D(xyz.x(), xyz.y(), xyz.z(), w)
	{

	}

	template <typename TYPE>
	template <typename T>
	Vector4D<TYPE>::Vector4D(const Vector4D<T>& toCopy) : Vector4D((TYPE)toCopy.xComponent, (TYPE)toCopy.yComponent, (TYPE)toCopy.zComponent, (TYPE)toCopy.wComponent)
	{

	}


	template <typename TYPE>
	Vector2D<TYPE> Vector4D<TYPE>::toVector2D() const
	{
		return Vector2D<TYPE>(x(), y());
	}

	template <typename TYPE>
	Vector3D<TYPE> Vector4D<TYPE>::toVector3D() const
	{
		return Vector3D<TYPE>(x(), y());
	}

	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::set(TYPE x, TYPE y, TYPE z, TYPE w)
	{
		x() = x;
		y() = y;
		z() = z;
		w() = w;

		return *this;
	}

	template <typename TYPE>
	bool Vector4D<TYPE>::operator==(const Vector4D<TYPE>& toCompare) const
	{
		return (x() == toCompare.x()) &&
			   (y() == toCompare.y()) &&
			   (z() == toCompare.y()) &&
			   (w() == toCompare.w());
	}

	template <typename TYPE>
	bool Vector4D<TYPE>::operator!=(const Vector4D<TYPE>& toCompare) const
	{
		return !(operator==(toCompare));
	}

	template <typename TYPE>
	TYPE& Vector4D<TYPE>::x()
	{
		return this->xComponent;
	}

	template <typename TYPE>
	TYPE& Vector4D<TYPE>::y()
	{
		return this->yComponent;
	}

	template <typename TYPE>
	TYPE& Vector4D<TYPE>::z()
	{
		return this->zComponent;
	}

	template <typename TYPE>
	TYPE& Vector4D<TYPE>::w()
	{
		return this->wComponent;
	}

	
	template <typename TYPE>
	TYPE Vector4D<TYPE>::x() const
	{
		return this->xComponent;
	}

	template <typename TYPE>
	TYPE Vector4D<TYPE>::y() const
	{
		return this->yComponent;
	}

	template <typename TYPE>
	TYPE Vector4D<TYPE>::z() const
	{
		return this->zComponent;
	}

	template <typename TYPE>
	TYPE Vector4D<TYPE>::w() const
	{
		return this->wComponent;
	}

	template <typename TYPE>
	TYPE& Vector4D<TYPE>::operator[](int operand)
	{
		assert(0 <= operand && operand <= 3);
		return (&xComponent)[operand];
	}

	template <typename TYPE>
	TYPE Vector4D<TYPE>::operator[](int operand) const
	{
		assert(0 <= operand && operand <= 3);
		return (&xComponent)[operand];
	}
	
	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::operator+(const TYPE operand) const
	{
		return Vector4D<TYPE>(x() + operand, y() + operand, z() + operand, w() + operand);
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::operator-(const TYPE operand) const
	{
		return Vector4D<TYPE>(x() - operand, y() - operand, z() - operand, w() - operand);
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::operator*(const TYPE operand) const
	{
		return Vector4D<TYPE>(x() * operand, y() * operand, z() * operand, w() * operand);
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::operator/(const TYPE operand) const
	{
		return Vector4D<TYPE>(x() / operand, y() / operand, z() / operand, w() / operand);
	}


	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::operator+=(const TYPE operand)
	{
		x() += operand;
		y() += operand;
		z() += operand;
		w() += operand;

		return *this;
	}

	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::operator-=(const TYPE operand)
	{
		x() -= operand;
		y() -= operand;
		z() -= operand;
		w() -= operand;

		return *this;
	}

	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::operator*=(const TYPE operand)
	{
		x() *= operand;
		y() *= operand;
		z() *= operand;
		w() *= operand;

		return *this;
	}

	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::operator/=(const TYPE operand)
	{
		x() /= operand;
		y() /= operand;
		z() /= operand;
		w() /= operand;

		return *this;
	}


	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::operator+(const Vector4D<TYPE>& operand) const
	{
		return Vector4D<TYPE>(x() + operand.x(), y() + operand.y(), z() + operand.z(), w() + operand.w());
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::operator-(const Vector4D<TYPE>& operand) const
	{
		return Vector4D<TYPE>(x() - operand.x(), y() - operand.y(), z() - operand.z() w() - operand.w());
	}


	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::operator+=(const Vector4D<TYPE>& operand)
	{
		x() += operand.x();
		y() += operand.y();
		z() += operand.z();
		w() += operand.w();

		return *this;
	}

	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::operator-=(const Vector4D<TYPE>& operand)
	{
		x() -= operand.x();
		y() -= operand.y();
		z() -= operand.z();
		w() -= operand.w();

		return *this;
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::operator-() const
	{
		return negated();
	}

	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::scale(const Vector4D<TYPE>& scalar)
	{
		x() *= scalar.x();
		y() *= scalar.y();
		z() *= scalar.z();
		w() *= scalar.w();

		return *this;
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::scaled(const Vector4D<TYPE>& scalar) const
	{
		return Vector4D<TYPE>(x() * scalar.x(), y() * scalar.y(), z() * scalar.z(), w() * scalar.w());
	}

	template <typename TYPE>
	TYPE Vector4D<TYPE>::getMagnitudeSquared() const
	{
		return x() * x() + y() * y() + z() * z() + w() * w();
	}

	template <typename TYPE>
	TYPE Vector4D<TYPE>::getMagnitude() const
	{
		return Math::sqrt(getMagnitudeSquared());
	}
	
	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::normalize()
	{
		TYPE magnitude = getMagnitude();
		
		return (*this) /= magnitude;
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::normalized() const
	{
		TYPE magnitude = getMagnitude();
		
		return Vector4D<TYPE>(x() / magnitude, y() / magnitude, z() / magnitude, w() / magnitude);
	}

	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::negate()
	{
		x() = -x();
		y() = -y();
		z() = -z();
		w() = -w();

		return *this;
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::negated() const
	{
		return Vector4D<TYPE>(-x(), -y(), -z(), -w());
	}

	template <typename TYPE>
	Vector4D<TYPE>& Vector4D<TYPE>::homogeneousDivide()
	{
		return *this /= w();
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::homogeneousDivided() const
	{
		return *this / w();
	}

	template <typename TYPE>
	TYPE Vector4D<TYPE>::dotProduct(const Vector4D<TYPE>& operand) const
	{
		return (x() * operand.x()) + (y() * operand.y()) + (z() * operand.z()) + (w() * operand.w());
	}

	template <typename TYPE>
	Vector4D<TYPE> Vector4D<TYPE>::crossProduct(const Vector4D<TYPE>& u, const Vector4D<TYPE>& v, const Vector4D<TYPE>& w) const
	{
		TYPE a = (v.x() * w.y()) - (v.y() * w.x());
		TYPE b = (v.x() * w.z()) - (v.z() * w.x());
		TYPE c = (v.x() * w.w()) - (v.w() * w.x());
		TYPE d = (v.y() * w.y()) - (v.z() * w.y());
		TYPE e = (v.y() * w.w()) - (v.w() * w.y());
		TYPE f = (v.z() * w.w()) - (v.w() * w.z());

		TYPE xResult = (u.y() * f) - (u.z() * e) + (u.w() * d);
		TYPE yResult = -(u.x() * f) + (u.z() * c) - (u.w() * b);
		TYPE zResult = (u.x() * e) - (u.y() * c) + (u.w() * a);
		TYPE wResult = -(u.x() * d) + (u.y() * b) - (u.z() * a);

		return Vector4D<TYPE>(xResult, yResult, zResult, wResult);
	}
	
	template <typename TYPE>
	TYPE Vector4D<TYPE>::getDistanceSquared(const Vector4D<TYPE>& point) const
	{
		return (point - *this).getMagnitudeSquared();
	}

	template <typename TYPE>
	TYPE Vector4D<TYPE>::getDistance(const Vector4D<TYPE>& point) const
	{
		return (point - *this).getMagnitude();
	}




	template <typename TYPE>
	Vector4D<TYPE> operator+(const TYPE operand1, const Vector4D<TYPE>& operand2)
	{
		return Vector4D<TYPE>(operand1 + operand2.x(), operand1 + operand2.y(), operand1 + operand2.z(), operand1 + operand2.w());
	}

	template <typename TYPE>
	Vector4D<TYPE> operator-(const TYPE operand1, const Vector4D<TYPE>& operand2)
	{
		return Vector4D<TYPE>(operand1 - operand2.x(), operand1 - operand2.y(), operand1 - operand2.z(), operand1 - operand2.w());
	}

	template <typename TYPE>
	Vector4D<TYPE> operator*(const TYPE operand1, const Vector4D<TYPE>& operand2)
	{
		return Vector4D<TYPE>(operand1 * operand2.x(), operand1 * operand2.y(), operand1 * operand2.z(), operand1 * operand2.w());
	}

	template <typename TYPE>
	Vector4D<TYPE> operator/(const TYPE operand1, const Vector4D<TYPE>& operand2)
	{
		return Vector4D<TYPE>(operand1 / operand2.x(), operand1 / operand2.y(), operand1 / operand2.z(), operand1 / operand2.w());
	}



}

