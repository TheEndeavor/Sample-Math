#pragma once

#include <assert.h>

#include "COR\Math\Math.h"
#include "COR\Math\Clamped.h"

#include "Vector2D.h"
#include "LineSegment2D.h"

namespace CommonObjectRepository
{
	template <typename TYPE>
	class Area2D
	{
		//	Befriend Thyself!
		template <typename T>
		friend class Area2D;

	protected:
		Vector2D<TYPE> area;
//		TYPE widthValue;
//		TYPE heightValue;

	public:
		Area2D();
		Area2D(TYPE width, TYPE height);
		Area2D(const Area2D<TYPE>& toCopy) = default;
		Area2D(Area2D<TYPE>&& toMove) = default;
		Area2D(const Vector2D<TYPE>& toCopy);
		template <typename T>
		explicit Area2D(const Area2D<T>& toCopy);
		~Area2D() = default;

		Area2D<TYPE>& operator=(const Area2D<TYPE>& toAssign) = default;
		Area2D<TYPE>& operator=(Area2D<TYPE>&& toMove) = default;

		bool operator==(const Area2D<TYPE>& toCompare) const;
		bool operator!=(const Area2D<TYPE>& toCompare) const;

		Area2D<TYPE> operator*(TYPE operand) const;
		Area2D<TYPE> operator/(TYPE operand) const;

		Area2D<TYPE>& operator*=(TYPE operand);
		Area2D<TYPE>& operator/=(TYPE operand);

		TYPE& width();
		TYPE width() const;

		TYPE& height();
		TYPE height() const;

		TYPE getArea() const;
		
		Area2D<TYPE>& flip();
		Area2D<TYPE> flipped() const;


		bool fits(const Area2D<TYPE>& toCheck) const;
		bool contains(const Vector2D<TYPE>& toCheck) const;
	};




	template <typename TYPE>
	class BoxAligned2D
	{
		//	Befriend Thyself!
		template <typename T>
		friend class BoxAligned2D;

	protected:
		Vector2D<TYPE> positionValue;

		Area2D<TYPE> areaValue;	
		
	public:
		BoxAligned2D();
		BoxAligned2D(TYPE left, TYPE width, TYPE bottom, TYPE height);
		BoxAligned2D(TYPE left, TYPE bottom, const Area2D<TYPE>& area);
		BoxAligned2D(const Vector2D<TYPE>& leftBottom, TYPE width, TYPE height);
		BoxAligned2D(const Vector2D<TYPE>& leftBottom, const Area2D<TYPE>& area);
		BoxAligned2D(const BoxAligned2D<TYPE>& toCopy) = default;
		BoxAligned2D(BoxAligned2D<TYPE>&& toMove) = default;
		template <typename T>
		explicit BoxAligned2D(const BoxAligned2D<T>& toCopy);
		~BoxAligned2D() = default;

		BoxAligned2D<TYPE>& operator=(const BoxAligned2D<TYPE>& toAssign) = default;
		BoxAligned2D<TYPE>& operator=(BoxAligned2D<TYPE>&& toAssign) = default;

		TYPE left() const;
		TYPE& left();

		TYPE right() const;
		
		TYPE bottom() const;
		TYPE& bottom();

		TYPE top() const;

		Vector2D<TYPE>& position();
		Vector2D<TYPE> position() const;

		Vector2D<TYPE> leftBottom() const;
		Vector2D<TYPE> rightBottom() const;
		Vector2D<TYPE> leftTop() const;
		Vector2D<TYPE> rightTop() const;

		TYPE& width();
		TYPE width() const;
		TYPE& height();
		TYPE height() const;

		Area2D<TYPE>& area();
		Area2D<TYPE> area() const;

		TYPE getArea() const;

		bool contains(const Vector2D<TYPE>& point) const;
		bool fits(const Area2D<TYPE>& toCheck) const;

		Vector2D<float32> normalize(const Vector2D<TYPE>& point) const;

	};



	template <typename TYPE>
	class Box2D
	{
		//	Befriend Thyself!
		template <typename T>
		friend class Box2D;

	protected:
		Vector2D<TYPE> centerValue;
		Area2D<TYPE> areaValue;

		TYPE angleValue;

	public:
		Box2D(Vector2D<TYPE> center = Vector2D<TYPE>(), Area2D<TYPE> area = Area2D<TYPE>(), TYPE angle = 0);
		Box2D(const Box2D<TYPE>& toCopy);
		template <typename T>
		explicit Box2D(const Box2D<T>& toCopy);
		~Box2D() = default;

		Box2D<TYPE>& operator=(const Box2D<TYPE>& toAssign);

		Vector2D<TYPE> center() const;
		Vector2D<TYPE>& center();

		TYPE width() const;
		Clamped<TYPE&> width();

		TYPE height() const;
		Clamped<TYPE&> height();

		TYPE angle() const;
		TYPE& angle();


		Vector2D<TYPE> getCornerLeftTop() const;
		Vector2D<TYPE> getCornerRightTop() const;
		Vector2D<TYPE> getCornerLeftBottom() const;
		Vector2D<TYPE> getCornerRightBottom() const;

		//	Edge line segments are aligned clockwise
		LineSegment2D<TYPE> getEdgeLeft() const;
		LineSegment2D<TYPE> getEdgeRight() const;
		LineSegment2D<TYPE> getEdgeTop() const;
		LineSegment2D<TYPE> getEdgeBottom() const;

		BoxAligned2D<TYPE> getBoundingBox() const;

		Vector2D<TYPE> transform(const Vector2D<TYPE>& point) const;

		bool contains(Vector2D<TYPE> point) const;

	};


}

#include "Box2D.hpp"
