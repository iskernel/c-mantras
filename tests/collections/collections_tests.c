#include <stdbool.h>

#include "collections_tests.h"
#include "cm_lists_tests.h"
#include "cm_array_tests.h"
#include "cm_arrayset_tests.h"
#include "cm_searching_tests.h"

#include "../cm_test_base.h"
#include "../cm_tests_configuration.h"

void collections_run_tests(void)
{
    run_if(RUN_CM_ARRAY_TESTS, "cm_array", &cm_array_run_tests);
    run_if(RUN_CM_ARRAY_SET_TESTS, "cm_arrayset", &cm_arrayset_run_tests);
    run_if(RUN_CM_LIST_TESTS, "cm_list", &cm_list_run_tests);
    run_if(RUN_CM_SEARCHING_TESTS, "cm_searching", &cm_searching_run_tests);
}
