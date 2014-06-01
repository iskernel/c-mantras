#ifndef ALGORITHMS_CM_SEARCHING_H_
#define ALGORITHMS_CM_SEARCHING_H_

#include <stdbool.h>

cm_index cm_search_array_linear(void* key, void** array, cm_size array_size,
								cm_cmp_size (*compare)(const void*, const void*));
cm_index cm_search_array_sentinel_linear(void* key, void** array, cm_size array_size,
										 cm_cmp_size (*compare)(const void*, const void*));
cm_index cm_search_array_binary(void* key, void** array, cm_size array_size,
								cm_cmp_size (*compare)(const void*, const void*));
cm_index cm_search_array_improved_binary(void* key, void** array, cm_size array_size,
										 cm_cmp_size (*compare)(const void*, const void*));
cm_index cm_search_array_interpolation(void* key, void** array, cm_size array_size,
								 	   cm_cmp_size (*compare)(const void*, const void*));

#endif
