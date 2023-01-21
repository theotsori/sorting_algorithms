#include "sort.h"

/**
 * selection_sort - sorts items by comparison
 * @array: numbers to be sorted
 * @size: listt amount
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t min_idx;
	size_t i;
	size_t j;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
