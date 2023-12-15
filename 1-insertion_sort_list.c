#include "sort.h"
/**
 * insertion_sort_list - sort doubly linked list of integers in ascending order
 * @list: list
 * Return: no return
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *node, *pass;

	node = (*list)->next;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	while (node)
	{
		pass = node;
		prev = node->prev;
		while (prev && pass->n < prev->n)
		{
			if (pass->next)
			{
				pass->next->prev = prev;
			}
			prev->next = pass->next;
			pass->prev = prev->prev;
			if (prev->prev)
			{
				prev->prev->next = pass;
			}
			prev->prev = pass;
			pass->next = prev;
			if (prev == *list)
			{
				*list = pass;
			}
			print_list(*list);
			prev = pass->prev;
		}
		node = node->next;
	}
}
