/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:09:10 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/04 16:41:58 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(const char *s)
{
	int		count;
	bool	in_quotes;
	bool	last_was_digit;

	count = 0;
	in_quotes = false;
	last_was_digit = false;
	while (*s)
	{
		if (!process_quotes(s, &in_quotes))
		{
			process_digits(s, in_quotes, &last_was_digit, &count);
		}
		s++;
	}
	if (last_was_digit)
		count++;
	if (in_quotes)
		ft_error();
	return (count);
}

int	process_quotes(const char *s, bool *in_quotes)
{
	if (*s == '\"')
	{
		*in_quotes = !(*in_quotes);
		return (1);
	}
	return (0);
}

int	process_digits(const char *s, bool in_quotes, bool *last_was_digit,
		int *count)
{
	if (ft_isspace((unsigned char)*s) && !in_quotes)
	{
		if (*last_was_digit)
			(*count)++;
		*last_was_digit = false;
	}
	else if (is_int((char *)s))
	{
		*last_was_digit = true;
	}
	else
	{
		ft_error();
	}
	return (0);
}
