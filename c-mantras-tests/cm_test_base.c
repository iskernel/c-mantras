#include<cm_test_base.h>

void assert_is_true(bool condition, const char* testName)
{
    if(condition == true)
    {
        printf("%s SUCCEEDED\n", testName);
    }
    else
    {
        printf("%s FAILED\n", testName);
    }
}
