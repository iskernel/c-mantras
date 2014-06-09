#include "text_tests.h"
#include "../cm_tests_configuration.h"
#include "../cm_test_base.h"

void text_run_tests(void)
{
    run_if(RUN_CM_STRING, "cm text", &cm_string_run_tests);
}
