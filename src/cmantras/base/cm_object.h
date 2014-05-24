#ifndef CM_OBJECT_H_
#define CM_OBJECT_H_

#include <stdbool.h>
#include <stdint.h>

#include "cm_base_common.h"

struct cm_object_interface
{
	void (*destroy)(void*);
	bool (*equals)(void*, void*);
	cm_cmp_size_i (*compare)(void*, void*);
	void* (*copy)(void*);
};

struct cm_object_interface* cm_object_interface_create(void (*destroy)(void*),
													   bool (*equals)(void*, void*),
													   cm_cmp_size_i (*compare)(void*, void*),
													   void* (*copy)(void*));

void cm_object_interface_destroy(struct cm_object_interface* object_interface);

#endif
