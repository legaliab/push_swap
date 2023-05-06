/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:09:10 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/04 16:55:24 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_array(int argc, char **argv, int *arr, t_error_data *error_data)
{
	int		i;
	char	**tokens;
	int		k;
	int		l;
	int		j;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		tokens = ft_split(argv[i], ' ');
		error_data->tokens = tokens;
		k = 0;
		while (tokens[k] != NULL)
		{
			if (!is_int2(tokens[k]))
				ft_error_handler(error_data);
			arr[j++] = ft_atoi(tokens[k], error_data);
			k++;
		}
		l = -1;
		while (tokens[++l] != NULL)
			free(tokens[l]);
		free(tokens);
	}
}

void	check_duplicates(int *arr, int total_numbers, t_error_data *error_data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < total_numbers)
	{
		j = i + 1;
		while (j < total_numbers)
		{
			if (arr[i] == arr[j])
			{
				error_data->arr = arr;
				error_data->tokens = NULL;
				ft_error_handler(error_data);
			}
			j++;
		}
		i++;
	}
}

int	parse_and_count_args(int argc, char **argv)
{
	int	total_numbers;
	int	i;

	total_numbers = 0;
	i = 1;
	if (argc < 2)
		exit(1);
	while (i < argc)
	{
		total_numbers += count_numbers(argv[i]);
		i++;
	}
	return (total_numbers);
}

int	parse_args(int argc, char **argv, int **arr_ptr)
{
	int				total_numbers;
	int				*arr;
	t_error_data	error_data;

	error_data.arr = NULL;
	error_data.tokens = NULL;
	total_numbers = parse_and_count_args(argc, argv);
	arr = (int *)malloc(sizeof(int) * total_numbers);
	error_data.arr = arr;
	if (!arr)
		return (0);
	fill_array(argc, argv, arr, &error_data);
	check_duplicates(arr, total_numbers, &error_data);
	*arr_ptr = arr;
	return (total_numbers);
}
