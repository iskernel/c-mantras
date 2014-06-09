#include "numeric_tests.h"
#include "cm_narray_tests.h"
#include "cm_nmatrix_tests.h"

#include "../cm_test_base.h"
#include "../cm_tests_configuration.h"

void numeric_run_tests(void)
{
	run_if(RUN_CM_NARRAY, "cm narray", &cm_narray_run_tests);
	run_if(RUN_CM_NMATRIX, "cm nmatrix", &cn_matrix_run_tests);
}
