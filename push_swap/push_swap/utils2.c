/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:20:11 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/02 16:01:29 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_Node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

int	ra_or_rra(t_Node *stack, int position)
{
	int	stack_size;

	stack_size = stack_len(stack);
	if (position <= stack_size / 2)
		return (1);
	else
		return (-1);
}

void	is_stack_sorted(t_Node **stack)
{
	t_Node	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->x > current->next->x)
			return ;
		current = current->next;
	}
	free_list(stack);
	exit(12);
}

int	find_position(t_Node *stack_a, int value)
{
	t_Node	*current;
	int		position;

	current = stack_a;
	position = 0;
	while (current != NULL)
	{
		if (current->x >= value)
		{
			break ;
		}
		current = current->next;
		position++;
	}
	return (position);
}
