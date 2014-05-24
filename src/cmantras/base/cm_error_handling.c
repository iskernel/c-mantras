#include <stdbool.h>
#include <stdlib.h>

#include "cm_string.h"
#include "cm_error_handling.h"


struct cm_result_with_status* cm_result_with_status_create(void* result, bool was_successful, const char* message)
{
	struct cm_result_with_status* result_with_status = NULL;

	result_with_status = malloc(sizeof(struct cm_result_with_status));
	result_with_status->result = result;
	result_with_status->was_successful = was_successful;
	result_with_status = cm_string_create_from_char_array(message);

	return result_with_status;
}
