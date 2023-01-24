#include "sort.h"

#define BASE 10
/**
 * radix_sort - sorts array by comparison
 * @array: number to be sorted
 * @size: memory to be used by the algorithm
 */
void radix_sort(int *array, size_t size)
{
	int max_value = 0, **buckets, *counts;
	size_t i, j, max_digits = 0;
	int digit, bucket, k, l;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
		{
			max_value = array[i];
		}
	}
	while (max_value > 0)
	{
		max_digits++;
		max_value /= BASE;
	}
	buckets = (int **)malloc(BASE * sizeof(int *));
	for (i = 0; i < BASE; i++)
	{
		buckets[i] = (int *)malloc(size * sizeof(int));
	}
	counts = (int *)malloc(BASE * sizeof(int));
	digit = 1;

	for (i = 0; i < max_digits; i++)
	{
		for (j = 0; j < BASE; j++)
		{
			counts[j] = 0;
		}
		for (j = 0; j < size; j++)
		{
			bucket = (array[j] / digit) % BASE;
			buckets[bucket][counts[bucket]++] = array[j];
		}
		for (k = 0; k < BASE; k++)
		{
			for (l = 0; l < counts[k]; l++)
			{
				array[j++] = buckets[k][l];
			}
		}
		digit *= BASE;
		print_array(array, size);
	}
	for (i = 0; i < BASE; i++)
	{
		free(buckets[i]);
	}
	free(buckets);
	free(counts);
}
