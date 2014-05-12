#include "cm_nmatrix.h"

/*
 * Description:
 * 	Alocates spaces for a NMatrix structure according to the parameters
 * @rows si @columns.
 * Parameters:
 * 	matrix - a pointer to the NMatrix structure
 * 	rows - the number of rows
 * 	columns - the number of columns
 * Returns:
 *  A pointer to the allocated matrix structure.
 */
cm_nmatrix* cm_nmatrix_create(cm_nmatrix *matrix, integer rows, integer columns)
{
	integer i = 0;
	matrix = (cm_nmatrix*) malloc(sizeof(cm_nmatrix));
	if (matrix != NULL)
	{
		matrix->rows = rows;
		matrix->columns = columns;
		matrix->data = (real**) malloc(rows * sizeof(real*));
		for (i = 0; i < rows; i++)
		{
			matrix->data[i] = (real *) malloc(columns * sizeof(real));
		}
	}
	return matrix;
}
/*
 * Description:
 * 	Free the space hold by a NMatrix structure
 * Parameters:
 * 	matrix - a pointer to the NMatrix structure
 * Returns:
 *  NULL
 * Preconditions:
 *  @matrix must not be NULL
 */
void cm_nmatrix_destroy(cm_nmatrix *matrix)
{
	integer i = 0;
	if (matrix != NULL)
	{
		for (i = 0; i < matrix->rows; i++)
		{
			free(matrix->data[i]);
		}
		free(matrix->data);
	}
	matrix->columns = 0;
	matrix->rows = 0;
	free(matrix);
}
/*
 * Description:
 * 	Creates a hard copy of the matrix @source
 * Parameters:
 * 	source - the matrix who shall be copied
 * 	destination - the matrix where the copy
 * 				  will be stored
 * Returns:
 * 	A pointer to the clone matrix
 * Preconditions:
 *  @matrix must not be NULL
 */
cm_nmatrix* cm_nmatrix_clone(const cm_nmatrix *source, cm_nmatrix *dest)
{
	integer i = 0, j = 0;
	if (dest != NULL)
	{
		cm_nmatrix_destroy(dest);
	}
	dest = cm_nmatrix_create(dest, source->rows, source->columns);
	if (dest != NULL)
	{
		for (i = 0; i < source->rows; i++)
		{
			for (j = 0; j < source->columns; j++)
			{
				dest->data[i][j] = source->data[i][j];
			}
		}
	}
	return dest;
}
/*
 * Description:
 * 	Sums up two matrices
 * Parameters:
 * 	mat1 - a pointer to the first matrix
 * 	mat2 - a pointer to the second matrix
 * Returns:
 *  A pointer to the result matrix.
 *  If the rows/columns of mat1 and mat2 are not
 * equal, the result will be NULL
 * Preconditions:
 *  @mat1 and @mat2 must not be NULL
 */
cm_nmatrix* cm_nmatrix_sum(const cm_nmatrix* mat1, const cm_nmatrix* mat2)
{
	integer i = 0, j = 0;
	cm_nmatrix *result = NULL;
	if ((mat1->rows == mat2->rows) && (mat1->columns == mat2->columns))
	{
		result = cm_nmatrix_create(result, mat1->rows, mat1->columns);
		for (i = 0; i < mat1->rows; i++)
		{
			for (j = 0; j < mat1->columns; j++)
			{
				result->data[i][j] = mat1->data[i][j] + mat2->data[i][j];
			}
		}
	}
	return result;
}
/*
 * Description:
 * 	Multiplies a NMatrix with a scalar
 * Parameters:
 * 	mat - a pointer to NMatrix who shall be multiplied
 * Returns:
 *  A pointer to the result matrix.
 * Preconditions:
 *  @mat must not be NULL
 */
cm_nmatrix* cm_nmatrix_multiply_with_scalar(const cm_nmatrix* mat, real value)
{
	integer i = 0, j = 0;
	cm_nmatrix *smat = NULL;
	smat = cm_nmatrix_clone(mat, smat);
	for (i = 0; i < mat->rows; i++)
	{
		for (j = 0; j < mat->columns; j++)
		{
			smat->data[i][j] *= value;
		}
	}
	return smat;
}
/*
 * Description:
 * 	Returns the product of two matrices
 * Parameters:
 * 	mat1 - a pointer to the first matrix
 * 	mat2 - a pointer to the second matrix
 * Returns:
 *  A pointer to the result matrix.
 * Preconditions:
 *  @mat must not be NULL
 */
