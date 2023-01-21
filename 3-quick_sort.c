#include "sort.h"

/**
 * quick_sort_h - function as quick sort in lomunto
 * @array: numbers to be sorted
 * @low: first lowest number to compare
 * @high: largest num to compare
 */
void quick_sort_h(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = array[high];
		int i = low - 1;
		int temp;
		int j;

		for (j = low; j <= high - 1; j++)
		{
			if (array[j] <= pivot)
			{
				i++;
				if (i != j)
				{
					temp = array[i];
					array[i] = array[j];
					array[j] = temp;
					print_array(array, size);
				}
			}
		}
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
		quick_sort_h(array, low, i, size);
		quick_sort_h(array, i + 1, high, size);
	}
}

/**
 * quick_sort - sort list by comparison
 * @array: numbers to be sorted
 * @size: volume of numbers
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_h(array, 0, size - 1, size);
}
