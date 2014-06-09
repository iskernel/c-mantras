#include "base/base_tests.h"
#include "collections/collections_tests.h"
#include "cryptography/cryptography_tests.h"
#include "media/media_tests.h"
#include "memory/memory_tests.h"
#include "text/text_tests.h"

int main(void)
{
    base_run_tests();
    collections_run_tests();
    cryptography_run_tests();
    media_run_tests();
    memory_run_tests();
    numeric_run_tests();
    text_run_tests();
    return 0;
}

