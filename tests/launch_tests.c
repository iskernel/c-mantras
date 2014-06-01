#include "base/base_tests.h"
#include "collections/collections_tests.h"
#include "cryptography/cm_cryptography_tests.h"

int main(void)
{
    base_run_tests();
    collections_run_tests();
    cryptography_run_tests();
    return 0;
}

