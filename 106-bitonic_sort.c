#include "sort.h"

/**
 * bitonic_sort - sorts arrays using comparison
 * @array: numbers to be sorted
 * @size: memory sed by the program
 */
void bitonic_sort(int *array, size_t size)
{
	size_t k, i = 0, j = 0;
	size_t l = i ^ j;

	for (k = 2; k <= size; k *= 2)
	{
		for (j = k / 2; j > 0; j /= 2)
		{
			for (i = 0; i < size; i++)
			{
				l = i ^ j;
				if (l > i)
				{
					if ((i & k) == 0 && array[i] > array[l])
					{
						swap(&array[i], &array[l]);
						printf("Merging [%lu/%lu] (up):\n", k, size);
						print_array(array, k);
					}
					if ((i & k) != 0 && array[i] < array[l])
					{
						swap(&array[i], &array[l]);
						printf("Merging [%lu/%lu] (down):\n", k, size);
						print_array(array, k);
					}
				}
			}
		}
		printf("Result [%lu/%lu] (up):\n", k, size);
		print_array(array, k);
	}
}
/**
 * swap - function that changes positions of int
 * @a: fisrt int
 * @b: second int
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
