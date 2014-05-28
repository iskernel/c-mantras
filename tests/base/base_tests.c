#include "../cm_tests_configuration.h"
#include "../cm_test_base.h"

#include "base_tests.h"
#include "helpers/cm_helpers_tests.h"
#include "cm_operations_tests.h"

void base_run_tests(void)
{
	run_if(RUN_BASE_TESTS, "Base tests", &cm_helpers_tests);
	run_if(RUN_CM_OPERATIONS_TESTS, "cm operations", &cm_operations_tests);

}
