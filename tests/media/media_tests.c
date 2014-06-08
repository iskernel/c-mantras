#include "media_tests.h"

#include "cm_colorspace_tests.h"
#include "cm_g711_tests.h"

#include "../cm_tests_configuration.h"
#include "../cm_test_base.h"

void media_run_tests(void)
{
    run_if(RUN_CM_COLORSPACE, "cm_colorspace", &cm_colorspace_run_tests);
    run_if(RUN_CM_G711, "cm_g711", &cm_g711_run_tests);
}
