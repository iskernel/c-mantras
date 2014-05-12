#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>

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
