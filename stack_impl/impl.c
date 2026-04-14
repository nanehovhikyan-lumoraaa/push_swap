/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:19:47 by mvoskany          #+#    #+#             */
/*   Updated: 2026/04/11 15:44:59 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// paylatakum: use this function to make pa pb... calls and change the struct as we need to



void	swap_num(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap(t_stack *st)
{
	if (!st || !st->next)
		return ;
	swap_num(&st->n, &st->next->n);
}

void	sa(t_stack *a, t_op_count *counts)
{
	swap(a);
	write(1, "sa\n", 3);
	(counts->sa)++;
	(counts->total)++;
}

void	sb(t_stack *b, t_op_count *counts)
{
	swap(b);
	write(1, "sb\n", 3);
	(counts->sb)++;
	(counts->total)++;
}

void	ss(t_stack *a, t_stack *b, t_op_count *counts)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	(counts->ss)++;
	(counts->total)++;
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dst;
	if (*dst)
		(*dst)->prev = tmp;
	*dst = tmp;
	(*dst)->prev = NULL;
}

void	pa(t_stack **a, t_stack **b, t_op_count *counts)
{
	push(b, a);
	write(1, "pa\n", 3);
	(counts->pa)++;
	(counts->total)++;
}

void	pb(t_stack **a, t_stack **b, t_op_count *counts)
{
	push(a, b);
	write(1, "pb\n", 3);
	(counts->pb)++;
	(counts->total)++;
}

void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	ra(t_stack **a, t_op_count *counts)
{
	rotate(a);
	write(1, "ra\n", 3);
	(counts->ra)++;
	(counts->total)++;
}

void	rb(t_stack **b, t_op_count *counts)
{
	rotate(b);
	write(1, "rb\n", 3);
	(counts->rb)++;
	(counts->total)++;
}

void	rr(t_stack **a, t_stack **b, t_op_count *counts)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	(counts->rr)++;
	(counts->total)++;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	(*stack)->prev = NULL;
}

void	rra(t_stack **a, t_op_count *counts)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
	(counts->rra)++;
	(counts->total)++;
}

void	rrb(t_stack **b, t_op_count *counts)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	(counts->rrb)++;
	(counts->total)++;
}

void	rrr(t_stack **a, t_stack **b, t_op_count *counts)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	(counts->rrr)++;
	(counts->total)++;
}
