#ifndef CM_ERROR_HANDLING_H_
#define CM_ERROR_HANDLING_H_

#include "cmantras/base/cm_config.h"

enum cm_operation_result_code
{
	CM_OPERATION_CODE_FAILED = 0,
	CM_OPERATION_CODE_SUCCESS  = 1
};

struct cm_operation_status
{
	enum cm_operation_result_code operation_code;
	char* message;
};

struct cm_operation_stack
{
	struct cm_operation_status** data;
	size_t index;
	size_t length;
};

/*
 * Description:
 *  Creates an operation status
 * Parameters:
 *  status - the status of the operation (see cm_operation_result_code)
 *  message - an optional message regarding the status of the operation
 * Returns:
 *  A cm_operation_status object
 */
struct cm_operation_status* cm_operation_status_create(enum cm_operation_result_code status,
													   const char* message);

struct cm_operation_stack* cm_operation_stack_create(size_t stack_size);

void cm_operation_stack_set_last(struct cm_operation_stack* stack, struct cm_operation_status* operation);

struct cm_operation_status* cm_operation_stack_get_last(struct cm_operation_stack* stack);

void cm_operation_status_destroy(struct cm_operation_status* status);

void cm_operation_stack_destroy(struct cm_operation_stack* stack);

#endif /* CM_ERROR_HANDLING_H_ */
