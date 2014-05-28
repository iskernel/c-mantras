#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <float.h>

#include "cm_numeric.h"
#include "../cm_error_log.h"

size_t get_number_of_digits(int64_t value)
{
	size_t result = 0U;

	value = (value < 0) ? (-value) : (value);
	while(value > 0)
	{
		result++;
		value /= 10;
	}

	return result;
}

bool double_is_within(double value, double min_value, double max_value)
{
	bool result = false;
	cm_error_log_critical_if( (min_value > max_value),
							   __func__, ": min_value greater than max_value");

	result = (value >= min_value) && (value <= max_value);
	return result;
}

bool uint8_is_within(uint8_t value, uint8_t min_value, uint8_t max_value)
{
	bool result = false;
	cm_error_log_critical_if((min_value > max_value),
							  __func__, ": min_value greater than max_value");
	result = (value >= min_value) && (value <= max_value);
	return result;
}

double double_get_min(uint8_t number_of_args, double arg, ...)
{
	double min = DBL_MAX;
	va_list list;
	uint8_t index;
	double iterator = 0.0;

	cm_error_log_critical_if( (number_of_args < 1) ,
							   __func__, ": number of args < 1");

	va_start(list, arg);
	if( arg < min)
	{
		min = arg;
	}
	for (index = 1; index < number_of_args; index++)
	{
		iterator =  va_arg(list, double);
		if( iterator < min )
		{
			min = iterator;
		}
	}
	va_end(list);
	return min;
}

double double_get_max(uint8_t number_of_args, double arg, ...)
{
	double max = DBL_MIN;
	va_list list;
	uint8_t index;
	double iterator = 0.0;

	cm_error_log_critical_if( (number_of_args < 1) ,
							   __func__, ": number of args < 1");

	va_start(list, arg);
	if( arg > max)
	{
		max = arg;
	}
	for (index = 1; index < number_of_args; index++)
	{
		iterator =  va_arg(list, double);
		if( iterator > max )
		{
			max = iterator;
		}
	}
	va_end(list);
	return max;
}
