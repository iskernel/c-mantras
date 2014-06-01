#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "cm_lists_tests.h"
#include "../cm_test_base.h"

#include "cmantras/base/cm_base_types.h"
#include "cmantras/text/cm_string.h"
#include "cmantras/collections/cm_list.h"

static cm_cmp_size compare_strings(const void* string1, const void* string2)
{
    struct cm_string* s1 = (struct cm_string*) (string1);
    struct cm_string* s2 = (struct cm_string*) (string2);
    cm_cmp_size size = strcmp(s1->content, s2->content);
    return size;
}

static cm_cmp_size compare_ints(const void* int1, const void* int2)
{
    int val1 = *(int*) int1;
    int val2 = *(int*) int2;
    int result = val1 - val2;
    return result;
}

static void transform_int(void *int1)
{
    *(int*) int1 += 2;
}

static void cm_list_create__normal_scenario__cm_list_created(void)
{
    struct cm_list* list = NULL;
    bool condition = false;

    list = cm_list_create(&compare_strings);

    condition = (list != NULL);
    assert_is_true(condition, __func__);

    cm_list_destroy(list);
}

static void cm_list_push_front__zero_elements__head_and_tail_initialized(void)
{
    struct cm_list* list = NULL;
    struct cm_string* s1 = NULL;
    bool condition = false;

    s1 = cm_string_create_from_char_array("Content");
    list = cm_list_create(&compare_strings);
    cm_list_push_front(list, s1);

    condition = (list->head != NULL) && (list->tail != NULL);

    assert_is_true(condition, __func__);

    cm_string_destroy(s1);
    cm_list_destroy(list);
}

static void cm_list_push_front__existing_elements__last_pushed_is_first(void)
{
    struct cm_list* list = NULL;
    struct cm_string* s1 = NULL;
    struct cm_string* s2 = NULL;
    struct cm_string* s3 = NULL;
    struct cm_string* s4 = NULL;
    struct cm_string* s5 = NULL;
    struct cm_string* s6 = NULL;
    bool condition = false;

    s1 = cm_string_create_from_char_array("Content 1");
    s2 = cm_string_create_from_char_array("Content 2");
    s3 = cm_string_create_from_char_array("Content 3");
    s4 = cm_string_create_from_char_array("Content 4");
    s5 = cm_string_create_from_char_array("Content 5");
    list = cm_list_create(&compare_strings);
    cm_list_push_front(list, s1);
    cm_list_push_front(list, s2);
    cm_list_push_front(list, s3);
    cm_list_push_front(list, s4);
    cm_list_push_front(list, s5);

    s6 = ((struct cm_string*) (list->head->element));
    condition = cm_string_are_equal(s6, s5);

    assert_is_true(condition, __func__);

    cm_string_destroy(s1);
    cm_string_destroy(s2);
    cm_string_destroy(s3);
    cm_string_destroy(s4);
    cm_string_destroy(s5);
    cm_list_destroy(list);
}

static void cm_list_push_back__zero_elements__head_and_tail_initialized(void)
{
    struct cm_list* list = NULL;
    struct cm_string* s1 = NULL;
    bool condition = false;

    s1 = cm_string_create_from_char_array("Content");
    list = cm_list_create(&compare_strings);
    cm_list_push_back(list, s1);

    condition = (list->head != NULL) && (list->tail != NULL);

    assert_is_true(condition, __func__);

    cm_string_destroy(s1);
    cm_list_destroy(list);
}

