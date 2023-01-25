#include "sort.h"

/**
 * quick_sort_hoare - sort array using quick sort
 * @array: list of numbers
 * @size: size of list
 */
void quick_sort_hoare(int *array, size_t size)
{
	int pivot, i, j, temp, pivot_index;

	if (array == NULL || size < 2)
	{
		return;
	}

	pivot_index = (rand() % size);
	pivot = array[pivot_index];
	array[pivot_index] = array[size - 1];
	array[size - 1] = pivot;
	i = -1;
	j = size;

	for (;;)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
		{
			break;
		}

		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array(array, size);
	}

	quick_sort_hoare(array, j + 1);
	quick_sort_hoare(array + j + 1, size - j - 1);
}
