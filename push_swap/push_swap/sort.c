/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:40:25 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/04 16:56:37 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_Node **stack)
{
	if (*stack && (*stack)->next != NULL)
	{
		if ((*stack)->x > (*stack)->next->x)
			sa(stack);
	}
}

void	three_sort(t_Node **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = (**stack_a).x;
	mid = (**stack_a).next->x;
	bot = (**stack_a).next->next->x;
	if ((top > mid) && (bot > top))
		sa(stack_a);
	else if ((top > mid) && (mid > bot))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((top > mid) && (mid < bot))
		ra(stack_a);
	else if ((top < mid) && (mid > bot) && (top < bot))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((top < mid) && (mid > bot) && (top > bot))
		rra(stack_a);
}

void	five_sort(t_Node **stack_a)
{
	t_Node	*stack_b;
	int		stack_len_a;
	int		elements_to_move;

	stack_b = NULL;
	stack_len_a = stack_len(*stack_a);
	if (stack_len_a < 4 || stack_len_a > 10)
		return ;
	elements_to_move = stack_len_a - 3;
	while (elements_to_move > 0)
	{
		push_smallest_to_b(stack_a, &stack_b);
		elements_to_move--;
	}
	three_sort(stack_a);
	while (stack_b)
		pa(stack_a, &stack_b);
}

int	get_max_bits(t_Node *stack)
{
	int	max_value;
	int	bits;

	max_value = INT_MIN;
	bits = 0;
	while (stack)
	{
		if (stack->i > max_value)
			max_value = stack->i;
		stack = stack->next;
	}
	while (max_value)
	{
		max_value >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_Node **stack_a, t_Node **stack_b)
{
	int	i;
	int	max_bits;
	int	len;

	i = -1;
	max_bits = get_max_bits(*stack_a);
	while (++i < max_bits)
	{
		len = stack_len(*stack_a);
		while (len-- > 0)
		{
			if ((((*stack_a)->i >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
