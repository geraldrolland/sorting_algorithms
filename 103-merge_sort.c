#include "sort.h"

void merge_sort_recursive(int *array, int start, int end);
void merge_func(int *array, int start, int mid, int end);
void print_left_array(int *array, int i, size_t size);

void merge_sort(int *array, size_t size)
{
    if (size < 2)
    return;
    merge_sort_recursive(array, 0, size - 1);
}
void merge_sort_recursive(int *array, int start, int end)
{
    if (start < end)// end = 3, start = 0
    {
        int mid = start + (end - start) / 2;
        merge_sort_recursive(array, start, mid);
        merge_sort_recursive(array, mid + 1, end);
        merge_func(array, start, mid, end);
        
    }
}
void merge_func(int *array, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = 0;
    printf("Merging...\n");
    printf("[Left]: ");
    print_array(array, mid + 1);
    printf("[Right]: ");
    print_left_array(array, mid + 1, end + 1);
    printf("\n");
    int *array_copy = malloc(sizeof(int) * (end - start + 1));
    if (array_copy == NULL)
    return;
    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j])
        {
            array_copy[k] = array[i];
            i++;
        }
        else
        {
            array_copy[k] = array[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        array_copy[k] = array[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        array_copy[k] = array[j];
        j++;
        k++;
    }
    for (i = 0; i < k; i++)
    array[start + i] = array_copy[i];
    printf("[Done]: ");
    print_array(array, end + 1);
    free(array_copy);
}
void print_left_array(int *array, int i, size_t size)
{
    for (; i < size; i++)
    {
        printf("%d", array[i]);
        if (i != size - 1)
        printf(", ");
    }
}
