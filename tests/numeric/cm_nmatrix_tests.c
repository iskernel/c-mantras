#include <stdlib.h>

#include "cm_nmatrix_tests.h"
#include "../cm_test_base.h"

#include "cmantras/numeric/cm_nmatrix.h"
#include "cmantras/base/helpers/cm_numeric.h"

static void cm_nmatrix_create__create__is_created(void)
{
    struct cm_nmatrix* matrix = NULL;
    matrix = cm_nmatrix_create(3, 3);

    assert_is_true( (matrix != NULL), __func__);

    cm_nmatrix_destroy(matrix);
}

static void cm_nmatrix_copy__copy__is_copied(void)
{
    struct cm_nmatrix* matrix = NULL;
    struct cm_nmatrix* matrix_2 = NULL;
    bool condition = false;

    matrix = cm_nmatrix_create(2, 2);
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    matrix_2 = cm_nmatrix_copy(matrix);

    condition = double_is_within(matrix_2->content[0][0], -0.1, 0.1) && double_is_within(matrix_2->content[1][0], 1.9, 2.1);

    assert_is_true( condition , __func__ );

    cm_nmatrix_destroy(matrix);
    cm_nmatrix_destroy(matrix_2);
}

static void cm_nmatrix_sum__sum__is_calculated(void)
{
    struct cm_nmatrix* matrix = NULL;
    struct cm_nmatrix* matrix_2 = NULL;
    struct cm_nmatrix* matrix_3 = NULL;
    bool condition = false;

    matrix = cm_nmatrix_create(2, 2);
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    matrix_2 = cm_nmatrix_create(2, 2);
    matrix_2->content[0][0] = 0;
    matrix_2->content[0][1] = 1;
    matrix_2->content[1][0] = 2;
    matrix_2->content[1][1] = 3;

    matrix_3 = cm_nmatrix_sum(matrix, matrix_2);

    condition = double_is_within(matrix_3->content[0][0], -0.1, 0.1) && double_is_within(matrix_3->content[1][0], 3.9, 4.1);

    assert_is_true( condition, __func__);

    cm_nmatrix_destroy(matrix);
    cm_nmatrix_destroy(matrix_2);
    cm_nmatrix_destroy(matrix_3);
}

static void cm_nmatrix_multiply_with_scalar__multiply_with_scalar__is_calculated(void)
{
    struct cm_nmatrix* matrix = NULL;
    struct cm_nmatrix* matrix_2 = NULL;
    bool condition = false;

    matrix = cm_nmatrix_create(2, 2);
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    matrix_2 = cm_nmatrix_multiply_with_scalar(matrix, 2);

    condition = double_is_within(matrix_2->content[0][0], -0.1, 0.1) && double_is_within(matrix_2->content[1][0], 3.9, 4.1);

    assert_is_true(condition , __func__);

    cm_nmatrix_destroy(matrix);
    cm_nmatrix_destroy(matrix_2);
}

static void cm_nmatrix_product__product__is_calculated(void)
{
    struct cm_nmatrix* matrix = NULL;
    struct cm_nmatrix* matrix_2 = NULL;
    struct cm_nmatrix* matrix_3 = NULL;
    bool condition = false;

    /*
     0 1
     2 3
     */
    matrix = cm_nmatrix_create(2, 2);
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    /*
     0 1
     2 3
     */
    matrix_2 = cm_nmatrix_create(2, 2);
    matrix_2->content[0][0] = 0;
    matrix_2->content[0][1] = 1;
    matrix_2->content[1][0] = 2;
    matrix_2->content[1][1] = 3;;

    matrix_3 = cm_nmatrix_product(matrix, matrix_2);

    condition = double_is_within(matrix_3->content[0][0], 1.9, 2.1) && double_is_within(matrix_3->content[1][0], 5.9, 6.1);

    assert_is_true( condition , __func__ );

    cm_nmatrix_destroy(matrix);
    cm_nmatrix_destroy(matrix_2);
    cm_nmatrix_destroy(matrix_3);
}

static void cm_nmatrix_get_primary_diagonal_as_array__get_diagonal__is_retrieved(void)
{
    struct cm_narray* array = NULL;
    struct cm_nmatrix* matrix = NULL;

    matrix = cm_nmatrix_create(2, 2);
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    array = cm_nmatrix_get_primary_diagonal_as_array(matrix);

    assert_is_true( ( (array->content[0] == 0) && (array->content[1] == 3) ), __func__ );

    cm_nmatrix_destroy(matrix);
    cm_narray_destroy(array);
}

