#include <stdlib.h>
#include "cm_list.h"

static struct cm_node* cm_node_create(void *element)
{
	struct cm_node* node;

	node = malloc(sizeof(struct cm_node));
	node->element = element;
	node->next = NULL;
	node->previous = NULL;

	return node;
}

struct cm_list* cm_list_create(struct cm_object_interface* object_interface)
{
	struct cm_list *list = NULL;

	list = malloc(sizeof(struct cm_list));
	list->count = 0U;
	list->head = NULL;
	list->tail = NULL;
	list->node_methods = object_interface;

	return list;
}

void cm_list_push_front(struct cm_list* list, void* element)
{
	struct cm_node *node = NULL;

	node = cm_node_create(element);
	if(list->head == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		node->next = list->head;
		list->head->previous = node;
		list->head = node;
	}
	list->count++;
}

void cm_list_pop_front(struct cm_list* list)
{
	struct cm_node *temp = NULL;

	if(list->head != NULL)
	{
		temp = list->head;
		if(list->head->next != NULL)
		{
			list->head = list->head->next;
			list->head->previous = NULL;
		}
		else
		{
			list->head = NULL;
			list->tail = NULL;
		}
		free(temp);
		list->count--;
	}
}

void cm_list_push_back(struct cm_list* list, void* element)
{
	struct cm_node* node = NULL;

	node = cm_node_create(element);
	if(list->tail == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		node->previous = list->tail;
		list->tail = node;
	}
	list->count++;
}

void cm_list_pop_back(struct cm_list* list)
{
	struct cm_node* temp = NULL;

	if(list->tail != NULL)
	{
		temp = list->tail;
		if(list->tail->previous != NULL)
		{
			list->tail = list->tail->previous;
			list->tail->next = NULL;
		}
		else
		{
			list->head = NULL;
			list->tail = NULL;
		}
		free(temp);
		list->count--;
	}
}

void cm_list_remove(struct cm_list* list, void* element)
{
	struct cm_node* iterator = NULL;

	for(iterator = list->head; iterator != NULL; iterator = iterator->next)
	{
		if(list->node_methods->equals(iterator->element, element) == true)
		{
			iterator->previous->next = iterator->next;
			free(iterator);
			list->count--;
			break;
		}
	}
}

void cm_list_apply_node_transform(struct cm_list* list, void* (*transform)(void*))
{
	struct cm_node* iterator = NULL;

	for(iterator = list->head; iterator != NULL; iterator = iterator->next)
	{
		iterator->element = transform(iterator->element);
	}
}

void* cm_list_at_index(struct cm_list* list, uint64_t index)
{
	struct cm_node* iterator = NULL;
	uint64_t index_iterator = 0;

	if(index < list->count)
	{
		iterator = list->head;
		while(index_iterator < index)
		{
			iterator = iterator->next;
		}
	}
	return iterator;
}

bool cm_list_contains(struct cm_list* list, void* element)
{
	struct cm_node* iterator = NULL;
	bool result = false;

	for(iterator = list->head; iterator != NULL; iterator = iterator->next)
	{
		if(list->node_methods->equals(iterator->element, element) == true)
		{
			result = true;
			break;
		}
	}

	return result;
}

