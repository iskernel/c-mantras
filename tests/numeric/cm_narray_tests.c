#include <stdbool.h>

#include "cmantras/numeric/cm_common.h"
#include "cmantras/base/helpers/cm_numeric.h"
#include "cmantras/numeric/cm_narray.h"

#include "cm_narray_tests.h"
#include "../cm_test_base.h"


static void cm_narray_create__defined_size__is_created()
{
	struct cm_narray* array = NULL;
	bool condition = false;

	array = cm_narray_create(10);
	condition = (array->size == 10);

	assert_is_true(condition, __func__);
}

static void cm_narray_min__normal_array__is_detected()
{
	struct cm_narray* array = NULL;
	real content[] = {1.0,2.0,3.0,4.0,5.0};
	real min = 0.0;
	bool condition = false;

	array = cm_narray_create(5);
	array->content = content;
	min = cm_narray_min(array);
	condition = (min == 1.0);

	assert_is_true(condition, __func__);
}

static void cm_narray_max__normal_array__is_detected()
{
	struct cm_narray* array = NULL;
	real content[] = {1.0,2.0,3.0,4.0,5.0};
	real max = 0.0;
	bool condition = false;

	array = cm_narray_create(10);
	array->content = content;
	max = cm_narray_max(array);
	condition = (max == 5.0);

	assert_is_true(condition, __func__);
}

static void cm_narray_sum__normal_array__is_computed()
{
	struct cm_narray* array = NULL;
	real content[] = {1.0,2.0,3.0,4.0,5.0};
	real sum = 0.0;
	bool condition = false;

	array = cm_narray_create(10);
	array->content = content;
	sum = cm_narray_sum(array);
	condition = (double_is_within(sum, 14.9, 15.1));

	assert_is_true(condition, __func__);
}

static void cm_narray_product__normal_array__is_computed()
{
	struct cm_narray* array = NULL;
	real content[] = {1.0,2.0,3.0,4.0,5.0};
	real sum = 0.0;
	bool condition = false;

	array = cm_narray_create(5);
	array->content = content;
	sum = cm_narray_product(array);
	condition = (double_is_within(sum, 119.9, 120.1));

	assert_is_true(condition, __func__);
}

static void cm_narray_arithmetic_mean__normal_array__is_computed()
{
	struct cm_narray* array = NULL;
	real content[] = {1.0,2.0,3.0,4.0,5.0};
	real sum = 0.0;
	bool condition = false;

	array = cm_narray_create(5);
	array->content = content;
	sum = cm_narray_arithmetic_mean(array);
	condition = (double_is_within(sum, 2.9, 3.1));

	assert_is_true(condition, __func__);
}

static void cm_narray_geometric_mean__normal_array__is_computed()
{
	struct cm_narray* array = NULL;
	real content[] = {1.0,2.0,3.0,4.0,5.0};
	real sum = 0.0;
	bool condition = false;

	array = cm_narray_create(5);
	array->content = content;
	sum = cm_narray_geometric_mean(array);
	condition = (double_is_within(sum, 2.5, 2.7));

	assert_is_true(condition, __func__);
}

static void cm_narray_harmonic_mean__normal_array__is_computed()
{
	struct cm_narray* array = NULL;
	real content[] = {1.0,2.0,3.0,4.0,5.0};
	real sum = 0.0;
	bool condition = false;

	array = cm_narray_create(5);
	array->content = content;
	sum = cm_narray_harmonic_mean(array);
	condition = (double_is_within(sum, 2.1, 2.2));

	assert_is_true(condition, __func__);
}

void cm_narray_run_tests(void)
{
	cm_narray_create__defined_size__is_created();
	cm_narray_max__normal_array__is_detected();
	cm_narray_min__normal_array__is_detected();
	cm_narray_sum__normal_array__is_computed();
	cm_narray_product__normal_array__is_computed();
	cm_narray_arithmetic_mean__normal_array__is_computed();
	cm_narray_geometric_mean__normal_array__is_computed();
	cm_narray_harmonic_mean__normal_array__is_computed();
}
