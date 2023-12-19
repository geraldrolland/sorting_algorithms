#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 *                      in ascending order using the insertion sort algorithm
 * @list: double pointer to the head of the list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *node, *ptr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	temp = (*list)->next;

	while (temp != NULL)
	{
		node = temp;
		temp = temp->next;

		while (node->prev != NULL && node->n < node->prev->n)
		{
			ptr = node->prev;

			/* Adjust pointers for insertion */
			ptr->next = node->next;
			if (node->next != NULL)
				node->next->prev = ptr;

			node->prev = ptr->prev;
			node->next = ptr;

			if (ptr->prev != NULL)
				ptr->prev->next = node;

			ptr->prev = node;

			if (node->prev == NULL)
				*list = node; /* Update head if needed */

			/* Print the current state of the list */
			print_list(*list);
		}
	}
}
