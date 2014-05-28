#include <stdlib.h>
#include <string.h>

#include "cm_array.h"
#include "cm_searching.h"
#include "cm_sorting.h"
#include "cmantras/base/cm_error_log.h"

struct cm_array* cm_array_create(cm_size capacity)
{
	struct cm_array* array = NULL;
	cm_index index = 0;

	cm_error_log_critical_if( (capacity < 1), __func__, ": capacity < 1");

	array = malloc(sizeof(struct cm_array));
	cm_error_log_critical_if( (array == NULL), __func__, ": not enough memory");
	array->capacity = capacity;
	array->element_size = sizeof(void*);
	array->elements = malloc(capacity * array->element_size);
	cm_error_log_critical_if( (array->elements == NULL), __func__, ": not enough memory");
	for( index = 0; index < array->capacity; index++)
	{
		array->elements[index] = NULL;
	}
	return array;
}

void cm_array_set(struct cm_array* array, const void* element, cm_index index)
{
	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (element == NULL), __func__, ": element is NULL");
	cm_error_log_critical_if( (index < 0), __func__, ": index < 0");

	array->elements[index] = (void*)element;
}

void cm_array_cancel(struct cm_array* array, cm_index index)
{
	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (index < 0), __func__, ": index < 0");

	array->elements[index] = NULL;
}

bool cm_array_contains(const struct cm_array* array, const void* element,
					   bool (*match)(const void* element_1, const void* element_2))
{
	bool it_contains = false;
	cm_size index = 0;

	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (element == NULL), __func__, ": element is NULL");
	cm_error_log_critical_if( (match == NULL), __func__, ": search criteria is NULL");

	for(index = 0; index < array->capacity; index++)
	{
		if( (array->elements[index]!=NULL) && (match(element, array->elements[index]) == true) )
		{
			it_contains = true;
			break;
		}
	}
	return it_contains;
}

void cm_array_sort(struct cm_array* array, cm_cmp_size (*compare)(const void* element_1, const void* element_2))
{
	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (compare == NULL), __func__, ": search criteria is NULL");

	qsort(array->elements, array->capacity, array->element_size, compare);
}

cm_index cm_array_get_first(const struct cm_array* array, const void* element,
					    	bool (*match)(const void* element_1, const void* element_2))
{
	cm_size result_index = -1;
	cm_size index = 0;

	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (element == NULL), __func__, ": element is NULL");
	cm_error_log_critical_if( (match == NULL), __func__, ": search criteria is NULL");

	for(index = 0; index < array->capacity; index++)
	{
		if( (array->elements[index] != NULL) && (match(element, array->elements[index]) == true) )
		{
			result_index = index;
			break;
		}
	}
	return result_index;
}

cm_index cm_array_get_last(const struct cm_array* array, const void* element,
					   	   bool (*match)(const void* element_1, const void* element_2))
{
	cm_size result_index = -1;
	cm_size index = 0;

	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (element == NULL), __func__, ": element is NULL");
	cm_error_log_critical_if( (match == NULL), __func__, ": search criteria is NULL");

	for(index = array->capacity - 1; index >= 0 ; index--)
	{
		if( (array->elements[index] != NULL) && (match(element, array->elements[index]) == true) )
		{
			result_index = index;
			break;
		}
	}
	return result_index;
}

void cm_array_pack(struct cm_array* array)
{
	cm_index index_1 = 0;
	cm_index index_2 = index_1;

	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");

	for( ; index_1 < array->capacity; index_1++ )
	{
		if( array->elements[index_1] == NULL)
		{
			for( index_2 = index_1; index_2 < (array->capacity - 1); index_2++ )
			{
				array->elements[index_2] = array->elements[index_2+1];
			}
		}
	}
}

void cm_array_destroy(struct cm_array* array)
{
	free(array->elements);
	free(array);
}

