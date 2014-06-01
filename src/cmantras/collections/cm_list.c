#include <stdlib.h>

#include "cmantras/base/cm_base_types.h"
#include "cmantras/base/cm_error_log.h"

#include "cm_list.h"

static struct cm_node* cm_node_create(void *element)
{
    struct cm_node* node = NULL;

    node = malloc(sizeof(struct cm_node));
    cm_error_log_critical_if((node == NULL), __func__, ": not enough memory");

    node->element = element;
    node->next = NULL;
    node->previous = NULL;

    return node;
}

static void cm_node_destroy(struct cm_node* node)
{
    free(node);
}

struct cm_list* cm_list_create(cm_cmp_size (*compare)(const void*, const void*))
{
    struct cm_list *list = NULL;

    list = malloc(sizeof(struct cm_list));
    cm_error_log_critical_if((list == NULL), __func__, ": not enough memory");

    list->count = 0U;
    list->head = NULL;
    list->tail = NULL;
    list->compare = compare;
    ;

    return list;
}

void cm_list_push_front(struct cm_list* list, void* element)
{
    struct cm_node *node = NULL;

    cm_error_log_critical_if((list == NULL), __func__, ": list is null");
    cm_error_log_critical_if((element == NULL), __func__, ": element is null");

    node = cm_node_create(element);
    if (list->head == NULL)
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

    cm_error_log_critical_if((list == NULL), __func__, ": list is null");

    if (list->head != NULL)
    {
        temp = list->head;
        if (list->head->next != NULL)
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

    cm_error_log_critical_if((list == NULL), __func__, ": list is null");
    cm_error_log_critical_if((element == NULL), __func__, ": element is null");

    node = cm_node_create(element);
    if (list->tail == NULL)
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

    cm_error_log_critical_if((list == NULL), __func__, ": list is null");

    if (list->tail != NULL)
    {
        temp = list->tail;
        if (list->tail->previous != NULL)
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

    cm_error_log_critical_if((list == NULL), __func__, ": list is null");
    cm_error_log_critical_if((element == NULL), __func__, ": element is null");

    for (iterator = list->head; iterator != NULL; iterator = iterator->next)
    {
        if (list->compare(iterator->element, element) == 0)
        {
            if ((iterator->previous == NULL) && (iterator->next == NULL))
            {
                list->head = NULL;
                list->tail = NULL;
            }
            else if (iterator->previous == NULL)
            {
                list->head = list->head->next;
                list->head->previous = NULL;
            }
            else if (iterator->next == NULL)
            {
                list->tail = list->tail->previous;
                list->tail->next = NULL;
            }
            else
            {
                iterator->previous->next = iterator->next;
            }
            free(iterator);
            list->count--;
            break;
        }
    }
}

void cm_list_apply_node_transform(struct cm_list* list,
                                  void (*transform)(void*))
{
    struct cm_node* iterator = NULL;

    cm_error_log_critical_if((list == NULL), __func__, ": list is null");
    cm_error_log_critical_if((transform == NULL), __func__,
                             ": transform is null");

    for (iterator = list->head; iterator != NULL; iterator = iterator->next)
    {
        transform(iterator->element);
    }
}

void* cm_list_at_index(struct cm_list* list, cm_index index)
{
    struct cm_node* iterator = NULL;
    void* result = NULL;
    uint64_t index_iterator = -1;

    cm_error_log_critical_if((list == NULL), __func__, ": list is null");

    if (index < list->count)
    {
        index_iterator = 0;
        iterator = list->head;
        while (index_iterator < index)
        {
            iterator = iterator->next;
            index_iterator++;
        }
    }
    result = iterator->element;
    return result;
}

bool cm_list_contains(struct cm_list* list, void* element)
{
    struct cm_node* iterator = NULL;
    bool result = false;

    cm_error_log_critical_if((list == NULL), __func__, ": list is null");
    cm_error_log_critical_if((element == NULL), __func__, ": element is null");

    for (iterator = list->head; iterator != NULL; iterator = iterator->next)
    {
        if (list->compare(iterator->element, element) == 0)
        {
            result = true;
            break;
        }
    }

    return result;
}

void cm_list_destroy(struct cm_list* list)
{
    struct cm_node* iterator = list->head;
    struct cm_node* other = NULL;
    while (iterator != NULL)
    {
        other = iterator;
        iterator = iterator->next;
        cm_node_destroy(other);
    }
    free(list);
}
