/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:29:44 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 14:30:00 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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