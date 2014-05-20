#include "colorspace.h"

/*
 * Description:
 * 	Checks if a value is within a specified interval
 * Parameters:
 *  value - the value who is checked
 *  lowerLimit - the lower limit of the interval
 *  upperLimit - the upper limit of the interval
 * Returns:
 *  true if the value is within the interval
 *  false if the value is not within the interval
 */
bool RealIsWithinBounds(double value, double lowerLimit, double upperLimit)
{
	if(value>=lowerLimit && value<=upperLimit)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
 * Description:
 * 	Checks if a value is within a specified interval
 * Parameters:
 *  value - the value who is checked
 *  lowerLimit - the lower limit of the interval
 *  upperLimit - the upper limit of the interval
 * Returns:
 *  true if the value is within the interval
 *  false if the value is not within the interval
 */
bool IntegerIsWithinBounds(uint8_t value, uint8_t lowerLimit, uint8_t upperLimit)
{
	if(value>=lowerLimit && value<=upperLimit)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/*
 * Description:
 * 	Returns the smallest of the three parameters
 * Parameters
 * 	r,g,b - 3 real numbers
 * Returns
 *  The smallest real number from the set {r,g,b}
 */
double Double_GetMinimum(double r, double g, double b)
{
	if(r<g)
	{
		if(r<b)
		{
			return r;
		}
		else
		{
			return b;
		}
	}
	else
	{
		if(g<b)
		{
			return g;
		}
		else
		{
			return b;
		}
	}
	return 0;
}
/*
 * Description:
 * 	Returns the largest of the three parameters
 * Parameters
 * 	r,g,b - 3 real numbers
 * Returns
 *  The largest real number from the set {r,g,b}
 */
double Double_GetMaximum(double r, double g, double b)
{
	if(r>g)
	{
		if(r>b)
		{
			return r;
		}
		else
		{
			return b;
		}
	}
	else
	{
		if(g>b)
		{
			return g;
		}
		else
		{
			return b;
		}
	}
	return 0;
}

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
bool RgbF_IsValid(double r, double g, double b)
{
	bool isValid = true;
	if( (RealIsWithinBounds(r,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) ||
	    (RealIsWithinBounds(g,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) ||
	    (RealIsWithinBounds(b,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) )
	{
		isValid = false;
	}
	return isValid;
}
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
bool Hsi_IsValid(double h, double s, double i)
{
	bool isValid = true;
	if( (RealIsWithinBounds(h,HUE_LOWER_LIMIT,HUE_UPPER_LIMIT) == false) ||
	    (RealIsWithinBounds(s,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) ||
	    (RealIsWithinBounds(i,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) )
	{
		isValid = false;
	}
	return isValid;
}
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
bool RgbI_IsValid(uint8_t r, uint8_t g, uint8_t b)
{
	bool isValid = true;
	if( (IntegerIsWithinBounds(r,RGBI_LOWER_LIMIT,RGBI_UPPER_LIMIT) == false) ||
		(IntegerIsWithinBounds(g,RGBI_LOWER_LIMIT,RGBI_UPPER_LIMIT) == false) ||
		(IntegerIsWithinBounds(b,RGBI_LOWER_LIMIT,RGBI_UPPER_LIMIT) == false) )
	{
		isValid = false;
	}
	return isValid;
}
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
bool Hsl_IsValid(double h, double s, double l)
{
	bool isValid = true;
	if( (RealIsWithinBounds(h,HUE_LOWER_LIMIT,HUE_UPPER_LIMIT) == false) ||
		(RealIsWithinBounds(s,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) ||
		(RealIsWithinBounds(l,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) )
	{
		isValid = false;
	}
	return isValid;
}
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
bool Hsv_IsValid(double h, double s, double v)
{
	bool isValid = true;
	if( (RealIsWithinBounds(h,HUE_LOWER_LIMIT,HUE_UPPER_LIMIT) == false) ||
		(RealIsWithinBounds(s,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) ||
		(RealIsWithinBounds(v,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) )
	{
		isValid = false;
	}
	return isValid;
}
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
bool Yiq_IsValid(double y, double i, double q)
{
	bool isValid = true;
	if( (RealIsWithinBounds(y,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) ||
		(RealIsWithinBounds(i,YIQ_I_LOWER_LIMIT,YIQ_I_UPPER_LIMIT) == false) ||
		(RealIsWithinBounds(q,YIQ_Q_LOWER_LIMIT,YIQ_Q_UPPER_LIMIT) == false) )
	{
		isValid = false;
	}
	return isValid;
}
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
bool Yuv_IsValid(double y, double u, double v)
{
	bool isValid = true;
	if( (RealIsWithinBounds(y,PER_LOWER_LIMIT,PER_UPPER_LIMIT) == false) ||
		(RealIsWithinBounds(u,YUV_U_LOWER_LIMIT,YUV_U_UPPER_LIMIT) == false) ||
		(RealIsWithinBounds(v,YUV_V_LOWER_LIMIT,YUV_V_UPPER_LIMIT) == false) )
	{
		isValid = false;
	}
	return isValid;
}

/*
 * Description:
 * 	Creates a RgbfColor structure
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_Create(double r, double g, double b)
{
	RgbFColor* color = NULL;
	if(RgbF_IsValid(r,g,b)==true)
	{
		color = (RgbFColor*)malloc(sizeof(RgbFColor));
		if(color!=NULL)
		{
			color->R = r;
			color->G = g;
			color->B = b;
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a RgbIColor structure
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as natural numbers
 * Returns:
 *  A pointer to the RgbIColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbIColor* RgbI_Create(uint8_t r, uint8_t g, uint8_t b)
{
	RgbIColor* color = NULL;
	if(RgbI_IsValid(r,g,b)==true)
	{
		color = (RgbIColor*)malloc(sizeof(RgbIColor));
		if(color!=NULL)
		{
			color->R = r;
			color->G = g;
			color->B = b;
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a HsiColor structure
 * Parameters:
 * 	h,s,i - the components of an HSI model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the HsiColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HsiColor* Hsi_Create(double h, double s, double i)
{
	HsiColor* color = NULL;
	if(Hsi_IsValid(h,s,i)==true)
	{
		color = (HsiColor*)malloc(sizeof(HsiColor));
		if(color!=NULL)
		{
			color->H = h;
			color->S = s;
			color->I = i;
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a HslColor structure
 * Parameters:
 * 	h,s,l - the components of an HSL model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the HslColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HslColor* Hsl_Create(double h, double s, double l)
{
	HslColor* color = NULL;
	if(Hsl_IsValid(h,s,l)==true)
	{
		color = (HslColor*)malloc(sizeof(HslColor));
		if(color!=NULL)
		{
			color->H = h;
			color->S = s;
			color->L = l;
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a HsvColor structure
 * Parameters:
 * 	h,s,v - the components of an HSV model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the HsvColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HsvColor* Hsv_Create(double h, double s, double v)
{
	HsvColor* color = NULL;
	if(Hsv_IsValid(h,s,v)==true)
	{
		color = (HsvColor*)malloc(sizeof(HsvColor));
		if(color!=NULL)
		{
			color->H = h;
			color->S = s;
			color->V = v;
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a YiqColor structure
 * Parameters:
 * 	y,i,q - the components of an YIQ model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the YiqColor is the parameters are
 * correct. Otherwise returns NULL.
 */
YiqColor* Yiq_Create(double y, double i, double q)
{
	YiqColor* color = NULL;
	if(Yiq_IsValid(y,i,q)==true)
	{
		color = (YiqColor*)malloc(sizeof(YiqColor));
		if(color!=NULL)
		{
			color->Y = y;
			color->I = i;
			color->Q = q;
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a YuvColor structure
 * Parameters:
 * 	y,u,v - the components of an YUV model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the YuvColor is the parameters are
 * correct. Otherwise returns NULL.
 */
YuvColor* Yuv_Create(double y, double u, double v)
{
	YuvColor* color = NULL;
	if(Yiq_IsValid(y,u,v)==true)
	{
		color = (YuvColor*)malloc(sizeof(YuvColor));
		if(color!=NULL)
		{
			color->Y = y;
			color->U = u;
			color->V = v;
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a RgbFColor structure from HSI components
 * Parameters:
 * 	h,s,i - the components of an HSI model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromHsi(double h, double s, double i)
{
	RgbFColor* color = NULL;
	if(Hsi_IsValid(h,s,i)==true)
	{
		color = RgbF_Create(0.0f,0.0f,0.0f);
		if(h>=0.0f && h<=(HUE_UPPER_LIMIT/3.0f))
		{
			color->B = (1.0f/3.0f)*(1.0f-s);
			color->R = (1.0f/3.0f)*((s*cos(h))/cos(60.0f-h));
			color->G = 1.0f-(color->B + color->R);
		}
		else if(h>(HUE_UPPER_LIMIT/3.0f) && h<=(2.0f*HUE_UPPER_LIMIT/3.0f))
		{
			h-=(HUE_UPPER_LIMIT/3.0f);
			color->R = (1.0f/3.0f)*(1.0f-s);
			color->G = (1.0f/3.0f)*((s*cos(h))/cos(60.0f-h));
			color->B = 1.0f-(color->G + color->R);

		}
		else /* h>240 h<360 */
		{
			h-=(2.0f*HUE_UPPER_LIMIT/3.0f);
			color->G = (1.0f/3.0f)*(1.0f-s);
			color->B = (1.0f/3.0f)*((s*cos(h))/cos(60.0f-h));
			color->R = 1.0f-(color->G + color->B);
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a RgbFColor structure from HSL components
 * Parameters:
 * 	h,s,l - the components of an HSL model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromHsl(double h, double s, double l)
{
	RgbFColor* color = NULL;
	double c = 0.0f, m = 0.0f, x = 0.0f;
	if(Hsl_IsValid(h,s,l)==true)
	{
		c = (1.0f - fabs(2*l-1.0f)) * s;
		m = 1.0f * (l - 0.5f * c);
		x = c * (1.0f-fabs(fmod(h/60.0f,2) -1.0f));
		if(h>=0.0f && h<(HUE_UPPER_LIMIT/6.0f))
		{
			color = RgbF_Create(c+m, x+m, m);
		}
		else if(h>=(HUE_UPPER_LIMIT/6.0f) && h<(HUE_UPPER_LIMIT/3.0f))
		{
			color = RgbF_Create(x+m, c+m, m);
		}
		else if(h<(HUE_UPPER_LIMIT/3.0f) && h<(HUE_UPPER_LIMIT/2.0f))
		{
			color = RgbF_Create(m,c+m,x+m);
		}
		else if(h>=(HUE_UPPER_LIMIT/2.0f) && h<(2.0f*HUE_UPPER_LIMIT/3.0f))
		{
			color = RgbF_Create(m,x+m,c+m);
		}
		else if(h>=(2.0f*HUE_UPPER_LIMIT/3.0f) && h<(5.0f*HUE_UPPER_LIMIT/6.0f))
		{
			color = RgbF_Create(x+m, m, c+m);
		}
		else if(h>=(5.0f*HUE_UPPER_LIMIT/6.0f) && h<HUE_UPPER_LIMIT)
		{
			color = RgbF_Create(c+m, m, x+m);
		}
		else
		{
			color = RgbF_Create(m,m,m);
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a RgbFColor structure from HSV components
 * Parameters:
 * 	h,s,v - the components of an HSV model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromHsv(double h, double s, double v)
{
	double c = 0.0f ,m = 0.0f, x = 0.0f;
	RgbFColor *color = NULL;
	if(Hsv_IsValid(h,s,v)==true)
	{
		c = v * s;
		x = c*(1.0f-fabs(fmod(h/60.0f,2)-1.0f));
		m = v - c;
		if(h>=0.0f && h<60.0f)
		{
			color = RgbF_Create(c+m, x+m,m);
		}
		else if(h>=60.0f && h<120.0f)
		{
			color = RgbF_Create(x+m, c+m, m);
		}
		else if(h>=120.0f && h<180.0f)
		{
			color = RgbF_Create(m,c+m,x+m);
		}
		else if(h>=180.0f && h<240.0f)
		{
			color = RgbF_Create(m,x+m,c+m);
		}
		else if(h>=240.0f && h<300.0f)
		{
			color = RgbF_Create(x+m, m, c+m);
		}
		else if(h>=300.0f && h<360.0f)
		{
			color = RgbF_Create(c+m, m, x+m);
		}
		else
		{
			color = RgbF_Create(m,m,m);
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a RgbFColor structure from YIQ components
 * Parameters:
 * 	y,i,q - the components of an YIQ model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromYiq(double y, double i, double q)
{
	RgbFColor *color = NULL;
	if(Yiq_IsValid(y,i,q)==true)
	{
		color = RgbF_Create(0.0f, 0.0f, 0.0f);
		color->R = y + 0.9563f*i + 0.62100*q;
		color->G = y - 0.2721f*i - 0.6474f*q;
		color->B = y - 1.1070f*i + 1.7046f*q;
	}
	return color;
}
/*
 * Description:
 * 	Creates a RgbFColor structure from YUV components
 * Parameters:
 * 	y,u,v - the components of an YUV model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromYuv(double y, double u, double v)
{
	RgbFColor *color = NULL;
	if(Yiq_IsValid(y,u,v)==true)
	{
		color = RgbF_Create(0.0f, 0.0f, 0.0f);
		color->R = y + 1.140f*v;
		color->G = y - 0.395f*u - 0.581f*v;
		color->B = y + 2.032f*u;
	}
	return color;
}


/* Description:
 * 	Creates a HsiColor structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the HsiColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HsiColor* Hsi_CreateFromRgbF(double r, double g, double b)
{
	HsiColor* color = NULL;
	double m = Double_GetMinimum(r,g,b);
	double M = Double_GetMaximum(r,g,b);
	double c = M-m;
	if(RgbF_IsValid(r,g,b)==true)
	{
		color = (HsiColor*)malloc(sizeof(HsiColor));
		color->I = (1.0f/3.0f)*(r+g+b);
		if(c==0)
		{
			color->H = 0.0f;
			color->S = 0.0f;
		}
		else
		{
			if(M==r)
			{
				color->H = fmod(((g-b)/c), 6);
			}
			else if(M==g)
			{
				color->H = (b-r)/c + 2.0f;
			}
			else if(M==b)
			{
				color->H = (r-g)/c + 4.0f;
			}
			color->H *=60.0f;
			color->S = 1.0f - (m/color->I);
		}
	}
	return color;
}
/* Description:
 * 	Creates a HslColor structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the HslColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HslColor* Hsl_CreateFromRgbF(double r, double g, double b)
{
	double M = 0.0f ,m = 0.0f ,c = 0.0f;
	HslColor* color = NULL;
	if(RgbF_IsValid(r,g,b)==true)
	{
		M = Double_GetMaximum(r,g,b);
		m = Double_GetMinimum(r,g,b);
		c = M-m;
		color = Hsl_Create(0.0f,0.0f,0.0f);
		color->L = 0.5f *(M+m);
		if(c!=0.0f)
		{
			if(M==r)
			{
				color->H = fmod(((g-b)/c), 6.0f);
			}
			else if(M==g)
			{
				color->H = ((b-r)/c) + 2.0f;
			}
			else/*if(M==b)*/
			{
				color->H = ((r-g)/c) + 4.0f;
			}
			color->H *=60.0f;
			color->S = c/(1.0f - fabs(2.0f*color->L - 1.0f));
		}
	}
	return color;
}
/* Description:
 * 	Creates a HsvColor structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the HsvColor is the parameters are
 * correct. Otherwise returns NULL.
 */
HsvColor* Hsv_CreateFromRgbF(double r, double g, double b)
{
	double M = 0.0f, m = 0.0f, c = 0.0f;
	HsvColor* color = NULL;
	if(RgbF_IsValid(r,g,b)==true)
	{
		color = Hsv_Create(0.0f, 0.0f, 0.0f);
		M = Double_GetMaximum(r,g,b);
		m = Double_GetMinimum(r,g,b);
		c = M-m;
		color->V = M;
		if(c!=0.0f)
		{
			if(M==r)
			{
				color->H = fmod(((g-b)/c), 6);
			}
			else if(M==g)
			{
				color->H = (b-r)/c + 2.0f;
			}
			else /*if(M==b)*/
			{
				color->H = (r-g)/c + 4.0f;
			}
			color->H *=60.0f;
			color->S = c/color->V;
		}
	}
	return color;
}
/* Description:
 * 	Creates a YiqColor structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the YiqColor is the parameters are
 * correct. Otherwise returns NULL.
 */
YiqColor* Yiq_CreateFromRgbF(double r, double g, double b)
{
	YiqColor* color = NULL;
	if(RgbF_IsValid(r,g,b)==true)
	{
		color = Yiq_Create(0.0f, 0.0f, 0.0f);
		color->Y = 0.299900f*r + 0.58700f*b + 0.11400f*b;
		color->I = 0.595716f*r - 0.274453*b - 0.321264*b;
		color->Q = 0.211456f*r - 0.522591*b + 0.31135f*b;
	}
	return color;
}
/* Description:
 * 	Creates a YuvColor structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the YuvColor is the parameters are
 * correct. Otherwise returns NULL.
 */
YuvColor* Yuv_CreateFromRgbF(double r, double g, double b)
{
	YuvColor* color = NULL;
	if(RgbF_IsValid(r,g,b)==true)
	{
		color = Yuv_Create(0.0f, 0.0f, 0.0f);
		color->Y = 0.299f*r + 0.587f*b + 0.114f*b;
		color->U = 0.492f* (b - color->Y);
		color->V = 0.877f* (r - color->Y);
	}
	return color;
}

/*
 * Description:
 * 	Creates a RgbIColor structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the RgbIColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbIColor* RgbI_CreateFromRealForm(double r, double g, double b)
{
	RgbIColor* color = NULL;
	if(RgbF_IsValid(r,g,b)==true)
	{
		color = (RgbIColor*)malloc(sizeof(RgbIColor));
		if(color!=NULL)
		{
			color->R = (uint8_t)( r * (double)RGBI_UPPER_LIMIT + 0.5f);
			color->G = (uint8_t)( g * (double)RGBI_UPPER_LIMIT + 0.5f);
			color->B = (uint8_t)( b * (double)RGBI_UPPER_LIMIT + 0.5f);
		}
	}
	return color;
}
/*
 * Description:
 * 	Creates a RgbFColor structure from RGB components
 * Parameters:
 * 	r,g,b - the components of an RGB model expressed
 * 			as real numbers
 * Returns:
 *  A pointer to the RgbFColor is the parameters are
 * correct. Otherwise returns NULL.
 */
RgbFColor* RgbF_CreateFromIntegerForm(uint8_t r, uint8_t g, uint8_t b)
{
	RgbFColor* color = NULL;
	if(RgbI_IsValid(r,g,b)==true)
	{
		color = (RgbFColor*)malloc(sizeof(RgbFColor));
		if(color!=NULL)
		{
			color->R = (double)(r)/(double)(RGBI_UPPER_LIMIT);
			color->G = (double)(g)/(double)(RGBI_UPPER_LIMIT);
			color->B = (double)(b)/(double)(RGBI_UPPER_LIMIT);
		}
	}
	return color;
}
