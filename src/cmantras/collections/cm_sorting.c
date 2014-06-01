#include <stdlib.h>
#include "cm_sorting.h"

#include "cmantras/base/cm_base_types.h"
#include "cmantras/base/helpers/cm_generic.h"
#include "cmantras/base/cm_error_log.h"

static cm_index cm_sort_array_quicksort_partition(
        void** array, cm_index left, cm_index right,
        cm_cmp_size (*compare)(const void*, const void*))
{
    cm_index pivot = (left - 1);
    void* right_value = array[right];
    cm_index iterator = left;
    void* temp = NULL;

    for (; iterator <= right - 1; iterator++)
    {
        if (compare(array[iterator], right_value) <= 0)
        {
            pivot++;
            temp = array[pivot];
            array[pivot] = array[iterator];
            array[iterator] = temp;
        }
    }
    temp = array[pivot + 1];
    array[pivot + 1] = array[right];
    array[right] = temp;
    return (pivot + 1);
}

void cm_sort_array_quicksort(void** array, cm_size array_size,
                             cm_cmp_size (*compare)(const void*, const void*))
{
    cm_index left = 0;
    cm_index pivot = 0;
    cm_index top = -1;
    cm_index stack[array_size -1 - left + 1];

    cm_error_log_critical_if((array == NULL), __func__, ": array is NULL");
    cm_error_log_critical_if((compare == NULL), __func__, ": compare is NULL");
    cm_error_log_critical_if((array_size < 1), __func__, ": array_size < 1");

    array_size--;
    // push initial values of l and h to stack
    stack[++top] = left;
    stack[++top] = array_size;

    // Keep popping from stack while is not empty
    while (top >= 0)
    {
        // Pop array_size and l
        array_size = stack[top--];
        left = stack[top--];

        // Set pivot element at its correct position in sorted array
        pivot = cm_sort_array_quicksort_partition(array, left, array_size,
                                                  compare);

        // If there are elements on left side of pivot, then push left
        // side to stack
        if (pivot - 1 > left)
        {
            stack[++top] = left;
            stack[++top] = pivot - 1;
        }

        // If there are elements on right side of pivot, then push right
        // side to stack
        if (pivot + 1 < array_size)
        {
            stack[++top] = pivot + 1;
            stack[++top] = array_size;
        }
    }
}
