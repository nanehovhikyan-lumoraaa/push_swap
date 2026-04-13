/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:07:48 by mvoskany          #+#    #+#             */
/*   Updated: 2026/04/13 21:18:40 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack {
    struct s_stack* prev;
    struct s_stack* next;
    int n;
    int rank;
} t_stack;

typedef struct s_op_count{
    int sa;
    int sb;
    int pa;
    int ra;
    int rra;
    int pb;
    int rb;
    int rrb;
    int ss;
    int rr;
    int rrr;
    int total;
    int chunk_min;
    int chunk_max;
} t_op_count;
// lists head is stacks top

void    swap_num(int *a, int *b);
void    swap(t_stack *st);
void    push(t_stack **src, t_stack **dst);

void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);

void    sa(t_stack *a, t_op_count *counts);
void    pa(t_stack **a, t_stack **b, t_op_count *counts);
void    ra(t_stack **a, t_op_count *counts);
void    rra(t_stack **a, t_op_count *counts);

void    sb(t_stack *b, t_op_count *counts);
void    pb(t_stack **a, t_stack **b, t_op_count *counts);
void    rb(t_stack **b, t_op_count *counts);
void    rrb(t_stack **b, t_op_count *counts);

void    ss(t_stack *a, t_stack *b, t_op_count *counts);
void    rr(t_stack **a, t_stack **b, t_op_count *counts);
void    rrr(t_stack **a, t_stack **b, t_op_count *counts);

// utils.c
int     stack_size(t_stack *st);
int     is_sorted(t_stack *a);
t_stack *stack_min(t_stack *st);
int     get_position(t_stack *st, t_stack *node);
void    free_stack(t_stack **st);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

// sort_simple.c
void    insertion_sort(t_stack **a, t_stack **b, t_op_count *counts);
void    rotate_to_top(t_stack **a, int val, int size, t_op_count *counts);
int     best_rotation(int pos, int size);
void helper_rot(t_stack **b, int rot, t_op_count *counts);

// sort_small.cs
void    sort_two(t_stack **a, t_op_count *counts);
void    sort_three(t_stack **a, t_op_count *counts);
void    sort_five(t_stack **a, t_stack **b, t_op_count *counts);

// medium
void    get_ranks(t_stack *a);
void    push_chunk(t_stack **a, t_stack **b, t_op_count *counts);
int     find_max_rank_pos(t_stack *b, int size_b);
void    pull_back(t_stack **a, t_stack **b, t_op_count *counts);
void    chunk_sort(t_stack **a, t_stack **b, t_op_count *counts);

// split
static void     free_all(char **res, int i);
static char     *create_dup(char *str, int n);
static int      count_words(const char *str, char charset);
static char     **fill_result(char **result, char const *s, char c);
char            **ft_split(char const *s, char c);

// adaptive 
float   compute_disorder(t_stack *a);
void    adaptive(float disorder, t_stack **a, t_stack **b, t_op_count *counts);

// radix
void radix_sort(t_stack **a, t_stack **b, t_op_count *counts);

// validation
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s);
int     ft_strcmp_strict(char *s1, char *s2);
char    *join_all_args(int argc, char **argv);
void    free_mat(char **mat);
int     is_valid_num_range(char *str);
int     is_flag(char *str, int *bench);
int     has_dup(char **mat);
int     is_valid(char *str, char **flag, int *bench);

// parsing.c
int	ft_atoi(const char *str);