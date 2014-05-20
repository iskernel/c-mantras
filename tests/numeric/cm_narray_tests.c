#include <stdbool.h>

#include "../cm_test_base.h"
#include "cm_narray_tests.h"
#include "cmantras/base/cm_helpers.h"
#include "cmantras/numeric/cm_narray.h"

static void cm_narray_create__defined_size__is_created()
{
	struct cm_narray* array = NULL;
	bool condition = false;

	array = cm_narray_create(10);
	condition = (array->data->size == 10);

	assert_is_true(condition, __func__);
}

static void cm_narray_min__normal_array__is_detected()
{
	struct cm_narray* array = NULL;
	real content[] = {1.0,2.0,3.0,4.0,5.0};
	real min = 0.0;
	bool condition = false;

	array = cm_narray_create(5);
	array->data->content = content;
	min = array->methods->min(array);
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
	array->data->content = content;
	max = array->methods->max(array);
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
	array->data->content = content;
	sum = array->methods->sum(array);
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
	array->data->content = content;
	sum = array->methods->product(array);
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
	array->data->content = content;
	sum = array->methods->arithmetic_mean(array);
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
	array->data->content = content;
	sum = array->methods->geometric_mean(array);
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
	array->data->content = content;
	sum = array->methods->harmonic_mean(array);
	condition = (double_is_within(sum, 2.1, 2.2));

	assert_is_true(condition, __func__);
}

void cm_array_run_tests(void)
{
	module_cm_narray_initialize();
	cm_narray_create__defined_size__is_created();
	cm_narray_max__normal_array__is_detected();
	cm_narray_min__normal_array__is_detected();
	cm_narray_sum__normal_array__is_computed();
	cm_narray_product__normal_array__is_computed();
	cm_narray_arithmetic_mean__normal_array__is_computed();
	cm_narray_geometric_mean__normal_array__is_computed();
	cm_narray_harmonic_mean__normal_array__is_computed();
}
