#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "cm_operations_tests.h"
#include "cmantras/base/cm_operations.h"
#include "../cm_test_base.h"

static void cm_operation_status_create__normal_scenario__is_created(void)
{
	struct cm_operation_status* status =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message");
	bool condition = ( strcmp(status->message, "Message") == 0 )
					 && (status->operation_code == CM_OPERATION_CODE_FAILED);

	assert_is_true(condition, __func__);

	cm_operation_status_destroy(status);
}

static void cm_operation_stack_create__normal_scenario__is_created(void)
{
	struct cm_operation_stack* stack = cm_operation_stack_create(10U);
	bool condition = (stack->data != NULL) && (stack->index == 0U) && (stack->length == 10U);

	assert_is_true(condition, __func__);

	cm_operation_stack_destroy(stack);
}

static void cm_operation_stack_set_last__no_existing_operations__is_added(void)
{
	struct cm_operation_stack* stack = cm_operation_stack_create(10U);
	struct cm_operation_status* status =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message");
	bool condition = false;
	cm_operation_stack_set_last(stack, status);
	condition = (strcmp(stack->data[stack->index]->message, "Message") == 0)
				&& (stack->data[stack->index]->operation_code == CM_OPERATION_CODE_FAILED);
	assert_is_true(condition, __func__);

	cm_operation_status_destroy(status);
	cm_operation_stack_destroy(stack);
}

static void cm_operation_stack_set_last__operations_already_added__is_added_corectly(void)
{
	struct cm_operation_stack* stack = cm_operation_stack_create(10U);
	struct cm_operation_status* status_1 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message");
	struct cm_operation_status* status_2 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message1");
	struct cm_operation_status* status_3 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message2");
	bool condition = false;

	cm_operation_stack_set_last(stack, status_1);
	cm_operation_stack_set_last(stack, status_2);
	cm_operation_stack_set_last(stack, status_3);

	condition = (strcmp(stack->data[stack->index]->message, "Message2") == 0)
				&& (stack->data[stack->index]->operation_code == CM_OPERATION_CODE_FAILED);
	assert_is_true(condition, __func__);

	cm_operation_status_destroy(status_1);
	cm_operation_status_destroy(status_2);
	cm_operation_status_destroy(status_3);
	cm_operation_stack_destroy(stack);
}

static void cm_operation_stack_set_last__overflow__is_restarted(void)
{
	struct cm_operation_stack* stack = cm_operation_stack_create(10U);
	struct cm_operation_status* status_1 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message");
	struct cm_operation_status* status_2 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message1");
	struct cm_operation_status* status_3 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message2");
	struct cm_operation_status* status_4 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message3");
	struct cm_operation_status* status_5 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message4");
	struct cm_operation_status* status_6 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message5");
	struct cm_operation_status* status_7 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message6");
	struct cm_operation_status* status_8 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message7");
	struct cm_operation_status* status_9 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message8");
	struct cm_operation_status* status_10 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message9");
	struct cm_operation_status* status_11 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message10");
	bool condition = false;

	cm_operation_stack_set_last(stack, status_1);
	cm_operation_stack_set_last(stack, status_2);
	cm_operation_stack_set_last(stack, status_3);
	cm_operation_stack_set_last(stack, status_4);
	cm_operation_stack_set_last(stack, status_5);
	cm_operation_stack_set_last(stack, status_6);
	cm_operation_stack_set_last(stack, status_7);
	cm_operation_stack_set_last(stack, status_8);
	cm_operation_stack_set_last(stack, status_9);
	cm_operation_stack_set_last(stack, status_10);
	cm_operation_stack_set_last(stack, status_11);

	condition = (strcmp(stack->data[stack->index]->message, "Message10") == 0)
				&& (stack->data[stack->index]->operation_code == CM_OPERATION_CODE_FAILED);
	assert_is_true(condition, __func__);

	cm_operation_status_destroy(status_1);
	cm_operation_status_destroy(status_2);
	cm_operation_status_destroy(status_3);
	cm_operation_status_destroy(status_4);
	cm_operation_status_destroy(status_5);
	cm_operation_status_destroy(status_6);
	cm_operation_status_destroy(status_7);
	cm_operation_status_destroy(status_8);
	cm_operation_status_destroy(status_9);
	cm_operation_status_destroy(status_10);
	cm_operation_status_destroy(status_11);
	cm_operation_stack_destroy(stack);
}


static void cm_operation_stack_get_last__overflow__is_retrieved(void)
{
	struct cm_operation_stack* stack = cm_operation_stack_create(10U);
	struct cm_operation_status* status_1 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message");
	struct cm_operation_status* status_2 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message1");
	struct cm_operation_status* status_3 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message2");
	struct cm_operation_status* status_4 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message3");
	struct cm_operation_status* status_5 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message4");
	struct cm_operation_status* status_6 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message5");
	struct cm_operation_status* status_7 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message6");
	struct cm_operation_status* status_8 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message7");
	struct cm_operation_status* status_9 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message8");
	struct cm_operation_status* status_10 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message9");
	struct cm_operation_status* status_11 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message10");
	struct cm_operation_status* status_12 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message11");
	struct cm_operation_status* status_13 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message12");
	struct cm_operation_status* status_14 =  cm_operation_status_create(CM_OPERATION_CODE_FAILED, "Message13");
	struct cm_operation_status* status_15 =  NULL;
	bool condition = false;

	cm_operation_stack_set_last(stack, status_1);
	cm_operation_stack_set_last(stack, status_2);
	cm_operation_stack_set_last(stack, status_3);
	cm_operation_stack_set_last(stack, status_4);
	cm_operation_stack_set_last(stack, status_5);
	cm_operation_stack_set_last(stack, status_6);
	cm_operation_stack_set_last(stack, status_7);
	cm_operation_stack_set_last(stack, status_8);
	cm_operation_stack_set_last(stack, status_9);
	cm_operation_stack_set_last(stack, status_10);
	cm_operation_stack_set_last(stack, status_11);
	cm_operation_stack_set_last(stack, status_12);
	cm_operation_stack_set_last(stack, status_13);
	cm_operation_stack_set_last(stack, status_14);
	status_15 = cm_operation_stack_get_last(stack);

	condition = (strcmp(status_15->message, "Message13") == 0)
				&& (status_15->operation_code == CM_OPERATION_CODE_FAILED);
	assert_is_true(condition, __func__);

	cm_operation_status_destroy(status_1);
	cm_operation_status_destroy(status_2);
	cm_operation_status_destroy(status_3);
	cm_operation_status_destroy(status_4);
	cm_operation_status_destroy(status_5);
	cm_operation_status_destroy(status_6);
	cm_operation_status_destroy(status_7);
	cm_operation_status_destroy(status_8);
	cm_operation_status_destroy(status_9);
	cm_operation_status_destroy(status_10);
	cm_operation_status_destroy(status_11);
	cm_operation_status_destroy(status_12);
	cm_operation_status_destroy(status_13);
	cm_operation_status_destroy(status_14);
	cm_operation_stack_destroy(stack);
}

void cm_operations_tests(void)
{
	cm_operation_status_create__normal_scenario__is_created();
	cm_operation_stack_create__normal_scenario__is_created();
	cm_operation_stack_set_last__no_existing_operations__is_added();
	cm_operation_stack_set_last__operations_already_added__is_added_corectly();
	cm_operation_stack_set_last__overflow__is_restarted();
	cm_operation_stack_get_last__overflow__is_retrieved();
}
