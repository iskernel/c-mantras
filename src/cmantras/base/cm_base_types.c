#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "cm_config.h"
#include "cm_base_types.h"
#include "cm_error_log.h"

struct cm_object_interface* cm_object_interface_create(void (*destroy)(void*),
													   bool (*equals)(void*, void*),
													   cm_cmp_size (*compare)(void*, void*),
													   void* (*copy)(void*))
{
	struct cm_object_interface* interface = NULL;

	interface = malloc(sizeof(struct cm_object_interface));
	if(interface == NULL)
	{
		cm_error_log_critical(__func__, ": not enough memory");
	}

	interface->compare = compare;
	interface->destroy = destroy;
	interface->copy = copy;
	interface->equals = equals;

	return interface;
}

void cm_object_interface_destroy(struct cm_object_interface* object_interface)
{
	free(object_interface);
}
