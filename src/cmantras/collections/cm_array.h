#ifndef CM_ARRAY_H_
#define CM_ARRAY_H_

#include <stdbool.h>
#include "cmantras/base/cm_base_types.h"

struct cm_array
{
	void** elements;
	cm_size capacity;
	size_t element_size;
};

struct cm_array* cm_array_create(cm_size capacity);

void cm_array_set(struct cm_array* array, const void* element, cm_index index);

void cm_array_cancel(struct cm_array* array, cm_index index);

bool cm_array_contains(const struct cm_array* array, const void* element,
					   bool (*match)(const void* element_1, const void* element_2));

void cm_array_sort(struct cm_array* array, cm_cmp_size (*compare)(const void* element_1, const void* element_2));

cm_index cm_array_get_first(const struct cm_array* array, const void* element,
					   		bool (*match)(const void* element_1, const void* element_2));

cm_index cm_array_get_last(const struct cm_array* array, const void* element,
					  bool (*match)(const void* element_1, const void* element_2));

void cm_array_destroy(struct cm_array* array);

void cm_array_pack(struct cm_array* array);

#endif /* CM_ARRAY_H_ */
