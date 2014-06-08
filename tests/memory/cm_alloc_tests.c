#include <stdlib.h>

#include "../cm_test_base.h"

#include "cm_alloc_tests.h"
#include "cmantras/memory/cm_nalloc.h"

void cm_nalloc_free_1d__alloc__is_allocated()
{
    char* character = NULL;
    character = cm_nalloc_1d(character, 10, sizeof(char));
    cm_nfree_1d(character);

    assert_win(__func__);
}

void cm_nalloc_free_2d__alloc__is_allocated()
{
    char** character = NULL;
    character = (char**)cm_nalloc_2d((void**)character, 10, 10, sizeof(char));
    cm_nfree_2d((void**)character, 10);

    assert_win(__func__);
}

void cm_nalloc_free_3d__alloc__is_allocated()
{
    char*** character = NULL;
    character = (char***)cm_nalloc_3d((void***)character, 10, 10, 10, sizeof(char));
    cm_nfree_3d((void***)character, 10, 10);

    assert_win(__func__);
}

void cm_nalloc_free_4d__alloc__is_allocated()
{
    char**** character = NULL;
    character = (char****)cm_nalloc_4d((void****)character, 10, 10, 10, 10, sizeof(char));
    cm_nfree_4d((void****)character, 10, 10, 10);

    assert_win(__func__);
}

void cm_alloc_run(void)
{
    cm_nalloc_free_1d__alloc__is_allocated();
    cm_nalloc_free_2d__alloc__is_allocated();
    cm_nalloc_free_3d__alloc__is_allocated();
    cm_nalloc_free_4d__alloc__is_allocated();
}
