/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:39:47 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/16 17:57:16 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a, t_op_count *counts)
{
	if ((*a)->n > (*a)->next->n)
		sa(*a, counts);
}

static void	get_vals(t_stack *a, int *top, int *mid, int *bot)
{
	*top = a->n;
	*mid = a->next->n;
	*bot = a->next->next->n;
}

void	sort_three(t_stack **a, t_op_count *counts)
{
	int	t;
	int	m;
	int	b;

	get_vals(*a, &t, &m, &b);
	if (t < m && m < b)
		return ;
	if (t < m && t < b && m > b)
	{
		sa(*a, counts);
		ra(a, counts);
	}
	else if (t > m && m < b && t < b)
		sa(*a, counts);
	else if (t > m && m > b)
	{
		sa(*a, counts);
		rra(a, counts);
	}
	else if (t > m && t > b && m < b)
		ra(a, counts);
	else if (t < m && t > b && m > b)
		rra(a, counts);
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

void	call_small(t_stack **a, t_stack **b, t_op_count *counts)
{
	if (stack_size(*a) == 2)
		sort_two(a, counts);
	else if (stack_size(*a) == 3)
		sort_three(a, counts);
	else if (stack_size(*a) == 4 || stack_size(*a) == 5)
		sort_five(a, b, counts);
}
