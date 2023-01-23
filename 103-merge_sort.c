#include "sort.h"

/**
 * merge_sort - sorts arrays by comparison
 * @array: numbers to compare
 * @size: memory allocated
 */
void merge_sort(int *array, size_t size)
{
	int mid = size / 2;
	int *left = array;
	size_t leftSize = mid;
	int *right = array + mid;
	size_t rightSize = size - mid;
	size_t i = 0, j = 0, k = 0;
	int *temp;

	if (size < 2)
	{
		return;
	}
	merge_sort(left, leftSize);
	merge_sort(right, rightSize);
	temp = (int *)malloc((leftSize + rightSize) * sizeof(int));
	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
		{
			temp[k++] = left[i++];
		}
		else
		{
			temp[k++] = right[j++];
		}
	}
	while (i < leftSize)
	{
		temp[k++] = left[i++];
	}
	while (j < rightSize)
	{
		temp[k++] = right[j++];
	}

	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	free(temp);
}