static void cm_list_push_back__existing_elements__last_pushed_is_tail(void)
{
    struct cm_list* list = NULL;
    struct cm_string* s1 = NULL;
    struct cm_string* s2 = NULL;
    struct cm_string* s3 = NULL;
    struct cm_string* s4 = NULL;
    struct cm_string* s5 = NULL;
    struct cm_string* s6 = NULL;
    bool condition = false;

    s1 = cm_string_create_from_char_array("Content 1");
    s2 = cm_string_create_from_char_array("Content 2");
    s3 = cm_string_create_from_char_array("Content 3");
    s4 = cm_string_create_from_char_array("Content 4");
    s5 = cm_string_create_from_char_array("Content 5");
    list = cm_list_create(&compare_strings);
    cm_list_push_back(list, s1);
    cm_list_push_back(list, s2);
    cm_list_push_back(list, s3);
    cm_list_push_back(list, s4);
    cm_list_push_back(list, s5);

    s6 = ((struct cm_string*) (list->tail->element));
    condition = cm_string_are_equal(s6, s5);

    assert_is_true(condition, __func__);

    cm_string_destroy(s1);
    cm_string_destroy(s2);
    cm_string_destroy(s3);
    cm_string_destroy(s4);
    cm_string_destroy(s5);
    cm_list_destroy(list);
}

static void cm_list_pop_back__existing_elements__element_removed(void)
{
    struct cm_list* list = NULL;

    struct cm_string* s1 = NULL;
    struct cm_string* s2 = NULL;
    struct cm_string* s3 = NULL;
    struct cm_string* s4 = NULL;
    struct cm_string *s5 = NULL;
    struct cm_string* s6 = NULL;
    bool condition = false;

    s1 = cm_string_create_from_char_array("Content 1");
    s2 = cm_string_create_from_char_array("Content 2");
    s3 = cm_string_create_from_char_array("Content 3");
    s4 = cm_string_create_from_char_array("Content 4");
    s5 = cm_string_create_from_char_array("Content 5");
    list = cm_list_create(&compare_strings);
    cm_list_push_front(list, s1);
    cm_list_push_front(list, s2);
    cm_list_push_front(list, s3);
    cm_list_push_front(list, s4);
    cm_list_push_front(list, s5);
    cm_list_pop_back(list);
    cm_list_pop_back(list);

    s6 = ((struct cm_string*) (list->tail->element));
    condition = cm_string_are_equal(s6, s3);

    assert_is_true(condition, __func__);

    cm_string_destroy(s1);
    cm_string_destroy(s2);
    cm_string_destroy(s3);
    cm_string_destroy(s4);
    cm_string_destroy(s5);
    cm_list_destroy(list);
}

static void cm_list_pop_front__existing_elements__element_removed(void)
{
    struct cm_list* list = NULL;

    struct cm_string* s1 = NULL;
    struct cm_string* s2 = NULL;
    struct cm_string* s3 = NULL;
    struct cm_string* s4 = NULL;
    struct cm_string *s5 = NULL;
    struct cm_string* s6 = NULL;
    bool condition = false;

    s1 = cm_string_create_from_char_array("Content 1");
    s2 = cm_string_create_from_char_array("Content 2");
    s3 = cm_string_create_from_char_array("Content 3");
    s4 = cm_string_create_from_char_array("Content 4");
    s5 = cm_string_create_from_char_array("Content 5");
    list = cm_list_create(&compare_strings);
    cm_list_push_front(list, s1);
    cm_list_push_front(list, s2);
    cm_list_push_front(list, s3);
    cm_list_push_front(list, s4);
    cm_list_push_front(list, s5);
    cm_list_pop_front(list);
    cm_list_pop_front(list);

    s6 = ((struct cm_string*) (list->head->element));
    condition = cm_string_are_equal(s6, s3);

    assert_is_true(condition, __func__);

    cm_string_destroy(s1);
    cm_string_destroy(s2);
    cm_string_destroy(s3);
    cm_string_destroy(s4);
    cm_string_destroy(s5);
    cm_list_destroy(list);
}

static void cm_list_remove__first_element__element_removed(void)
{
    struct cm_list* list = NULL;
    bool condition = false;

    list = cm_list_create(&compare_ints);
    cm_list_push_front(list, &(int ) { 1 });
    cm_list_push_front(list, &(int ) { 2 });
    cm_list_push_front(list, &(int ) { 3 });

    cm_list_remove(list, &(int ) { 3 });

    condition = (*(int*) (list->head->element) == 2);

    assert_is_true(condition, __func__);

    cm_list_destroy(list);
}

