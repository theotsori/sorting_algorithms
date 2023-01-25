#include "sort.h"

/**
 * bubble_sort - sort a list of arrays starting with the largest
 * @array: number in an array
 * @size: size of list
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i;
	size_t j;

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				print_array(array, size);
			}
		}
	}
}
