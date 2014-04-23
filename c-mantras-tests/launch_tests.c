#include "cm_test_base.h"
#include "cm_helpers_tests.h"
#include "cm_string_tests.h"

int main(void)
{
    cmhelpers_runTests();
    cmstring_runTests();
    return 0;
}

