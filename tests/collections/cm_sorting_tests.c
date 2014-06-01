#include "cm_sorting_tests.h"

#include "cmantras/base/cm_base_types.h"
#include "cmantras/collections/cm_array.h"
#include "cmantras/collections/cm_sorting.h"

#include "../cm_test_base.h"

static cm_cmp_size compare_ints(const void* int1, const void* int2)
{
    int val1 = *(int*) (int1);
    int val2 = *(int*) (int2);
    cm_cmp_size result = val1 - val2;
    return result;
}

static void cm_sort_array_quicksort__normal_scenario__array_is_sorted(void)
{
    struct cm_array* array = cm_array_create(10);
    bool condition = false;

    cm_array_set(array, &(int ) { 5 }, 0);
    cm_array_set(array, &(int ) { 3 }, 1);
    cm_array_set(array, &(int ) { 3 }, 2);
    cm_array_set(array, &(int ) { 2 }, 3);
    cm_array_set(array, &(int ) { 1 }, 4);

    cm_sort_array_quicksort(array->elements, 5, &compare_ints);

    condition = ( (*(int*)array->elements[0] == 1) && (*(int*)array->elements[4] == 5) );

    assert_is_true(condition, __func__);

    cm_array_destroy(array);
}

void cm_sorting_run_tests(void)
{
    cm_sort_array_quicksort__normal_scenario__array_is_sorted();
}
