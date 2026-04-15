/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:07:48 by mvoskany          #+#    #+#             */
/*   Updated: 2026/04/15 16:14:58 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	int				n;
	int				rank;
}					t_stack;

typedef struct s_op_count
{
	int				sa;
	int				sb;
	int				pa;
	int				ra;
	int				rra;
	int				pb;
	int				rb;
	int				rrb;
	int				ss;
	int				rr;
	int				rrr;
	int				total;
	int				chunk_min;
	int				chunk_max;
}					t_op_count;

typedef struct s_data
{
	char			*flag;
	int				bench;
	t_op_count		counts;
}					t_data;

// impl_helpers.c
void				swap_num(int *a, int *b);
void				swap(t_stack *st);
void				push(t_stack **src, t_stack **dst);
void				rotate(t_stack **stack);
void				reverse_rotate(t_stack **stack);

// impl_1.c
void				sa(t_stack *a, t_op_count *counts);
void				sb(t_stack *b, t_op_count *counts);
void				ss(t_stack *a, t_stack *b, t_op_count *counts);
void				pa(t_stack **a, t_stack **b, t_op_count *counts);
void				pb(t_stack **a, t_stack **b, t_op_count *counts);

// impl_2.c
void				ra(t_stack **a, t_op_count *counts);
void				rb(t_stack **b, t_op_count *counts);
void				rr(t_stack **a, t_stack **b, t_op_count *counts);

// impl_3.c
void				rra(t_stack **a, t_op_count *counts);
void				rrb(t_stack **b, t_op_count *counts);
void				rrr(t_stack **a, t_stack **b, t_op_count *counts);

// utils_stack.c
int					stack_size(t_stack *st);
int					is_sorted(t_stack *a);
t_stack				*stack_min(t_stack *st);
int					get_position(t_stack *st, t_stack *node);
void				free_stack(t_stack **st);

// utils_str.c
char				*ft_strstr(const char *big, const char *little);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

// insertion_sort.c
void				insertion_sort(t_stack **a, t_stack **b,
						t_op_count *counts);
void				rotate_to_top(t_stack **a, int val, int size,
						t_op_count *counts);
int					best_rotation(int pos, int size);
void				helper_rot(t_stack **b, int rot, t_op_count *counts);

// sort_small.c
void				sort_two(t_stack **a, t_op_count *counts);
void				sort_three(t_stack **a, t_op_count *counts);
void				sort_five(t_stack **a, t_stack **b, t_op_count *counts);

// chunk_helper.c
int					ft_sqrt(int nb);
int					find_max_rank_pos(t_stack *b);

// chunk_sort.c
void				get_ranks(t_stack *a);
void				push_chunk(t_stack **a, t_stack **b, t_op_count *counts);
void				pull_back(t_stack **a, t_stack **b, t_op_count *counts);
void				chunk_sort(t_stack **a, t_stack **b, t_op_count *counts);

// split.c
void				free_all(char **res, int i);
char				*create_dup(char *str, int n);
int					count_words(const char *str, char charset);
char				**fill_result(char **result, char const *s, char c);
char				**ft_split(char const *s, char c);

// adaptive.c
double				compute_disorder(t_stack *a);
void				adaptive(double disorder, t_stack **a, t_stack **b,
						t_op_count *counts);

// radix_sort.c
int					get_bits_size(int size);
void				radix_sort_helper(t_stack **a, t_stack **b, int bit,
						t_op_count *counts);
void				radix_sort(t_stack **a, t_stack **b, t_op_count *counts);

// val_helpers_1.c
int					ft_strcmp_strict(char *s1, char *s2);
size_t				ft_strlen(const char *s);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s);

// val_helpers_2.c
int					is_flag(char *str, int *bench);
int					has_dup(char **mat);
void				free_mat(char **mat);
char				*join_all_args(int argc, char **argv);

// validation.c
int					is_valid_num_range(char *str);
int					is_valid(char *str, char **flag, int *bench);

// parse_helpers.c
int					ft_atoi(const char *str);
int					is_digit(char c);
int					is_number(char *str);

// parsing.c
t_stack				*create_node(int n);
void				stack_add_back(t_stack **stack, t_stack *new);
t_stack				*parse(char *str);

// bench_helper.c
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);

// bench.c
char				*get_flag(char *flag, double disorder);
void				write_double(double f, int fd);
void				print_bench(t_op_count *counts, double disorder,
						char *flag);

#endif