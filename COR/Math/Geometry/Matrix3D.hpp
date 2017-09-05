
namespace CommonObjectRepository
{
	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::identity()
	{
		return Matrix3D<TYPE>(1, 0, 0,
							  0, 1, 0,
							  0, 0, 1);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::translate(TYPE x, TYPE y)
	{
		return Matrix3D<TYPE>(1, 0, x,
							  0, 1, y,
							  0, 0, 1);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::translate(const Vector2D<TYPE>& translation)
	{
		return translate(translation.x(), translation.y());
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::scale(TYPE x, TYPE y)
	{
		return Matrix3D<TYPE>(x, 0, 0,
							  0, y, 0,
							  0, 0, 1);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::scale(const Vector2D<TYPE>& scale)
	{
		return scale(scale.x(), scale.y());
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::scale(TYPE x, TYPE y, TYPE z)
	{
		return Matrix3D<TYPE>(x, 0, 0,
							  0, y, 0,
							  0, 0, z);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::scale(const Vector3D<TYPE>& scale)
	{
		return scale(scale.x(), scale.y(), scale.z());
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::rotate(TYPE angle)
	{
		return rotationZ(angle);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::rotateX(TYPE angle)
	{
		TYPE cosAngle = Math::cos(angle);
		TYPE sinAngle = Math::sin(angle);

		return Matrix3D<TYPE>(1, 0, 0,
							  0, cosAngle, sinAngle,
							  0, -sinAngle, cosAngle);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::rotateY(TYPE angle)
	{
		TYPE cosAngle = Math::cos(angle);
		TYPE sinAngle = Math::sin(angle);

		return Matrix3D<TYPE>(cosAngle, 0, -sinAngle,
							  0, 1, 0,
							  sinAngle, 0, cosAngle);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::rotateZ(TYPE angle)
	{
		TYPE cosAngle = Math::cos(angle);
		TYPE sinAngle = Math::sin(angle);

		return Matrix3D<TYPE>(cosAngle, sinAngle, 0,
							  -sinAngle, cosAngle, 0,
							  0, 0, 1);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::rotate(const Vector3D<TYPE>& axis, TYPE angle)
	{
		return rotateNormalized(axis.normalized(), angle);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::rotateNormalized(const Vector3D<TYPE>& axis, TYPE angle)
	{
		TYPE cosAngle = Math::cos(-angle);
		TYPE sinAngle = Math::sin(-angle);

		TYPE xy = axis.x() * axis.y();
		TYPE xz = axis.x() * axis.z();
		TYPE yz = axis.y() * axis.z();

		return Matrix3D<TYPE>(cosAngle + axis.x() * axis.x() * (1.0 - cosAngle),
							  xy * (1.0 - cosAngle) - axis.z() * sinAngle,
							  xz * (1.0 - cosAngle) + axis.y() * sinAngle,

							  xy * (1.0 - cosAngle) + axis.z() * sinAngle,
							  cosAngle + axis.y() * axis.y() * (1.0 - cosAngle),
							  yz * (1.0 - cosAngle) + axis.x() * sinAngle,

							  xz * (1.0 - cosAngle) + axis.y() * sinAngle,
							  yz * (1.0 - cosAngle) + axis.x() * sinAngle,
							  cosAngle + axis.z() * axis.z() * (1.0 - cosAngle));
	}




	template <typename TYPE>
	Matrix3D<TYPE>::Matrix3D() : matrix({1, 0, 0,
										 0, 1, 0,
										 0, 0, 1})
	{

	}

	template <typename TYPE>
	Matrix3D<TYPE>::Matrix3D(TYPE x0y0, TYPE x1y0, TYPE x2y0,
							 TYPE x0y1, TYPE x1y1, TYPE x2y1,
							 TYPE x0y2, TYPE x1y2, TYPE x2y2)
	{
		matrix[0] = x0y0;
		matrix[1] = x1y0;
		matrix[2] = x2y0;

		matrix[3] = x0y1;
		matrix[4] = x1y1;
		matrix[5] = x2y1;

		matrix[6] = x0y2;
		matrix[7] = x1y2;
		matrix[8] = x2y2;
	}


	template <typename TYPE>
	TYPE& Matrix3D<TYPE>::get(int x, int y)
	{
		assert(0 <= x && x <= 2);
		assert(0 <= y && y <= 2);

		return &matrix[y * 3 + x];
	}

	template <typename TYPE>
	TYPE Matrix3D<TYPE>::get(int x, int y) const
	{
		assert(0 <= x && x <= 2);
		assert(0 <= y && y <= 2);

		return matrix[y * 3 + x];
	}

	template <typename TYPE>
	Vector3D<TYPE>& Matrix3D<TYPE>::operator[](int y)
	{
		assert(0 <= y && y <= 2);
		return *reinterpret_cast<Vector3D<TYPE>*>(matrix + (y * 3));
	}

	template <typename TYPE>
	bool Matrix3D<TYPE>::isIdentity()
	{
		return matrix[0] == 1.0 && matrix[1] == 0.0 && matrix[2] == 0.0 &&
			   matrix[3] == 1.0 && matrix[4] == 0.0 && matrix[5] == 0.0 &&
			   matrix[6] == 1.0 && matrix[7] == 0.0 && matrix[8] == 0.0;
	}
	
	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::operator+(TYPE operand) const
	{
		return Matrix3D<TYPE>(matrix[0] + operand, matrix[1] + operand, matrix[2] + operand,
							  matrix[3] + operand, matrix[4] + operand, matrix[5] + operand,
							  matrix[6] + operand, matrix[7] + operand, matrix[8] + operand);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::operator-(TYPE operand) const
	{
		return Matrix3D<TYPE>(matrix[0] - operand, matrix[1] - operand, matrix[2] - operand,
							  matrix[3] - operand, matrix[4] - operand, matrix[5] - operand,
							  matrix[6] - operand, matrix[7] - operand, matrix[8] - operand);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::operator*(TYPE operand) const
	{
		return Matrix3D<TYPE>(matrix[0] * operand, matrix[1] * operand, matrix[2] * operand,
							  matrix[3] * operand, matrix[4] * operand, matrix[5] * operand,
							  matrix[6] * operand, matrix[7] * operand, matrix[8] * operand);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::operator/(TYPE operand) const
	{
		return Matrix3D<TYPE>(matrix[0] / operand, matrix[1] / operand, matrix[2] / operand,
							  matrix[3] / operand, matrix[4] / operand, matrix[5] / operand,
							  matrix[6] / operand, matrix[7] / operand, matrix[8] / operand);
	}
	
	template <typename TYPE>
	Matrix3D<TYPE>& Matrix3D<TYPE>::operator+=(TYPE operand)
	{
		matrix[0] += operand;
		matrix[1] += operand;
		matrix[2] += operand;
		matrix[3] += operand;
		matrix[4] += operand;
		matrix[5] += operand;
		matrix[6] += operand;
		matrix[7] += operand;
		matrix[8] += operand;

		return *this;
	}

	template <typename TYPE>
	Matrix3D<TYPE>& Matrix3D<TYPE>::operator-=(TYPE operand)
	{
		matrix[0] -= operand;
		matrix[1] -= operand;
		matrix[2] -= operand;
		matrix[3] -= operand;
		matrix[4] -= operand;
		matrix[5] -= operand;
		matrix[6] -= operand;
		matrix[7] -= operand;
		matrix[8] -= operand;

		return *this;
	}

	template <typename TYPE>
	Matrix3D<TYPE>& Matrix3D<TYPE>::operator*=(TYPE operand)
	{
		matrix[0] *= operand;
		matrix[1] *= operand;
		matrix[2] *= operand;
		matrix[3] *= operand;
		matrix[4] *= operand;
		matrix[5] *= operand;
		matrix[6] *= operand;
		matrix[7] *= operand;
		matrix[8] *= operand;

		return *this;
	}

	template <typename TYPE>
	Matrix3D<TYPE>& Matrix3D<TYPE>::operator/=(TYPE operand)
	{
		matrix[0] /= operand;
		matrix[1] /= operand;
		matrix[2] /= operand;
		matrix[3] /= operand;
		matrix[4] /= operand;
		matrix[5] /= operand;
		matrix[6] /= operand;
		matrix[7] /= operand;
		matrix[8] /= operand;

		return *this;
	}


	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::operator+(const Matrix3D<TYPE>& operand) const
	{
		return Matrix3D<TYPE>(matrix[0] + operand.matrix[0], matrix[1] + operand.matrix[1], matrix[2] + operand.matrix[2],
							  matrix[3] + operand.matrix[3], matrix[4] + operand.matrix[4], matrix[5] + operand.matrix[5],
							  matrix[6] + operand.matrix[6], matrix[7] + operand.matrix[7], matrix[8] + operand.matrix[8]);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::operator-(const Matrix3D<TYPE>& operand) const
	{
		return Matrix3D<TYPE>(matrix[0] - operand.matrix[0], matrix[1] - operand.matrix[1], matrix[2] - operand.matrix[2],
							  matrix[3] - operand.matrix[3], matrix[4] - operand.matrix[4], matrix[5] - operand.matrix[5],
							  matrix[6] - operand.matrix[6], matrix[7] - operand.matrix[7], matrix[8] - operand.matrix[8]);
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::operator*(const Matrix3D<TYPE>& operand) const
	{
		return Matrix3D<TYPE>(matrix[0] * operand.matrix[0] + matrix[1] * operand.matrix[3] + matrix[2] * operand.matrix[6],
							  matrix[0] * operand.matrix[1] + matrix[1] * operand.matrix[4] + matrix[2] * operand.matrix[7],
							  matrix[0] * operand.matrix[2] + matrix[1] * operand.matrix[5] + matrix[2] * operand.matrix[8],
							  matrix[3] * operand.matrix[0] + matrix[4] * operand.matrix[3] + matrix[5] * operand.matrix[6],
							  matrix[3] * operand.matrix[1] + matrix[4] * operand.matrix[4] + matrix[5] * operand.matrix[7],
							  matrix[3] * operand.matrix[2] + matrix[4] * operand.matrix[5] + matrix[5] * operand.matrix[8],
							  matrix[6] * operand.matrix[0] + matrix[7] * operand.matrix[3] + matrix[8] * operand.matrix[6],
							  matrix[6] * operand.matrix[1] + matrix[7] * operand.matrix[4] + matrix[8] * operand.matrix[7],
							  matrix[6] * operand.matrix[2] + matrix[7] * operand.matrix[5] + matrix[8] * operand.matrix[8]);
	}

	template <typename TYPE>
	Vector3D<TYPE> Matrix3D<TYPE>::operator*(const Vector3D<TYPE>& operand) const
	{
		return Vector3D<TYPE>(matrix[0] * operand[0] + matrix[1] * operand[1] + matrix[2] * operand[2],
							  matrix[3] * operand[0] + matrix[4] * operand[1] + matrix[5] * operand[2],
							  matrix[6] * operand[0] + matrix[7] * operand[1] + matrix[8] * operand[2]);
	}


	template <typename TYPE>
	Matrix3D<TYPE>& Matrix3D<TYPE>::operator+=(const Matrix3D<TYPE>& operand)
	{
		matrix[0] += operand.matrix[0];
		matrix[1] += operand.matrix[1];
		matrix[2] += operand.matrix[2];

		matrix[3] += operand.matrix[3];
		matrix[4] += operand.matrix[4];
		matrix[5] += operand.matrix[5];

		matrix[6] += operand.matrix[6];
		matrix[7] += operand.matrix[7];
		matrix[8] += operand.matrix[8];

		return *this;
	}

	template <typename TYPE>
	Matrix3D<TYPE>& Matrix3D<TYPE>::operator-=(const Matrix3D<TYPE>& operand)
	{
		matrix[0] -= operand.matrix[0];
		matrix[1] -= operand.matrix[1];
		matrix[2] -= operand.matrix[2];

		matrix[3] -= operand.matrix[3];
		matrix[4] -= operand.matrix[4];
		matrix[5] -= operand.matrix[5];

		matrix[6] -= operand.matrix[6];
		matrix[7] -= operand.matrix[7];
		matrix[8] -= operand.matrix[8];

		return *this;
	}

	template <typename TYPE>
	Matrix3D<TYPE>& Matrix3D<TYPE>::operator*=(const Matrix3D<TYPE>& operand)
	{
		TYPE x0y0 = matrix[0] * operand.matrix[0] + matrix[1] * operand.matrix[3] + matrix[2] * operand.matrix[6];
		TYPE x1y0 = matrix[0] * operand.matrix[1] + matrix[1] * operand.matrix[4] + matrix[2] * operand.matrix[7];
		TYPE x2y0 = matrix[0] * operand.matrix[2] + matrix[1] * operand.matrix[5] + matrix[2] * operand.matrix[8];

		TYPE x0y1 = matrix[3] * operand.matrix[0] + matrix[4] * operand.matrix[3] + matrix[5] * operand.matrix[6];
		TYPE x1y1 = matrix[3] * operand.matrix[1] + matrix[4] * operand.matrix[4] + matrix[5] * operand.matrix[7];
		TYPE x2y1 = matrix[3] * operand.matrix[2] + matrix[4] * operand.matrix[5] + matrix[5] * operand.matrix[8];

		TYPE x0y2 = matrix[6] * operand.matrix[0] + matrix[7] * operand.matrix[3] + matrix[8] * operand.matrix[6];
		TYPE x1y2 = matrix[6] * operand.matrix[1] + matrix[7] * operand.matrix[4] + matrix[8] * operand.matrix[7];
		TYPE x2y2 = matrix[6] * operand.matrix[2] + matrix[7] * operand.matrix[5] + matrix[8] * operand.matrix[8];

		matrix[0] = x0y0;
		matrix[1] = x1y0;
		matrix[2] = x2y0;

		matrix[3] = x0y1;
		matrix[4] = x1y1;
		matrix[5] = x2y1;

		matrix[6] = x0y2;
		matrix[7] = x1y2;
		matrix[8] = x2y2;


		return *this;
	}

	template <typename TYPE>
	TYPE Matrix3D<TYPE>::getDeterminant() const
	{
		return matrix[0] * (matrix[4] * matrix[8] - matrix[5] * matrix[7]) -
			   matrix[1] * (matrix[3] * matrix[8] - matrix[5] * matrix[6]) +
			   matrix[2] * (matrix[3] * matrix[7] - matrix[4] * matrix[6]);
	}

	template <typename TYPE>
	Matrix3D<TYPE>& Matrix3D<TYPE>::transpose()
	{
		Common::swap(matrix[1], matrix[3]);
		Common::swap(matrix[2], matrix[6]);
		Common::swap(matrix[5], matrix[7]);
		
		return *this;
	}

	template <typename TYPE>
	Matrix3D<TYPE> Matrix3D<TYPE>::transposed()
	{
		return Matrix3D<TYPE>(matrix[0], matrix[3], matrix[6],
							  matrix[1], matrix[4], matrix[7],
							  matrix[2], matrix[5], matrix[8]);
	}

	template <typename TYPE>
	Matrix3D<TYPE>&  Matrix3D<TYPE>::invert()
	{
		*this = inverted();
	}

	template <typename TYPE>
	Matrix3D<TYPE>  Matrix3D<TYPE>::inverted() const
	{
		Matrix3D<TYPE> toReturn = Matrix3D<TYPE>(matrix[4] * matrix[8] - matrix[5] * matrix[7], matrix[2] * matrix[7] - matrix[1] * matrix[8], matrix[1] * matrix[5] - matrix[2] * matrix[4],
												 matrix[5] * matrix[6] - matrix[3] * matrix[8], matrix[0] * matrix[8] - matrix[2] * matrix[6], matrix[2] * matrix[3] - matrix[0] * matrix[5],
												 matrix[3] * matrix[7] - matrix[4] * matrix[6], matrix[1] * matrix[6] - matrix[0] * matrix[7], matrix[0] * matrix[4] - matrix[1] * matrix[3]);

		TYPE determinant = matrix[0] * toReturn.matrix[0] + matrix[1] * toReturn.matrix[3] + matrix[3] * toReturn.matrix[6];

		if (Numbers::almostEqualsZero(determinant))
			return identity();

		toReturn /= determinant;

		return toReturn;
	}


	template <typename TYPE>
	Matrix3D<TYPE>&  Matrix3D<TYPE>::affineInvert()
	{
		return *this = inverted();
	}

	template <typename TYPE>
	Matrix3D<TYPE>  Matrix3D<TYPE>::affineInverted() const
	{
		Matrix3D<TYPE> toReturn = Matrix3D<TYPE>(matrix[0], matrix[3], 0,
												 matrix[1], matrix[4], 0,
												 matrix[2], matrix[5], 1);

		toReturn[2] = toReturn * Vector3D<TYPE>(-matrix[6], -matrix[7], matrix[8]);

		return toReturn;
	}

}

