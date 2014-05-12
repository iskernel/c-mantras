#include "cm_common_numeric.h"
#include "cm_narray.h"

/*
 * Description:
 * 	Creates a dynamic array of size @size
 * Parameters:
 * 	array - a pointer to the NArray structure
 * 	size - the size of the array
 * Returns:
 * 	A pointer to the allocated NArray structure
 */
cm_narray* cm_narray_create(cm_narray* array, integer size)
{
	if (array == NULL)
	{
		array = (cm_narray*) malloc(sizeof(cm_narray));
	}
	array->data = (real*) malloc(sizeof(real) * size);
	array->size = size;
	return array;
}
/*
 * Description:
 * 	Frees the memory hold by a NArray structure.
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	NULL
 * Preconditions:
 * 	@array must not be NULL
 */
void cm_narray_destroy(cm_narray* array)
{
	if (array != NULL)
	{
		free(array->data);
		free(array);
	}
}
/*
 * Description:
 * 	Returns the smallest element of the array
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The smallest element of the array
 * Preconditions:
 * 	@array must not be NULL
 */
real cm_narray_min(const cm_narray *array)
{
	integer i = 0;
	real min_val = array->data[0];
	for (i = 1; i < array->size; i++)
	{
		if (array->data[i] < min_val)
		{
			min_val = array->data[i];
		}
	}
	return min_val;
}
/*
 * Description:
 * 	Returns the largest element of the array
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The largest element of the array
 * Preconditions:
 * 	@array must not be NULL
 */
real cm_narray_max(const cm_narray *array)
{
	integer i = 0;
	real max_val = array->data[0];
	for (i = 1; i < array->size; i++)
	{
		if (array->data[i] > max_val)
		{
			max_val = array->data[i];
		}
	}
	return max_val;
}
/*
 * Description:
 * 	Computes the sum of all the elements of the array
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The sum of all the elements of the array
 * Preconditions:
 * 	@array must not be NULL
 */
real cm_narray_sum(const cm_narray* array)
{
	integer i = 0;
	real sum = 0;
	for (i = 0; i < array->size; i++)
	{
		sum += array->data[i];
	}
	return sum;
}
/*
 * Description:
 * 	Computes the product of all the elements of the array
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The product of all the elements of the array
 * Preconditions:
 * 	@array must not be NULL
 */
real cm_narray_product(const cm_narray* vec)
{
	integer i;
	real product = 1.0;
	for (i = 0; i < vec->size; i++)
	{
		product *= vec->data[i];
	}
	return product;
}
/*
 * Description:
 * 	Computes the arithmetic mean of the array's elements
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The arithmetic mean of the array's elements
 * Preconditions:
 * 	@array must not be NULL
 */
real cm_narray_arithemetic_mean(const cm_narray* array)
{
	real mean = cm_narray_sum(array) / (real) array->size;
	return mean;
}
/*
 * Description:
 * 	Computes the geometric mean of the array's elements
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The geometric mean of the array's elements
 * Preconditions:
 * 	@array must not be NULL
 */
real cm_narray_geometric_mean(const cm_narray* array)
{
	real mean = pow(cm_narray_product(array), (1.0f / (real) (array->size)));
	return mean;
}
/*
 * Description:
 * 	Computes the harmonic mean of the array's elements
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The harmonic mean of the array's elements
 * Preconditions:
 * 	@array must not be NULL
 */
real cm_narray_harmonic_mean(const cm_narray *array)
{
	integer i = 0;
	real sum = 0.0f;
	real mean = 0.0f;
	for (i = 0; i < array->size; i++)
	{
		sum += 1.0f / array->data[i];
	}
	mean = (real) (array->size) * pow(sum, -1.0f);
	return mean;
}
