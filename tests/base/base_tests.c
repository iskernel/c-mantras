#include "base_tests.h"
#include "cm_helpers_tests.h"
#include "cm_string_tests.h"

void base_run_tests(void)
{
	cm_helpers_run_tests();
	cm_string_run_tests();
}
