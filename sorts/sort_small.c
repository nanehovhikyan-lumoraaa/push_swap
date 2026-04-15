/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:39:47 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 16:08:10 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_op_count *counts)
{
	if ((*a)->n > (*a)->next->n)
		sa(*a, counts);
}

static int	get_min_pos(int top, int mid, int bot)
{
	if (top < mid && top < bot)
		return (0);
	if (mid < top && mid < bot)
		return (1);
	return (2);
}

void	sort_three(t_stack **a, t_op_count *counts)
{
	int	top;
	int	mid;
	int	bot;
	int	min_pos;

	top = (*a)->n;
	mid = (*a)->next->n;
	bot = (*a)->next->next->n;
	if (top < mid && mid < bot)
		return ;
	min_pos = get_min_pos(top, mid, bot);
	if (min_pos == 1)
		ra(a, counts);
	else if (min_pos == 2)
		rra(a, counts);
	if ((*a)->n > (*a)->next->n)
		sa(*a, counts);
}

void	sort_five(t_stack **a, t_stack **b, t_op_count *counts)
{
	int	size;
	int	pos;
	int	rot;

	size = stack_size(*a);
	while (size > 3)
	{
		pos = get_position(*a, stack_min(*a));
		rot = best_rotation(pos, size);
		while (rot > 0)
		{
			ra(a, counts);
			rot--;
		}
		while (rot < 0)
		{
			rra(a, counts);
			rot++;
		}
		pb(a, b, counts);
		size--;
	}
	sort_three(a, counts);
	while (*b)
		pa(a, b, counts);
}
