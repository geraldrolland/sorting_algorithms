include "sort.h"

void shell_sort(int *array, size_t size)
{

    int gap = 1, temp, i, j;

    while (gap < size / 3) {
        gap = gap * 3 + 1;
    }
    while (gap > 0) {
        for (i = gap; i < size; i++) {
            temp = array[i];
            j = i;

            while (j >= gap && array[j - gap] > temp) {
                array[j] = array[j - gap];
                j -= gap;
            }

            array[j] = temp;
        }
        gap /= 3;
        print_array(array, size);
    }
}
