#include "cm_cryptography_tests.h"
#include "cm_classical_ciphers_tests.h"

#include "../cm_test_base.h"
#include "../cm_tests_configuration.h"

void cryptography_run_tests(void)
{
    run_if(RUN_CM_CLASSICAL_CIPHERS, "cm_classical_ciphers", &cm_classical_ciphers_tests_run);
}
