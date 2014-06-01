#include "../cm_test_base.h"
#include "cm_searching_tests.h"

#include "cmantras/base/cm_base_types.h"
#include "cmantras/collections/cm_array.h"
#include "cmantras/collections/cm_searching.h"

static cm_cmp_size compare_ints(const void* int1, const void* int2)
{
	int val1 = *(int*)(int1);
	int val2 = *(int*)(int2);
	cm_cmp_size result = val1 - val2;
	return result;
}

static void cm_search_array_linear__element_exists__is_found(void)
{
	struct cm_array* array = cm_array_create(10);
	cm_index index = - 1;

	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_linear(&(int){2}, array->elements, 5, &compare_ints);

	assert_is_true( (index  == 1), __func__);

	cm_array_destroy(array);
}

static void cm_search_array_sentinel_linear__element_exists__is_found(void)
{
	struct cm_array* array = cm_array_create(10);

	cm_index index = - 1;
	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_sentinel_linear(&(int){2}, array->elements, 5, &compare_ints);

	assert_is_true( (index == 1), __func__);

	cm_array_destroy(array);
}

static void cm_search_array_binary__element_exists__is_found(void)
{
	struct cm_array* array = cm_array_create(10);

	cm_index index = - 1;
	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_binary(&(int){2}, array->elements, 5, &compare_ints);

	assert_is_true( (index == 1), __func__);

	cm_array_destroy(array);
}

static void cm_search_array_improved_binary__element_exists__is_found(void)
{
	struct cm_array* array = cm_array_create(10);

	cm_index index = - 1;
	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_improved_binary(&(int){2}, array->elements, 5, &compare_ints);

	assert_is_true( (index == 1), __func__);

	cm_array_destroy(array);
}

static void cm_search_array_interpolation__element_exists__is_found(void)
{
	struct cm_array* array = cm_array_create(10);

	cm_index index = - 1;
	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_interpolation(&(int){2}, array->elements, 5, &compare_ints);

	assert_is_true( (index == 1), __func__);

	cm_array_destroy(array);
}

static void cm_search_array_linear__element_does_not_exist__not_found(void)
{
	struct cm_array* array = cm_array_create(10);
	cm_index index = - 1;

	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_linear(&(int){-1}, array->elements, 5, &compare_ints);

	assert_is_true( (index  == -1), __func__);

	cm_array_destroy(array);
}

static void cm_search_array_sentinel_linear__element_does_not_exist__not_found(void)
{
	struct cm_array* array = cm_array_create(10);

	cm_index index = - 1;
	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_sentinel_linear(&(int){-1}, array->elements, 5, &compare_ints);

	assert_is_true( (index == -1), __func__);

	cm_array_destroy(array);
}

static void cm_search_array_binary__element_does_not_exist__not_found(void)
{
	struct cm_array* array = cm_array_create(10);

	cm_index index = - 1;
	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_binary(&(int){-1}, array->elements, 5, &compare_ints);

	assert_is_true( (index == -1), __func__);

	cm_array_destroy(array);
}

static void cm_search_array_improved_binary__element_does_not_exist__not_found(void)
{
	struct cm_array* array = cm_array_create(10);

	cm_index index = - 1;
	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_improved_binary(&(int){-1}, array->elements, 5, &compare_ints);

	assert_is_true( (index == -1), __func__);

	cm_array_destroy(array);
}

static void cm_search_array_interpolation__element_does_not_exist__not_found(void)
{
	struct cm_array* array = cm_array_create(10);

	cm_index index = - 1;
	cm_array_set(array, &(int){1}, 0);
	cm_array_set(array, &(int){2}, 1);
	cm_array_set(array, &(int){3}, 2);
	cm_array_set(array, &(int){4}, 3);
	cm_array_set(array, &(int){5}, 4);
	index = cm_search_array_interpolation(&(int){-1}, array->elements, 5, &compare_ints);

	assert_is_true( (index == -1), __func__);

	cm_array_destroy(array);
}

void cm_searching_run_tests(void)
{
	cm_search_array_linear__element_exists__is_found();
	cm_search_array_sentinel_linear__element_exists__is_found();
	cm_search_array_binary__element_exists__is_found();
	cm_search_array_improved_binary__element_exists__is_found();
	cm_search_array_interpolation__element_exists__is_found();
	cm_search_array_linear__element_does_not_exist__not_found();
	cm_search_array_sentinel_linear__element_does_not_exist__not_found();
	cm_search_array_binary__element_does_not_exist__not_found();
	cm_search_array_improved_binary__element_does_not_exist__not_found();
	cm_search_array_interpolation__element_does_not_exist__not_found();
}
