#include "StdAfx.h"
#include "Box2D.h"

namespace CommonObjectRepository
{

	template <>
	bool Area2D<float32>::operator==(const Area2D<float32>& toCompare) const
	{
		return Numbers::almostEquals(width(), toCompare.width()) &&
			   Numbers::almostEquals(height(), toCompare.height());
	}

	template <>
	bool Area2D<float64>::operator==(const Area2D<float64>& toCompare) const
	{
		return Numbers::almostEquals(width(), toCompare.width()) &&
			   Numbers::almostEquals(height(), toCompare.height());
	}


}
