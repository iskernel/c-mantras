#ifndef CM_NMATRIX_H_
#define CM_NMATRIX_H_

#include <stdlib.h>
#include <limits.h>
#include "cm_common_numeric.h"
#include "cm_narray.h"

typedef struct
{
   real** data;
   integer rows;
   integer columns;
}cm_nmatrix;

cm_nmatrix* nmatrix_create(cm_nmatrix *matrix, integer rows, integer columns);
cm_nmatrix* nmatrix_destroy(cm_nmatrix *matrix);
cm_nmatrix* nmatrix_copy(const cm_nmatrix *source, cm_nmatrix *dest);
cm_nmatrix* nmatrix_add(const cm_nmatrix* matrix1,const cm_nmatrix* matrix2);
cm_nmatrix* nmatrix_multiply_with_scalar(const cm_nmatrix* matrix, real value);
cm_nmatrix* nmatrix_muliply(const cm_nmatrix* matrix1,const cm_nmatrix* matrix2);
cm_narray* nmatrix_get_secondary_diagonal_as_array(cm_nmatrix* matrix);
cm_narray* nmatrix_get_primary_diagonal_as_array(cm_nmatrix *matrix);
cm_nmatrix* nmatrix_get_minor(const cm_nmatrix *matrix, integer row, integer column, integer order);
real nmatrix_get_determinant(const cm_nmatrix *matrix, integer order);
cm_nmatrix* nmatrix_get_transpose(const cm_nmatrix* matrix);
cm_nmatrix* nmatrix_get_adjugate(const cm_nmatrix* matrix);
cm_nmatrix* nmatrix_get_inverse(cm_nmatrix* matrix);

#endif /* NMATRIX_H_ */
