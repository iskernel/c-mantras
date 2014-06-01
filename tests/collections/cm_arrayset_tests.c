#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#include "cm_arrayset_tests.h"

#include "cmantras/collections/cm_arrayset.h"
#include "cmantras/base/cm_base_types.h"
#include "../cm_test_base.h"

static cm_cmp_size compare_ints(const void* int1, const void* int2)
{
    cm_cmp_size result = (*(int*) int1) - (*(int*) int2);
    return result;
}

static void cm_arrayset_create__normal_scenario__is_created(void)
{
    struct cm_arrayset* set = cm_arrayset_create(10, &compare_ints);

    assert_is_true(((set != NULL) && (set->capacity == 10)), __func__);

    cm_arrayset_destroy(set);
}

static void cm_arrayset_contains__element_exists__returns_true(void)
{
    struct cm_arrayset* set = cm_arrayset_create(5, &compare_ints);
    bool condition = false;

    cm_arrayset_add(set, &(int ) { 0 });
    cm_arrayset_add(set, &(int ) { 1 });
    cm_arrayset_add(set, &(int ) { 2 });
    cm_arrayset_add(set, &(int ) { 3 });
    cm_arrayset_add(set, &(int ) { 4 });
    condition = cm_arrayset_contains(set, &(int ) { 2 });

    assert_is_true((condition), __func__);

    cm_arrayset_destroy(set);
}

static void cm_arrayset_contains__element_does_not_exist__returns_false(void)
{
    struct cm_arrayset* set = cm_arrayset_create(5, &compare_ints);
    bool condition = false;

    cm_arrayset_add(set, &(int ) { 0 });
    cm_arrayset_add(set, &(int ) { 1 });
    cm_arrayset_add(set, &(int ) { 2 });
    cm_arrayset_add(set, &(int ) { 3 });
    cm_arrayset_add(set, &(int ) { 4 });
    condition = cm_arrayset_contains(set, &(int ) { -1 });

    assert_is_false((condition), __func__);

    cm_arrayset_destroy(set);
}

static void cm_arrayset_resize__normal_scenario__is_created(void)
{
    struct cm_arrayset* set = cm_arrayset_create(5, &compare_ints);
    cm_arrayset_add(set, &(int ) { 0 });
    cm_arrayset_add(set, &(int ) { 1 });
    cm_arrayset_add(set, &(int ) { 2 });
    cm_arrayset_add(set, &(int ) { 3 });
    cm_arrayset_add(set, &(int ) { 4 });

    cm_arrayset_resize(set, 6);
    cm_arrayset_add(set, &(int ) { 5 });

    assert_is_true(
            ((set != NULL) && (set->capacity == 6)
             && (*(int*) set->content[1] == 1) && (*(int*) set->content[5] == 5)),
            __func__);

    cm_arrayset_destroy(set);
}

static void cm_arrayset_add__duplicate_element__is_not_added(void)
{
    struct cm_arrayset* set = cm_arrayset_create(10, &compare_ints);
    bool condition = false;
    cm_arrayset_add(set, &(int ) { 0 });
    cm_arrayset_add(set, &(int ) { 1 });
    cm_arrayset_add(set, &(int ) { 2 });
    cm_arrayset_add(set, &(int ) { 3 });
    cm_arrayset_add(set, &(int ) { 4 });

    condition = (cm_arrayset_add(set, &(int ) { 1 }) == false);

    assert_is_true((condition && (set->size == 5)), __func__);

    cm_arrayset_destroy(set);
}

static void cm_arrayset_remove__existing_element__is_removed(void)
{
    struct cm_arrayset* set = cm_arrayset_create(10, &compare_ints);
    bool condition = false;
    cm_arrayset_add(set, &(int ) { 0 });
    cm_arrayset_add(set, &(int ) { 1 });
    cm_arrayset_add(set, &(int ) { 2 });
    cm_arrayset_add(set, &(int ) { 3 });
    cm_arrayset_add(set, &(int ) { 4 });

    condition = cm_arrayset_remove(set, &(int ) { 1 });

    assert_is_true(
            (condition && (set->size == 4) && (*(int*) set->content[1] == 2)),
            __func__);

    cm_arrayset_destroy(set);
}

static void cm_arrayset_copy__normal_scenario__is_copied(void)
{
    struct cm_arrayset* set = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* other_set = NULL;
    bool condition = false;

    cm_arrayset_add(set, &(int ) { 0 });
    cm_arrayset_add(set, &(int ) { 1 });
    cm_arrayset_add(set, &(int ) { 2 });
    cm_arrayset_add(set, &(int ) { 3 });
    cm_arrayset_add(set, &(int ) { 4 });

    other_set = cm_arrayset_copy(set);
    condition = (other_set != NULL) && (other_set->capacity == 10)
                && (other_set->size == 5)
                && (*(int*) other_set->content[2] == 2);

    assert_is_true(condition, __func__);

    cm_arrayset_destroy(set);
    cm_arrayset_destroy(other_set);
}

