#include "cm_nmatrix.h"

struct cm_interface_nmatrix CM_NARRAY_INTERFACE;

struct cm_nmatrix* cm_nmatrix_create(struct cm_nmatrix *matrix, integer rows,
                                     integer columns)
{
    integer i = 0;
    matrix = malloc(sizeof(struct cm_nmatrix));
    if (matrix != NULL)
    {
        matrix->data->rows = rows;
        matrix->data->columns = columns;
        matrix->data->content = malloc(rows * sizeof(real*));
        matrix->methods = &CM_NARRAY_INTERFACE;
        for (i = 0; i < rows; i++)
        {
            matrix->data->content[i] = malloc(columns * sizeof(real));
        }
    }
    return matrix;
}

void cm_nmatrix_destroy(struct cm_nmatrix *matrix)
{
    integer index = 0;
    for (index = 0; index < matrix->data->rows; index++)
    {
        free(matrix->data->content[index]);
    }
    free(matrix->data);
    free(matrix);
}

struct cm_nmatrix* cm_nmatrix_copy(const struct cm_nmatrix *source)
{
    integer i = 0, j = 0;
    struct cm_nmatrix* result = NULL;

    result = cm_nmatrix_create(result, source->data->rows,
                               source->data->columns);
    if (result != NULL)
    {
        for (i = 0; i < source->data->rows; i++)
        {
            for (j = 0; j < source->data->columns; j++)
            {
                result->data->content[i][j] = source->data->content[i][j];
            }
        }
    }
    return result;
}

struct cm_nmatrix* cm_nmatrix_sum(const struct cm_nmatrix* mat1,
                                  const struct cm_nmatrix* mat2)
{
    integer i = 0, j = 0;
    struct cm_nmatrix *result = NULL;
    if ((mat1->data->rows == mat2->data->rows)
            && (mat1->data->columns == mat2->data->columns))
    {
        result = cm_nmatrix_create(result, mat1->data->rows,
                                   mat1->data->columns);
        for (i = 0; i < mat1->data->rows; i++)
        {
            for (j = 0; j < mat1->data->columns; j++)
            {
                result->data->content[i][j] = mat1->data->content[i][j]
                        + mat2->data->content[i][j];
            }
        }
    }
    return result;
}

struct cm_nmatrix* cm_nmatrix_multiply_with_scalar(const struct cm_nmatrix* mat,
                                                   real value)
{
    integer index_i = 0;
    integer index_j = 0;
    struct cm_nmatrix *smat = NULL;
    smat = cm_nmatrix_copy(mat);
    for (index_i = 0; index_i < mat->data->rows; index_i++)
    {
        for (index_j = 0; index_j < mat->data->columns; index_j++)
        {
            smat->data->content[index_i][index_j] *= value;
        }
    }
    return smat;
}

struct cm_nmatrix* cm_nmatrix_product(const struct cm_nmatrix* mat1,
                                      const struct cm_nmatrix* mat2)
{
    integer i = 0, j = 0, k = 0, p = 0;
    struct cm_nmatrix *result = NULL;
    if (mat1->data->rows == mat2->data->columns)
    {
        result = cm_nmatrix_create(result, mat1->data->rows,
                                   mat2->data->columns);
        for (i = 0; i < mat1->data->rows; i++)
        {
            for (j = 0; j < mat2->data->columns; j++)
            {
                p = 0;
                for (k = 0; k < mat1->data->columns; k++)
                {
                    p += mat1->data->content[i][k] * mat2->data->content[k][j];
                }
                result->data->content[i][j] = p;
            }
        }
    }
    return result;
}

struct cm_narray* cm_nmatrix_get_primary_diagonal_as_array(
        const struct cm_nmatrix *mat)
{
    integer i = 0;
    struct cm_narray *array = NULL;
    if (mat->data->rows == mat->data->columns)
    {
        array = cm_narray_create(mat->data->rows);
        for (i = 0; i < mat->data->rows; i++)
        {
            array->data->content[i] = mat->data->content[i][i];
        }
    }
    return array;
}

struct cm_narray* cm_nmatrix_get_secondary_diagonal_as_array(
        const struct cm_nmatrix* mat)
{
    integer i = 0;
    struct cm_narray *array = NULL;
    if (mat->data->rows == mat->data->columns)
    {
        array = cm_narray_create(mat->data->rows);
        for (i = 0; i < mat->data->rows; i++)
        {
            array->data->content[i] = mat->data->content[i][mat->data->rows - 1
                    - i];
        }
    }
    return array;
}

