#include "sort.h"

/**
 * quick_sort - sort list by comparison
 * @array: numbers to be sorted
 * @size: volume of numbers
 */
void quick_sort(int *array, size_t size)
{
	int pivot;
	int i;
	size_t j = 0;
	int temp;

	if (size < 2)
	{
		return;
	}

	pivot = array[size - 1];
	i = -1;

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i + 1];
	array[i + 1] = pivot;
	array[size - 1] = temp;
	print_array(array, size);
	quick_sort(array, i + 1);
	quick_sort(array + i + 1, size - i - 1);
}
