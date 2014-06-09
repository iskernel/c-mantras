#include "cmantras/base/cm_error_log.h"
#include "cm_nmatrix.h"


struct cm_nmatrix* cm_nmatrix_create(integer rows, integer columns)
{
    struct cm_nmatrix* matrix = NULL;
    integer i = 0;

    matrix = malloc(sizeof(struct cm_nmatrix));
    cm_error_log_critical_if((matrix == NULL), __func__, " not enough memory ");

    if (matrix != NULL)
    {
        matrix->rows = rows;
        matrix->columns = columns;
        matrix->content = malloc(rows * sizeof(real*));
        cm_error_log_critical_if((matrix->content == NULL), __func__,
                                 " not enough memory ");
        for (i = 0; i < rows; i++)
        {
            matrix->content[i] = malloc(columns * sizeof(real));
            cm_error_log_critical_if((matrix->content[i] == NULL), __func__,
                                     " not enough memory ");
        }
    }
    return matrix;
}

void cm_nmatrix_destroy(struct cm_nmatrix *matrix)
{
    integer index = 0;

    cm_error_log_critical_if((matrix == NULL), __func__, " matrix is null ");

    for (index = 0; index < matrix->rows; index++)
    {
        free(matrix->content[index]);
    }
    free(matrix->content);
    free(matrix);
}

struct cm_nmatrix* cm_nmatrix_copy(const struct cm_nmatrix *source)
{
    integer i = 0, j = 0;
    struct cm_nmatrix* result = NULL;

    cm_error_log_critical_if((source == NULL), __func__, " matrix is null ");

