#include "cm_colorspace_tests.h"

#include "../cm_test_base.h"
#include "cmantras/base/helpers/cm_numeric.h"
#include "cmantras/media/cm_colorspace.h"

static void cm_rgb_f_create__normal_scenario__is_created(void)
{
    struct cm_rgb_f_color* color = cm_rgb_f_create(0.2, 0.3, 0.1);
    assert_is_true( (color != NULL), __func__ );

    free(color);
}

static void cm_rgb_i_create__normal_scenario__is_created(void)
{
    struct cm_rgb_i_color* color = cm_rgb_i_create(20, 30, 40);

    assert_is_true( (color != NULL), __func__ );

    free(color);
}

static void cm_hsi_create__normal_scenario__is_created(void)
{
    struct cm_hsi_color *color = cm_hsi_create(0.3, 0.3, 0.3);

    assert_is_true( (color != NULL), __func__ );

    free(color);
}

static void cm_hsl_create__normal_scenario__is_created(void)
{
    struct cm_hsl_color *color = cm_hsl_create(0.3, 0.3, 0.3);

    assert_is_true( (color != NULL), __func__ );

    free(color);
}

static void cm_hsv_create__normal_scenario__is_created(void)
{
    struct cm_hsv_color *color = cm_hsv_create(0.3, 0.3, 0.3);

    assert_is_true( (color != NULL), __func__ );

    free(color);
}

static void cm_yiq_create__normal_scenario__is_created(void)
{
    struct cm_yiq_color *color = cm_yiq_create(0.3, 0.3, 0.3);

    assert_is_true( (color != NULL), __func__ );

    free(color);
}

static void cm_yuv_create__normal_scenario__is_created(void)
{
    struct cm_yuv_color *color = cm_yuv_create(0.3, 0.3, 0.3);

    assert_is_true( (color != NULL), __func__ );

    free(color);
}

static void cm_rgb_f_from_hsi__normal_scenario__is_created(void)
{
    struct cm_rgb_f_color* color_f = cm_rgb_f_from_hsi(200.0, 0.2, 0.2);
    struct cm_rgb_i_color* color_i = cm_rgb_i_from_rgb_f(color_f->R, color_f->G, color_f->B);
    bool condition = (color_i->R == 41)
                     && (color_i->G == 53)
                     && (color_i->B == 59);

    assert_is_true(condition, __func__);

    free(color_f);
    free(color_i);
}

static void cm_rgb_f_from_hsl__normal_scenario__is_created(void)
{
    struct cm_rgb_f_color* color_f = cm_rgb_f_from_hsl(200.0, 0.2, 0.2);
    struct cm_rgb_i_color* color_i = cm_rgb_i_from_rgb_f(color_f->R, color_f->G, color_f->B);
    bool condition = (color_i->R == 41)
                     && (color_i->G == 54)
                     && (color_i->B == 61);

    assert_is_true(condition, __func__);

    free(color_f);
    free(color_i);
}

static void cm_rgb_f_from_hsv__normal_scenario__is_created(void)
{
    struct cm_rgb_f_color* color_f = cm_rgb_f_from_hsv(200.0, 0.2, 0.2);
    struct cm_rgb_i_color* color_i = cm_rgb_i_from_rgb_f(color_f->R, color_f->G, color_f->B);
    bool condition = (color_i->R == 41)
                     && (color_i->G == 48)
                     && (color_i->B == 51);

    assert_is_true(condition, __func__);

    free(color_f);
    free(color_i);
}

static void cm_rgb_f_from_yuv__normal_scenario__is_created(void)
{
    struct cm_rgb_f_color* color_f = cm_rgb_f_from_yuv(0.083, 0.044, 0.038);
    struct cm_rgb_i_color* color_i = cm_rgb_i_from_rgb_f(color_f->R, color_f->G, color_f->B);
    bool condition = (color_i->R == 32)
                     && (color_i->G == 11)
                     && (color_i->B == 44);

    assert_is_true(condition, __func__);

    free(color_f);
    free(color_i);
}

