#ifndef CM_NARRAY_H_
#define CM_NARRAY_H_

#include <stdlib.h>
#include <math.h>

#include "cm_common.h"

struct cm_narray_data
{
    real* content;
    integer size;
};

struct cm_narray;

struct cm_interface_narray
{
    real (*min)(const struct cm_narray*);
    real (*max)(const struct cm_narray*);
    real (*sum)(const struct cm_narray*);
    real (*product)(const struct cm_narray*);
    real (*arithmetic_mean)(const struct cm_narray*);
    real (*geometric_mean)(const struct cm_narray*);
    real (*harmonic_mean)(const struct cm_narray*);
};

struct cm_narray
{
    struct cm_narray_data* data;
    struct cm_interface_narray* methods;
};

/**
 * Description:
 * 	Initializes the cm_narray module
 * Parameters:
 *  None
 * Returns:
 *  None
 */
void module_cm_narray_initialize();

/*
 * Description:
 * 	Creates a dynamic array of size @size
 * Parameters:
 * 	size - the size of the array
 * Returns:
 * 	A pointer to the allocated NArray structure
 */
struct cm_narray* cm_narray_create(integer size);
/*
 * Description:
 * 	Frees the memory hold by a NArray structure.
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 *  Nothing
 */
void cm_narray_destroy(struct cm_narray* array);
/*
 * Description:
 * 	Returns the smallest element of the array
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The smallest element of the array
 */
real cm_narray_min(const struct cm_narray *array);
/*
 * Description:
 * 	Returns the largest element of the array
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The largest element of the array
 */
real cm_narray_max(const struct cm_narray *array);
/*
 * Description:
 * 	Computes the sum of all the elements of the array
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The sum of all the elements of the array
 */
real cm_narray_sum(const struct cm_narray* array);
/*
 * Description:
 * 	Computes the product of all the elements of the array
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The product of all the elements of the array
 */
real cm_narray_product(const struct cm_narray* array);
/*
 * Description:
 * 	Computes the arithmetic mean of the array's elements
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The arithmetic mean of the array's elements
 */
real cm_narray_arithmetic_mean(const struct cm_narray* array);

/*
 * Description:
 * 	Computes the geometric mean of the array's elements
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The geometric mean of the array's elements
 */
real cm_narray_geometric_mean(const struct cm_narray* array);
/*
 * Description:
 * 	Computes the harmonic mean of the array's elements
 * Parameters:
 * 	array - a pointer to the array structure
 * Returns:
 * 	The harmonic mean of the array's elements
 */
real cm_narray_harmonic_mean(const struct cm_narray* array);

#endif /* CM_NARRAY_H_ */
