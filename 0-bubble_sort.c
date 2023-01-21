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
	size_t k;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				for (k = 0; k < size; k++)
				{
					printf("%d ", array[k]);
				}
				printf("\n");
			}
		}
	}
}
