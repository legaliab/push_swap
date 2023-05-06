/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:12:44 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/03 14:59:43 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*arr;
	int		count;
	t_Node	*stack_a;

	stack_a = NULL;
	count = parse_args(ac, av, &arr);
	if (count == 0)
		ft_error();
	stack_a = create_stack(count, arr);
	assign_indexes(&stack_a);
	free(arr);
	is_stack_sorted(&stack_a);
	sort(&stack_a);
	free_list(&stack_a);
	return (0);
}

void	sort(t_Node **stack_a)
{
	t_Node	*stack_b;
	int		len_stack_a;

	stack_b = NULL;
	len_stack_a = stack_len(*stack_a);
	if (len_stack_a == 2)
		two_sort(stack_a);
	else if (len_stack_a == 3)
		three_sort(stack_a);
	else if (len_stack_a <= 10)
		five_sort(stack_a);
	else
		radix_sort(stack_a, &stack_b);
}

void	print_stack(t_Node *head)
{
	t_Node	*temp;

	temp = head;
	while (temp)
	{
		ft_printf("%d ", temp->x);
		temp = temp->next;
	}
	free_list(&temp);
	free_list(&head);
	ft_printf("\n");
}
