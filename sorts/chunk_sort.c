/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:41:28 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 16:13:07 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_ranks(t_stack *a)
{
	t_stack	*current;
	t_stack	*cmp;
	int		rank;

	current = a;
	while (current)
	{
		rank = 0;
		cmp = a;
		while (cmp)
		{
			if (cmp->n < current->n)
				rank++;
			cmp = cmp->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

static int	get_next_pos(t_stack *a, int min, int max)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->rank >= min && a->rank <= max)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	push_chunk(t_stack **a, t_stack **b, t_op_count *counts)
{
	int	pos;
	int	size;
	int	pushed;
	int	rem;

	size = stack_size(*a);
	pushed = 0;
	rem = counts->chunk_max - counts->chunk_min + 1;
	while (pushed < rem && *a)
	{
		pos = get_next_pos(*a, counts->chunk_min, counts->chunk_max);
		if (pos == -1)
			break ;
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(a, counts);
		else
			while (size - pos++ > 0)
				rra(a, counts);
		pb(a, b, counts);
		size--;
		pushed++;
	}
}

void	pull_back(t_stack **a, t_stack **b, t_op_count *counts)
{
	int	size_b;
	int	pos;
	int	back;

	while (*b)
	{
		size_b = stack_size(*b);
		pos = find_max_rank_pos(*b);
		if (pos <= size_b / 2)
			while (pos-- > 0)
				rb(b, counts);
		else
		{
			back = size_b - pos;
			while (back-- > 0)
				rrb(b, counts);
		}
		pa(a, b, counts);
	}
}

void	chunk_sort(t_stack **a, t_stack **b, t_op_count *counts)
{
	int	n;
	int	chunk_size;
	int	i;

	n = stack_size(*a);
	if (n <= 5)
	{
		sort_five(a, b, counts);
		return ;
	}
	get_ranks(*a);
	chunk_size = ft_sqrt(n);
	if (chunk_size < 1)
		chunk_size = 1;
	i = 0;
	while (i * chunk_size < n)
	{
		counts->chunk_min = i * chunk_size;
		counts->chunk_max = counts->chunk_min + chunk_size - 1;
		if (counts->chunk_max >= n)
			counts->chunk_max = n - 1;
		push_chunk(a, b, counts);
		i++;
	}
	pull_back(a, b, counts);
}
