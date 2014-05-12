#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "cm_common.h"
#include "cm_object.h"

struct cm_interface_object* cm_object_interface_create(void (*destroy)(void*),
													   bool (*equals)(void*),
													   cm_cmp_size_i (*compare)(void*, void*),
													   void* (*copy)(void*))
{
	struct cm_interface_object* interface = NULL;

	interface = malloc(sizeof(struct cm_interface_object));
	interface->compare = compare;
	interface->destroy = destroy;
	interface->copy = copy;
	interface->equals = equals;

	return interface;
}

void cm_object_interface_destroy(struct cm_interface_object* object_interface)
{
	free(object_interface->compare);
	free(object_interface->copy);
	free(object_interface->destroy);
	free(object_interface->equals);
	free(object_interface);
}

struct cm_object* cm_object_create(void* data, struct cm_interface_object* methods)
{
	struct cm_object* object = NULL;

	object = malloc(sizeof(struct cm_object));
	object->data = data;
	object->object_methods = methods;

	return object;
}

void cm_object_destroy(struct cm_object* object)
{
	object->object_methods->destroy(object->data);
	cm_object_interface_destroy(object->object_methods);
	free(object);
}
