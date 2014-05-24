#ifndef CM_HASH_H_
#define CM_HASH_H_

#include "cmantras/base/cm_object.h"
#include "cm_binding.h"
#include "cm_list.h"

struct cm_hash
{
	struct cm_list* list;
};

struct cm_hash* cm_hash_create();
void cm_hash_add(void* key, void* value);
void cm_hash_remove(void *key);
void* cm_hash_get(void *key);

#endif /* CM_HASH_H_ */
