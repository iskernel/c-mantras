#include "cmantras/base/helpers/cm_numeric.h"
#include "cm_narray.h"

#include <stdlib.h>

struct cm_interface_narray CM_NARRAY_INTERFACE;

struct cm_narray* cm_narray_create(integer size)
{
    struct cm_narray* array = NULL;

    array = malloc(sizeof(struct cm_narray));
    array->data = malloc(sizeof(struct cm_narray_data));
    array->data->content = malloc(sizeof(real) * size);
    array->data->size = size;
    array->methods = &CM_NARRAY_INTERFACE;

    return array;
}

void cm_narray_destroy(struct cm_narray* array)
{
    free(array->data);
    free(array);
}

real cm_narray_min(const struct cm_narray *array)
{
    integer index = 0;
    real min_val = array->data->content[0];
    for (index = 1; index < array->data->size; index++)
    {
        if (array->data->content[index] < min_val)
        {
            min_val = array->data->content[index];
        }
    }
    return min_val;
}

real cm_narray_max(const struct cm_narray *array)
{
    integer index = 0;
    real max_val = array->data->content[0];
    for (index = 1; index < array->data->size; index++)
    {
        if (array->data->content[index] > max_val)
        {
            max_val = array->data->content[index];
        }
    }
    return max_val;
}

real cm_narray_sum(const struct cm_narray* array)
{
    integer index = 0;
    real sum = 0;
    for (index = 0; index < array->data->size; index++)
    {
        sum += array->data->content[index];
    }
    return sum;
}

real cm_narray_product(const struct cm_narray* array)
{
    integer index;
    real product = 1.0;
    for (index = 0; index < array->data->size; index++)
    {
        product *= array->data->content[index];
    }
    return product;
}

real cm_narray_arithmetic_mean(const struct cm_narray* array)
{
    real mean = cm_narray_sum(array) / (real) array->data->size;
    return mean;
}

real cm_narray_geometric_mean(const struct cm_narray* array)
{
    real mean = pow(cm_narray_product(array),
                    (1.0f / (real) (array->data->size)));
    return mean;
}

real cm_narray_harmonic_mean(const struct cm_narray *array)
{
    integer index = 0;
    real sum = 0.0f;
    real mean = 0.0f;
    for (index = 0; index < array->data->size; index++)
    {
        sum += 1.0f / array->data->content[index];
    }
    mean = (real) (array->data->size) * pow(sum, -1.0f);
    return mean;
}

void module_cm_narray_initialize()
{
    CM_NARRAY_INTERFACE.arithmetic_mean = &cm_narray_arithmetic_mean;
    CM_NARRAY_INTERFACE.geometric_mean = &cm_narray_geometric_mean;
    CM_NARRAY_INTERFACE.harmonic_mean = &cm_narray_harmonic_mean;
    CM_NARRAY_INTERFACE.max = &cm_narray_max;
    CM_NARRAY_INTERFACE.min = &cm_narray_min;
    CM_NARRAY_INTERFACE.product = &cm_narray_product;
    CM_NARRAY_INTERFACE.sum = &cm_narray_sum;
}
