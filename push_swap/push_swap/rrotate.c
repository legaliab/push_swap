/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 00:28:18 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/02 16:01:44 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Node	*rev_rotate(t_Node *stack)
{
	t_Node	*last;
	t_Node	*first;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	last = stack;
	while (last->next != NULL)
		last = last->next;
	first = stack;
	stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	return (stack);
}

void	rra(t_Node **stack_a)
{
	*stack_a = rev_rotate(*stack_a);
	ft_putendl_fd("rra", 1);
}
