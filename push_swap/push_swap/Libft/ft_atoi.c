/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 14:57:45 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/03 00:31:44 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static void	ft_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

static void	ft_error_handler(t_error_data *error_data)
{
	if (error_data->arr)
		free(error_data->arr);
	if (error_data->tokens)
	{
		free_tokens(error_data->tokens);
	}
	ft_error();
}

char	ft_iswhitespaces(const int c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atoi(char *str, t_error_data *error_data)
{
	int			i;
	int			n;
	long long	result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] && ft_iswhitespaces(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		n = -1;
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		if ((n == 1 && (result > INT_MAX)) || (n == -1
				&& ((-result < INT_MIN))))
			ft_error_handler(error_data);
		i++;
	}
	return (result * n);
}
