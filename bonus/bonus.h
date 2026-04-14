/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:43:24 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/14 15:37:59 by nhovhiky         ###   ########.fr       */
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

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

char	*ft_split_leftover(char *leftover);
char	*ft_save_remainder(char *leftover);
char	*get_next_line(int fd);

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

void    free_stack(t_stack **st);
int     is_sorted(t_stack *a);

char    *join_all_args(int argc, char **argv);

#endif