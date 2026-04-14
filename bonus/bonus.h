/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:43:24 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/14 21:47:22 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BONUS_H
#define BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

// get_next_line functions
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_split_leftover(char *leftover);
char	*ft_save_remainder(char *leftover);
char	*get_next_line(int fd);

// bonus_impl.c
void    swap_num(int *a, int *b);
void    swap(t_stack *st);
void    push(t_stack **src, t_stack **dst);
void    rotate(t_stack **stack);
void    reverse_rotate(t_stack **stack);
void    sa(t_stack *a);
void    pa(t_stack **a, t_stack **b);
void    ra(t_stack **a);
void    rra(t_stack **a);
void    sb(t_stack *b);
void    pb(t_stack **a, t_stack **b);
void    rb(t_stack **b);
void    rrb(t_stack **b);
void    ss(t_stack *a, t_stack *b);
void    rr(t_stack **a, t_stack **b);
void    rrr(t_stack **a, t_stack **b);

//utils_bonus.c
void    free_stack(t_stack **st);
int     is_sorted(t_stack *a);
char    *join_all_args(int argc, char **argv);
int	ft_strcmp(const char *s1, const char *s2);
void free_and_exit(t_stack **a, t_stack **b);
int is_valid(char *str);
int has_dup(char **mat);
t_stack	*parse(char *str);

// bonus.c
void apply_ops(t_stack **a, t_stack **b);

// helpers.c
void	free_all(char **res, int i);
char	*create_dup(char *str, int n);
int	count_words(const char *str, char charset);
char	**fill_result(char **result, char const *s, char c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s);
int	is_valid_num_range(char *str);
void free_mat(char **mat);
int	ft_atoi(const char *str);
t_stack *create_node(int n);
void stack_add_back(t_stack **stack, t_stack *new);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif