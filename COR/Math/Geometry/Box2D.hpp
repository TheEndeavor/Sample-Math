#pragma once



namespace CommonObjectRepository
{
	template <typename TYPE>
	Area2D<TYPE>::Area2D() : area()
	{

	}

	template <typename TYPE>
	Area2D<TYPE>::Area2D(TYPE width, TYPE height) : area(width, height)
	{

	}

	template <typename TYPE>
	Area2D<TYPE>::Area2D(const Vector2D<TYPE>& toCopy) :
		area(toCopy)
	{

	}

	template <typename TYPE>
	template <typename T>
	Area2D<TYPE>::Area2D(const Area2D<T>& toCopy) : area(toCopy.area)
	{

	}


	template <typename TYPE>
	bool Area2D<TYPE>::operator==(const Area2D<TYPE>& toCompare) const
	{
		return area == toCompare.area;
	}

	template <typename TYPE>
	bool Area2D<TYPE>::operator!=(const Area2D<TYPE>& toCompare) const
	{
		return !operator==(toCompare);
	}
	
	template <typename TYPE>
	Area2D<TYPE> Area2D<TYPE>::operator*(TYPE operand) const
	{
		return Area2D<TYPE>(area * operand);
	}

	template <typename TYPE>
	Area2D<TYPE> Area2D<TYPE>::operator/(TYPE operand) const
	{
		return Area2D<TYPE>(area / operand);
	}
	
	template <typename TYPE>
	Area2D<TYPE>& Area2D<TYPE>::operator*=(TYPE operand)
	{
		area *= operand;

		return *this;
	}

	template <typename TYPE>
	Area2D<TYPE>& Area2D<TYPE>::operator/=(TYPE operand)
	{
		area /= operand;

		return *this;
	}
	
	template <typename TYPE>
	TYPE& Area2D<TYPE>::width()
	{
		return area.x();
	}

	template <typename TYPE>
	TYPE Area2D<TYPE>::width() const
	{
		return area.x();
	}

	template <typename TYPE>
	TYPE& Area2D<TYPE>::height()
	{
		return area.y();
	}

	template <typename TYPE>
	TYPE Area2D<TYPE>::height() const
	{
		return area.y();
	}
	
	template <typename TYPE>
	TYPE Area2D<TYPE>::getArea() const
	{
		return area.getMagnitudeSquared();
	}

	template <typename TYPE>
	Area2D<TYPE>& Area2D<TYPE>::flip()
	{
		Common::swap(width(), height());

		return *this;
	}

	template <typename TYPE>
	Area2D<TYPE> Area2D<TYPE>::flipped() const
	{
		return Area2D<TYPE>(height(), width());
	}

	template <typename TYPE>
	bool Area2D<TYPE>::fits(const Area2D<TYPE>& toCheck) const
	{
		return toCheck.width() <= width() &&
			   toCheck.height() <= height();
	}

	template <typename TYPE>
	bool Area2D<TYPE>::contains(const Vector2D<TYPE>& toCheck) const
	{
		return toCheck.x() >= 0 && toCheck.x() <= width() &&
			   toCheck.y() >= 0 && toCheck.y() <= height();
	}





	template <typename TYPE>
	BoxAligned2D<TYPE>::BoxAligned2D() :
		positionValue(0, 0),
		areaValue(0, 0)
	{

	}

	template <typename TYPE>
	BoxAligned2D<TYPE>::BoxAligned2D(TYPE left, TYPE bottom, TYPE width, TYPE height) :
		BoxAligned2D(Vector2D<TYPE>(left, bottom), Area2D<TYPE>(width, height))
	{

	}

	template <typename TYPE>
	BoxAligned2D<TYPE>::BoxAligned2D(TYPE left, TYPE bottom, const Area2D<TYPE>& area) :
		BoxAligned2D(Vector2D<TYPE>(left, bottom), area)
	{

	}

	template <typename TYPE>
	BoxAligned2D<TYPE>::BoxAligned2D(const Vector2D<TYPE>& leftBottom, TYPE width, TYPE height) :
		BoxAligned2D(leftBottom, Area2D<TYPE>(width, height))
	{

	}

	template <typename TYPE>
	BoxAligned2D<TYPE>::BoxAligned2D(const Vector2D<TYPE>& leftBottom, const Area2D<TYPE>& area) :
		positionValue(leftBottom),
		areaValue(area)
	{

	}

