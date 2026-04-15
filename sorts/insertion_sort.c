/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:35:24 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 14:39:25 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	best_rotation(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	helper_rot(t_stack **b, int rot, t_op_count *counts)
{
	while (rot > 0)
	{
		rb(b, counts);
		rot--;
	}
	while (rot < 0)
	{
		rrb(b, counts);
		rot++;
	}
}

void	rotate_to_top(t_stack **b, int val, int size, t_op_count *counts)
{
	t_stack	*current;
	t_stack	*best;
	int		best_pos;
	int		rot;

	current = *b;
	best = NULL;
	best_pos = -1;
	while (current)
	{
		if (current->n < val)
		{
			if (best == NULL || current->n > best->n)
			{
				best = current;
				best_pos = get_position(*b, current);
			}
		}
		current = current->next;
	}
	if (best == NULL)
		best_pos = get_position(*b, stack_min(*b));
	rot = best_rotation(best_pos, size);
	helper_rot(b, rot, counts);
}

// the main insertion sort
void	insertion_sort(t_stack **a, t_stack **b, t_op_count *counts)
{
	int size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		return (sort_two(a, counts));
	if (size == 3)
		return (sort_three(a, counts));
	if (size <= 5)
		return (sort_five(a, b, counts));
	pb(a, b, counts);
	pb(a, b, counts);
	while (*a)
	{
		rotate_to_top(b, (*a)->n, stack_size(*b), counts);
		pb(a, b, counts);
	}
	while (*b)
		pa(a, b, counts);
}