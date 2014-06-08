#include <stdlib.h>

#include "cmantras/base/cm_error_log.h"

#include "cm_nalloc.h"

void* cm_nalloc_1d(void* vector, size_t x_size, size_t element_size)
{
    vector = malloc(sizeof(element_size) * x_size);

    return vector;
}

void cm_nfree_1d(void* vector)
{
    free(vector);
}

void** cm_nalloc_2d(void **vector, size_t x_size, size_t y_size,
                    size_t element_size)
{
    size_t index;
    vector = malloc(y_size * x_size * element_size);
    for (index = 0; index < x_size; index++)
    {
        vector[index] = malloc(element_size * y_size);
    }
    return vector;
}

void cm_nfree_2d(void **vector, size_t x_size)
{
    size_t index;

    for (index = 0; index < x_size; index++)
    {
        free(vector[index]);
    }
    free(vector);
}

void*** cm_nalloc_3d(void ***vector, size_t x_size, size_t y_size,
                     size_t z_size, size_t element_size)
{
    size_t index_i;
    size_t index_j;

    vector = malloc(y_size * z_size * x_size * element_size);
    for (index_i = 0; index_i < x_size; index_i++)
    {
        vector[index_i] = malloc(z_size * y_size * element_size);
        for (index_j = 0; index_j < y_size; index_j++)
        {
            vector[index_i][index_j] = malloc(element_size * z_size);
        }
    }
    return vector;
}

void cm_nfree_3d(void ***vector, size_t x_size, size_t y_size)
{
    size_t index_i;
    size_t index_j;

    for (index_i = 0; index_i < x_size; index_i++)
    {
        for (index_j = 0; index_j < y_size; index_j++)
        {
            free(vector[index_i][index_j]);
        }
    }
    for (index_i = 0; index_i < x_size; index_i++)
    {
        free(vector[index_i]);
    }
    free(vector);
}

void**** cm_nalloc_4d(void ****vector, size_t x_size, size_t y_size,
                      size_t z_size, size_t t_size, size_t element_size)
{
    int i, j, k;
    vector = malloc(t_size * z_size * y_size * x_size * element_size);
    for (i = 0; i < x_size; i++)
    {
        vector[i] = malloc(t_size * z_size * y_size * element_size);
        for (j = 0; j < y_size; j++)
        {
            vector[i][j] = malloc(t_size * z_size * element_size);
            for (k = 0; k < z_size; k++)
            {
                vector[i][j][k] = malloc(t_size * element_size);
            }
        }
    }
    return vector;
}

void cm_nfree_4d(void**** vector, size_t x_size, size_t y_size, size_t z_size)
{
    size_t index_i;
    size_t index_j;
    size_t index_k;

    for (index_i = 0; index_i < x_size; index_i++)
    {
        for (index_j = 0; index_j < y_size; index_j++)
        {
            for (index_k = 0; index_k < z_size; index_k++)
            {
                free(vector[index_i][index_j][index_k]);
            }
        }
    }
    for (index_i = 0; index_i < x_size; index_i++)
    {
        for (index_j = 0; index_j < y_size; index_j++)
        {
            free(vector[index_i][index_j]);
        }
    }
    for (index_i = 0; index_i < x_size; index_i++)
    {
        free(vector[index_i]);
    }
    free(vector);
}

