#include <stdbool.h>

#include "cmantras/base/helpers/cm_numeric.h"
#include "cmantras/base/cm_error_log.h"
#include "cm_colorspace.h"

/*The lower limit for R, G, B (real version), S, I*/
#define PER_LOWER_LIMIT (0.0f)
/*The upper limit for R, G, B (real version), S, I*/
#define PER_UPPER_LIMIT (1.0f)
/*The lower limit for H*/
#define HUE_LOWER_LIMIT (0.0f)
/*The upper limit for H*/
#define HUE_UPPER_LIMIT (360.0f)
/*The lower limit for R, G, B (integer version)*/
#define RGBI_LOWER_LIMIT (0U)
/*The upper limit for R, G, B (integer version)*/
#define RGBI_UPPER_LIMIT (255U)
/*The upper limit for I in YIQ*/
#define YIQ_I_UPPER_LIMIT (0.5957f)
/*The lower limit for I in YIQ*/
#define YIQ_I_LOWER_LIMIT (-0.5957f)
/*The upper limit for Q in YIQ*/
#define YIQ_Q_UPPER_LIMIT (0.5226f)
/*The lower limit for Q in YIQ*/
#define YIQ_Q_LOWER_LIMIT (-0.5226f)
/*The upper limit for U in YUV*/
#define YUV_U_UPPER_LIMIT (0.436f)
/*The lower limit for U in YUV*/
#define YUV_U_LOWER_LIMIT (-0.436f)
/*The upper limit for V in YUV*/
#define YUV_V_UPPER_LIMIT (0.615f)
/*The lower limit for V in YUV*/
#define YUV_V_LOWER_LIMIT (-0.615f)

