#include "monty.h"

/**
 * print_list - print doubly linked list
 * @h: head of a doubly linked list
 * Return: size of the list
 */
size_t print_list(stack_t *h)
{
	size_t listsize;

	if (!h)
		return (0);

	listsize = 0;
	while (h)
	{
		printf("%d\n", h->n);
		listsize++;
		h = h->next;
	}

	return (listsize);
}

/**
 * add_node_head - add new node to head
 * @head: head of a doubly linked list
 * @n: int data to add to the node
 * Return: head of list
 */
stack_t *add_node_head(stack_t **head, int n)
{
	stack_t *new_node;
	stack_t *tmp;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	tmp = *head;

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = tmp;

	if (tmp)
		tmp->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * delete_node_head - delete head node
 * @head: ptr to head of list
 * Return: 1 on success
 */
int delete_node_head(stack_t **head)
{
	stack_t *tmp;

	tmp = *head;
	if (tmp)
	{
		*head = tmp->next;
		if (tmp->next)
			tmp->next->prev = NULL;
		free(tmp);

		return (1);
	}
	return (-1);
}

/**
 * add_node_end - add new node to end
 * @head: head of a doubly linked list
 * @n: int data to add to the node
 * Return: new node ptr
 */
stack_t *add_node_end(stack_t **head, int n)
{
	stack_t *new_node;
	stack_t *tmp;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	tmp = *head;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;

		tmp->next = new_node;
	}
	new_node->prev = tmp;

	if (!tmp)
		*head = new_node;

	return (new_node);
}

/**
 * free_stack - free list
 * @head: head of a doubly linked list
 */
void free_stack(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (tmp)
	{
		head = tmp->next;
		free(tmp);
		tmp = head;
	}
}
