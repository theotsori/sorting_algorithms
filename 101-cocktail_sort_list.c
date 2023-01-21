#include "sort.h"

void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = *list;
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;
	do {
		swapped = 0;
		current = start;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				if (current->prev != NULL)
				{
					current->prev->next = current->next;
				}
				current->next->prev = current->prev;

				if (current->next->next != NULL)
				{
					current->next->next->prev = current;
				}
				current->prev = current->next;
				current->next = current->next->next;
				current->prev->next = current;

				if (current->prev->prev == NULL)
				{
					*list = current->prev;
				}
				swapped = 1;
				print_list(start);
			}
			current = current->next;
		}
		current = start->prev;
		while (current != start)
		{
			if (current->n < current->prev->n)
			{
				if (current->prev->prev != NULL)
				{
					current->prev->prev->next = current;
				}
				current->prev->next = current->next;
				current->next->prev = current->prev;
				current->next = current->prev;
				current->prev = current->prev->prev;
				current->next->prev = current;
				if (current->prev->prev == NULL)
				{
					*list = current;
				}
				swapped = 1;
				print_list(start);
			}
			if (current->next == NULL)
			{
				break;
			}
			current = current->prev;
		}
	} while (swapped);
}
