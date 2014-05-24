#ifndef CM_ERROR_HANDLING_H_
#define CM_ERROR_HANDLING_H_

#include <stdbool.h>
#include "cm_string.h"

struct cm_result_with_status
{
	void* result;
	bool was_successful;
	struct cm_string* message;
};

struct cm_result_with_status* cm_result_with_status_create(void* result, bool was_successful, const char* message);

#endif /* CM_ERROR_HANDLING_H_ */
