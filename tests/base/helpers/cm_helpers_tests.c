#include <stdbool.h>

#include "../../cm_tests_configuration.h"
#include "../../cm_test_base.h"

#include "cm_helpers_tests.h"
#include "cm_text_tests.h"
#include "cm_numeric_tests.h"
#include "cm_generic_tests.h"

void cm_helpers_tests()
{
	run_if(RUN_CM_TEXT_TESTS, "Base/Helpers/cm_text", &cm_text_tests_run);
	run_if(RUN_CM_NUMERIC_TESTS, "Base/Helpers/cm_numeric", &cm_numeric_tests_run);
	run_if(RUN_CM_GENERIC_TESTS, "Base/Helpers/cm generic", &cm_generic_run_tests);
}
