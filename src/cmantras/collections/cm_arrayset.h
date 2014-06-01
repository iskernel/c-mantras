#ifndef COLLECTIONS_CM_ARRAYSET_H
#define COLLECTIONS_CM_ARRAYSET_H

#include <stdlib.h>
#include <stdbool.h>

#include "cmantras/base/cm_base_types.h"

struct cm_arrayset
{
    /*The allocated size for the Object array elements*/
    cm_size capacity;
    /*How many elements are actually in the array*/
    cm_size size;
    /*The vector containing the objects*/
    void** content;
    /*The size of an element*/
    size_t element_size;
    /*Compare function*/
    cm_cmp_size (*compare)(const void*, const void*);
};

/*
 * Description:
 *  Creates an ArraySet data structure
 * Parameters:
 *  set - a pointer to the set who is going to be created
 * Returns:
 *  A pointer to the initialized set OR
 *  NULL if there is not enough memory
 */
struct cm_arrayset* cm_arrayset_create(
        cm_size capacity, cm_cmp_size (*compare)(const void*, const void*));
/*
 * Description:
 *  Resizes an ArraySet data structure
 * Parameters:
 *  capacity - the new capacity of the set
 * Returns:
 *  A pointer to the set OR
 *  NULL if there is no memory left or the newCapacity is
 *  smaller than the size of the array.
 */
void cm_arrayset_resize(struct cm_arrayset* set, int new_capacity);
/*
 * Description:
 *  Destroys an ArraySet structure
 * Parameters:
 *  set - a pointer to the set who is going to be created
 * Returns:
 *  NULL
 */
void cm_arrayset_destroy(struct cm_arrayset* set);
/*
 * Description:
 *  Verifies if @object belongs in @set
 * Parameters:
 *  object - a pointer to a object
 *  set - a pointer to a set
 * Returns:
 *  True - if the object exists in the set
 *  False - if the object does not exist in the set
 */
bool cm_arrayset_contains(const struct cm_arrayset* set, const void* object);
/*
 * Description:
 *  Adds an object to a set
 * Parameters:
 *  set - a pointer to the current set
 *  object - a pointer to an object
 * Returns:
 *  A pointer to the current set OR
 *  NULL if the object already exists in the set or
 *    if adding the object would cause a buffer overflow
 */
bool cm_arrayset_add(struct cm_arrayset* set, const void* element);
/*
 * Description:
 *  Removes an object from the set
 * Parameters:
 *  set - a pointer to the current set
 *  object - a pointer to an object
 * Returns:
 *  A pointer to the current set OR
 *  NULL if the object does not exist in the set or
 *    if there is no object in the set
 */
bool cm_arrayset_remove(struct cm_arrayset* set, const void* element);
/*
 * Description:
 *  Removes all objects from the set
 * Parameters:
 *  set - a pointer to the current set
 * Returns:
 *  A pointer to the set
 */
void cm_arrayset_remove_all(struct cm_arrayset* set);
/*
 * Description:
 *  Creates a hard copy of a set
 * Parameters:
 *  set - a pointer to a set
 * Returns:
 *  A pointer to a copy of the set
 */
struct cm_arrayset* cm_arrayset_copy(const struct cm_arrayset* set);
/*
 * Description:
 *  Compares two sets to see if they are equal
 * Parameters:
 *  set1, set2 - pointers to the two sets
 * Returns:
 *  True - if both sets have the same objects
 *  False - if there are differences between the sets
 */
bool cm_arrayset_equals(const struct cm_arrayset* set1,
                        const struct cm_arrayset* set2);
/*
 * Description:
 *  Check is a a set is a subset of another set
 * Parameters:
 *  smallSet - the possible subset
 *  largeSet - the set who is verified
 * Returns:
 *  True - if @smallset is a subset of @largeset
 *  False - otherwise
 */
bool cm_arrayset_is_subset(const struct cm_arrayset* set,
                           const struct cm_arrayset* subset);
/*
 * Description:
 *  Creates a new ArraySet containing the result of the reunion
 *  between 2 other sets.
 * Parameters:
 *  set1, set2 - the sets who are going to be reunited
 * Returns:
 *  A pointer to the ArraySet containing the result of the reunion OR
 *  NULL if there is no memory available to allocate for the new set
 */
struct cm_arrayset* cm_arrayset_reunion(const struct cm_arrayset* set1,
                                        const struct cm_arrayset* set2);
/*
 * Description:
 *  Creates a new ArraySet containing the result of the intersection
 *  between 2 other sets.
 * Parameters:
 *  set1, set2 - the sets who are going to be intersected
 * Returns:
 *  A pointer to the ArraySet containing the result of the intersection OR
 *  NULL if there is no memory available to allocate for the new set
 */
struct cm_arrayset* cm_arrayset_intersection(const struct cm_arrayset* set1,
                                             const struct cm_arrayset* set2);
/*
 * Description:
 *  Creates a new ArraySet containing the result of the difference
 *  between the first set and the last set.
 * Parameters:
 *  mainSet - the set which will evaluated according to the secondary set
 *  secondarySet - the set containing the objects which will be eliminated
 *        from the main set.
 * Returns:
 *  A pointer to the ArraySet containing the result of set1 \ set2
 *  (the difference between set1 and set2) OR
 *  NULL if there is no memory available to allocate for the new set
 */
struct cm_arrayset* cm_arrayset_difference(
        const struct cm_arrayset* main_set,
        const struct cm_arrayset* secondary_set);

#endif /* CM_ARRAYSET_H_ */
