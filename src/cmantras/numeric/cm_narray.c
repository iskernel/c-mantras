#include "cmantras/base/cm_error_log.h"
#include "cmantras/base/helpers/cm_numeric.h"
#include "cm_narray.h"

#include <stdlib.h>

struct cm_narray* cm_narray_create(integer size)
{
    struct cm_narray* array = NULL;

    array = malloc(sizeof(struct cm_narray));
    cm_error_log_critical_if( (array == NULL), __func__, "not enough memory." );

    array->content = malloc(sizeof(real) * size);
    cm_error_log_critical_if( (array->content == NULL), __func__, "not enough memory." );

    array->size = size;

    return array;
}

void cm_narray_destroy(struct cm_narray* array)
{
    free(array->content);
    free(array);
}

real cm_narray_min(const struct cm_narray *array)
{
    integer index = 0;
    real min_val = array->content[0];

    cm_error_log_critical_if( (array == NULL), __func__, " array is null " );

    for (index = 1; index < array->size; index++)
    {
        if (array->content[index] < min_val)
        {
            min_val = array->content[index];
        }
    }
    return min_val;
}

real cm_narray_max(const struct cm_narray *array)
{
    integer index = 0;
    real max_val = array->content[0];

    cm_error_log_critical_if( (array == NULL), __func__, " array is null " );

    for (index = 1; index < array->size; index++)
    {
        if (array->content[index] > max_val)
        {
            max_val = array->content[index];
        }
    }
    return max_val;
}

real cm_narray_sum(const struct cm_narray* array)
{
    integer index = 0;
    real sum = 0;

    cm_error_log_critical_if( (array == NULL), __func__, " array is null " );

    for (index = 0; index < array->size; index++)
    {
        sum += array->content[index];
    }
    return sum;
}

real cm_narray_product(const struct cm_narray* array)
{
    integer index;
    real product = 1.0;

    cm_error_log_critical_if( (array == NULL), __func__, " array is null " );

    for (index = 0; index < array->size; index++)
    {
        product *= array->content[index];
    }
    return product;
}

real cm_narray_arithmetic_mean(const struct cm_narray* array)
{
    real mean = 0.0;

    cm_error_log_critical_if( (array == NULL), __func__, " array is null " );

    mean = cm_narray_sum(array) / (real) array->size;

    return mean;
}

real cm_narray_geometric_mean(const struct cm_narray* array)
{
    real mean = 0.0;

    cm_error_log_critical_if( (array == NULL), __func__, " array is null " );

    mean = pow(cm_narray_product(array), (1.0f / (real) (array->size)));

    return mean;
}

real cm_narray_harmonic_mean(const struct cm_narray *array)
{
    integer index = 0;
    real sum = 0.0f;
    real mean = 0.0f;

    cm_error_log_critical_if( (array == NULL), __func__, " array is null " );

    for (index = 0; index < array->size; index++)
    {
        sum += 1.0f / array->content[index];
    }
    mean = (real) (array->size) * pow(sum, -1.0f);

    return mean;
}
