#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *              using the shell sort algorithm
 * @array: array of integers
 * @size: size of array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	int temp;
	size_t gap, i, j;

	/* Calculate initial gap for shell sort */
	while (gap < size / 3) {
		gap = gap * 3 + 1;
	}

	/* Perform shell sort */
	while (gap > 0) {
		for (i = gap; i < size; i++) {
			temp = array[i];
			j = i;

			/* Move elements to their correct positions within the gap */
			while (j >= gap && array[j - gap] > temp) {
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		/* Reduce the gap and print array after each iteration */
		gap /= 3;
		print_array(array, size);
	}
}

