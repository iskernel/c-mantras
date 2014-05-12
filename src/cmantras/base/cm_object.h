#ifndef CM_OBJECT_H
#define CM_OBJECT_H_

#include <stdbool.h>
#include <stdint.h>

#include "cm_common.h"

struct cm_interface_object
{
	void (*destroy)(void*);
	bool (*equals)(void*);
	cm_cmp_size_i (*compare)(void*, void*);
	void* (*copy)(void*);
};

struct cm_object
{
	void *data;
	struct cm_interface_object *object_methods;
};

struct cm_interface_object* cm_object_interface_create(void (*destroy)(void*),
													   bool (*equals)(void*),
													   cm_cmp_size_i (*compare)(void*, void*),
													   void* (*copy)(void*));

void cm_object_interface_destroy(struct cm_interface_object* object_interface);

struct cm_object* cm_object_create(void* data, struct cm_interface_object* methods);

void cm_object_destroy(struct cm_object* object);

#endif
