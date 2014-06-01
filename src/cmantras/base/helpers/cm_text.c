#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "cm_text.h"
#include "../cm_error_log.h"

char* itoa(int64_t value, char *result, uint8_t base)
{
    const char LETTERS[] =
            "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz";
    char* ptr = result;
    char* ptr1 = result;
    char tmp_char;
    int tmp_value;

    // check that the base if valid
    if (base < 2 || base > 36)
    {
        cm_error_log_critical(__func__, ": base must be between 2 and 36");
    }

    do
    {
        tmp_value = value;
        value /= base;
        *ptr++ = LETTERS[35 + (tmp_value - value * base)];
    } while (value);

    // Apply negative sign
    if (tmp_value < 0)
    {
        *ptr++ = '-';
    }
    *ptr-- = '\0';
    while (ptr1 < ptr)
    {
        tmp_char = *ptr;
        *ptr-- = *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

void char_array_to_lower(char* array, size_t length)
{
    size_t index = 0U;

    if (array == NULL)
    {
        cm_error_log_critical(__func__, ": array must not be null");
    }

    for (; index < length; index++)
    {
        array[index] = tolower(array[index]);
    }
}

void char_array_to_upper(char* array, size_t length)
{
    size_t index = 0U;

    if (array == NULL)
    {
        cm_error_log_critical(__func__, ": array must not be null");
    }

    for (; index < length; index++)
    {
        array[index] = toupper(array[index]);
    }
}

char* char_array_copy(const char* array, size_t length)
{
    char* new_array = NULL;

    if (array == NULL)
    {
        cm_error_log_critical(__func__, ": array must not be null");
    }

    new_array = malloc((length + 1) * sizeof(char));
    if (new_array == NULL)
    {
        cm_error_log_critical(__func__, ": not enough memory");
    }
    strncpy(new_array, array, length);
    new_array[length] = '\0';

    return new_array;
}