static void cm_rgb_f_from_yiq__normal_scenario__is_created(void)
{
    struct cm_rgb_f_color* color_f = cm_rgb_f_from_yiq(0.083, 0.007, 0.058);
    struct cm_rgb_i_color* color_i = cm_rgb_i_from_rgb_f(color_f->R, color_f->G, color_f->B);
    bool condition = (color_i->R == 32)
                     && (color_i->G == 11)
                     && (color_i->B == 44);

    assert_is_true(condition, __func__);

    free(color_f);
    free(color_i);
}

static void cm_hsi_from_rgb_f__normal_scenario__is_created(void)
{
    struct cm_hsi_color* color = cm_hsi_from_rgb_f(0.12, 0.04, 0.17);
    bool condition = double_is_within(color->H, 276, 279)
                     && double_is_within(color->S, 0.6, 0.67)
                     && double_is_within(color->I, 0.11, 0.12);

    assert_is_true(condition, __func__);

    free(color);
}

static void cm_hsv_from_rgb_f__normal_scenario__is_created(void)
{
    struct cm_hsv_color* color = cm_hsv_from_rgb_f(0.12, 0.04, 0.17);
    bool condition = double_is_within(color->H, 276, 279)
                     && double_is_within(color->S, 0.7, 0.8)
                     && double_is_within(color->V, 0.1, 0.2);

    assert_is_true(condition, __func__);

    free(color);
}

static void cm_hsl_from_rgb_f__normal_scenario__is_created(void)
{
    struct cm_hsl_color* color = cm_hsl_from_rgb_f(0.12, 0.04, 0.17);
    bool condition = double_is_within(color->H, 276, 279)
                     && double_is_within(color->S, 0.55, 0.65)
                     && double_is_within(color->L, 0.09, 0.11);

    assert_is_true(condition, __func__);

    free(color);
}

static void cm_yiq_from_rgb_f__normal_scenario__is_created(void)
{
    struct cm_yiq_color* color = cm_yiq_from_rgb_f(0.12, 0.04, 0.17);
    bool condition = double_is_within(color->Y, 0.075, 0.085)
                     && double_is_within(color->I, 0.0055, 0.007)
                     && double_is_within(color->Q, 0.05, 0.06);

    assert_is_true(condition, __func__);

    free(color);
}

static void cm_yuv_from_rgb_f__normal_scenario__is_created(void)
{
    struct cm_yuv_color* color = cm_yuv_from_rgb_f(0.12, 0.04, 0.17);
    bool condition = double_is_within(color->Y, 0.075, 0.085)
                     && double_is_within(color->U, 0.04, 0.05)
                     && double_is_within(color->V, 0.03, 0.04);

    assert_is_true(condition, __func__);

    free(color);
}

static void cm_rgb_i_from_rgb_f__normal_scenario__is_created(void)
{
    struct cm_rgb_f_color* color_f = cm_rgb_f_from_rgb_i(32,11,44);
    struct cm_rgb_i_color* color = cm_rgb_i_from_rgb_f(color_f->R, color_f->G, color_f->B);
    bool condition = (color->R == 32)
                      && (color->G == 11)
                      && (color->B == 44);
    assert_is_true(condition, __func__);

    free(color_f);
    free(color);
}

void cm_colorspace_run_tests(void)
{
    cm_rgb_f_create__normal_scenario__is_created();
    cm_rgb_i_create__normal_scenario__is_created();
    cm_hsi_create__normal_scenario__is_created();
    cm_hsl_create__normal_scenario__is_created();
    cm_hsv_create__normal_scenario__is_created();
    cm_yiq_create__normal_scenario__is_created();
    cm_yuv_create__normal_scenario__is_created();
    cm_rgb_f_from_hsi__normal_scenario__is_created();
    cm_rgb_f_from_hsl__normal_scenario__is_created();
    cm_rgb_f_from_hsv__normal_scenario__is_created();
    cm_rgb_f_from_yuv__normal_scenario__is_created();
    cm_rgb_f_from_yiq__normal_scenario__is_created();
    cm_hsi_from_rgb_f__normal_scenario__is_created();
    cm_hsv_from_rgb_f__normal_scenario__is_created();
    cm_hsl_from_rgb_f__normal_scenario__is_created();
    cm_yiq_from_rgb_f__normal_scenario__is_created();
    cm_yuv_from_rgb_f__normal_scenario__is_created();
    cm_rgb_i_from_rgb_f__normal_scenario__is_created();
}
