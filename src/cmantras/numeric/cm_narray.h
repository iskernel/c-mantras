#ifndef CM_NARRAY_H_
#define CM_NARRAY_H_

#include<stdlib.h>
#include<math.h>
#include "cm_common_numeric.h"

typedef struct
{
   real* data;
   integer size;
}cm_narray;

cm_narray* cm_narray_create(cm_narray* array, integer size);
void cm_narray_destroy(cm_narray* array);
real cm_narray_min(const cm_narray *array);
real cm_narray_max(const cm_narray *array);
real cm_narray_sum(const cm_narray* array);
real cm_narray_product(const cm_narray* array);
real cm_narray_arithemetic_mean(const cm_narray* array);
real cm_narray_geometric_mean(const cm_narray* array);
real cm_narray_harmonic_mean(const cm_narray* array);

#endif /* CM_NARRAY_H_ */
