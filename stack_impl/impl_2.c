/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   impl_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:25:02 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 16:16:18 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
