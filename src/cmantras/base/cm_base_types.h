#ifndef CM_BASE_TYPES_H_
#define CM_BASE_TYPES_H_

#include <stdint.h>
#include <stdbool.h>

/*Generic settings*/
typedef uint32_t cm_size;
typedef int32_t cm_cmp_size;
typedef int32_t cm_index;

/*Objects*/
struct cm_object_interface
{
    void (*destroy)(void*);
    bool (*equals)(void*, void*);
    cm_cmp_size (*compare)(void*, void*);
    void* (*copy)(void*);
};

struct cm_object_interface* cm_object_interface_create(
        void (*destroy)(void*),
        bool (*equals)(void*, void*),
        cm_cmp_size (*compare)(void*, void*), void* (*copy)(void*));

void cm_object_interface_destroy(struct cm_object_interface* object_interface);

#endif /* CM_BASE_TYPES_H_ */