cm_nmatrix* cm_nmatrix_product(const cm_nmatrix* mat1, const cm_nmatrix* mat2)
{
	integer i = 0, j = 0, k = 0, p = 0;
	cm_nmatrix *result = NULL;
	if (mat1->rows == mat2->columns)
	{
		result = cm_nmatrix_create(result, mat1->rows, mat2->columns);
		for (i = 0; i < mat1->rows; i++)
		{
			for (j = 0; j < mat2->columns; j++)
			{
				p = 0;
				for (k = 0; k < mat1->columns; k++)
				{
					p += mat1->data[i][k] * mat2->data[k][j];
				}
				result->data[i][j] = p;
			}
		}
	}
	return result;
}
/*
 * Description:
 * 	Returns the primary diagonal of a square
 * 	matrix as an NArray
 * Parameters:
 * 	mat1 - a pointer to the matrix
 * Returns:
 *  A pointer to the NArray holding the values
 * situated on the primary diagonal
 * Preconditions:
 *  @mat must not be NULL
 *  @may must be a square matrix
 */
cm_narray* cm_nmatrix_get_primary_diagonal_as_array(cm_nmatrix *mat)
{
	integer i = 0;
	cm_narray *array = NULL;
	if (mat->rows == mat->columns)
	{
		array = cm_narray_create(array, mat->rows);
		for (i = 0; i < mat->rows; i++)
		{
			array->data[i] = mat->data[i][i];
		}
	}
	return array;
}
/*
 * Description:
 * 	Returns the secondary diagonal of a square
 * 	matrix as an NArray
 * Parameters:
 * 	mat1 - a pointer to the matrix
 * Returns:
 *  A pointer to the NArray holding the values
 * situated on the secondary diagonal
 * Preconditions:
 *  @mat must not be NULL
 *  @may must be a square matrix
 */
cm_narray* cm_nmatrix_get_secondary_diagonal_as_array(cm_nmatrix* mat)
{
	integer i = 0;
	cm_narray *array = NULL;
	if (mat->rows == mat->columns)
	{
		array = cm_narray_create(array, mat->rows);
		for (i = 0; i < mat->rows; i++)
		{
			array->data[i] = mat->data[i][mat->rows - 1 - i];
		}
	}
	return array;
}
/*
 * Description:
 * 	Computes the minor of a given matrix according to
 * a predefined @row, @column and @order.
 * Parameters:
 * 	mat1 - a pointer to the matrix
 * 	row - the starting row
 * 	column - the starting column
 * 	order - the size of the minor
 * Returns:
 *  A pointer to the minor matrix if the conditions are valid.
 * Otherwise returns NULL.
 * Preconditions:
 *  @mat must not be NULL
 *  @may must be a square matrix
 *  @column and @row must be smaller than @order
 *  @order must be greater than 1 but smaller than
 *  the size of the matrix
 */
cm_nmatrix* cm_nmatrix_minor(const cm_nmatrix *mat, integer row, integer column,
							 integer order)
{
	integer i = 0, j = 0;
	integer rowCount = 0, colCount = 0;
	cm_nmatrix *minor = NULL;

	if ((mat->rows == mat->columns) && ((row - 1) < order)
			&& ((column - 1) < order) && (order >= 1) && (order < mat->rows))
	{
		if (order == 1)
		{
			minor = cm_nmatrix_create(minor, 1, 1);
			minor->data[0][0] = mat->data[row][column];
		}
		else
		{
			minor = cm_nmatrix_create(minor, order, order);
			for (i = 0; i <= order; i++)
			{
				if (i != row)
				{
					colCount = 0;
					for (j = 0; j <= order; j++)
					{
						if (j != column)
						{
							minor->data[rowCount][colCount] = mat->data[i][j];
							colCount++;
						}
					}
					rowCount++;
				}
			}
		}
	}
	return minor;
}
/*
 * Description:
 * 	Computes the determinant of a given matrix
 * Parameters:
 * 	mat   - a pointer to the matrix
 * 	order - usually the size of square matrix, but it can be used
 * 		    if you want to compute a determinant of a minor
 * Returns:
 *  The value of the determinant if the input is correct.
 * Otherwise returns NaN.
 * Preconditions:
 *  @mat must not be NULL
 *  @mat must be a square matrix
 *  @column and @row must be smaller than @order
 *  @order must be greater than 1 but smaller or equal when
 *  compared to the size of the matrix
 */
