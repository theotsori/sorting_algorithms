#include "sort.h"

/**
 * counting_sort - sorts an array by comparison
 * @array: numbers to be sorted
 * @size: memory used be the algoritm
 *
 */
void counting_sort(int *array, size_t size)
{
	int max = 0;
	size_t i;
	int *counting_array;
	size_t k;
	int h;
	int index = 0;
	int m;
	int n;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}

	counting_array = (int *) malloc((max + 1) * sizeof(int));
	memset(counting_array, 0, (max + 1) * sizeof(int));

	for (k = 0; k < size; k++)
	{
		counting_array[array[k]]++;
	}

	for (h = 0; h <= max; h++)
	{
		printf("%d ", counting_array[h]);
	}
	printf("\n");

	for (m = 0; m <= max; m++)
	{
		for (n = 0; n < counting_array[m]; n++)
		{
			array[index++] = m;
		}
	}
	free(counting_array);
}
