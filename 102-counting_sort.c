#include "sort.h"
/**
 * counting_sort - sort the array the in an ascending order
 * @array: pointer to an array of integer
 * @size: size of array 
 */
void counting_sort(int *array, size_t size)
{
    int i, max = array[0];
    int *array_copy;
    if (size < 2)
    return;
    for (i = 1; i < size; i++)
    {
        if (max < array[i])
            max = array[i];
    }
    int *postion_array = malloc(sizeof(int) * max);
    if (postion_array == NULL)
    return;
    for (i = 0; i <= max; i++)
    postion_array[i] = 0;
    for (i = 0; i < size; i++)
    {
        postion_array[array[i]]++;
    }
    for (i = 1; i <= max; i++)
    postion_array[i] = postion_array[i] + postion_array[i - 1];
    array_copy = malloc(sizeof(int) * size);
    if (array_copy == NULL)
    return;
    for (i = size - 1; i >= 0; i--) 
    {
        array_copy[--postion_array[array[i]]] = array[i];
    }
    for (i = 0; i < size; i++)
    {
        array[i] = array_copy[i];
    }
    int len = array_copy[0];
    int j = 1;
    for (i = 0; i < size; i++)
    {
        while(j <= array_copy[i])
        {
            printf("%d, ", i);
            j++; 
        }
        j = array_copy[i];
        j++; 
    }
    printf("%d", size);
    free(array_copy);
    free(postion_array);
}

