
namespace CommonObjectRepository
{
	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::identity()
	{
		return Matrix2D<TYPE>(1, 0, 0, 1);
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::rotation(TYPE angle)
	{
		TYPE cosAngle = Math::cos(angle);
		TYPE sinAngle = Math::sin(angle);

		return Matrix2D<TYPE>(cosAngle, sinAngle,
							  -sinAngle, cosAngle);
	}





	template <typename TYPE>
	Matrix2D<TYPE>::Matrix2D() : matrix({1, 0,
										 0, 1})
	{

	}

	template <typename TYPE>
	Matrix2D<TYPE>::Matrix2D(TYPE x0y0, TYPE x1y0, TYPE x0y1, TYPE x1y1)
	{
		matrix[0] = x0y0;
		matrix[1] = x1y0;
		matrix[2] = x0y1;
		matrix[3] = x1y1;
	}


	template <typename TYPE>
	TYPE& Matrix2D<TYPE>::get(int x, int y)
	{
		assert(0 <= x && x <= 1);
		assert(0 <= y && y <= 1);

		return &matrix[y * 2 + x];
	}

	template <typename TYPE>
	TYPE Matrix2D<TYPE>::get(int x, int y) const
	{
		assert(0 <= x && x <= 1);
		assert(0 <= y && y <= 1);

		return matrix[y * 2 + x];
	}

	template <typename TYPE>
	Vector2D<TYPE>& Matrix2D<TYPE>::operator[](int y)
	{
		assert(0 <= y && y <= 1);
		return *reinterpret_cast<Vector2D<TYPE>*>(matrix + (y * 2));
	}

	template <typename TYPE>
	bool Matrix2D<TYPE>::isIdentity()
	{
		return matrix[0] == 1.0 && matrix[1] == 0.0 &&
			   matrix[2] == 0.0 && matrix[3] == 1.0;
	}
	
	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::operator+(TYPE operand) const
	{
		return Matrix2D<TYPE>(matrix[0] + operand, matrix[1] + operand,
							  matrix[2] + operand, matrix[3] + operand);
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::operator-(TYPE operand) const
	{
		return Matrix2D<TYPE>(matrix[0] - operand, matrix[1] - operand,
							  matrix[2] - operand, matrix[3] - operand);
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::operator*(TYPE operand) const
	{
		return Matrix2D<TYPE>(matrix[0] * operand, matrix[1] * operand,
							  matrix[2] * operand, matrix[3] * operand);
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::operator/(TYPE operand) const
	{
		return Matrix2D<TYPE>(matrix[0] / operand, matrix[1] / operand,
							  matrix[2] / operand, matrix[3] / operand);
	}

	
	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::operator+=(TYPE operand)
	{
		matrix[0] += operand;
		matrix[1] += operand;
		matrix[2] += operand;
		matrix[3] += operand;

		return *this;
	}

	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::operator-=(TYPE operand)
	{
		matrix[0] -= operand;
		matrix[1] -= operand;
		matrix[2] -= operand;
		matrix[3] -= operand;

		return *this;
	}

	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::operator*=(TYPE operand)
	{
		matrix[0] *= operand;
		matrix[1] *= operand;
		matrix[2] *= operand;
		matrix[3] *= operand;

		return *this;
	}

	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::operator/=(TYPE operand)
	{
		matrix[0] /= operand;
		matrix[1] /= operand;
		matrix[2] /= operand;
		matrix[3] /= operand;

		return *this;
	}


	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::operator+(const Matrix2D<TYPE>& operand) const
	{
		return Matrix2D<TYPE>(matrix[0] + operand.matrix[0],
								matrix[1] + operand.matrix[1],
								matrix[2] + operand.matrix[2],
								matrix[3] + operand.matrix[3]);
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::operator-(const Matrix2D<TYPE>& operand) const
	{
		return Matrix2D<TYPE>(matrix[0] - operand.matrix[0],
								matrix[1] - operand.matrix[1],
								matrix[2] - operand.matrix[2],
								matrix[3] - operand.matrix[3]);
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::operator*(const Matrix2D<TYPE>& operand) const
	{
		return Matrix2D<TYPE>(matrix[0] * operand.matrix[0] + matrix[1] * operand.matrix[2],
							  matrix[0] * operand.matrix[1] + matrix[1] * operand.matrix[3],
							  matrix[2] * operand.matrix[0] + matrix[3] * operand.matrix[2],
							  matrix[2] * operand.matrix[1] + matrix[3] * operand.matrix[3]);
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::operator/(const Matrix2D<TYPE>& operand) const
	{
		return *this * operand.inverted();
	}

	template <typename TYPE>
	Vector2D<TYPE> Matrix2D<TYPE>::operator*(const Vector2D<TYPE>& operand) const
	{
		return Vector2D<TYPE>(matrix[0] * operand[0] + matrix[1] * operand[1], matrix[2] * operand[0] + matrix[3] * operand[1]);
	}


	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::operator+=(const Matrix2D<TYPE>& operand)
	{
		matrix[0] += operand.matrix[0];
		matrix[1] += operand.matrix[1];
		matrix[2] += operand.matrix[2];
		matrix[3] += operand.matrix[3];

		return *this;
	}

	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::operator-=(const Matrix2D<TYPE>& operand)
	{
		matrix[0] -= operand.matrix[0];
		matrix[1] -= operand.matrix[1];
		matrix[2] -= operand.matrix[2];
		matrix[3] -= operand.matrix[3];

		return *this;
	}

	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::operator*=(const Matrix2D<TYPE>& operand)
	{
		matrix[0] = matrix[0] * operand.matrix[0] + matrix[1] * operand.matrix[2];
		matrix[1] = matrix[0] * operand.matrix[1] + matrix[1] * operand.matrix[3];
		matrix[2] = matrix[2] * operand.matrix[0] + matrix[3] * operand.matrix[2];
		matrix[3] = matrix[2] * operand.matrix[1] + matrix[3] * operand.matrix[3];

		return *this;
	}

	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::operator/=(const Matrix2D<TYPE>& operand)
	{
		*this *= operand.inverted();

		return *this;
	}

	template <typename TYPE>
	TYPE Matrix2D<TYPE>::getDeterminant() const
	{
		return matrix[0] * matrix[3] - matrix[1] * matrix[2];
	}

	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::transpose()
	{
		std::swap(matrix[1], matrix[2]);

		return *this;
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::transposed() const
	{
		return Matrix2D<TYPE>(matrix[0], matrix[2], matrix[1], matrix[3]);
	}
	
	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::invert()
	{
		*this = inverted();
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::inverted() const
	{
		TYPE determinant = getDeterminant();

		if (Numbers::almostEqualsZero(determinant))
			return identity();

		return Matrix2D<TYPE>(+matrix[3] / determinant, -matrix[1] / determinant,
							  -matrix[2] / determinant, +matrix[0] / determinant);
	}
	
	template <typename TYPE>
	Matrix2D<TYPE>& Matrix2D<TYPE>::affineInvert()
	{
		return invert();
	}

	template <typename TYPE>
	Matrix2D<TYPE> Matrix2D<TYPE>::affineInverted() const
	{
		return inverted();
	}
}

