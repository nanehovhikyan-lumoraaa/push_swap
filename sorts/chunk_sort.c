/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:41:28 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 14:43:39 by nhovhiky         ###   ########.fr       */
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

void	push_chunk(t_stack **a, t_stack **b, t_op_count *counts)
{
	int		pushed;
	int		pos;
	int		remaining;
	int		size_a;
	t_stack	*tmp;
	int		back;

	size_a = stack_size(*a);
	pushed = 0;
	remaining = counts->chunk_max - counts->chunk_min + 1;
	while (pushed < remaining && *a)
	{
		pos = 0;
		{
			tmp = *a;
			while (tmp && !(tmp->rank >= counts->chunk_min
					&& tmp->rank <= counts->chunk_max))
			{
				pos++;
				tmp = tmp->next;
			}
			if (!tmp)
				break ;
		}
		if (pos <= size_a / 2)
			while (pos-- > 0)
				ra(a, counts);
		else
		{
			back = size_a - pos;
			while (back-- > 0)
				rra(a, counts);
		}
		pb(a, b, counts);
		size_a--;
		pushed++;
	}
}

int	find_max_rank_pos(t_stack *b)
{
	t_stack	*cur;
	int		max_rank;
	int		max_pos;
	int		pos;

	cur = b;
	max_rank = -1;
	max_pos = 0;
	pos = 0;
	while (cur)
	{
		if (cur->rank > max_rank)
		{
			max_rank = cur->rank;
			max_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	return (max_pos);
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
	int n;
	int chunk_size;
	int i;

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