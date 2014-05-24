#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "cm_base_common.h"
#include "cm_object.h"

struct cm_object_interface* cm_object_interface_create(void (*destroy)(void*),
													   bool (*equals)(void*, void*),
													   cm_cmp_size_i (*compare)(void*, void*),
													   void* (*copy)(void*))
{
	struct cm_object_interface* interface = NULL;

	interface = malloc(sizeof(struct cm_object_interface));
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


