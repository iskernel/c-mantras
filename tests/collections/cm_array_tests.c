#include <stdlib.h>
#include <limits.h>

#include "cm_array_tests.h"

#include "cmantras/collections/cm_array.h"
#include "cmantras/base/cm_base_types.h"
#include "../cm_test_base.h"

static void cm_array_create__normal_scenario__is_created(void)
{
	struct cm_array* array = cm_array_create(10);

	bool condition = (array->elements != NULL) && (array->capacity == 10);

	assert_is_true(condition,__func__);

	cm_array_destroy(array);
}

static void cm_array_set__normal_scenario__is_set(void)
{
	struct cm_array* array = cm_array_create(10);
	bool condition = false;

	cm_array_set(array, &(int){3}, 0);
	condition = ( *(int*)array->elements[0] == 3);

	assert_is_true(condition, __func__);

	cm_array_destroy(array);
}

static void cm_array_cancel__normal_scenario__is_removed(void)
{
	struct cm_array* array = cm_array_create(10);
	bool condition = false;

	cm_array_set(array, &(int){3}, 0);
	cm_array_cancel(array, 0);
	condition = ( (array->elements[0] == NULL)  );

	assert_is_true(condition, __func__);

	cm_array_destroy(array);
}

static cm_cmp_size compare_ints(const void* int1, const void* int2)
{
	int val1 = (*(int**)int1 == NULL) ? INT_MAX : (**(int**)int1);
	int val2 = (*(int**)int2 == NULL) ? INT_MAX : (**(int**)int2);
	cm_cmp_size result = val1 - val2;
	return result;
}

static bool are_equal_ints(const void* int1, const void* int2)
{
	bool condition = false;
	if(int1 == NULL && int2 == NULL)
	{
		condition = true;
	}
	else if( ( (int1 == NULL) && (int2 != NULL) ) || ( (int1 != NULL) && (int2 == NULL) ) )
	{
		condition = false;
	}
	else
	{
		condition = ( (*(int*)int1) == (*(int*)int2) );
	}
	return condition;
}

static void cm_array_contain__array_contains_element__is_found(void)
{
	struct cm_array* array = cm_array_create(10);
	bool condition = false;

	cm_array_set(array, &(int){3}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){1}, 2);
	cm_array_set(array, &(int){4}, 3);

	condition = cm_array_contains(array, &(int){2}, &are_equal_ints);

	assert_is_true(condition, __func__);

	cm_array_destroy(array);
}

static void cm_array_contain__array_do_not_contain_element__is_found(void)
{
	struct cm_array* array = cm_array_create(10);
	bool condition = false;

	cm_array_set(array, &(int){3}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){1}, 2);
	cm_array_set(array, &(int){4}, 3);

	condition = cm_array_contains(array, &(int){-10}, &are_equal_ints);

	assert_is_true(!condition, __func__);

	cm_array_destroy(array);
}

static void cm_array_sort__normal_scenario__array_is_sorted(void)
{
	struct cm_array* array = cm_array_create(10);
	bool condition = false;

	cm_array_set(array, &(int){3}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){1}, 2);
	cm_array_set(array, &(int){4}, 3);

	cm_array_sort(array, &compare_ints);
	condition = (*(int*)array->elements[0] == 1) && (*(int*)array->elements[1] == 2)
				 && (*(int*)array->elements[2] == 3) && (*(int*)array->elements[3] == 4);

	assert_is_true(condition, __func__);

	cm_array_destroy(array);
}

static void cm_array_get_first__normal_scenario__is_retrieved(void)
{
	struct cm_array* array = cm_array_create(10);
	int index = 0;
	bool condition = false;

	cm_array_set(array, &(int){3}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){1}, 2);
	cm_array_set(array, &(int){4}, 3);

	index = cm_array_get_first(array, &(int){3}, &are_equal_ints);
	condition = ( index == 0 );

	assert_is_true(condition, __func__);

	cm_array_destroy(array);
}

static void cm_array_get_last__normal_scenario__is_retrieved(void)
{
	struct cm_array* array = cm_array_create(10);
	int index = 0;
	bool condition = false;

	cm_array_set(array, &(int){3}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){1}, 2);
	cm_array_set(array, &(int){3}, 3);

	index = cm_array_get_last(array, &(int){3}, &are_equal_ints);
	condition = ( index == 3 );

	assert_is_true(condition, __func__);

	cm_array_destroy(array);
}

static void cm_array_pack__normal_scenario__is_retrieved(void)
{
	struct cm_array* array = cm_array_create(10);
	bool condition = false;

	cm_array_set(array, &(int){3}, 0);
	cm_array_set(array, &(int){2}, 2);
	cm_array_set(array, &(int){1}, 4);
	cm_array_set(array, &(int){3}, 6);

	cm_array_pack(array);

	condition = (*(int*)array->elements[0] == 3) && (*(int*)array->elements[1] == 2)
			     && (*(int*)array->elements[2] == 1) && (*(int*)array->elements[3] == 3);

	assert_is_true(condition, __func__);

	cm_array_destroy(array);
}

void cm_array_run_tests(void)
{
	cm_array_create__normal_scenario__is_created();
	cm_array_set__normal_scenario__is_set();
	cm_array_cancel__normal_scenario__is_removed();
	cm_array_contain__array_contains_element__is_found();
	cm_array_contain__array_do_not_contain_element__is_found();
	cm_array_sort__normal_scenario__array_is_sorted();
	cm_array_get_first__normal_scenario__is_retrieved();
	cm_array_get_last__normal_scenario__is_retrieved();
	cm_array_pack__normal_scenario__is_retrieved();
}
