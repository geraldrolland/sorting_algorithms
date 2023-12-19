#include "sort.h"

/**
 * swap - swaps two integer elements
 * @elem1: pointer to the first element
 * @elem2: pointer to the second element
 *
 * Return: void
 */
void swap(int *elem1, int *elem2)
{
	int temp;

	temp = *elem1;
	*elem1 = *elem2;
	*elem2 = temp;
}

/**
 * partition - partitions the array and places the pivot element
 * at its correct position
 * @array: array of integers
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int partition(int *array, int low, int high, size_t size)
{
	int j;
	int pivot = array[high];
	int i = low;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	swap(&array[i], &array[high]);
	if (i != high)
		print_array(array, size);
	return (i);
}

/**
 * quick_sort_recursive - recursively sorts the sub-arrays
 * @array: array of integers
 * @low: starting index of the sub-array
 * @high: ending index of the sub-array
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_end = partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot_end - 1, size);
		quick_sort_recursive(array, pivot_end + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the quicksort algorithm
 * @array: array of integers
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_recursive(array, 0, size - 1, size);
}
