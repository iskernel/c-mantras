#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <limits.h>
#include <float.h>

#include "cm_helpers.h"

int64_t itoa(int64_t value, char *string, uint8_t radix)
{
    char buffer[16];// be careful with the length of the buffer
    char *topOfPointer = buffer;
    int64_t index;
    int64_t length = 0L;
    uint64_t uValue;
    bool isNegative = ( (radix == 10) && (value < 0) );

    if (isNegative == true)
    {
        uValue = -value;
    }
    else
    {
        uValue = (unsigned)value;
    }
    while ( (uValue != 0UL) || ( topOfPointer == buffer ) )
    {
        index = uValue % radix;
        uValue /= radix; // v/=radix uses less CPU clocks than v=v/radix does
        if (index < 10)
        {
          *topOfPointer++ = index+'0';
        }
        else
        {
          *topOfPointer++ = index + 'a' - 10;
        }
    }

    length = topOfPointer - buffer;

    if (isNegative == true)
    {
        *string++ = '-';
        length++;
    }

    while (topOfPointer > buffer)
    {
        *string++ = *--topOfPointer;
    }

    return length;
}

char* char_array_to_lower(char* array, cm_size_u length)
{
	cm_size_u index = 0U;

	for(;index < length ; index++)
	{
		array[index] = tolower(array[index]);
	}

	return array;
}

char* char_array_copy(char* array, cm_size_u length)
{
	char* new_array = NULL;

	new_array = malloc(length * sizeof(char));
	strcpy(new_array, array);

	return new_array;
}

cm_size_u get_number_of_digits(int64_t value)
{
	cm_size_u result = 0U;

	while(value > 0)
	{
		result++;
		value /= 10;
	}

	return result;
}

bool double_is_within(double value, double min_value, double max_value)
{
	bool result = (value >= min_value) && (value <= max_value);
	return result;
}

bool uint8_is_within(uint8_t value, uint8_t min_value, uint8_t max_value)
{
	bool result = (value >= min_value) && (value <= max_value);
	return result;
}

double double_get_min(uint8_t number_of_args, double arg, ...)
{
	double min = DBL_MAX;
	va_list list;
	uint8_t index;
	double iterator = 0.0;

	va_start(list, number_of_args);
	for (index = 0; index < number_of_args; index++)
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

	va_start(list, number_of_args);
	for (index = 0; index < number_of_args; index++)
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