	template <typename TYPE>
	template <typename T>
	BoxAligned2D<TYPE>::BoxAligned2D(const BoxAligned2D<T>& toCopy) :
		positionValue((Vector2D<TYPE>)toCopy.positionValue),
		areaValue((Area2D<TYPE>)toCopy.areaValue)
	{

	}


	template <typename TYPE>
	TYPE BoxAligned2D<TYPE>::left() const
	{
		return positionValue.x();
	}

	template <typename TYPE>
	TYPE& BoxAligned2D<TYPE>::left()
	{
		return positionValue.x();
	}

	template <typename TYPE>
	TYPE BoxAligned2D<TYPE>::right() const
	{
		return left() + area().width();
	}

	template <typename TYPE>
	TYPE BoxAligned2D<TYPE>::bottom() const
	{
		return positionValue.y();
	}

	template <typename TYPE>
	TYPE& BoxAligned2D<TYPE>::bottom()
	{
		return positionValue.y();
	}

	template <typename TYPE>
	TYPE BoxAligned2D<TYPE>::top() const
	{
		return bottom() + area().height();
	}

	template <typename TYPE>
	Vector2D<TYPE>& BoxAligned2D<TYPE>::position()
	{
		return positionValue;
	}

	template <typename TYPE>
	Vector2D<TYPE> BoxAligned2D<TYPE>::position() const
	{
		return positionValue;
	}

	template <typename TYPE>
	Vector2D<TYPE> BoxAligned2D<TYPE>::leftBottom() const
	{
		return position();
	}

	template <typename TYPE>
	Vector2D<TYPE> BoxAligned2D<TYPE>::leftTop() const
	{
		return Vector2D<TYPE>(left(), top());
	}

	template <typename TYPE>
	Vector2D<TYPE> BoxAligned2D<TYPE>::rightBottom() const
	{
		return Vector2D<TYPE>(right(), bottom());
	}

	template <typename TYPE>
	Vector2D<TYPE> BoxAligned2D<TYPE>::rightTop() const
	{
		return Vector2D<TYPE>(right(), top());
	}

	template <typename TYPE>
	TYPE& BoxAligned2D<TYPE>::width()
	{
		return area().width();
	}

	template <typename TYPE>
	TYPE BoxAligned2D<TYPE>::width() const
	{
		return area().width();
	}

	template <typename TYPE>
	TYPE& BoxAligned2D<TYPE>::height()
	{
		return area().height();
	}

	template <typename TYPE>
	TYPE BoxAligned2D<TYPE>::height() const
	{
		return area().height();
	}

	template <typename TYPE>
	Area2D<TYPE>& BoxAligned2D<TYPE>::area()
	{
		return areaValue;
	}

	template <typename TYPE>
	Area2D<TYPE> BoxAligned2D<TYPE>::area() const
	{
		return areaValue;
	}

	template <typename TYPE>
	TYPE BoxAligned2D<TYPE>::getArea() const
	{
		return area().getArea();
	}

	template <typename TYPE>
	bool BoxAligned2D<TYPE>::contains(const Vector2D<TYPE>& point) const
	{
		return point.x() >= left() && point.x() <= right() && point.y() >= bottom() && point.y() <= top();
	}

	template <typename TYPE>
	bool BoxAligned2D<TYPE>::fits(const Area2D<TYPE>& toCheck) const
	{
		return width() >= toCheck.width() &&
			   height() >= toCheck.height();
	}
	
	template <typename TYPE>
	Vector2D<float32> BoxAligned2D<TYPE>::normalize(const Vector2D<TYPE>& point) const
	{
		Vector2D<float32> toReturn = Vector2D<float32>(point.x() / (float32)width(), point.y() / (float32)height());

		toReturn.x() -= left() / (float32)width();
		toReturn.y() -= bottom() / (float32)height();

		return toReturn;
	}





	template <typename TYPE>
	Box2D<TYPE>::Box2D(Vector2D<TYPE> center, Area2D<TYPE> area, TYPE angle = 0) :
		centerValue(center),
		areaValue(area),
		angleValue(angle)
	{

	}

	template <typename TYPE>
	Box2D<TYPE>::Box2D(const Box2D<TYPE>& toCopy) :
		centerValue(toCopy.centerValue),
		areaValue(toCopy.areaValue),
		angleValue(toCopy.angleValue)
	{

	}

