#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "cm_operations.h"
#include "helpers/cm_text.h"
#include "cm_error_log.h"

struct cm_operation_status* cm_operation_status_create(enum cm_operation_result_code status,
													   const char* message)
{
	struct cm_operation_status* op_status = NULL;

	cm_error_log_critical_if( (message == NULL), __func__, ": message is null");

	op_status = malloc(sizeof(struct cm_operation_status));
	cm_error_log_critical_if( (op_status == NULL), __func__, ": not enough memory");
	op_status->message = char_array_copy(message, strlen(message));
	op_status->operation_code = status;
	return op_status;
}

struct cm_operation_stack* cm_operation_stack_create(size_t stack_size)
{
	struct cm_operation_stack* op_stack = NULL;
	cm_index index = 0;

	cm_error_log_critical_if( (stack_size < 1), __func__, ": stack_size < 1");

	op_stack = malloc(sizeof(struct cm_operation_stack));
	cm_error_log_critical_if( (op_stack == NULL), __func__, ": not enough memory");
	op_stack->length = stack_size;
	op_stack->index = 0U;
	op_stack->data = malloc(sizeof(struct cm_operation_status) * stack_size);
	cm_error_log_critical_if( (op_stack->data == NULL), __func__, ": not enough memory");
	for(index = 0; index < stack_size; index++)
	{
		op_stack->data[index] = NULL;
	}

	return op_stack;
}

void cm_operation_stack_set_last(struct cm_operation_stack* stack, struct cm_operation_status* operation)
{
	cm_error_log_critical_if( (stack == NULL), __func__, ": stack is null");
	cm_error_log_critical_if( (operation == NULL), __func__, ": operation is null");

	if(stack->index < stack->length)
	{
		stack->index++;
	}
	else
	{
		stack->index = 0U;
	}

	stack->data[stack->index] = operation;
}

struct cm_operation_status* cm_operation_stack_get_last(struct cm_operation_stack* stack)
{
	struct cm_operation_status *status = NULL;

	cm_error_log_critical_if( (stack == NULL), __func__, ": stack is null");

	status = stack->data[stack->index];
	return status;
}

void cm_operation_status_destroy(struct cm_operation_status* status)
{
	free(status->message);
	free(status);
}

void cm_operation_stack_destroy(struct cm_operation_stack* stack)
{
	free(stack->data);
	free(stack);
}
