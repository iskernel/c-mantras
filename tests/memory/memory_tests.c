#include "memory_tests.h"
#include "cm_alloc_tests.h"
#include "../cm_tests_configuration.h"

#include "cmantras/memory/cm_nalloc.h"

void memory_run_tests(void)
{
    run_if(RUN_CM_NALLOC, "cm nalloc", &cm_alloc_run);
}
