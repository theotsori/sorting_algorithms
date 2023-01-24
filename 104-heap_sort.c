#include "sort.h"

/**
 * heap_sort - sorts an array using comparison
 * @array: numbers to be compared
 * @size: memory used by the algorithm
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
	{
		sift_down(array, size, i);
	}

	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0);
		print_array(array, size);
	}
}

void sift_down(int *array, size_t size, int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < (int)size && array[left] > array[largest])
	{
		largest = left;
	}

	if (right < (int)size && array[right] > array[largest])
	{
		largest = right;
	}

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		sift_down(array, size, largest);
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
