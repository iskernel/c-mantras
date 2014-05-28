#include <string.h>
#include <stdlib.h>

#include "cm_generic.h"
#include "../cm_error_log.h"

void cm_swap_content ( void* a, void* b, size_t size)
{
    void* temp = NULL;

    cm_error_log_critical_if( (a == NULL), __func__, "a is null");

    temp = malloc(size);
    memcpy(temp, b,    size);
    memcpy(b,    a,    size);
    memcpy(a,    temp, size);

    free(temp);
}
