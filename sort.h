#ifndef _SORT_H_
#define _SORT_H_

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_h(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void swap(int *a, int *b);
void sift_down(int *array, size_t size, int i);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void qiuck_sort_hoare(int *array, size_t size);
/*void merge(int *arr, int *left, int leftSize, int *right, int rightSize);*/
void merge(int *array, int *left, int leftSize, int *right, int rightSize); 
/*void sort_deck(deck_node_t **deck);*/

#endif /*sort.h*/
