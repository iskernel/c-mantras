#ifndef CM_LIST_H_
#define CM_LIST_H_

#include <stdint.h>
#include <stdbool.h>
#include "cmantras/base/cm_base_types.h"

struct cm_node
{
    void *element;
    struct cm_node *next;
    struct cm_node *previous;
};

struct cm_list
{
    struct cm_node *head;
    struct cm_node *tail;

    cm_size count;
    cm_cmp_size (*compare)(const void*, const void*);
};

struct cm_list* cm_list_create(cm_cmp_size (*compare)(const void*, const void*));

void cm_list_push_front(struct cm_list* list, void* element);
void cm_list_pop_front(struct cm_list* list);

void cm_list_push_back(struct cm_list* list, void* element);
void cm_list_pop_back(struct cm_list* list);

void cm_list_remove(struct cm_list* list, void* element);
void cm_list_apply_node_transform(struct cm_list* list,
                                  void (*transform)(void*));

void* cm_list_at_index(struct cm_list* list, cm_index index);
bool cm_list_contains(struct cm_list* list, void* element);

void cm_list_destroy(struct cm_list* list);

#endif /* CM_ENUMERABLE_H_ */
