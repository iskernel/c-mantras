#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "cmantras/base/cm_base_types.h"
#include "cmantras/base/cm_error_log.h"
#include "cm_arrayset.h"

struct cm_arrayset* cm_arrayset_create(cm_size capacity, cm_cmp_size (*compare)(const void*, const void*))
{
	struct cm_arrayset* set = NULL;

	set = malloc(sizeof(struct cm_arrayset));
	cm_error_log_critical_if( (set == NULL), __func__, "set is null");


	set->element_size = sizeof(void*);
	set->content =  malloc( set->element_size * capacity );
	cm_error_log_critical_if( (set == NULL), __func__, "content is null");

	set->capacity = capacity;
	set->size = 0;
	set->compare = compare;

	return set;
}

bool cm_arrayset_contains(const struct cm_arrayset* set, const void* element)
{
	int index;
	bool contains = false;

	cm_error_log_critical_if( (set == NULL), __func__, "set is null");
	cm_error_log_critical_if( (element == NULL), __func__, "element is null");

	for(index = 0; index< set->size; index++)
	{
		if(set->compare(set->content[index],element) == 0 )
		{
			contains = true;
			break;
		}
	}

	return contains;
}

void cm_arrayset_resize(struct cm_arrayset* set, int new_capacity)
{
	void* content = NULL;

	cm_error_log_critical_if( (set == NULL), __func__, "set is null");
	cm_error_log_critical_if( (new_capacity < 1), __func__, "new capacity < 1" );

	content = malloc(new_capacity * set->element_size);
	cm_error_log_critical_if( (content == NULL), __func__, "Not enough memory");

	memcpy(content, set->content, set->capacity * set->element_size);
	free(set->content);
	set->content = content;
	set->capacity = new_capacity;
}

void cm_arrayset_destroy(struct cm_arrayset* set)
{
	free(set->content);
	free(set);
}

bool cm_arrayset_add(struct cm_arrayset* set, const void* element)
{
	bool result = false;

	cm_error_log_critical_if( (set == NULL), __func__, "set is null");
	cm_error_log_critical_if( (element == NULL), __func__, "element is null");
	cm_error_log_critical_if( (set->size > set->capacity), __func__, "Capacity reached");

	if(cm_arrayset_contains(set, element) == false)
	{
		set->content[set->size] = (void*)element;
		set->size++;
		result = true;
	}

	return result;
}

bool cm_arrayset_remove(struct cm_arrayset* set, const void* element)
{
	cm_index index_1;
	cm_index index_2;
	bool found = false;

	cm_error_log_critical_if( (set == NULL), __func__, "set is null");
	cm_error_log_critical_if( (element == NULL), __func__, "element is null");

	if(set->size > 0 )
	{
		for(index_1 = 0; (index_1< set->size) && (found==false); index_1++)
		{
			if(set->compare(set->content[index_1], element)==0)
			{
				for(index_2 = index_1; index_2<(set->size - 1); index_2++)
				{
					set->content[index_2] = set->content[index_2+1];
				}
				set->size--;
				found = true;
			}
		}
	}
	return found;
}

void cm_arrayset_remove_all(struct cm_arrayset* set)
{
	set->size = 0;
}

struct cm_arrayset* cm_arrayset_copy(const struct cm_arrayset* set)
{
	struct cm_arrayset *new_set = NULL;

	cm_error_log_critical_if( (set == NULL), __func__, "set is null");

	new_set = cm_arrayset_create(set->capacity, set->compare);
	new_set->size = set->size;
	memcpy(new_set->content, set->content, set->size * set->element_size);

	return new_set;
}

bool cm_arrayset_equals(const struct cm_arrayset* set1, const struct cm_arrayset* set2)
{
	bool result = true;
	cm_index index = 0;

	cm_error_log_critical_if( (set1 == NULL), __func__, "set 1 is null");
	cm_error_log_critical_if( (set2 == NULL), __func__, "set 2 is null");

	if(set1->size == set2->size)
	{
		for( ; index<set1->size; index++)
		{
			if( set1->compare( set1->content[index], set2->content[index])!=0 )
			{
				result = false;
				break;
			}
		}
	}
	else
	{
		result = false;
	}
	return result;
}

bool cm_arrayset_is_subset(const struct cm_arrayset* set, const struct cm_arrayset* subset)
{
	cm_index i = 0;
	cm_index j = 0;
	bool found = 0;
	bool result = true;

	cm_error_log_critical_if( (set == NULL), __func__, "set is null");
	cm_error_log_critical_if( (subset == NULL), __func__, "subset is null");

	for(i = 0; i< subset->size; i++)
	{
		found = false;
		for(j = 0; j < set->size; j++)
		{
			if( set->compare(subset->content[i], set->content[j]) == 0 )
			{
				found = true;
				break;
			}
		}
		if(found == false)
		{
			result = false;
			break;
		}
	}
	return result;
}

struct cm_arrayset* cm_arrayset_reunion(const struct cm_arrayset* set1, const struct cm_arrayset* set2)
{
	struct cm_arrayset* result = NULL;
	cm_index index;

	cm_error_log_critical_if( (set1 == NULL), __func__, "set 1 is null");
	cm_error_log_critical_if( (set2 == NULL), __func__, "set 2 is null");
	cm_error_log_critical_if( (set1->element_size != set2->element_size),
							  __func__, "elements must have same type");

	result =  cm_arrayset_create(set1->size + set2->size,
								 set1->compare);
	cm_error_log_critical_if( (result == NULL), __func__, "not enough memory.");

	for(index=0; index < set1->size; index++)
	{
		cm_arrayset_add(result, set1->content[index]);
	}
	for(index=0; index < set2->size; index++)
	{
		cm_arrayset_add(result, set2->content[index]);
	}
	return result;
}

struct cm_arrayset* cm_arrayset_intersection(const struct cm_arrayset* set1, const struct cm_arrayset* set2)
{
	struct cm_arrayset* result = NULL;
	cm_index i,j;
	bool was_found = false;

	cm_error_log_critical_if( (set1 == NULL), __func__, "set 1 is null");
	cm_error_log_critical_if( (set2 == NULL), __func__, "set 2 is null");

	result = cm_arrayset_copy(set1);
	if(result!=NULL)
	{
		for(i=0; i<set1->size; i++)
		{
			was_found = false;
			for(j=0; j<set2->size; j++)
			{
				if(set1->compare(set1->content[i], set2->content[j])==0)
				{
					was_found = true;
					break;
				}
			}
			if(was_found==false)
			{
				cm_arrayset_remove(result, set1->content[i]);
			}
		}
	}
	return result;
}

struct cm_arrayset* cm_arrayset_difference(const struct cm_arrayset* main_set, const struct cm_arrayset* secondary_set)
{
	struct cm_arrayset* result = NULL;
	int i,j;
	bool was_found = false;

	cm_error_log_critical_if( (main_set == NULL), __func__, "main set is null");
	cm_error_log_critical_if( (secondary_set == NULL), __func__, "secondary set is null");

	result = cm_arrayset_copy(main_set);
	if(result!=NULL)
	{
		for(i=0; i<main_set->size; i++)
		{
			was_found = false;
			for(j=0; j<secondary_set->size; j++)
			{
				if(main_set->compare(main_set->content[i], secondary_set->content[j])==0)
				{
					was_found = true;
					break;
				}
			}
			if(was_found==true)
			{
				cm_arrayset_remove(result, main_set->content[i]);
			}
		}
	}
	return result;
}
