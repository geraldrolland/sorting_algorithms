#include "sort.h"

int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void quick_sort_recursive(int *array, int low, int high, size_t size);

void quick_sort(int *array, size_t size)
{
    quick_sort_recursive(array, 0, size - 1, size);
}
int partition(int *array, int low, int high, size_t size) {
    int pivot = array[high];
    int i = low;

    for (int j = low; j <= high - 1; j++) {
        if (array[j] <= pivot) {
            swap(&array[i], &array[j]);
            if (i != j)
            print_array(array, size);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    if (i != high)
    print_array(array, size);
    return i;
}
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_end = partition(array, low, high, size);
        quick_sort_recursive(array, low, pivot_end - 1, size);
        quick_sort_recursive(array, pivot_end + 1, high, size);
    }
}
void swap(int *elem1, int *elem2)
{
    int temp;
    temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}
