#ifndef CM_NMATRIX_H_
#define CM_NMATRIX_H_

#include <stdlib.h>
#include <limits.h>

#include "cmantras/base/helpers/cm_numeric.h"
#include "cm_narray.h"

struct cm_nmatrix_data
{
   real** content;
   integer rows;
   integer columns;
};

struct cm_nmatrix;

struct cm_interface_nmatrix
{
	struct cm_nmatrix* (*destroy)(struct cm_nmatrix*);
	struct cm_nmatrix* (*copy)(const struct cm_nmatrix*);
	struct cm_nmatrix* (*add)(const struct cm_nmatrix*, const struct cm_nmatrix*);
	struct cm_nmatrix* (*multiply_with_scalar)(const struct cm_nmatrix*, real);
	struct cm_nmatrix* (*muliply)(const struct cm_nmatrix*, const struct cm_nmatrix*);
	struct cm_narray* (*get_secondary_diagonal_as_array)(struct cm_nmatrix*);
	struct cm_narray* (*get_primary_diagonal_as_array)(struct cm_nmatrix*);
	struct cm_nmatrix* (*get_minor)(const struct cm_nmatrix, integer, integer, integer);
	real (*get_determinant)(const struct cm_nmatrix*, integer);
	struct cm_nmatrix* (*get_transpose)(const struct cm_nmatrix*);
	struct cm_nmatrix* (*get_adjugate)(const struct cm_nmatrix*);
	struct cm_nmatrix* (*get_inverse)(struct cm_nmatrix*);
};

struct cm_nmatrix
{
	struct cm_nmatrix_data* data;
	struct cm_interface_matrix* methods;
};

/**
 * Description:
 * 	Initializes the cm_nmatrix module. Needs to be called before
 * 	using cm_nmatrix as an object.
 * Parameters:
 *  None
 * Returns:
 *  None
 */
void module_cm_nmatrix_initialize(void);
/*
 * Description:
 * 	Alocates spaces for a cm_nmatrix structure according to the parameters
 * rows si columns.
 * Parameters:
 * 	matrix - a pointer to the cm_nmatrix structure
 * 	rows - the number of rows
 * 	columns - the number of columns
 * Returns:
 *  A pointer to the allocated matrix structure.
 */
struct cm_nmatrix* cm_nmatrix_create(struct cm_nmatrix *matrix, integer rows, integer columns);
/*
 * Description:
 * 	Free the space hold by a cm_nmatrix structure
 * Parameters:
 * 	matrix - a pointer to the cm_nmatrix structure
 * Returns:
 *  NULL
 */
void cm_nmatrix_destroy(struct cm_nmatrix *matrix);
/*
 * Description:
 * 	Creates a hard copy of the matrix source
 * Parameters:
 * 	source - the cm_nmatrix who shall be copied
 * Returns:
 * 	A pointer to the clone matrix
 */
struct cm_nmatrix* cm_nmatrix_copy(const struct cm_nmatrix *source);
/*
 * Description:
 * 	Sums up two matrices
 * Parameters:
 * 	matrix1 - a pointer to the first matrix
 * 	matrix2 - a pointer to the second matrix
 * Returns:
 *  A pointer to the result matrix.
 *  If the rows/columns of mat1 and mat2 are not
 * equal, the result will be NULL
 */
struct cm_nmatrix* cm_nmatrix_add(const struct cm_nmatrix* matrix1, const struct cm_nmatrix* matrix2);
/*
 * Description:
 * 	Multiplies a cm_nmatrix with a scalar
 * Parameters:
 * 	mat - a pointer to cm_nmatrix who shall be multiplied
 * Returns:
 *  A pointer to the result matrix.
 */
struct cm_nmatrix* cm_nmatrix_multiply_with_scalar(const struct cm_nmatrix* matrix, real value);
/*
 * Description:
 * 	Returns the product of two matrices
 * Parameters:
 * 	mat1 - a pointer to the first matrix
 * 	mat2 - a pointer to the second matrix
 * Returns:
 *  A pointer to the result matrix.
 */
struct cm_nmatrix* cm_nmatrix_muliply(const struct cm_nmatrix* matrix1, const struct cm_nmatrix* matrix2);
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
struct cm_narray* cm_nmatrix_get_secondary_diagonal_as_array(const struct cm_nmatrix* matrix);
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
struct cm_narray* cm_nmatrix_get_primary_diagonal_as_array(const struct cm_nmatrix *matrix);
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
struct cm_nmatrix* cm_nmatrix_get_minor(const struct cm_nmatrix *matrix, integer row, integer column, integer order);
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
 *  matrix must be a square matrix
 *  order must be greater than 1 but smaller or equal when compared to the size of the matrix
 */
real cm_nmatrix_get_determinant(const struct cm_nmatrix *matrix, integer order);
/*
 * Description:
 * 	Computes the transpose matrix of a given matrix
 * Parameters:
 * 	mat   - a pointer to the original matrix
 * Returns:
 *  A pointer to the transpose matrix of the original matrix.
 */
struct cm_nmatrix* cm_nmatrix_get_transpose(const struct cm_nmatrix* matrix);
/*
 * Description:
 * 	Computes the adjugate matrix of a given matrix
 * Parameters:
 * 	mat   - a pointer to the original matrix
 * Returns:
 *  A pointer to the adjugate matrix of the original matrix.
 */
struct cm_nmatrix* cm_nmatrix_get_adjugate(const struct cm_nmatrix* matrix);
/*
 * Description:
 * 	Computes the inverse matrix of a given matrix
 * Parameters:
 * 	mat   - a pointer to the original matrix
 * Returns:
 *  A pointer to the inverse matrix of the original matrix.
 * Preconditions:
 *  @mat must not be singular (det(matrix)!=0)
 */
struct cm_nmatrix* cm_nmatrix_get_inverse(struct cm_nmatrix* matrix);

#endif /* NMATRIX_H_ */
