/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:20:11 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/04 16:36:00 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_Node **list)
{
	t_Node	*current_node;
	t_Node	*next_node;

	current_node = (*list);
	while (current_node != NULL)
	{
		next_node = current_node->next;
		free(current_node);
		current_node = next_node;
	}
}

void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	free_str_array(char **str_array)
{
	int	i;

	if (str_array == NULL)
		return ;
	i = -1;
	while (str_array[++i] != NULL)
		free(str_array[i]);
	free(str_array);
}

int	is_sign(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-') || (str[i] == '+'))
		return (1);
	else
		return (0);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	if (is_sign(&str[i]) && str[i + 1] != '\0')
		i++;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]) && !ft_isspace(str[i]))
		return (0);
	return (1);
}