	template <typename TYPE>
	template <typename T>
	Box2D<TYPE>::Box2D(const Box2D<T>& toCopy) :
		centerValue((TYPE)toCopy.centerValue),
		areaValue((Area2D<TYPE>)toCopy.areaValue),
		angleValue((TYPE)toCopy.angleValue)
	{

	}

	
	template <typename TYPE>
	Box2D<TYPE>& Box2D<TYPE>::operator=(const Box2D<TYPE>& toAssign)
	{
		centerValue = toAssign.centerValue;
		areaValue = toAssign.areaValue;
		angleValue = toAssign.angleValue;

		return *this;
	}
	
	template <typename TYPE>
	Vector2D<TYPE> Box2D<TYPE>::center() const
	{
		return centerValue;
	}

	template <typename TYPE>
	Vector2D<TYPE>& Box2D<TYPE>::center()
	{
		return centerValue;
	}

	template <typename TYPE>
	TYPE Box2D<TYPE>::width() const
	{
		return areaValue.width();
	}

	template <typename TYPE>
	Clamped<TYPE&> Box2D<TYPE>::width()
	{
		return Clamped<TYPE&>(areaValue.width(), 0, Numbers::max<TYPE>());
	}

	template <typename TYPE>
	TYPE Box2D<TYPE>::height() const
	{
		return areaValue.height();
	}

	template <typename TYPE>
	Clamped<TYPE&> Box2D<TYPE>::height()
	{
		return Clamped<TYPE&>(areaValue.height(), 0, Numbers::max<TYPE>());
	}

	template <typename TYPE>
	TYPE Box2D<TYPE>::angle() const
	{
		return angleValue;
	}

	template <typename TYPE>
	TYPE& Box2D<TYPE>::angle()
	{
		return angleValue;
	}

	template <typename TYPE>
	Vector2D<TYPE> Box2D<TYPE>::getCornerLeftTop() const
	{
		return Vector2D<>(center.x() - (width() / 2), center.y() + height() / 2).rotate(angle(), center());
	}

	template <typename TYPE>
	Vector2D<TYPE> Box2D<TYPE>::getCornerRightTop() const
	{
		return Vector2D<>(center.x() + (width() / 2), center.y() + height() / 2).rotate(angle(), center());
	}

	template <typename TYPE>
	Vector2D<TYPE> Box2D<TYPE>::getCornerLeftBottom() const
	{
		return Vector2D<>(center.x() - (width() / 2), center.y() - height() / 2).rotate(angle(), center());
	}

	template <typename TYPE>
	Vector2D<TYPE> Box2D<TYPE>::getCornerRightBottom() const
	{
		return Vector2D<>(center.x() + (width() / 2), center.y() - height() / 2).rotate(angle(), center());
	}

	template <typename TYPE>
	LineSegment2D<TYPE> Box2D<TYPE>::getEdgeLeft() const
	{
		return LineSegment2D<>(cornerLeftBottom(), cornerLeftTop());
	}

	template <typename TYPE>
	LineSegment2D<TYPE> Box2D<TYPE>::getEdgeRight() const
	{
		return LineSegment2D<>(cornerRightTop(), cornerRightBottom());
	}

	template <typename TYPE>
	LineSegment2D<TYPE> Box2D<TYPE>::getEdgeTop() const
	{
		return LineSegment2D<>(cornerLeftTop(), cornerRightTop());
	}

	template <typename TYPE>
	LineSegment2D<TYPE> Box2D<TYPE>::getEdgeBottom() const
	{
		return LineSegment2D<>(cornerRightBottom(), cornerLeftBottom());
	}

	template <typename TYPE>
	BoxAligned2D<TYPE> Box2D<TYPE>::getBoundingBox() const
	{
		TYPE halfWidth = width() / 2 * Math::SquareRoot2;
		TYPE halfHeight = height() / 2 * Math::SquareRoot2;
		return BoxAligned2D<>(center.x() - halfWidth, center.x() + halfWidth, center.y() + halfHeight, center.y() - halfHeight);
	}

	template <typename TYPE>
	Vector2D<TYPE> Box2D<TYPE>::transform(const Vector2D<TYPE>& point) const
	{
		return (point - center()).rotate(angle());
	}

	template <typename TYPE>
	bool Box2D<TYPE>::contains(Vector2D<TYPE> point) const
	{
		//	Transform the candidate vector into This box's space and then a simple Bounding Box compare.
		Vector2D<float32> transformed = transform(point);

		TYPE halfWidth = width() / 2;
		TYPE halfHeight = height() / 2;
		return (transformed.x() >= -halfWidth) && (transformed.x() <= halfWidth) &&
			   (transformed.y() >= -halfHeight) && (transformed.y() <= halfHeight);
	}



}