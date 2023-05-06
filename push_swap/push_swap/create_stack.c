/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:59:52 by alabdull          #+#    #+#             */
/*   Updated: 2023/04/24 13:54:44 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Node	*create_node(int data)
{
	t_Node	*new_node;

	new_node = (t_Node *)malloc(sizeof(t_Node));
	if (new_node == NULL)
		return (NULL);
	new_node->x = data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_Node	*create_stack(int ac, int *arr)
{
	t_Node	*head;
	int		i;

	head = NULL;
	i = -1;
	while (++i < ac)
		append_node(&head, arr[i]);
	return (head);
}

void	append_node(t_Node **head, int data)
{
	t_Node	*new_node;
	t_Node	*temp;

	new_node = create_node(data);
	if (new_node == NULL)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
	new_node->prev = temp;
}

t_Node	*get_next_min_value(t_Node *stack, long last_min_value)
{
	long	min_value;
	t_Node	*smallest_next_node;

	min_value = 2147483649;
	smallest_next_node = NULL;
	while (stack)
	{
		if (stack->x < min_value && stack->x > last_min_value)
		{
			min_value = stack->x;
			smallest_next_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_next_node);
}

void	assign_indexes(t_Node **stack)
{
	int		len;
	int		index;
	t_Node	*node;
	long	last_min_value;

	len = stack_len(*stack);
	index = 0;
	node = NULL;
	last_min_value = -2147483649;
	while (len-- > 0)
	{
		node = get_next_min_value(*stack, last_min_value);
		last_min_value = node->x;
		node->i = index;
		index++;
	}
}
