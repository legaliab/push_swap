/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:20:11 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/04 16:30:13 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_smallest_node(t_Node *head)
{
	int		pos;
	int		smallest_pos;
	t_Node	*current;
	t_Node	*smallest_node;

	pos = 1;
	smallest_pos = 1;
	if (head == NULL)
	{
		return (0);
	}
	current = head;
	smallest_node = head;
	while (current != NULL)
	{
		if (current->x < smallest_node->x)
		{
			smallest_node = current;
			smallest_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (smallest_pos);
}

void	push_smallest_to_b(t_Node **stack_a, t_Node **stack_b)
{
	int	stack_len_a;
	int	min_pos;
	int	direction;

	stack_len_a = stack_len(*stack_a);
	min_pos = find_smallest_node(*stack_a);
	direction = ra_or_rra(*stack_a, min_pos);
	if (direction == 1)
	{
		min_pos = min_pos - 1;
		while (min_pos-- > 0)
			ra(stack_a);
	}
	else
	{
		min_pos = stack_len_a - min_pos + 1;
		while (min_pos-- > 0)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

int	lst_last(t_Node *head)
{
	if (!head)
		return (0);
	while (head && head->next)
		head = head->next;
	return (head->x);
}

int	is_int2(char *str)
{
	int	i;

	i = 0;
	if (is_sign(&str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	if (str[i] && !ft_isdigit(str[i]) && !ft_isspace(str[i]))
		return (0);
	return (1);
}
