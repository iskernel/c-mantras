#ifndef COLORSPACES_H_
#define COLORSPACES_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

struct cm_rgb_f_color
{
    double R;
    double G;
    double B;
};

struct cm_rgb_i_color
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
};

struct cm_hsi_color
{
    double H;
    double S;
    double I;
};

struct cm_hsl_color
{
    double H;
    double S;
    double L;
};

struct cm_hsv_color
{
    double H;
    double S;
    double V;
};

struct cm_yiq_color
{
    double Y;
    double I;
    double Q;
};

struct cm_yuv_color
{
    double Y;
    double U;
    double V;
};

/*
 * Description:
 * 	Checks if the RGB components are valid
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */
bool cm_rgb_f_is_valid(double r, double g, double b);
/*
 * Description:
 * 	Checks if the HSI components are valid
 * Parameters:
 * 	h,s,i - the components of an HSI model expressed
 * 			as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */
bool cm_hsi_is_valid(double h, double s, double i);
/*
 * Description:
 * 	Checks if the RGB components are valid
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as natural numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */
bool cm_rgb_i_is_valid(uint8_t r, uint8_t g, uint8_t b);
/*
 * Description:
 * 	Checks if the HSL components are valid
 * Parameters:
 * 	h,s,l - the components of an HSL model expressed
 * 			as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */
bool cm_hsl_is_valid(double h, double s, double l);
/*
 * Description:
 * 	Checks if the HSV components are valid
 * Parameters:
 * 	h,s,v - the components of an HSV model expressed
 * 			as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */
bool cm_hsv_is_valid(double h, double s, double v);
/*
 * Description:
 * 	Checks if the YIQ components are valid
 * Parameters:
 * 	y,i,q - the components of an YIQ model expressed
 * 			as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */
bool cm_yiq_is_valid(double y, double i, double q);
/*
 * Description:
 * 	Checks if the YUV components are valid
 * Parameters:
 * 	y,u,v - the components of an YUV model expressed
 * 			as real numbers
 * Returns:
 *  true if the values are correct
 *  false if the values are incorrect
 */
bool cm_yuv_is_valid(double y, double u, double v);
/*
 * Description:
 * 	Creates a cm_rgb_i_color structure
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_rgb_i_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_rgb_i_color* cm_rgb_i_create(uint8_t r, uint8_t g, uint8_t b);
/*
 * Description:
 * 	Creates a cm_rgb_i_color structure
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_rgb_i_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_rgb_i_color* cm_rgb_i_from_rgb_f(double r, double g, double b);
/*
 * Description:
 * 	Creates a cm_rgb_f_create structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_rgb_f_create is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_rgb_f_color* cm_rgb_f_create(double r, double g, double b);
/*
 * Description:
 * 	Creates a cm_rgb_f_color structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_rgb_f_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_rgb_f_color* cm_rgb_f_from_rgb_i(uint8_t r, uint8_t g, uint8_t b);
/*
 * Description:
 * 	Creates a cm_rgb_f_color structure from HSI components
 * Parameters:
 * 	h,s,i - the components of an HSI model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_rgb_f_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_rgb_f_color* cm_rgb_f_from_hsi(double h, double s, double i);
/*
 * Description:
 * 	Creates a cm_rgb_f_color structure from HSL components
 * Parameters:
 * 	h,s,l - the components of an HSL model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_rgb_f_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_rgb_f_color* cm_rgb_f_from_hsl(double h, double s, double l);
/*
 * Description:
 * 	Creates a cm_rgb_f_color structure from HSV components
 * Parameters:
 * 	h,s,v - the components of an HSV model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_rgb_f_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_rgb_f_color* cm_rgb_f_from_hsv(double h, double s, double v);
/*
 * Description:
 * 	Creates a cm_rgb_f_color structure from YIQ components
 * Parameters:
 * 	y,i,q - the components of an YIQ model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_rgb_f_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_rgb_f_color* cm_rgb_f_from_yiq(double y, double i, double q);
/*
 * Description:
 * 	Creates a cm_rgb_f_color structure from YUV components
 * Parameters:
 * 	y,u,v - the components of an YUV model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_rgb_f_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_rgb_f_color* cm_rgb_f_from_yuv(double y, double u, double v);
/*
 * Description:
 * 	Creates a cm_hsi_color structure
 * Parameters:
 * 	h,s,i - the components of an HSI model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_hsi_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_hsi_color* cm_hsi_create(double h, double s, double i);
/* Description:
 * 	Creates a cm_hsi_color structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_hsi_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_hsi_color* cm_hsi_from_rgb_f(double r, double g, double b);
/*
 * Description:
 * 	Creates a cm_hsl_color structure
 * Parameters:
 * 	h,s,l - the components of an HSL model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_hsl_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_hsl_color* cm_hsl_create(double h, double s, double l);
/* Description:
 * 	Creates a cm_hsl_color structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_hsl_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_hsl_color* cm_hsl_from_rgb_f(double r, double g, double b);
/*
 * Description:
 * 	Creates a HsvColor structure
 * Parameters:
 * 	h,s,v - the components of an cm_hsv_color model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_hsv_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_hsv_color* cm_hsv_create(double h, double s, double v);
/* Description:
 * 	Creates a cm_hsv_color structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_hsv_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_hsv_color* cm_hsv_from_rgb_f(double r, double g, double b);
/*
 * Description:
 * 	Creates a cm_yiq_color structure
 * Parameters:
 * 	y,i,q - the components of an YIQ model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_yiq_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_yiq_color* cm_yiq_create(double y, double i, double q);
/* Description:
 * 	Creates a cm_yiq_color structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_yiq_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_yiq_color* cm_yiq_from_rgb_f(double r, double g, double b);
/*
 * Description:
 * 	Creates a cm_yuv_color structure
 * Parameters:
 * 	y,u,v - the components of an YUV model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_yuv_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_yuv_color* cm_yuv_create(double y, double u, double v);
/* Description:
 * 	Creates a cm_yuv_color structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the cm_yuv_color is the parameters are
 * correct. Otherwise returns NULL.
 */
struct cm_yuv_color* cm_yuv_from_rgb_f(double r, double g, double f);

#endif /* COLORSPACES_H_ */
