#include <stdint.h>

#include "cm_g711_tests.h"
#include "../cm_test_base.h"

#include "cmantras/media/cm_g711.h"

void cm_g711_mu_law_encode_decode__value__is_encoded_decoded()
{
    int8_t val = cm_g711_mu_law_encode(-3);
    int16_t val_2 = cm_g711_mu_law_decode(val);
    assert_is_true( (val_2 >= -4) && (val_2 <= -2), __func__);
}

void cm_g711_a_law_encode_decode__value__is_encoded_decoded()
{
    int8_t val = cm_g711_a_law_encode(-3);
    int16_t val_2 = cm_g711_a_law_decode(val);
    assert_is_true( (val_2 == -3), __func__);
}

void cm_g711_run_tests(void)
{
    cm_g711_mu_law_encode_decode__value__is_encoded_decoded();
    cm_g711_a_law_encode_decode__value__is_encoded_decoded();
}

