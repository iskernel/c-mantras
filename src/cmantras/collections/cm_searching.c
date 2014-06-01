#include <stdlib.h>

#include "cmantras/base/cm_base_types.h"
#include "cmantras/base/cm_error_log.h"
#include "cm_searching.h"

cm_index cm_search_array_linear(void* key, void** array, cm_size array_size, cm_cmp_size (*compare)(const void*, const void*))
{
	cm_index index = 0;

	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (compare == NULL), __func__, ": compare is NULL");

	for ( ; index < array_size && compare(array[index], key) != 0; index++) ;
	index  = (index == array_size) ? (-1) : index;

	return index;
}

cm_index cm_search_array_sentinel_linear(void* key, void** array, cm_size array_size, cm_cmp_size (*compare)(const void*, const void*))
{
	cm_index index = 0;

	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (compare == NULL), __func__, ": compare is NULL");

	array[array_size] = key;
	for ( ; compare(array[index], key) != 0; index++);
	index = (index == array_size) ? (-1) : (index);

	return index;
}

cm_index cm_search_array_binary(void* key, void** array, cm_size array_size, cm_cmp_size (*compare)(const void*, const void*))
{
	cm_index left = 0;
	cm_index right = array_size - 1;
	cm_index middle = (left + right) / 2;
	cm_index result = -1;

	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (compare == NULL), __func__, ": compare is NULL");

	if( ( compare(key, array[left]) >=0 ) && ( compare(key, array[right]) <=0 ) )
	{
		while( (left <= right) && ( compare(array[middle], key) != 0) )
		{
			(compare(key, array[middle]) > 0) ? (left = middle + 1) : (right = middle + 1);
			middle = (left + right) / 2;
		}
		result  = (compare(array[middle], key) != 0) ? (-1) : middle;
	}
	return result;
}

cm_index cm_search_array_improved_binary(void* key, void** array, cm_size array_size, cm_cmp_size (*compare)(const void*, const void*))
{
	cm_index left = 0;
	cm_index right = array_size - 1;
	cm_index middle = (left + right) / 2;
	cm_index result = -1;

	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (compare == NULL), __func__, ": compare is NULL");

	if( ( compare(key, array[left]) >=0 ) && ( compare(key, array[right]) <=0 ) )
	{
		while( left < right)
		{
			( compare(key, array[middle]) > 0 ) ? (left = middle + 1) : (right = middle);
			middle = (left + right) / 2;
		}
		if( ( (right < array_size) && ( compare(array[right], key) == 0 ) ) )
		{
			result = right;
		}
		else
		{
			result = -1;
		}
	}
	return result;
}

cm_index cm_search_array_interpolation(void* key, void** array, cm_size array_size,
								 	   cm_cmp_size (*compare)(const void*, const void*))
{
	cm_index left = 0;
	cm_index right = array_size - 1;
	cm_index result = -1;
	cm_index middle = left + compare(key, array[left]) * (right - left)
					  / compare(array[right], array[left]);

	cm_error_log_critical_if( (array == NULL), __func__, ": array is NULL");
	cm_error_log_critical_if( (compare == NULL), __func__, ": compare is NULL");

	if( ( compare(key, array[left]) >=0 ) && ( compare(key, array[right]) <=0 ) )
	{
		while ( (compare(array[middle], key) !=0 )
				&& (left < right)
				&& (compare(array[left], array[right]) !=0 )
				&& (compare(key, array[left]) >= 0)
				&& (compare(key, array[right]) <= 0))
		{
			middle = left + compare(key, array[left]) * (right - left)
					 / compare(array[right], array[left]);
			(compare(key, array[middle]) > 0) ? (left = middle + 1)
											  : (right = middle - 1);
		}
		result = middle;
	}
	return result;
}

