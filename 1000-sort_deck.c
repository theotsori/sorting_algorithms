#include "deck.h"

int compare_cards(const void *a, const void *b)
{
	int value_cmp;

	deck_node_t *card1 = *(deck_node_t **)a;
	deck_node_t *card2 = *(deck_node_t **)b;

	value_cmp = strcmp(card1->card->value, card2->card->value);

	if (value_cmp != 0)
	{
		return (value_cmp);
	}
	return (card1->card->kind - card2->card->kind);
}

void sort_deck(deck_node_t **deck)
{
	int num_cards = 52;
	int i;

	deck_node_t *current = *deck;
	deck_node_t **cards = malloc(num_cards * sizeof(deck_node_t *));

	for (i = 0; i < num_cards; i++)
	{
		cards[i] = current;
		current = current->next;
	}

	qsort(cards, num_cards, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < num_cards; i++)
	{
		cards[i]->prev = (i > 0) ? cards[i - 1] : NULL;
		cards[i]->next = (i < num_cards - 1) ? cards[i + 1] : NULL;
	}

	*deck = cards[0];
	free(cards);
}
