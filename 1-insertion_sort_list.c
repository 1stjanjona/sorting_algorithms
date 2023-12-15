#include "sort.h"
/**
 * insertion_sort_list - sort doubly linked list of integers in ascending order
 * @list: list
 * Return: no return
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *prev, *node, *pass;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	node = (*list)->next;
	while (node)
	{
		pass = node;
		prev = node->prev;
		while (prev && (pass->n < prev->n))
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
			else
			{
				(*list) = pass;
			}
			prev->prev = pass;
			pass->next = prev;
			print_list(*list);
			prev = pass->prev;
		}
		node = node->next;
	}
}