static void cm_nmatrix_get_secondary_diagonal_as_array__get_diagonal__is_retrieved(void)
{
    struct cm_narray* array = NULL;
    struct cm_nmatrix* matrix = NULL;

    matrix = cm_nmatrix_create(2, 2);
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    array = cm_nmatrix_get_secondary_diagonal_as_array(matrix);

    assert_is_true( ( (array->content[0] == 1) && (array->content[1] == 2) ), __func__ );

    cm_nmatrix_destroy(matrix);
    cm_narray_destroy(array);
}

static void cn_nmatrix_minor__get_minor__is_retrieved(void)
{
    struct cm_nmatrix* matrix = NULL;
    struct cm_nmatrix* minor = NULL;

    matrix = cm_nmatrix_create(3, 3);
    /*
     0 1 2
     3 4 5
     6 7 8
     */
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[0][2] = 2;
    matrix->content[1][0] = 3;
    matrix->content[1][1] = 4;
    matrix->content[1][2] = 5;
    matrix->content[2][0] = 6;
    matrix->content[2][1] = 7;
    matrix->content[2][2] = 8;

    minor = cm_nmatrix_get_minor(matrix, 0, 0, 2);

    assert_is_true( ( (minor->content[0][0] == 4) && (minor->content[1][1] == 8) ), __func__ );

    cm_nmatrix_destroy(matrix);
    cm_nmatrix_destroy(minor);
}

static void cm_nmatrix_get_determinant__get_determinant__is_retrieved(void)
{
    struct cm_nmatrix* matrix = NULL;
    double determinant = 0.0;

    matrix = cm_nmatrix_create(2, 2);
    /*
     0 1
     2 3
     */
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    determinant = cm_nmatrix_get_determinant(matrix, 2);

    assert_is_true( (determinant == -2), __func__ );

    cm_nmatrix_destroy(matrix);
}

static void cn_nmatrix_transpose__get_transpose__is_retrieved(void)
{
    struct cm_nmatrix* matrix = NULL;
    struct cm_nmatrix* transpose = NULL;

    matrix = cm_nmatrix_create(2, 2);
    /*
     0 1
     2 3
     */
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    transpose = cm_nmatrix_get_transpose(matrix);

    assert_is_true( ( (transpose->content[0][1] == 2) && (transpose->content[1][0] == 1) ), __func__ );

    cm_nmatrix_destroy(matrix);
    cm_nmatrix_destroy(transpose);
}

static void cn_nmatrix_adjugate__get_adjugate__is_retrieved(void)
{
    struct cm_nmatrix* matrix = NULL;
    struct cm_nmatrix* adjugate = NULL;

    matrix = cm_nmatrix_create(2, 2);
    /*
     0 1
     2 3
     */
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    adjugate = cm_nmatrix_get_adjugate(matrix);

    assert_is_true( ( (adjugate->content[0][0] == 3) && (adjugate->content[1][1] == 0) ), __func__ );

    cm_nmatrix_destroy(matrix);
    cm_nmatrix_destroy(adjugate);
}

static void cn_nmatrix_inverse__get_inverse__is_retrieved(void)
{
    struct cm_nmatrix* matrix = NULL;
    struct cm_nmatrix* adjugate = NULL;

    matrix = cm_nmatrix_create(2, 2);
    /*
     0 1
     2 3
     */
    matrix->content[0][0] = 0;
    matrix->content[0][1] = 1;
    matrix->content[1][0] = 2;
    matrix->content[1][1] = 3;

    adjugate = cm_nmatrix_get_inverse(matrix);

    assert_is_true( ( (adjugate->content[0][0] == -1.5) && (adjugate->content[1][1] == 0) ), __func__ );

    cm_nmatrix_destroy(matrix);
    cm_nmatrix_destroy(adjugate);
}

void cn_matrix_run_tests(void)
{
    cm_nmatrix_create__create__is_created();
    cm_nmatrix_copy__copy__is_copied();
    cm_nmatrix_sum__sum__is_calculated();
    cm_nmatrix_multiply_with_scalar__multiply_with_scalar__is_calculated();
    cm_nmatrix_product__product__is_calculated();
    cm_nmatrix_get_primary_diagonal_as_array__get_diagonal__is_retrieved();
    cm_nmatrix_get_secondary_diagonal_as_array__get_diagonal__is_retrieved();
    cn_nmatrix_minor__get_minor__is_retrieved();
    cm_nmatrix_get_determinant__get_determinant__is_retrieved();
    cn_nmatrix_transpose__get_transpose__is_retrieved();
    cn_nmatrix_adjugate__get_adjugate__is_retrieved();
    cn_nmatrix_inverse__get_inverse__is_retrieved();
}
