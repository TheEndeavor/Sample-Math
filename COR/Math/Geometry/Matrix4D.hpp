
namespace CommonObjectRepository
{
	template <typename TYPE>
	const Matrix4D<TYPE>& Matrix4D<TYPE>::identity()
	{
		static const Matrix4D<TYPE> value = Matrix4D<TYPE>(1, 0, 0, 0,
														   0, 1, 0, 0,
														   0, 0, 1, 0,
														   0, 0, 0, 1);

		return value;
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::translate(TYPE x, TYPE y, TYPE z)
	{
		return Matrix4D<TYPE>(1, 0, 0, x,
							  0, 1, 0, y,
							  0, 0, 1, z,
							  0, 0, 0, 1);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::translate(const Vector2D<TYPE>& translation)
	{
		return translate(translation.x(), translation.y());
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::translate(const Vector3D<TYPE>& translation)
	{
		return translate(translation.x(), translation.y(), translation.z());
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::translate(const Vector4D<TYPE>& translation)
	{
		return translate(translation.x(), translation.y(), translation.z());
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::scale(TYPE scalar)
	{
		return scale(scalar, scalar, scalar, 1);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::scale(TYPE x, TYPE y, TYPE z)
	{
		return Matrix4D<TYPE>(x, 0, 0, 0,
							  0, y, 0, 0,
							  0, 0, z, 0,
							  0, 0, 0, 1);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::scale(const Vector2D<TYPE>& scalar)
	{
		return scale(scalar.x(), scalar.y());
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::scale(const Vector3D<TYPE>& scalar)
	{
		return scale(scalar.x(), scalar.y(), scalar.z());
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::scale(const Vector4D<TYPE>& scalar)
	{
		return scale(scalar.x(), scalar.y(), scalar.z());
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::rotateX(TYPE angle)
	{
		TYPE cosAngle = Math::cos(angle);
		TYPE sinAngle = Math::sin(angle);

		return Matrix4D<TYPE>(1, 0, 0, 0,
							  0, cosAngle, sinAngle, 0,
							  0, -sinAngle, cosAngle, 0,
							  0, 0, 0, 1);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::rotateY(TYPE angle)
	{
		TYPE cosAngle = Math::cos(angle);
		TYPE sinAngle = Math::sin(angle);

		return Matrix4D<TYPE>(cosAngle, 0, -sinAngle, 0,
							  0, 1, 0, 0,
							  sinAngle, 0, cosAngle, 0,
							  0, 0, 0, 1);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::rotateZ(TYPE angle)
	{
		TYPE cosAngle = Math::cos(angle);
		TYPE sinAngle = Math::sin(angle);

		return Matrix4D<TYPE>(cosAngle, sinAngle, 0, 0,
							  -sinAngle, cosAngle, 0, 0,
							  0, 0, 1, 0,
							  0, 0, 0, 1);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::rotate(const Vector3D<TYPE>& axis, TYPE angle)
	{
		return rotateNormalized(axis.normalized(), angle);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::rotateNormalized(const Vector3D<TYPE>& axis, TYPE angle)
	{
		TYPE cosAngle = Math::cos(-angle);
		TYPE sinAngle = Math::sin(-angle);

		TYPE xy = axis.x() * axis.y();
		TYPE xz = axis.x() * axis.z();
		TYPE yz = axis.y() * axis.z();

		return Matrix4D<TYPE>(cosAngle + axis.x() * axis.x() * (1 - cosAngle),
							  xy * (1 - cosAngle) - axis.z() * sinAngle,
							  xz * (1 - cosAngle) + axis.y() * sinAngle,
							  0,

							  xy * (1 - cosAngle) + axis.z() * sinAngle,
							  cosAngle + axis.y() * axis.y() * (1 - cosAngle),
							  yz * (1 - cosAngle) - axis.x() * sinAngle,
							  0,

							  xz * (1 - cosAngle) - axis.y() * sinAngle,
							  yz * (1 - cosAngle) + axis.x() * sinAngle,
							  cosAngle + axis.z() * axis.z() * (1 - cosAngle),
							  0,
							  
							  0, 0, 0, 1);
	}
/*
	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::rotate(const Line3D<TYPE>& line, TYPE angle)
	{
		return translate(-line.origin()) * rotateNormalized(line.direction(), angle) * translate(line.origin);
	}
*/
	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::orthographicProjection(TYPE left, TYPE right, TYPE bottom, TYPE top, TYPE near, TYPE far)
	{
		return Matrix4D<TYPE>(2 / (right - left), 0, 0, -((right + left) / (right - left)),
							  0, 2 / (top - bottom), 0, -((top + bottom) / (top - bottom)),
							  0, 0, 2 / (far - near), -((far + near) / (far - near)),
							  0, 0, 0, 1);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::orthographicProjection(TYPE width, TYPE height, TYPE near, TYPE far)
	{
		return Matrix4D<TYPE>(2 / width, 0, 0, 0,
							  0, 2 / height, 0, 0,
							  0, 0, 2 / (far - near), -(far + near) / (far - near),
							  0, 0, 0, 1);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::orthographicProjection(TYPE aspectRatio, TYPE near, TYPE far)
	{
		TYPE width = aspectRatio;
		TYPE height = 1;

		return orthographicProjection(width, height, near, far);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::obliqueProjection(TYPE left, TYPE right, TYPE bottom, TYPE top, TYPE near, TYPE far)
	{
		return Matrix4D<TYPE>(2 * near / (right - left), 0, -((right + left) / (right - left)), 0,
							  0, 2 * near / (top - bottom), -((top + bottom) / (top - bottom)), 0,
							  0, 0, far / (far - near), -((far * near) / (far - near)),
							  0, 0, 1, 0);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::obliqueProjection(TYPE width, TYPE height, TYPE near, TYPE far)
	{
		return Matrix4D<TYPE>(2 * near / width, 0, 0, 0,
							  0, 2 * near / height, 0, 0,
							  0, 0, (far + near) / (far - near), -((far * near) / (far - near)),
							  0, 0, 1, 0);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::perspectiveProjection(TYPE viewingAngle, TYPE aspectRatio, TYPE near, TYPE far)
	{
		TYPE d = 1 / Math::tan(viewingAngle / 2);

		return Matrix4D<TYPE>(d / aspectRatio, 0, 0, 0,
							  0, d, 0, 0,
							  0, 0, -(far + near) / (near - far), -((2 * far * near) / (far - near)),
							  0, 0, 1, 0);
	}




	template <typename TYPE>
	Matrix4D<TYPE>::Matrix4D()
	{
		*this = identity();
	}

	template <typename TYPE>
	Matrix4D<TYPE>::Matrix4D(TYPE x0y0, TYPE x1y0, TYPE x2y0, TYPE x3y0,
							 TYPE x0y1, TYPE x1y1, TYPE x2y1, TYPE x3y1,
							 TYPE x0y2, TYPE x1y2, TYPE x2y2, TYPE x3y2,
							 TYPE x0y3, TYPE x1y3, TYPE x2y3, TYPE x3y3)
	{
		matrix[0] = x0y0;
		matrix[1] = x1y0;
		matrix[2] = x2y0;
		matrix[3] = x3y0;

		matrix[4] = x0y1;
		matrix[5] = x1y1;
		matrix[6] = x2y1;
		matrix[7] = x3y1;

		matrix[8] = x0y2;
		matrix[9] = x1y2;
		matrix[10] = x2y2;
		matrix[11] = x3y2;

		matrix[12] = x0y3;
		matrix[13] = x1y3;
		matrix[14] = x2y3;
		matrix[15] = x3y3;

	}


	template <typename TYPE>
	TYPE& Matrix4D<TYPE>::get(int x, int y)
	{
		assert(0 <= x && x <= 3);
		assert(0 <= y && y <= 3);

		return &matrix[y * 4 + x];
	}

	template <typename TYPE>
	TYPE Matrix4D<TYPE>::get(int x, int y) const
	{
		assert(0 <= x && x <= 3);
		assert(0 <= y && y <= 3);

		return matrix[y * 4 + x];
	}

	template <typename TYPE>
	Vector4D<TYPE>& Matrix4D<TYPE>::operator[](int y)
	{
		assert(0 <= y && y <= 3);
		return *reinterpret_cast<Vector4D<TYPE>*>(matrix + (y * 4));
	}

	template <typename TYPE>
	bool Matrix4D<TYPE>::isIdentity()
	{
		return matrix[0] == 1.0 && matrix[1] == 0.0 && matrix[2] == 0.0 && matrix[3] == 0.0 &&
			   matrix[4] == 1.0 && matrix[5] == 0.0 && matrix[6] == 0.0 && matrix[7] == 0.0 &&
			   matrix[8] == 1.0 && matrix[9] == 0.0 && matrix[10] == 0.0 && matrix[11] == 0.0 &&
			   matrix[12] == 1.0 && matrix[13] == 0.0 && matrix[14] == 0.0 && matrix[15] == 0.0;
	}


	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::operator+(const Matrix4D<TYPE>& operand) const
	{
		return Matrix4D<TYPE>(matrix[0] + operand.matrix[0], matrix[1] + operand.matrix[1], matrix[2] + operand.matrix[2], matrix[3] + operand[3],
							  matrix[4] + operand.matrix[4], matrix[5] + operand.matrix[5], matrix[6] + operand.matrix[6], matrix[7] + operand[7],
							  matrix[8] + operand.matrix[8], matrix[9] + operand.matrix[9], matrix[10] + operand.matrix[10], matrix[11] + operand[11],
							  matrix[12] + operand.matrix[12], matrix[13] + operand.matrix[13], matrix[14] + operand.matrix[14], matrix[15] + operand[15]);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::operator-(const Matrix4D<TYPE>& operand) const
	{
		return Matrix4D<TYPE>(matrix[0] - operand.matrix[0], matrix[1] - operand.matrix[1], matrix[2] - operand.matrix[2], matrix[3] - operand[3],
							  matrix[4] - operand.matrix[4], matrix[5] - operand.matrix[5], matrix[6] - operand.matrix[6], matrix[7] - operand[7],
							  matrix[8] - operand.matrix[8], matrix[9] - operand.matrix[9], matrix[10] - operand.matrix[10], matrix[11] - operand[11],
							  matrix[12] - operand.matrix[12], matrix[13] - operand.matrix[13], matrix[14] - operand.matrix[14], matrix[15] - operand[15]);
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::operator*(const Matrix4D<TYPE>& operand) const
	{

		return Matrix4D<TYPE>(matrix[0] * operand.matrix[0] + matrix[1] * operand.matrix[4] + matrix[2] * operand.matrix[8] + matrix[3] * operand.matrix[12],
							  matrix[0] * operand.matrix[1] + matrix[1] * operand.matrix[5] + matrix[2] * operand.matrix[9] + matrix[3] * operand.matrix[13],
							  matrix[0] * operand.matrix[2] + matrix[1] * operand.matrix[6] + matrix[2] * operand.matrix[10] + matrix[3] * operand.matrix[14],
							  matrix[0] * operand.matrix[3] + matrix[1] * operand.matrix[7] + matrix[2] * operand.matrix[11] + matrix[3] * operand.matrix[15],

							  matrix[4] * operand.matrix[0] + matrix[5] * operand.matrix[4] + matrix[6] * operand.matrix[8] + matrix[7] * operand.matrix[12],
							  matrix[4] * operand.matrix[1] + matrix[5] * operand.matrix[5] + matrix[6] * operand.matrix[9] + matrix[7] * operand.matrix[13],
							  matrix[4] * operand.matrix[2] + matrix[5] * operand.matrix[6] + matrix[6] * operand.matrix[10] + matrix[7] * operand.matrix[14],
							  matrix[4] * operand.matrix[3] + matrix[5] * operand.matrix[7] + matrix[6] * operand.matrix[11] + matrix[7] * operand.matrix[15],

							  matrix[8] * operand.matrix[0] + matrix[9] * operand.matrix[4] + matrix[10] * operand.matrix[8] + matrix[11] * operand.matrix[12],
							  matrix[8] * operand.matrix[1] + matrix[9] * operand.matrix[5] + matrix[10] * operand.matrix[9] + matrix[11] * operand.matrix[13],
							  matrix[8] * operand.matrix[2] + matrix[9] * operand.matrix[6] + matrix[10] * operand.matrix[10] + matrix[11] * operand.matrix[14],
							  matrix[8] * operand.matrix[3] + matrix[9] * operand.matrix[7] + matrix[10] * operand.matrix[11] + matrix[11] * operand.matrix[15],

							  matrix[12] * operand.matrix[0] + matrix[13] * operand.matrix[4] + matrix[14] * operand.matrix[8] + matrix[15] * operand.matrix[12],
							  matrix[12] * operand.matrix[1] + matrix[13] * operand.matrix[5] + matrix[14] * operand.matrix[9] + matrix[15] * operand.matrix[13],
							  matrix[12] * operand.matrix[2] + matrix[13] * operand.matrix[6] + matrix[14] * operand.matrix[10] + matrix[15] * operand.matrix[14],
							  matrix[12] * operand.matrix[3] + matrix[13] * operand.matrix[7] + matrix[14] * operand.matrix[11] + matrix[15] * operand.matrix[15]);

/*

		//	SSE Implementation
		//	Seems to be about the same speed...
		Matrix4D<TYPE> toReturn;
		
		__m128 row1 = _mm_load_ps(&operand.matrix[0]);
		__m128 row2 = _mm_load_ps(&operand.matrix[4]);
		__m128 row3 = _mm_load_ps(&operand.matrix[8]);
		__m128 row4 = _mm_load_ps(&operand.matrix[12]);

		__m128 col1 = _mm_set1_ps(matrix[0]);
		__m128 col2 = _mm_set1_ps(matrix[1]);
		__m128 col3 = _mm_set1_ps(matrix[2]);
		__m128 col4 = _mm_set1_ps(matrix[3]);
		__m128 result = _mm_add_ps(
							_mm_add_ps(
								_mm_mul_ps(col1, row1),
								_mm_mul_ps(col2, row2)),
							_mm_add_ps(
								_mm_mul_ps(col3, row3),
								_mm_mul_ps(col4, row4)));
		_mm_store_ps(&toReturn.matrix[0], result);

		col1 = _mm_set1_ps(matrix[4]);
		col2 = _mm_set1_ps(matrix[5]);
		col3 = _mm_set1_ps(matrix[6]);
		col4 = _mm_set1_ps(matrix[7]);
		result = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(col1, row1),
						_mm_mul_ps(col2, row2)),
					_mm_add_ps(
						_mm_mul_ps(col3, row3),
						_mm_mul_ps(col4, row4)));
		_mm_store_ps(&toReturn.matrix[4], result);

		col1 = _mm_set1_ps(matrix[8]);
		col2 = _mm_set1_ps(matrix[9]);
		col3 = _mm_set1_ps(matrix[10]);
		col4 = _mm_set1_ps(matrix[11]);
		result = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(col1, row1),
						_mm_mul_ps(col2, row2)),
					_mm_add_ps(
						_mm_mul_ps(col3, row3),
						_mm_mul_ps(col4, row4)));
		_mm_store_ps(&toReturn.matrix[8], result);

		col1 = _mm_set1_ps(matrix[12]);
		col2 = _mm_set1_ps(matrix[13]);
		col3 = _mm_set1_ps(matrix[14]);
		col4 = _mm_set1_ps(matrix[15]);
		result = _mm_add_ps(
					_mm_add_ps(
						_mm_mul_ps(col1, row1),
						_mm_mul_ps(col2, row2)),
					_mm_add_ps(
						_mm_mul_ps(col3, row3),
						_mm_mul_ps(col4, row4)));
		_mm_store_ps(&toReturn.matrix[12], result);

		return toReturn;
*/
	}

	template <typename TYPE>
	Vector4D<TYPE> Matrix4D<TYPE>::operator*(const Vector4D<TYPE>& operand) const
	{
		return Vector4D<TYPE>(matrix[0] * operand[0] + matrix[1] * operand[1] + matrix[2] * operand[2] + matrix[3] * operand[3],
							  matrix[4] * operand[0] + matrix[5] * operand[1] + matrix[6] * operand[2] + matrix[7] * operand[3],
							  matrix[8] * operand[0] + matrix[9] * operand[1] + matrix[10] * operand[2] + matrix[11] * operand[3],
							  matrix[12] * operand[0] + matrix[13] * operand[1] + matrix[14] * operand[2] + matrix[15] * operand[3]);
	}


	template <typename TYPE>
	Matrix4D<TYPE>& Matrix4D<TYPE>::operator+=(const Matrix4D<TYPE>& operand)
	{
/*
		//	SIMD addition

		__m128 a1 = _mm_loadr_ps(&matrix[0]);
		__m128 a2 = _mm_loadr_ps(&operand.matrix[0]);
		a1 = _mm_add_ps(a1, a2);
		_mm_storer_ps(&matrix[0], a1);

		__m128 a1 = _mm_loadr_ps(&matrix[4]);
		__m128 a2 = _mm_loadr_ps(&operand.matrix[4]);
		a1 = _mm_add_ps(a1, a2);
		_mm_storer_ps(&matrix[4], a1);

		__m128 a1 = _mm_loadr_ps(&matrix[8]);
		__m128 a2 = _mm_loadr_ps(&operand.matrix[8]);
		a1 = _mm_add_ps(a1, a2);
		_mm_storer_ps(&matrix[8], a1);

		__m128 a1 = _mm_loadr_ps(&matrix[12]);
		__m128 a2 = _mm_loadr_ps(&operand.matrix[12]);
		a1 = _mm_add_ps(a1, a2);
		_mm_storer_ps(&matrix[12], a1);
*/


		matrix[0] += operand.matrix[0];
		matrix[1] += operand.matrix[1];
		matrix[2] += operand.matrix[2];
		matrix[3] += operand.matrix[3];

		matrix[4] += operand.matrix[4];
		matrix[5] += operand.matrix[5];
		matrix[6] += operand.matrix[6];
		matrix[7] += operand.matrix[7];

		matrix[8] += operand.matrix[8];
		matrix[9] += operand.matrix[9];
		matrix[10] += operand.matrix[10];
		matrix[11] += operand.matrix[11];

		matrix[12] += operand.matrix[12];
		matrix[13] += operand.matrix[13];
		matrix[14] += operand.matrix[14];
		matrix[15] += operand.matrix[15];

		return *this;
	}

	template <typename TYPE>
	Matrix4D<TYPE>& Matrix4D<TYPE>::operator-=(const Matrix4D<TYPE>& operand)
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
		matrix[9] -= operand.matrix[9];
		matrix[10] -= operand.matrix[10];
		matrix[11] -= operand.matrix[11];

		matrix[12] -= operand.matrix[12];
		matrix[13] -= operand.matrix[13];
		matrix[14] -= operand.matrix[14];
		matrix[15] -= operand.matrix[15];

		return *this;
	}

	template <typename TYPE>
	Matrix4D<TYPE>& Matrix4D<TYPE>::operator*=(const Matrix4D<TYPE>& operand)
	{
		TYPE x0y0 = matrix[0] * operand.matrix[0] + matrix[1] * operand.matrix[4] + matrix[2] * operand.matrix[8] + matrix[3] * operand.matrix[12],
		TYPE x1y0 = matrix[0] * operand.matrix[1] + matrix[1] * operand.matrix[5] + matrix[2] * operand.matrix[9] + matrix[3] * operand.matrix[13],
		TYPE x2y0 = matrix[0] * operand.matrix[2] + matrix[1] * operand.matrix[6] + matrix[2] * operand.matrix[10] + matrix[3] * operand.matrix[14],
		TYPE x3y0 = matrix[0] * operand.matrix[3] + matrix[1] * operand.matrix[7] + matrix[2] * operand.matrix[11] + matrix[3] * operand.matrix[15],

		TYPE x0y1 = matrix[4] * operand.matrix[0] + matrix[5] * operand.matrix[4] + matrix[6] * operand.matrix[8] + matrix[7] * operand.matrix[12],
		TYPE x1y1 = matrix[4] * operand.matrix[1] + matrix[5] * operand.matrix[5] + matrix[6] * operand.matrix[9] + matrix[7] * operand.matrix[13],
		TYPE x2y1 = matrix[4] * operand.matrix[2] + matrix[5] * operand.matrix[6] + matrix[6] * operand.matrix[10] + matrix[7] * operand.matrix[14],
		TYPE x3y1 = matrix[4] * operand.matrix[3] + matrix[5] * operand.matrix[7] + matrix[6] * operand.matrix[11] + matrix[7] * operand.matrix[15],

		TYPE x0y2 = matrix[8] * operand.matrix[0] + matrix[9] * operand.matrix[4] + matrix[10] * operand.matrix[8] + matrix[11] * operand.matrix[12],
		TYPE x1y2 = matrix[8] * operand.matrix[1] + matrix[9] * operand.matrix[5] + matrix[10] * operand.matrix[9] + matrix[11] * operand.matrix[13],
		TYPE x2y2 = matrix[8] * operand.matrix[2] + matrix[9] * operand.matrix[6] + matrix[10] * operand.matrix[10] + matrix[11] * operand.matrix[14],
		TYPE x3y2 = matrix[8] * operand.matrix[3] + matrix[9] * operand.matrix[7] + matrix[10] * operand.matrix[11] + matrix[11] * operand.matrix[15],

		TYPE x0y3 = matrix[12] * operand.matrix[0] + matrix[13] * operand.matrix[4] + matrix[14] * operand.matrix[8] + matrix[15] * operand.matrix[12],
		TYPE x1y3 = matrix[12] * operand.matrix[1] + matrix[13] * operand.matrix[5] + matrix[14] * operand.matrix[9] + matrix[15] * operand.matrix[13],
		TYPE x2y3 = matrix[12] * operand.matrix[2] + matrix[13] * operand.matrix[6] + matrix[14] * operand.matrix[10] + matrix[15] * operand.matrix[14],
		TYPE x3y3 = matrix[12] * operand.matrix[3] + matrix[13] * operand.matrix[7] + matrix[14] * operand.matrix[11] + matrix[15] * operand.matrix[15]

		matrix[0] = x0y0;
		matrix[1] = x1y0;
		matrix[2] = x2y0;
		matrix[3] = x3y0;

		matrix[4] = x0y1;
		matrix[5] = x1y1;
		matrix[6] = x2y1;
		matrix[7] = x3y1;

		matrix[8] = x0y2;
		matrix[9] = x1y2;
		matrix[10] = x2y2;
		matrix[11] = x3y2;

		matrix[12] = x0y3;
		matrix[13] = x1y3;
		matrix[14] = x2y3;
		matrix[15] = x3y3;
		
		return *this;
	}

	template <typename TYPE>
	TYPE Matrix4D<TYPE>::getCofactor(TYPE x0y0, TYPE x1y0, TYPE x2y0, TYPE x0y1, TYPE x1y1, TYPE x2y1, TYPE x0y2, TYPE x1y2, TYPE x2y2) const
	{
		return x0y0 * (x1y1 * x2y2 - x2y1 * x1y2) -
			   x1y0 * (x0y1 * x2y2 - x2y1 * x0y2) +
			   x2y0 * (x0y1 * x1y2 - x1y1 * x0y2);
	}

	template <typename TYPE>
	TYPE Matrix4D<TYPE>::getDeterminant() const
	{
		return matrix[0] * getCofactor(matrix[5], matrix[6], matrix[7], matrix[9], matrix[10], matrix[11], matrix[13], matrix[14], matrix[15]) - 
			   matrix[1] * getCofactor(matrix[4], matrix[6], matrix[7], matrix[8], matrix[10], matrix[11], matrix[12], matrix[14], matrix[15]) + 
			   matrix[2] * getCofactor(matrix[4], matrix[5], matrix[7], matrix[8], matrix[9], matrix[11], matrix[12], matrix[13], matrix[15]) - 
			   matrix[3] * getCofactor(matrix[4], matrix[5], matrix[6], matrix[8], matrix[9], matrix[10], matrix[12], matrix[13], matrix[14]);
	}

	template <typename TYPE>
	Matrix4D<TYPE>& Matrix4D<TYPE>::transpose()
	{
		std::swap(matrix[1], matrix[4]);
		std::swap(matrix[2], matrix[8]);
		std::swap(matrix[3], matrix[12]);
		std::swap(matrix[6], matrix[9]);
		std::swap(matrix[7], matrix[13]);
		std::swap(matrix[11], matrix[14]);
		
		return *this;
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::transposed() const
	{
		return Matrix4D<TYPE>(matrix[0], matrix[4], matrix[8], matrix[12],
							  matrix[1], matrix[5], matrix[9], matrix[13],
							  matrix[2], matrix[6], matrix[10], matrix[14],
							  matrix[3], matrix[7], matrix[11], matrix[15]);
	}

	template <typename TYPE>
	Matrix4D<TYPE>& Matrix4D<TYPE>::invert()
	{
		TYPE cofactor0 = getCofactor(matrix[5], matrix[6], matrix[7], matrix[9], matrix[10], matrix[11], matrix[13], matrix[14], matrix[15]);
		TYPE cofactor1 = getCofactor(matrix[4], matrix[6], matrix[7], matrix[8], matrix[10], matrix[11], matrix[12], matrix[14], matrix[15]);
		TYPE cofactor2 = getCofactor(matrix[4], matrix[5], matrix[7], matrix[8], matrix[9], matrix[11], matrix[12], matrix[13], matrix[15]);
		TYPE cofactor3 = getCofactor(matrix[4], matrix[5], matrix[6], matrix[8], matrix[9], matrix[10], matrix[12], matrix[13], matrix[14]);

		TYPE determinant = matrix[0] * cofactor0 - matrix[1] * cofactor1 + matrix[2] * cofactor2 - matrix[3] * cofactor3;
		if (Numbers::almostEqualsZero(determinant))
			return *this;

		TYPE cofactor4 = getCofactor(matrix[1],matrix[2],matrix[3], matrix[9],matrix[10],matrix[11], matrix[13],matrix[14],matrix[15]);
		TYPE cofactor5 = getCofactor(matrix[0],matrix[2],matrix[3], matrix[8],matrix[10],matrix[11], matrix[12],matrix[14],matrix[15]);
		TYPE cofactor6 = getCofactor(matrix[0],matrix[1],matrix[3], matrix[8],matrix[9], matrix[11], matrix[12],matrix[13],matrix[15]);
		TYPE cofactor7 = getCofactor(matrix[0],matrix[1],matrix[2], matrix[8],matrix[9], matrix[10], matrix[12],matrix[13],matrix[14]);

		TYPE cofactor8 = getCofactor(matrix[1],matrix[2],matrix[3], matrix[5],matrix[6], matrix[7], matrix[13],matrix[14],matrix[15]);
		TYPE cofactor9 = getCofactor(matrix[0],matrix[2],matrix[3], matrix[4],matrix[6], matrix[7], matrix[12],matrix[14],matrix[15]);
		TYPE cofactor10 = getCofactor(matrix[0],matrix[1],matrix[3], matrix[4],matrix[5], matrix[7], matrix[12],matrix[13],matrix[15]);
		TYPE cofactor11 = getCofactor(matrix[0],matrix[1],matrix[2], matrix[4],matrix[5], matrix[6], matrix[12],matrix[13],matrix[14]);

		TYPE cofactor12 = getCofactor(matrix[1],matrix[2],matrix[3], matrix[5],matrix[6], matrix[7], matrix[9], matrix[10],matrix[11]);
		TYPE cofactor13 = getCofactor(matrix[0],matrix[2],matrix[3], matrix[4],matrix[6], matrix[7], matrix[8], matrix[10],matrix[11]);
		TYPE cofactor14 = getCofactor(matrix[0],matrix[1],matrix[3], matrix[4],matrix[5], matrix[7], matrix[8], matrix[9], matrix[11]);
		TYPE cofactor15 = getCofactor(matrix[0],matrix[1],matrix[2], matrix[4],matrix[5], matrix[6], matrix[8], matrix[9], matrix[10]);

		determinant = 1 / determinant;
		
		matrix[0] = cofactor0 * determinant;
		matrix[1] = cofactor4 * determinant;
		matrix[2] = cofactor8 * determinant;
		matrix[3] = cofactor12 * determinant;
		matrix[4] = cofactor1 * determinant;
		matrix[5] = cofactor5 * determinant;
		matrix[6] = cofactor9 * determinant;
		matrix[7] = cofactor13 * determinant;
		matrix[8] = cofactor2 * determinant;
		matrix[9] = cofactor6 * determinant;
		matrix[10] = cofactor10 * determinant;
		matrix[11] = cofactor14 * determinant;
		matrix[12] = cofactor3 * determinant;
		matrix[13] = cofactor7 * determinant;
		matrix[14] = cofactor11 * determinant;
		matrix[15] = cofactor15 * determinant;
		

		return *this;
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::inverted() const
	{
		TYPE cofactor0 = getCofactor(matrix[5], matrix[6], matrix[7], matrix[9], matrix[10], matrix[11], matrix[13], matrix[14], matrix[15]);
		TYPE cofactor1 = getCofactor(matrix[4], matrix[6], matrix[7], matrix[8], matrix[10], matrix[11], matrix[12], matrix[14], matrix[15]);
		TYPE cofactor2 = getCofactor(matrix[4], matrix[5], matrix[7], matrix[8], matrix[9], matrix[11], matrix[12], matrix[13], matrix[15]);
		TYPE cofactor3 = getCofactor(matrix[4], matrix[5], matrix[6], matrix[8], matrix[9], matrix[10], matrix[12], matrix[13], matrix[14]);

		TYPE determinant = matrix[0] * cofactor0 - matrix[1] * cofactor1 + matrix[2] * cofactor2 - matrix[3] * cofactor3;
		if (Numbers::almostEqualsZero(determinant))
			return identity();

		TYPE cofactor4 = getCofactor(matrix[1],matrix[2],matrix[3], matrix[9],matrix[10],matrix[11], matrix[13],matrix[14],matrix[15]);
		TYPE cofactor5 = getCofactor(matrix[0],matrix[2],matrix[3], matrix[8],matrix[10],matrix[11], matrix[12],matrix[14],matrix[15]);
		TYPE cofactor6 = getCofactor(matrix[0],matrix[1],matrix[3], matrix[8],matrix[9], matrix[11], matrix[12],matrix[13],matrix[15]);
		TYPE cofactor7 = getCofactor(matrix[0],matrix[1],matrix[2], matrix[8],matrix[9], matrix[10], matrix[12],matrix[13],matrix[14]);

		TYPE cofactor8 = getCofactor(matrix[1],matrix[2],matrix[3], matrix[5],matrix[6], matrix[7], matrix[13],matrix[14],matrix[15]);
		TYPE cofactor9 = getCofactor(matrix[0],matrix[2],matrix[3], matrix[4],matrix[6], matrix[7], matrix[12],matrix[14],matrix[15]);
		TYPE cofactor10 = getCofactor(matrix[0],matrix[1],matrix[3], matrix[4],matrix[5], matrix[7], matrix[12],matrix[13],matrix[15]);
		TYPE cofactor11 = getCofactor(matrix[0],matrix[1],matrix[2], matrix[4],matrix[5], matrix[6], matrix[12],matrix[13],matrix[14]);

		TYPE cofactor12 = getCofactor(matrix[1],matrix[2],matrix[3], matrix[5],matrix[6], matrix[7], matrix[9], matrix[10],matrix[11]);
		TYPE cofactor13 = getCofactor(matrix[0],matrix[2],matrix[3], matrix[4],matrix[6], matrix[7], matrix[8], matrix[10],matrix[11]);
		TYPE cofactor14 = getCofactor(matrix[0],matrix[1],matrix[3], matrix[4],matrix[5], matrix[7], matrix[8], matrix[9], matrix[11]);
		TYPE cofactor15 = getCofactor(matrix[0],matrix[1],matrix[2], matrix[4],matrix[5], matrix[6], matrix[8], matrix[9], matrix[10]);

		determinant = 1 / determinant;
		
		return Matrix4D<TYPE>(cofactor0 * determinant, cofactor4 * determinant, cofactor8 * determinant, cofactor12 * determinant,
							  cofactor1 * determinant, cofactor5 * determinant, cofactor9 * determinant, cofactor13 * determinant,
							  cofactor2 * determinant, cofactor6 * determinant, cofactor10 * determinant, cofactor14 * determinant,
							  cofactor3 * determinant, cofactor7 * determinant, cofactor11 * determinant, cofactor15 * determinant);
		/*
		return Matrix4D<TYPE>(cofactor0 * determinant, cofactor1 * determinant, cofactor2 * determinant, cofactor3 * determinant,
							  cofactor4 * determinant, cofactor5 * determinant, cofactor6 * determinant, cofactor7 * determinant,
							  cofactor8 * determinant, cofactor9 * determinant, cofactor10 * determinant, cofactor11 * determinant,
							  cofactor12 * determinant, cofactor13 * determinant, cofactor14 * determinant, cofactor15 * determinant);
		*/
	}

	template <typename TYPE>
	Matrix4D<TYPE>& Matrix4D<TYPE>::affineInvert()
	{
		return *this = inverted();
	}

	template <typename TYPE>
	Matrix4D<TYPE> Matrix4D<TYPE>::affineInverted() const
	{
		Matrix4D<TYPE> toReturn = Matrix4D<TYPE>(matrix[0], matrix[4], matrix[8], 0,
												 matrix[1], matrix[5], matrix[9], 0,
												 matrix[2], matrix[6], matrix[10], 0,
												 matrix[3], matrix[7], matrix[11], 1);

		toReturn[3] = toReturn * Vector4D<TYPE>(-matrix[12], -matrix[13], -matrix[14], matrix[15]);

		return toReturn;
	}
}

