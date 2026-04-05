/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:07:48 by mvoskany          #+#    #+#             */
/*   Updated: 2026/04/05 21:06:40 by nhovhiky         ###   ########.fr       */
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
} t_stack;
// lists head is stacks top

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

// utils.c
int     stack_size(t_stack *st);
int     is_sorted(t_stack *a);
t_stack *stack_min(t_stack *st);
int     get_position(t_stack *st, t_stack *node);
void    free_stack(t_stack **st);

// sort_simple.c
void    sort_simple(t_stack **a, t_stack **b);
void    rotate_to_top(t_stack **a, int val, int size);
int     best_rotation(int pos, int size);

// sort_small.cs
void    sort_two(t_stack **a);
void    sort_three(t_stack **a);
void    sort_five(t_stack **a, t_stack **b);