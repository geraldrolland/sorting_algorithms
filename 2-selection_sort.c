#include "sort.h"

void selection_sort(int *array, size_t size)
{
    int i , j, min_val;
    int idx;
    for (i = 0; i < size - 1; i++)
    {
        idx = i;
        min_val = array[i];
        j = i + 1;
        for (; j < size; j++)
        {
            if (array[j] < min_val)
            {
                min_val = array[j];
                idx = j;
            }
        }
        array[idx] = array[i];
        if (array[i] != min_val)
        {
            array[i] = min_val;
            print_array(array, size);
        }
    }
}