struct cm_nmatrix* cm_nmatrix_minor(const struct cm_nmatrix *mat, integer row,
                                    integer column, integer order)
{
    integer i = 0, j = 0;
    integer rowCount = 0, colCount = 0;
    struct cm_nmatrix *minor = NULL;

    if ((mat->data->rows == mat->data->columns) && ((row - 1) < order)
            && ((column - 1) < order) && (order >= 1)
            && (order < mat->data->rows))
    {
        if (order == 1)
        {
            minor = cm_nmatrix_create(minor, 1, 1);
            minor->data->content[0][0] = mat->data->content[row][column];
        }
        else
        {
            minor = cm_nmatrix_create(minor, order, order);
            for (i = 0; i <= order; i++)
            {
                if (i != row)
                {
                    colCount = 0;
                    for (j = 0; j <= order; j++)
                    {
                        if (j != column)
                        {
                            minor->data->content[rowCount][colCount] =
                                    mat->data->content[i][j];
                            colCount++;
                        }
                    }
                    rowCount++;
                }
            }
        }
    }
    return minor;
}

real cm_nmatrix_determinant(const struct cm_nmatrix *mat, integer order)
{
    integer i = 0, j = 0, k = 0, l = 0;
    real det = 0.0f;
    struct cm_nmatrix *minor = NULL;
    if ((mat->data->rows == mat->data->columns) && (order >= 1)
            && (order <= mat->data->rows))
    {
        if (order == 1)
        {
            det = mat->data->content[0][0];
        }
        else
        {
            for (k = 0; k < order; k++)
            {
                minor = cm_nmatrix_create(minor, order, order);
                for (i = 1; i < order; i++)
                {
                    l = 0;
                    for (j = 0; j < order; j++)
                    {
                        if (j != k)
                        {
                            minor->data->content[i - 1][l] =
                                    mat->data->content[i][j];
                            l++;
                        }
                    }
                }
                det += pow(-1.0, k) * mat->data->content[0][k]
                        * cm_nmatrix_determinant(minor, order - 1);
                cm_nmatrix_destroy(minor);
            }
        }
    }
    else
    {
        det = NAN;
    }
    return det;
}

struct cm_nmatrix* cm_nmatrix_transpose(const struct cm_nmatrix* mat)
{
    integer i = 0, j = 0;
    struct cm_nmatrix* transpose = NULL;
    transpose = cm_nmatrix_create(transpose, mat->data->columns,
                                  mat->data->rows);
    for (i = 0; i < transpose->data->rows; i++)
    {
        for (j = 0; j < transpose->data->columns; j++)
        {
            transpose->data->content[i][j] = mat->data->content[j][i];
        }
    }
    return transpose;
}

struct cm_nmatrix* cm_nmatrix_adjugate(const struct cm_nmatrix* mat)
{
    integer i = 0, j = 0, dim = 0;
    real det = 0.0f;
    struct cm_nmatrix* minor = NULL;
    struct cm_nmatrix* cofactor = NULL;
    if (mat->data->columns == mat->data->rows)
    {
        dim = mat->data->columns;
        cofactor = cm_nmatrix_create(cofactor, dim, dim);
        for (j = 0; j < dim; j++)
        {
            for (i = 0; i < dim; i++)
            {
                minor = cm_nmatrix_minor(mat, i, j, dim - 1);
                det = cm_nmatrix_determinant(minor, dim - 1);
                cofactor->data->content[i][j] = pow(-1.0f, i + j + 2.0f) * det;
            }
        }
    }
    return cofactor;
}

struct cm_nmatrix* cm_nmatrix_inverse(struct cm_nmatrix* mat)
{
    struct cm_nmatrix* inv = NULL;
    real det = 0.0f;
    real coeficent = 0.0f;
    if (mat->data->rows == mat->data->columns)
    {
        det = cm_nmatrix_determinant(mat, mat->data->rows);
        if (det != 0.0f)
        {
            inv = cm_nmatrix_create(inv, mat->data->rows, mat->data->columns);
            coeficent = 1.0f / cm_nmatrix_determinant(mat, mat->data->rows);
            inv = cm_nmatrix_adjugate(mat);
            inv = cm_nmatrix_multiply_with_scalar(inv, coeficent);
        }
    }
    return inv;
}

