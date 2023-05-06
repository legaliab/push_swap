/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:26:00 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/02 16:01:50 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Node	*rotate(t_Node *stack)
{
	t_Node	*first;
	t_Node	*second;
	t_Node	*last;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	first = stack;
	second = stack->next;
	last = stack;
	while (last->next != NULL)
		last = last->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	second->prev = NULL;
	stack = second;
	return (stack);
}

void	ra(t_Node **stack_a)
{
	*stack_a = rotate(*stack_a);
	ft_putendl_fd("ra", 1);
}
