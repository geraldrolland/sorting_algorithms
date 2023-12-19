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
	int set_flag;

	/* Calculate initial gap for shell sort */
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}

	/* Perform shell sort */
	while (gap > 0)
	{
		set_flag = 0;
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Move elements to their correct positions within the gap */
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
				set_flag = 1;
			}
			array[j] = temp;
		}
		if (set_flag != 0)
		print_array(array, size);

		/* Reduce the gap and print array after each iteration */
		gap /= 3;
	}
}

