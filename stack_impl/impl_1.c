/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 16:19:47 by mvoskany          #+#    #+#             */
/*   Updated: 2026/04/15 16:16:16 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
