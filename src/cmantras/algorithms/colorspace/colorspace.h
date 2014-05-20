#ifndef COLORSPACES_H_
#define COLORSPACES_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

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


typedef struct
{
	double R;
	double G;
	double B;
}RgbFColor;

typedef struct
{
	uint8_t R;
	uint8_t G;
	uint8_t B;
}RgbIColor;

typedef struct
{
	double H;
	double S;
	double I;
}HsiColor;

typedef struct
{
	double H;
	double S;
	double L;
}HslColor;

typedef struct
{
	double H;
	double S;
	double V;
}HsvColor;

typedef struct
{
	double Y;
	double I;
	double Q;
}YiqColor;

typedef struct
{
	double Y;
	double U;
	double V;
}YuvColor;

bool RgbF_IsValid(double r, double g, double b);
bool Hsi_IsValid(double h, double s, double i);
bool RgbI_IsValid(uint8_t r, uint8_t g, uint8_t b);
bool Hsl_IsValid(double h, double s, double l);
bool Hsv_IsValid(double h, double s, double v);
bool Yiq_IsValid(double y, double i, double q);
bool Yuv_IsValid(double y, double u, double v);

RgbIColor* RgbI_Create(uint8_t r, uint8_t g, uint8_t b);
RgbIColor* RgbI_CreateFromRealForm(double r, double g, double b);

RgbFColor* RgbF_Create(double r, double g, double b);
RgbFColor* RgbF_CreateFromIntegerForm(uint8_t r, uint8_t g, uint8_t b);
RgbFColor* RgbF_CreateFromHsi(double h, double s, double i);
RgbFColor* RgbF_CreateFromHsl(double h, double s, double l);
RgbFColor* RgbF_CreateFromHsv(double h, double s, double v);
RgbFColor* RgbF_CreateFromYiq(double y, double i, double q);
RgbFColor* RgbF_CreateFromYuv(double y, double u, double v);

HsiColor* Hsi_Create(double h, double s, double i);
HsiColor* Hsi_CreateFromRgbF(double r, double g, double b);

HslColor* Hsl_Create(double h, double s, double l);
HslColor* Hsl_CreateFromRgbF(double r, double g, double b);

HsvColor* Hsv_Create(double h, double s, double v);
HsvColor* Hsv_CreateFromRgbF(double r, double g, double b);

YiqColor* Yiq_Create(double y, double i, double q);
YiqColor* Yiq_CreateFromRgbF(double r, double g, double b);

YuvColor* Yuv_Create(double y, double u, double v);
YuvColor* Yuv_CreateFromRgbF(double r, double g, double f);


#endif /* COLORSPACES_H_ */
