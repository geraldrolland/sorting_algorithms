#include "sort.h"
/*
 * bubble_sort -  sorts an array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;

    if (size < 2)
    return;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j + 1 < size; j++)
        {
            if (array[j] > array[j + 1])
            {
                
                temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
            continue;
        }
    }
}
