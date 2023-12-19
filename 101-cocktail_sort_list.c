#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: pointer to the head pointer
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr, *temp;
	int set_flag = 0;

	if (*list == NULL || (*list)->next == NULL)
		return;

	do
	{
		set_flag = 0;
		ptr = *list;

		/* Traverse the list from left to right */
		while (ptr->next != NULL)
		{
			temp = ptr->next;

			if (ptr->n > temp->n)
			{
				swap_nodes(list, ptr, temp);
				print_list(*list);
				set_flag = 1;
			}
			else
			{
				ptr = temp;
			}
		}

		if (!set_flag)
			break;

		set_flag = 0;
		temp = ptr->prev;

		/* Traverse the list from right to left */
		while (temp != NULL)
		{
			ptr = temp;

			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				print_list(*list);
				set_flag = 1;
			}
			else
			{
				temp = temp->prev;
			}
		}
	} while (set_flag);
}

/**
 * swap_nodes - swap nodes in the list
 * @list: pointer to the head pointer
 * @node1: pointer to the first node to swap
 * @node2: pointer to the second node to swap
 *
 * Return: void
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}

