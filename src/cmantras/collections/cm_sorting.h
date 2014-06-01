#ifndef COLLECTIONS_CM_SORTING_H
#define COLLECTIONS_CM_SORTING_H

#include "cmantras/base/cm_base_types.h"

/*
 * Credits for itterative quicksort
 * 	http://www.geeksforgeeks.org/iterative-quick-sort/
 */

void cm_sort_array_quicksort(void** array, cm_size array_size,
                             cm_cmp_size (*compare)(const void*, const void*));

#endif