real cm_nmatrix_deteminant(const cm_nmatrix *mat, integer order)
{
	integer i = 0, j = 0, k = 0, l = 0;
	real det = 0.0f;
	cm_nmatrix *minor = NULL;
	if ((mat->rows == mat->columns) && (order >= 1) && (order <= mat->rows))
	{
		if (order == 1)
		{
			det = mat->data[0][0];
		}
		else
		{
			for (k = 0; k < order; k++)
			{
				minor = cm_nmatrix_create(minor, order, order);
				for (i = 1; i < order; i++)
				{
					l = 0;
					for (j = 0; j < order; j++)
					{
						if (j != k)
						{
							minor->data[i - 1][l] = mat->data[i][j];
							l++;
						}
					}
				}
				det += pow(-1.0, k) * mat->data[0][k]
						* cm_nmatrix_deteminant(minor, order - 1);
				cm_nmatrix_destroy(minor);
			}
		}
	}
	else
	{
		det = NAN;
	}
	return det;
}
/*
 * Description:
 * 	Computes the transpose matrix of a given matrix
 * Parameters:
 * 	mat   - a pointer to the original matrix
 * Returns:
 *  A pointer to the transpose matrix of the original matrix.
 * Preconditions:
 *  @mat must not be NULL
 */
cm_nmatrix* cm_nmatrix_transpose(const cm_nmatrix* mat)
{
	integer i = 0, j = 0;
	cm_nmatrix* transpose = NULL;
	transpose = cm_nmatrix_create(transpose, mat->columns, mat->rows);
	for (i = 0; i < transpose->rows; i++)
	{
		for (j = 0; j < transpose->columns; j++)
		{
			transpose->data[i][j] = mat->data[j][i];
		}
	}
	return transpose;
}
/*
 * Description:
 * 	Computes the adjugate matrix of a given matrix
 * Parameters:
 * 	mat   - a pointer to the original matrix
 * Returns:
 *  A pointer to the adjugate matrix of the original matrix.
 * Preconditions:
 *  @mat must not be NULL
 */
cm_nmatrix* cm_nmatrix_adjugate(const cm_nmatrix* mat)
{
	integer i = 0, j = 0, dim = 0;
	real det = 0.0f;
	cm_nmatrix* minor = NULL;
	cm_nmatrix* cofactor = NULL;
	if (mat->columns == mat->rows)
	{
		dim = mat->columns;
		cofactor = cm_nmatrix_create(cofactor, dim, dim);
		for (j = 0; j < dim; j++)
		{
			for (i = 0; i < dim; i++)
			{
				minor = cm_nmatrix_minor(mat, i, j, dim - 1);
				det = cm_nmatrix_deteminant(minor, dim - 1);
				cofactor->data[i][j] = pow(-1.0f, i + j + 2.0f) * det;
			}
		}
	}
	return cofactor;
}
/*
 * Description:
 * 	Computes the inverse matrix of a given matrix
 * Parameters:
 * 	mat   - a pointer to the original matrix
 * Returns:
 *  A pointer to the inverse matrix of the original matrix.
 * Preconditions:
 *  @mat must not be NULL
 *  @mat must not be singular (det(@mat)!=0)
 */
cm_nmatrix* cm_nmatrix_inverse(cm_nmatrix* mat)
{
	cm_nmatrix* inv = NULL;
	real det = 0.0f;
	real coeficent = 0.0f;
	if (mat->rows == mat->columns)
	{
		det = cm_nmatrix_deteminant(mat, mat->rows);
		if (det != 0.0f)
		{
			inv = cm_nmatrix_create(inv, mat->rows, mat->columns);
			coeficent = 1.0f / cm_nmatrix_deteminant(mat, mat->rows);
			inv = cm_nmatrix_adjugate(mat);
			inv = cm_nmatrix_multiply_with_scalar(inv, coeficent);
		}
	}
	return inv;
}
