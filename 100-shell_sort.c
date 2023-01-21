#include "sort.h"

/**
 * shell_sort - knuth sequence in sorting
 * @array: number to be sorted
 * @size: amount of characters present
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1;

	while (interval < size / 3)
	{
		interval = interval * 3 + 1;
	}

	while (interval > 0)
	{
		size_t i;

		for (i = interval; i < size; i++)
	{
		int current = array[i];
		size_t j;

		for (j = i; j >= interval && array[j - interval] > current; j -= interval)
		{
			array[j] = array[j - interval];
		}
		array[j] = current;
	}
	interval = (interval - 1) / 3;
	print_array(array, size);
	}
}