static void cm_list_remove__last_element__element_removed(void)
{
    struct cm_list* list = NULL;
    bool condition = false;

    list = cm_list_create(&compare_ints);
    cm_list_push_front(list, &(int ) { 1 });
    cm_list_push_front(list, &(int ) { 2 });
    cm_list_push_front(list, &(int ) { 3 });

    cm_list_remove(list, &(int ) { 1 });

    condition = (*(int*) (list->tail->element) == 2);

    assert_is_true(condition, __func__);

    cm_list_destroy(list);
}

static void cm_list_remove__middle_element__element_removed(void)
{
    struct cm_list* list = NULL;
    bool condition = false;

    list = cm_list_create(&compare_ints);
    cm_list_push_front(list, &(int ) { 1 });
    cm_list_push_front(list, &(int ) { 2 });
    cm_list_push_front(list, &(int ) { 3 });

    cm_list_remove(list, &(int ) { 2 });

    condition = (list->count == 2);

    assert_is_true(condition, __func__);

    cm_list_destroy(list);
}

static void cm_list_apply_node_transform__add_value__transformation_applied(
        void)
{
    struct cm_list* list = NULL;
    bool condition = false;

    list = cm_list_create(&compare_ints);
    cm_list_push_front(list, &(int ) { 1 });
    cm_list_push_front(list, &(int ) { 2 });
    cm_list_push_front(list, &(int ) { 3 });

    cm_list_apply_node_transform(list, &transform_int);

    condition = (*(int*) list->head->element == 5)
            && (*(int*) (list->tail->element) == 3);

    assert_is_true(condition, __func__);

    cm_list_destroy(list);
}

static void cm_list_at_index__get_value__is_retrieved()
{
    struct cm_list* list = NULL;
    int* value = NULL;
    bool condition = false;

    list = cm_list_create(&compare_ints);
    cm_list_push_front(list, &(int ) { 1 });
    cm_list_push_front(list, &(int ) { 2 });
    cm_list_push_front(list, &(int ) { 3 });

    value = cm_list_at_index(list, 1);

    condition = (*value == 2);

    assert_is_true(condition, __func__);

    cm_list_destroy(list);
}

static void cm_list_contains__value_exists__is_true()
{
    struct cm_list* list = NULL;
    bool condition = false;

    list = cm_list_create(&compare_ints);
    cm_list_push_front(list, &(int ) { 1 });
    cm_list_push_front(list, &(int ) { 2 });
    cm_list_push_front(list, &(int ) { 3 });

    condition = cm_list_contains(list, &(int ) { 1 });

    assert_is_true(condition, __func__);

    cm_list_destroy(list);
}

static void cm_list_contains__value_does_not_exist__is_false()
{
    struct cm_list* list = NULL;
    bool condition = false;

    list = cm_list_create(&compare_ints);
    cm_list_push_front(list, &(int ) { 1 });
    cm_list_push_front(list, &(int ) { 2 });
    cm_list_push_front(list, &(int ) { 3 });

    condition = cm_list_contains(list, &(int ) { -1 });

    assert_is_false(condition, __func__);

    cm_list_destroy(list);
}

void cm_list_run_tests()
{
    cm_list_create__normal_scenario__cm_list_created();
    cm_list_push_front__zero_elements__head_and_tail_initialized();
    cm_list_push_front__existing_elements__last_pushed_is_first();
    cm_list_push_back__zero_elements__head_and_tail_initialized();
    cm_list_push_back__existing_elements__last_pushed_is_tail();
    cm_list_pop_back__existing_elements__element_removed();
    cm_list_pop_front__existing_elements__element_removed();
    cm_list_remove__first_element__element_removed();
    cm_list_remove__last_element__element_removed();
    cm_list_remove__middle_element__element_removed();
    cm_list_apply_node_transform__add_value__transformation_applied();
    cm_list_at_index__get_value__is_retrieved();
    cm_list_contains__value_exists__is_true();
    cm_list_contains__value_does_not_exist__is_false();
}
