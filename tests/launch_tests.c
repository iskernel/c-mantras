#include "cm_test_base.h"
#include "base/base_tests.h"
#include "numeric/numeric_tests.h"

int main(void)
{
	puts("BASE TESTS");
	//base_run_tests();
	numeric_run_tests();
    return 0;
}

