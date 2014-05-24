#include <stdlib.h>

#include "cm_lists_tests.h"
#include "../cm_test_base.h"

#include "cmantras/base/cm_string.h"
#include "cmantras/base/cm_object.h"
#include "cmantras/collections/cm_list.h"

void cm_list_create__normal_scenario__cm_list_created(void)
{
	struct cm_list* list = NULL;
	struct cm_object_interface* interface = NULL;
	bool condition = false;

	interface = cm_string_get_object_interface();
	list = cm_list_create(interface);

	condition = (list != NULL);
	assert_is_true(condition, __func__);
}

void cm_list_push_front__zero_elements__head_and_tail_initialized(void)
{
	struct cm_list* list = NULL;
	struct cm_string* s1 = NULL;
	struct cm_object_interface* interface = NULL;
	bool condition = false;

	interface = cm_string_get_object_interface();
	s1 = cm_string_create_from_char_array("Content");
	list = cm_list_create(interface);
	cm_list_push_front(list, s1);

	condition = (list->head != NULL) && (list->tail != NULL);

	assert_is_true(condition, __func__);
}


void cm_list_push_front__existing_elements__last_pushed_is_first(void)
{
	struct cm_list* list = NULL;
	struct cm_string* s1 = NULL;
	struct cm_string* s2 = NULL;
	struct cm_string* s3 = NULL;
	struct cm_string* s4 = NULL;
	struct cm_string* s5 = NULL;
	struct cm_string* s6 = NULL;
	struct cm_object_interface* interface = NULL;
	bool condition = false;

	interface = cm_string_get_object_interface();
	s1 = cm_string_create_from_char_array("Content 1");
	s2 = cm_string_create_from_char_array("Content 2");
	s3 = cm_string_create_from_char_array("Content 3");
	s4 = cm_string_create_from_char_array("Content 4");
	s5 = cm_string_create_from_char_array("Content 5");
	list = cm_list_create(interface);
	cm_list_push_front(list, s1);
	cm_list_push_front(list, s2);
	cm_list_push_front(list, s3);
	cm_list_push_front(list, s4);
	cm_list_push_front(list, s5);

	s6 = ((struct cm_string*)(list->head->element));
	condition = s2->methods->are_equal(s6,s5);

	assert_is_true(condition, __func__);
}

void cm_list_push_back__zero_elements__head_and_tail_initialized(void)
{
	struct cm_list* list = NULL;
	struct cm_string* s1 = NULL;
	struct cm_object_interface* interface = NULL;
	bool condition = false;

	interface = cm_string_get_object_interface();
	s1 = cm_string_create_from_char_array("Content");
	list = cm_list_create(interface);
	cm_list_push_back(list, s1);

	condition = (list->head != NULL) && (list->tail != NULL);

	assert_is_true(condition, __func__);
}

void cm_list_push_back__existing_elements__last_pushed_is_tail(void)
{
	struct cm_list* list = NULL;
	struct cm_string* s1 = NULL;
	struct cm_string* s2 = NULL;
	struct cm_string* s3 = NULL;
	struct cm_string* s4 = NULL;
	struct cm_string* s5 = NULL;
	struct cm_string* s6 = NULL;
	struct cm_object_interface* interface = NULL;
	bool condition = false;

	interface = cm_string_get_object_interface();
	s1 = cm_string_create_from_char_array("Content 1");
	s2 = cm_string_create_from_char_array("Content 2");
	s3 = cm_string_create_from_char_array("Content 3");
	s4 = cm_string_create_from_char_array("Content 4");
	s5 = cm_string_create_from_char_array("Content 5");
	list = cm_list_create(interface);
	cm_list_push_front(list, s1);
	cm_list_push_front(list, s2);
	cm_list_push_front(list, s3);
	cm_list_push_front(list, s4);
	cm_list_push_front(list, s5);

	s6 = ((struct cm_string*)(list->head->element));
	condition = s2->methods->are_equal(s6,s5);

	assert_is_true(condition, __func__);
}

void cm_list_run_tests()
{
	module_cm_string_initialize();

	cm_list_create__normal_scenario__cm_list_created();
	cm_list_push_front__zero_elements__head_and_tail_initialized();
	cm_list_push_front__existing_elements__last_pushed_is_first();
	cm_list_push_back__zero_elements__head_and_tail_initialized();
	cm_list_push_back__existing_elements__last_pushed_is_tail();
}