static void cm_arrayset_equals__same_elements__are_equal(void)
{
    struct cm_arrayset* set = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* other_set = NULL;
    bool condition = false;

    cm_arrayset_add(set, &(int ) { 0 });
    cm_arrayset_add(set, &(int ) { 1 });
    cm_arrayset_add(set, &(int ) { 2 });
    cm_arrayset_add(set, &(int ) { 3 });
    cm_arrayset_add(set, &(int ) { 4 });

    other_set = cm_arrayset_copy(set);

    condition = cm_arrayset_equals(set, other_set);

    assert_is_true(condition, __func__);

    cm_arrayset_destroy(set);
    cm_arrayset_destroy(other_set);
}

static void cm_arrayset_is_subset__are_same__returns_true(void)
{
    struct cm_arrayset* set = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* other_set = NULL;
    bool condition = false;

    cm_arrayset_add(set, &(int ) { 0 });
    cm_arrayset_add(set, &(int ) { 1 });
    cm_arrayset_add(set, &(int ) { 2 });
    cm_arrayset_add(set, &(int ) { 3 });
    cm_arrayset_add(set, &(int ) { 4 });

    other_set = cm_arrayset_copy(set);

    condition = cm_arrayset_is_subset(set, other_set);

    assert_is_true(condition, __func__);

    cm_arrayset_destroy(set);
    cm_arrayset_destroy(other_set);
}

static void cm_arrayset_is_subset__is_subset__returns_true(void)
{
    struct cm_arrayset* set = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* other_set = NULL;
    bool condition = false;

    cm_arrayset_add(set, &(int ) { 0 });
    cm_arrayset_add(set, &(int ) { 1 });
    cm_arrayset_add(set, &(int ) { 2 });
    cm_arrayset_add(set, &(int ) { 3 });
    cm_arrayset_add(set, &(int ) { 4 });

    other_set = cm_arrayset_copy(set);
    cm_arrayset_remove(other_set, &(int ) { 2 });

    condition = cm_arrayset_is_subset(set, other_set);

    assert_is_true(condition, __func__);

    cm_arrayset_destroy(set);
    cm_arrayset_destroy(other_set);
}

static void cm_arrayset_reunion__normal_scenario__is_correct(void)
{
    struct cm_arrayset* set_1 = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* set_2 = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* result = NULL;
    bool condition = false;

    cm_arrayset_add(set_1, &(int ) { 0 });
    cm_arrayset_add(set_1, &(int ) { 1 });
    cm_arrayset_add(set_2, &(int ) { 0 });
    cm_arrayset_add(set_2, &(int ) { 1 });
    cm_arrayset_add(set_2, &(int ) { 2 });

    result = cm_arrayset_reunion(set_1, set_2);
    condition = (result->size == 3) && (*(int*) result->content[0] == 0)
                && (*(int*) result->content[2] == 2);

    assert_is_true(condition, __func__);

    cm_arrayset_destroy(set_1);
    cm_arrayset_destroy(set_2);
    cm_arrayset_destroy(result);
}

static void cm_arrayset_intersection__normal_scenario__is_correct(void)
{
    struct cm_arrayset* set_1 = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* set_2 = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* result = NULL;
    bool condition = false;

    cm_arrayset_add(set_1, &(int ) { 0 });
    cm_arrayset_add(set_1, &(int ) { 1 });
    cm_arrayset_add(set_2, &(int ) { 0 });
    cm_arrayset_add(set_2, &(int ) { 1 });
    cm_arrayset_add(set_2, &(int ) { 2 });

    result = cm_arrayset_intersection(set_1, set_2);
    condition = (result->size == 2) && (*(int*) result->content[0] == 0);

    assert_is_true(condition, __func__);

    cm_arrayset_destroy(set_1);
    cm_arrayset_destroy(set_2);
    cm_arrayset_destroy(result);
}

static void cm_arrayset_difference__normal_scenario__is_correct(void)
{
    struct cm_arrayset* set_1 = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* set_2 = cm_arrayset_create(10, &compare_ints);
    struct cm_arrayset* result = NULL;
    bool condition = false;

    cm_arrayset_add(set_1, &(int ) { 0 });
    cm_arrayset_add(set_1, &(int ) { 1 });
    cm_arrayset_add(set_2, &(int ) { 0 });
    cm_arrayset_add(set_2, &(int ) { 1 });
    cm_arrayset_add(set_2, &(int ) { 2 });

    result = cm_arrayset_difference(set_2, set_1);
    condition = (result->size == 1) && (*(int*) result->content[0] == 2);

    assert_is_true(condition, __func__);

    cm_arrayset_destroy(set_1);
    cm_arrayset_destroy(set_2);
    cm_arrayset_destroy(result);
}

void cm_arrayset_run_tests(void)
{
    cm_arrayset_create__normal_scenario__is_created();
    cm_arrayset_contains__element_exists__returns_true();
    cm_arrayset_contains__element_does_not_exist__returns_false();
    cm_arrayset_resize__normal_scenario__is_created();
    cm_arrayset_add__duplicate_element__is_not_added();
    cm_arrayset_remove__existing_element__is_removed();
    cm_arrayset_copy__normal_scenario__is_copied();
    cm_arrayset_equals__same_elements__are_equal();
    cm_arrayset_is_subset__are_same__returns_true();
    cm_arrayset_is_subset__is_subset__returns_true();
    cm_arrayset_reunion__normal_scenario__is_correct();
    cm_arrayset_intersection__normal_scenario__is_correct();
    cm_arrayset_difference__normal_scenario__is_correct();
}
