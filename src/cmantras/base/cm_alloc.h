#ifndef CM_ALLOC_H_
#define CM_ALLOC_H_

#include<stdio.h>
#include<stdlib.h>

/*
 * Abstract:
 * 	Allocates a 1D array
 * Parameters:
 * 	vector - a pointer to the 1D array
 * 	xsize - the size of the array
 *  elementSize - the size of one element
 * Returns:
 *  A pointer to the allocated array
 */
void* cm_nalloc_1d(void* vector, size_t x_size, size_t element_size);
/*
 * Abstract:
 * 	Allocates a 2D array
 * Parameters:
 * 	vector - a pointer to the 2D array
 * 	xsize - the x size of the array (real of rows)
 * 	ysize - the y size of the array (real of columns)
 *  elementSize - the size of one element
 * Returns:
 *  A pointer to the allocated array
 */
void** cm_nalloc_2d(void **vector, size_t x_size, size_t y_size, size_t element_size);
/*
 * Abstract:
 * 	Allocates a 3D array
 * Parameters:
 * 	vector - a pointer to the 3D array
 * 	xsize - the x size of the array (real of rows)
 * 	ysize - the y size of the array (real of columns)
 * 	zsize - the z size of the array (real of tables)
 *  elementSize - the size of an array element
 * Returns:
 *  A pointer to the allocated array
 */
void*** cm_nalloc_3d(void ***vector, size_t x_size, size_t y_size, size_t z_size, size_t element_size);
/*
 * Abstract:
 * 	Allocates a 4D array
 * Parameters:
 * 	vector - a pointer to the 4D array
 * 	xsize - the x size of the array (real of rows)
 * 	ysize - the y size of the array (real of columns)
 * 	zsize - the z size of the array (real of tables)
 * 	tsize - the t size of the array
 *  elementSize - the size of an array element
 * Returns:
 *  NULL
 */
void**** cm_nalloc_4d(void ****vector, size_t x_size, size_t y_size, size_t z_size, size_t tsize, size_t element_size);

/*
 * Abstract:
 * 	Deallocates a 1D array
 * Parameters:
 * 	vector - a pointer to the 1D array
 * Return:
 *  NULL
 */
void cm_nfree_1d(void *vector);
/*
 * Abstract:
 * 	Deallocates a 2D array
 * Parameters:
 * 	vector - a pointer to the 2D array
 * 	xsize - the x size of the array (real of rows)
 * Returns:
 *  NULL
 */
void cm_nfree_2d(void **vector, size_t xSize);
/*
 * Abstract:
 * 	Deallocates a 3D array
 * Parameters:
 * 	vector - a pointer to the 3D array
 * 	xsize - the x size of the array (real of rows)
 * 	ysize - the y size of the array (real of columns)
 * Returns:
 *  NULL
 */
void cm_nfree_3d(void ***vector, size_t x_size, size_t y_size);
/*
 * Abstract:
 * 	Deallocates a 4D array
 * Parameters:
 * 	vector - a pointer to the 3D array
 * 	xsize - the x size of the array (real of rows)
 * 	ysize - the y size of the array (real of columns)
 * 	zsize - the z size of the array (real of tables
 * Returns:
 *  NULL
 */
void cm_nfree_4d(void ****vector, size_t x_size, size_t y_size, size_t z_size);


#endif
