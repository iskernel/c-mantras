#ifndef CM_NARRAY_H_
#define CM_NARRAY_H_

#include <stdlib.h>
#include <math.h>
#include "cm_common_numeric.h"

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

void module_cm_narray_initialize();
struct cm_narray* cm_narray_create(integer size);
void cm_narray_destroy(struct cm_narray* array);
real cm_narray_min(const struct cm_narray *array);
real cm_narray_max(const struct cm_narray *array);
real cm_narray_sum(const struct cm_narray* array);
real cm_narray_product(const struct cm_narray* array);
real cm_narray_arithmetic_mean(const struct cm_narray* array);
real cm_narray_geometric_mean(const struct cm_narray* array);
real cm_narray_harmonic_mean(const struct cm_narray* array);

#endif /* CM_NARRAY_H_ */