    result = cm_nmatrix_create(source->rows, source->columns);
    if (result != NULL)
    {
        for (i = 0; i < source->rows; i++)
        {
            for (j = 0; j < source->columns; j++)
            {
                result->content[i][j] = source->content[i][j];
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

    cm_error_log_critical_if((mat1 == NULL), __func__, " mat1 is null ");
    cm_error_log_critical_if((mat1 == NULL), __func__, " mat2 is null ");
    cm_error_log_critical_if(
            ((mat1->rows != mat2->rows) || (mat1->columns != mat2->columns)),
            __func__, "mat1 and mat2 do not have the same size");

    result = cm_nmatrix_create(mat1->rows, mat1->columns);
    for (i = 0; i < mat1->rows; i++)
    {
        for (j = 0; j < mat1->columns; j++)
        {
            result->content[i][j] = mat1->content[i][j] + mat2->content[i][j];
        }
    }
    return result;
}

struct cm_nmatrix* cm_nmatrix_multiply_with_scalar(const struct cm_nmatrix* mat,
                                                   real value)
{
    integer index_i = 0;
    integer index_j = 0;

    cm_error_log_critical_if((mat == NULL), __func__, " mat1 is null ");

    struct cm_nmatrix *smat = NULL;
    smat = cm_nmatrix_copy(mat);
    for (index_i = 0; index_i < mat->rows; index_i++)
    {
        for (index_j = 0; index_j < mat->columns; index_j++)
        {
            smat->content[index_i][index_j] *= value;
        }
    }
    return smat;
}

struct cm_nmatrix* cm_nmatrix_product(const struct cm_nmatrix* mat1,
                                      const struct cm_nmatrix* mat2)
{
    integer i = 0, j = 0, k = 0, p = 0;
    struct cm_nmatrix *result = NULL;

    cm_error_log_critical_if((mat1 == NULL), __func__, " mat1 is null ");
    cm_error_log_critical_if((mat1 == NULL), __func__, " mat2 is null ");
    cm_error_log_critical_if(
            ((mat1->rows != mat2->columns)), __func__,
            "mat1 rows and mat2 columns do not have the same size");

    result = cm_nmatrix_create(mat1->rows, mat2->columns);
    for (i = 0; i < mat1->rows; i++)
    {
        for (j = 0; j < mat2->columns; j++)
        {
            p = 0;
            for (k = 0; k < mat1->columns; k++)
            {
                p += mat1->content[i][k] * mat2->content[k][j];
            }
            result->content[i][j] = p;
        }
    }
    return result;
}

struct cm_narray* cm_nmatrix_get_primary_diagonal_as_array(
        const struct cm_nmatrix *mat)
{
    integer i = 0;

    cm_error_log_critical_if((mat == NULL), __func__, " mat1 is null ");

    struct cm_narray *array = NULL;
    if (mat->rows == mat->columns)
    {
        array = cm_narray_create(mat->rows);
        for (i = 0; i < mat->rows; i++)
        {
            array->content[i] = mat->content[i][i];
        }
    }
    return array;
}

struct cm_narray* cm_nmatrix_get_secondary_diagonal_as_array(
        const struct cm_nmatrix* mat)
{
    integer i = 0;

    cm_error_log_critical_if((mat == NULL), __func__, " mat1 is null ");

    struct cm_narray *array = NULL;
    if (mat->rows == mat->columns)
    {
        array = cm_narray_create(mat->rows);
        for (i = 0; i < mat->rows; i++)
        {
            array->content[i] = mat->content[i][mat->rows - 1 - i];
        }
    }
    return array;
}

struct cm_nmatrix* cm_nmatrix_get_minor(const struct cm_nmatrix *mat, integer row,
                                        integer column, integer order)
{
    integer i = 0, j = 0;
    integer rowCount = 0, colCount = 0;
    struct cm_nmatrix *minor = NULL;

    cm_error_log_critical_if((mat == NULL), __func__, " mat1 is null ");
    cm_error_log_critical_if(
            ((mat->rows == mat->columns) && ((row - 1) < order)
                    && ((column - 1) < order) && (order >= 1)
                    && (order < mat->rows)) == false,
            __func__, "matrix is not square or parameters are not correct");

    if (order == 1)
    {
        minor = cm_nmatrix_create(1, 1);
        minor->content[0][0] = mat->content[row][column];
    }
    else
    {
        minor = cm_nmatrix_create(order, order);
        for (i = 0; i <= order; i++)
        {
            if (i != row)
            {
                colCount = 0;
                for (j = 0; j <= order; j++)
                {
                    if (j != column)
                    {
                        minor->content[rowCount][colCount] = mat->content[i][j];
                        colCount++;
                    }
                }
                rowCount++;
            }
        }
    }
    return minor;
}

real cm_nmatrix_get_determinant(const struct cm_nmatrix *mat, integer order)
{
    integer i = 0, j = 0, k = 0, l = 0;
    real det = 0.0f;
    struct cm_nmatrix *minor = NULL;

    cm_error_log_critical_if((mat == NULL), __func__, " mat is null ");
    cm_error_log_critical_if(
            ((mat->rows == mat->columns) && (order >= 1) && (order <= mat->rows))
                    == false,
            __func__, "matrix is not square or order is not valid ");

    if (order == 1)
    {
        det = mat->content[0][0];
    }
    else
    {
        for (k = 0; k < order; k++)
        {
            minor = cm_nmatrix_create(order, order);
            for (i = 1; i < order; i++)
            {
                l = 0;
                for (j = 0; j < order; j++)
                {
                    if (j != k)
                    {
                        minor->content[i - 1][l] = mat->content[i][j];
                        l++;
                    }
                }
            }
            det += pow(-1.0, k) * mat->content[0][k]
                    * cm_nmatrix_get_determinant(minor, order - 1);
            cm_nmatrix_destroy(minor);
        }
    }
    return det;
}

struct cm_nmatrix* cm_nmatrix_get_transpose(const struct cm_nmatrix* mat)
{
    integer i = 0, j = 0;
    struct cm_nmatrix* transpose = NULL;

    cm_error_log_critical_if((mat == NULL), __func__, " mat is null ");

    transpose = cm_nmatrix_create(mat->columns, mat->rows);
    for (i = 0; i < transpose->rows; i++)
    {
        for (j = 0; j < transpose->columns; j++)
        {
            transpose->content[i][j] = mat->content[j][i];
        }
    }
    return transpose;
}

struct cm_nmatrix* cm_nmatrix_get_adjugate(const struct cm_nmatrix* mat)
{
    integer i = 0, j = 0, dim = 0;
    real det = 0.0f;
    struct cm_nmatrix* minor = NULL;
    struct cm_nmatrix* cofactor = NULL;

    cm_error_log_critical_if((mat == NULL), __func__, " matrix is null ");
    cm_error_log_critical_if((mat->columns != mat->rows), __func__,
                             " matrix is not square ");

    dim = mat->columns;
    cofactor = cm_nmatrix_create(dim, dim);
    for (j = 0; j < dim; j++)
    {
        for (i = 0; i < dim; i++)
        {
            minor = cm_nmatrix_get_minor(mat, i, j, dim - 1);
            det = cm_nmatrix_get_determinant(minor, dim - 1);
            cofactor->content[dim - i - 1][dim - j - 1] = pow(-1.0f, i + j + 2.0f) * det;
        }
    }
    return cofactor;
}

struct cm_nmatrix* cm_nmatrix_get_inverse(struct cm_nmatrix* mat)
{
    struct cm_nmatrix* inv = NULL;
    real det = 0.0f;
    real coeficent = 0.0f;

    cm_error_log_critical_if((mat == NULL), __func__, " matrix is null ");
    cm_error_log_critical_if((mat->columns != mat->rows), __func__,
                                " matrix is not square ");

    det = cm_nmatrix_get_determinant(mat, mat->rows);
    if (det != 0.0f)
    {
        inv = cm_nmatrix_create(mat->rows, mat->columns);
        coeficent = 1.0f / cm_nmatrix_get_determinant(mat, mat->rows);
        inv = cm_nmatrix_get_adjugate(mat);
        inv = cm_nmatrix_multiply_with_scalar(inv, coeficent);
    }
    return inv;
}

