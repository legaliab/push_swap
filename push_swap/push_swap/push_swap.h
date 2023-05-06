/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alabdull <@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:03:49 by alabdull          #+#    #+#             */
/*   Updated: 2023/05/04 16:40:58 by alabdull         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct t_Node
{
	int				x;
	int				i;
	struct t_Node	*next;
	struct t_Node	*prev;
}					t_Node;

int					is_sign(char *str);
int					is_int(char *str);
int					parse_args(int argc, char **argv, int **arr_ptr);
int					parse_and_count_args(int argc, char **argv);
int					is_only_spaces(const char *str);
int					count_numbers(const char *s);
int					is_empty_or_whitespace(const char *str);
int					ft_isspace(const int c);
int					get_max_bits(t_Node *stack);
int					stack_len(t_Node *stack);
int					find_smallest_node(t_Node *head);
int					ra_or_rra(t_Node *stack, int position);
int					find_position(t_Node *stack_a, int value);
int					lst_last(t_Node *head);
int					process_quotes(const char *s, bool *in_quotes);
int					process_digits(const char *s, bool in_quotes,
						bool *last_was_digit, int *count);
int					is_int2(char *str);
void				ft_error(void);
void				append_node(t_Node **head, int data);
void				print_stack(t_Node *head);
void				free_str_array(char **str_array);
void				radix_sort(t_Node **stack_a, t_Node **stack_b);
void				push(t_Node **stack_a, t_Node **stack_b);
void				pa(t_Node **stack_a, t_Node **stack_b);
void				pb(t_Node **stack_a, t_Node **stack_b);
void				free_list(t_Node **list);
void				fill_arr(int ac, char **av, int *arr);
void				check_duplicates(int *arr, int total_numbers,
						t_error_data *error_data);
void				ra(t_Node **stack_a);
void				rra(t_Node **stack_a);
void				sa(t_Node **stack_a);
void				three_sort(t_Node **stack_top);
void				five_sort(t_Node **stack_a);
void				is_stack_sorted(t_Node **stack);
void				push_smallest_to_b(t_Node **stack_a, t_Node **stack_b);
void				ft_error_handler(t_error_data *error_data);
void				free_tokens(char **tokens);
void				assign_indexes(t_Node **stack);
void				sort(t_Node **stack_a);
void				two_sort(t_Node **stack);
t_Node				*get_next_min_value(t_Node *stack, long last_min_value);
t_Node				*swap(t_Node *stack);
t_Node				*create_node(int data);
t_Node				*create_stack(int ac, int *arr);
t_Node				*rotate(t_Node *stack);

#endif