static bool cm_rgb_f_is_valid(double r, double g, double b)
{
    bool is_valid = true;
    if ((double_is_within(r, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (double_is_within(g, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (double_is_within(b, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false))
    {
        is_valid = false;
    }
    return is_valid;
}

static bool cm_hsi_is_valid(double h, double s, double i)
{
    bool isValid = true;
    if ((double_is_within(h, HUE_LOWER_LIMIT, HUE_UPPER_LIMIT) == false)
            || (double_is_within(s, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (double_is_within(i, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false))
    {
        isValid = false;
    }
    return isValid;
}

static bool cm_rgb_i_is_valid(uint8_t r, uint8_t g, uint8_t b)
{
    bool isValid = true;
    if ((uint8_is_within(r, RGBI_LOWER_LIMIT, RGBI_UPPER_LIMIT) == false)
            || (uint8_is_within(g, RGBI_LOWER_LIMIT, RGBI_UPPER_LIMIT) == false)
            || (uint8_is_within(b, RGBI_LOWER_LIMIT, RGBI_UPPER_LIMIT) == false))
    {
        isValid = false;
    }
    return isValid;
}

static bool cm_hsl_is_valid(double h, double s, double l)
{
    bool isValid = true;
    if ((double_is_within(h, HUE_LOWER_LIMIT, HUE_UPPER_LIMIT) == false)
            || (double_is_within(s, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (double_is_within(l, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false))
    {
        isValid = false;
    }
    return isValid;
}

static bool cm_hsv_is_valid(double h, double s, double v)
{
    bool isValid = true;
    if ((double_is_within(h, HUE_LOWER_LIMIT, HUE_UPPER_LIMIT) == false)
            || (double_is_within(s, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (double_is_within(v, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false))
    {
        isValid = false;
    }
    return isValid;
}

static bool cm_yiq_is_valid(double y, double i, double q)
{
    bool isValid = true;
    if ((double_is_within(y, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (double_is_within(i, YIQ_I_LOWER_LIMIT, YIQ_I_UPPER_LIMIT)
                    == false)
            || (double_is_within(q, YIQ_Q_LOWER_LIMIT, YIQ_Q_UPPER_LIMIT)
                    == false))
    {
        isValid = false;
    }
    return isValid;
}

static bool cm_yuv_is_valid(double y, double u, double v)
{
    bool isValid = true;
    if ((double_is_within(y, PER_LOWER_LIMIT, PER_UPPER_LIMIT) == false)
            || (double_is_within(u, YUV_U_LOWER_LIMIT, YUV_U_UPPER_LIMIT)
                    == false)
            || (double_is_within(v, YUV_V_LOWER_LIMIT, YUV_V_UPPER_LIMIT)
                    == false))
    {
        isValid = false;
    }
    return isValid;
}

struct cm_rgb_f_color* cm_rgb_f_create(double r, double g, double b)
{
    struct cm_rgb_f_color* color = NULL;
    if (cm_rgb_f_is_valid(r, g, b) == true)
    {
        color = malloc(sizeof(struct cm_rgb_f_color));
        if (color != NULL)
        {
            color->R = r;
            color->G = g;
            color->B = b;
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_rgb_i_color* cm_rgb_i_create(uint8_t r, uint8_t g, uint8_t b)
{
    struct cm_rgb_i_color* color = NULL;
    if (cm_rgb_i_is_valid(r, g, b) == true)
    {
        color = malloc(sizeof(struct cm_rgb_f_color));
        if (color != NULL)
        {
            color->R = r;
            color->G = g;
            color->B = b;
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_hsi_color* cm_hsi_create(double h, double s, double i)
{
    struct cm_hsi_color* color = NULL;
    if (cm_hsi_is_valid(h, s, i) == true)
    {
        color = malloc(sizeof(struct cm_hsi_color));
        if (color != NULL)
        {
            color->H = h;
            color->S = s;
            color->I = i;
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_hsl_color* cm_hsl_create(double h, double s, double l)
{
    struct cm_hsl_color* color = NULL;
    if (cm_hsl_is_valid(h, s, l) == true)
    {
        color = malloc(sizeof(struct cm_hsl_color));
        if (color != NULL)
        {
            color->H = h;
            color->S = s;
            color->L = l;
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_hsv_color* cm_hsv_create(double h, double s, double v)
{
    struct cm_hsv_color* color = NULL;
    if (cm_hsv_is_valid(h, s, v) == true)
    {
        color = malloc(sizeof(struct cm_hsv_color));
        if (color != NULL)
        {
            color->H = h;
            color->S = s;
            color->V = v;
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_yiq_color* cm_yiq_create(double y, double i, double q)
{
    struct cm_yiq_color* color = NULL;
    if (cm_yiq_is_valid(y, i, q) == true)
    {
        color = malloc(sizeof(struct cm_yiq_color));
        if (color != NULL)
        {
            color->Y = y;
            color->I = i;
            color->Q = q;
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_yuv_color* cm_yuv_create(double y, double u, double v)
{
    struct cm_yuv_color* color = NULL;
    if (cm_yiq_is_valid(y, u, v) == true)
    {
        color = malloc(sizeof(struct cm_yuv_color));
        if (color != NULL)
        {
            color->Y = y;
            color->U = u;
            color->V = v;
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_rgb_f_color* cm_rgb_f_from_hsi(double h, double s, double i)
{
    struct cm_rgb_f_color* color = NULL;
    if (cm_hsi_is_valid(h, s, i) == true)
    {
        color = cm_rgb_f_create(0.0f, 0.0f, 0.0f);
        if (h >= 0.0f && h <= (HUE_UPPER_LIMIT / 3.0f))
        {
            color->B = (1.0f / 3.0f) * (1.0f - s);
            color->R = (1.0f / 3.0f) * ((s * cos(h)) / cos(60.0f - h));
            color->G = 1.0f - (color->B + color->R);
        }
        else if (h > (HUE_UPPER_LIMIT / 3.0f)
                && h <= (2.0f * HUE_UPPER_LIMIT / 3.0f))
        {
            h -= (HUE_UPPER_LIMIT / 3.0f);
            color->R = (1.0f / 3.0f) * (1.0f - s);
            color->G = (1.0f / 3.0f) * ((s * cos(h)) / cos(60.0f - h));
            color->B = 1.0f - (color->G + color->R);

        }
        else /* h>240 h<360 */
        {
            h -= (2.0f * HUE_UPPER_LIMIT / 3.0f);
            color->G = (1.0f / 3.0f) * (1.0f - s);
            color->B = (1.0f / 3.0f) * ((s * cos(h)) / cos(60.0f - h));
            color->R = 1.0f - (color->G + color->B);
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_rgb_f_color* cm_rgb_f_from_hsl(double h, double s, double l)
{
    struct cm_rgb_f_color* color = NULL;
    double c = 0.0f, m = 0.0f, x = 0.0f;
    if (cm_hsl_is_valid(h, s, l) == true)
    {
        c = (1.0f - fabs(2 * l - 1.0f)) * s;
        m = 1.0f * (l - 0.5f * c);
        x = c * (1.0f - fabs(fmod(h / 60.0f, 2) - 1.0f));
        if (h >= 0.0f && h < (HUE_UPPER_LIMIT / 6.0f))
        {
            color = cm_rgb_f_create(c + m, x + m, m);
        }
        else if (h >= (HUE_UPPER_LIMIT / 6.0f) && h < (HUE_UPPER_LIMIT / 3.0f))
        {
            color = cm_rgb_f_create(x + m, c + m, m);
        }
        else if (h < (HUE_UPPER_LIMIT / 3.0f) && h < (HUE_UPPER_LIMIT / 2.0f))
        {
            color = cm_rgb_f_create(m, c + m, x + m);
        }
        else if (h >= (HUE_UPPER_LIMIT / 2.0f)
                && h < (2.0f * HUE_UPPER_LIMIT / 3.0f))
        {
            color = cm_rgb_f_create(m, x + m, c + m);
        }
        else if (h >= (2.0f * HUE_UPPER_LIMIT / 3.0f)
                && h < (5.0f * HUE_UPPER_LIMIT / 6.0f))
        {
            color = cm_rgb_f_create(x + m, m, c + m);
        }
        else if (h >= (5.0f * HUE_UPPER_LIMIT / 6.0f) && h < HUE_UPPER_LIMIT)
        {
            color = cm_rgb_f_create(c + m, m, x + m);
        }
        else
        {
            color = cm_rgb_f_create(m, m, m);
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_rgb_f_color* cm_rgb_f_from_hsv(double h, double s, double v)
{
    double c = 0.0f, m = 0.0f, x = 0.0f;
    struct cm_rgb_f_color* color = NULL;
    if (cm_hsv_is_valid(h, s, v) == true)
    {
        c = v * s;
        x = c * (1.0f - fabs(fmod(h / 60.0f, 2) - 1.0f));
        m = v - c;
        if (h >= 0.0f && h < 60.0f)
        {
            color = cm_rgb_f_create(c + m, x + m, m);
        }
        else if (h >= 60.0f && h < 120.0f)
        {
            color = cm_rgb_f_create(x + m, c + m, m);
        }
        else if (h >= 120.0f && h < 180.0f)
        {
            color = cm_rgb_f_create(m, c + m, x + m);
        }
        else if (h >= 180.0f && h < 240.0f)
        {
            color = cm_rgb_f_create(m, x + m, c + m);
        }
        else if (h >= 240.0f && h < 300.0f)
        {
            color = cm_rgb_f_create(x + m, m, c + m);
        }
        else if (h >= 300.0f && h < 360.0f)
        {
            color = cm_rgb_f_create(c + m, m, x + m);
        }
        else
        {
            color = cm_rgb_f_create(m, m, m);
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_rgb_f_color* cm_rgb_f_from_yiq(double y, double i, double q)
{
    struct cm_rgb_f_color* color = NULL;
    if (cm_yiq_is_valid(y, i, q) == true)
    {
        color = cm_rgb_f_create(0.0f, 0.0f, 0.0f);
        color->R = y + 0.9563f * i + 0.62100 * q;
        color->G = y - 0.2721f * i - 0.6474f * q;
        color->B = y - 1.1070f * i + 1.7046f * q;
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_rgb_f_color* cm_rgb_f_from_yuv(double y, double u, double v)
{
    struct cm_rgb_f_color* color = NULL;
    if (cm_yuv_is_valid(y, u, v) == true)
    {
        color = cm_rgb_f_create(0.0f, 0.0f, 0.0f);
        color->R = y + 1.140f * v;
        color->G = y - 0.395f * u - 0.581f * v;
        color->B = y + 2.032f * u;
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_hsi_color* cm_hsi_from_rgb_f(double r, double g, double b)
{
    struct cm_hsi_color* color = NULL;
    double m = double_get_min(r, g, b);
    double M = double_get_max(r, g, b);
    double c = M - m;
    if (cm_rgb_f_is_valid(r, g, b) == true)
    {
        color = malloc(sizeof(struct cm_hsi_color));
        color->I = (1.0f / 3.0f) * (r + g + b);
        if (c == 0)
        {
            color->H = 0.0f;
            color->S = 0.0f;
        }
        else
        {
            if (M == r)
            {
                color->H = fmod(((g - b) / c), 6);
            }
            else if (M == g)
            {
                color->H = (b - r) / c + 2.0f;
            }
            else if (M == b)
            {
                color->H = (r - g) / c + 4.0f;
            }
            color->H *= 60.0f;
            color->S = 1.0f - (m / color->I);
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_hsl_color* cm_hsl_from_rgb_f(double r, double g, double b)
{
    double M = 0.0f, m = 0.0f, c = 0.0f;
    struct cm_hsl_color* color = NULL;
    if (cm_rgb_f_is_valid(r, g, b) == true)
    {
        M = double_get_max(r, g, b);
        m = double_get_min(r, g, b);
        c = M - m;
        color = cm_hsl_create(0.0f, 0.0f, 0.0f);
        color->L = 0.5f * (M + m);
        if (c != 0.0f)
        {
            if (M == r)
            {
                color->H = fmod(((g - b) / c), 6.0f);
            }
            else if (M == g)
            {
                color->H = ((b - r) / c) + 2.0f;
            }
            else/*if(M==b)*/
            {
                color->H = ((r - g) / c) + 4.0f;
            }
            color->H *= 60.0f;
            color->S = c / (1.0f - fabs(2.0f * color->L - 1.0f));
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_hsv_color* cm_hsv_from_rgb_f(double r, double g, double b)
{
    double M = 0.0f, m = 0.0f, c = 0.0f;
    struct cm_hsv_color* color = NULL;
    if (cm_rgb_f_is_valid(r, g, b) == true)
    {
        color = cm_hsv_create(0.0f, 0.0f, 0.0f);
        M = double_get_max(3, r, g, b);
        m = double_get_min(3, r, g, b);
        c = M - m;
        color->V = M;
        if (c != 0.0f)
        {
            if (M == r)
            {
                color->H = fmod(((g - b) / c), 6);
            }
            else if (M == g)
            {
                color->H = (b - r) / c + 2.0f;
            }
            else /*if(M==b)*/
            {
                color->H = (r - g) / c + 4.0f;
            }
            color->H *= 60.0f;
            color->S = c / color->V;
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_yiq_color* cm_yiq_from_rgb_f(double r, double g, double b)
{
    struct cm_yiq_color* color = NULL;
    if (cm_rgb_f_is_valid(r, g, b) == true)
    {
        color = cm_yiq_create(0.0f, 0.0f, 0.0f);
        color->Y = 0.299900f * r + 0.58700f * b + 0.11400f * b;
        color->I = 0.595716f * r - 0.274453 * b - 0.321264 * b;
        color->Q = 0.211456f * r - 0.522591 * b + 0.31135f * b;
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_yuv_color* cm_yuv_from_rgb_f(double r, double g, double b)
{
    struct cm_yuv_color* color = NULL;
    if (cm_rgb_f_is_valid(r, g, b) == true)
    {
        color = cm_yuv_create(0.0f, 0.0f, 0.0f);
        color->Y = 0.299f * r + 0.587f * b + 0.114f * b;
        color->U = 0.492f * (b - color->Y);
        color->V = 0.877f * (r - color->Y);
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_rgb_i_color* cm_rgb_i_from_rgb_f(double r, double g, double b)
{
    struct cm_rgb_i_color* color = NULL;
    if (cm_rgb_f_is_valid(r, g, b) == true)
    {
        color = malloc(sizeof(struct cm_rgb_i_color));
        if (color != NULL)
        {
            color->R = (uint8_t) (r * (double) RGBI_UPPER_LIMIT + 0.5f);
            color->G = (uint8_t) (g * (double) RGBI_UPPER_LIMIT + 0.5f);
            color->B = (uint8_t) (b * (double) RGBI_UPPER_LIMIT + 0.5f);
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

struct cm_rgb_f_color* cm_rgb_f_from_rgb_i(uint8_t r, uint8_t g, uint8_t b)
{
    struct cm_rgb_f_color* color = NULL;
    if (cm_rgb_i_is_valid(r, g, b) == true)
    {
        color = malloc(sizeof(struct cm_rgb_f_color));
        if (color != NULL)
        {
            color->R = (double) (r) / (double) (RGBI_UPPER_LIMIT);
            color->G = (double) (g) / (double) (RGBI_UPPER_LIMIT);
            color->B = (double) (b) / (double) (RGBI_UPPER_LIMIT);
        }
    }
    else
    {
        cm_error_log_critical(__func__, "Invalid values for color");
    }
    return color;
}

