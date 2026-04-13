#include "push_swap.h"

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	i = 1;
	while (i * i <= nb)
	{
		if (i > 46340) // Square root of INT_MAX to prevent overflow
			break ;
		i++;
	}
	return (i - 1);
}

/*
** STEP 1 — Assign a rank (0-based index in sorted order) to every node.
** Rank 0 = smallest, rank n-1 = largest.
** We do this with an O(n²) double loop — fine since it's setup work only.
*/
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

/*
** STEP 2 helper — scan stack A and push every node whose rank falls
** inside [chunk_min, chunk_max] onto B.
**
** We rotate A smartly: if the target is in the first half, ra forward;
** if in the second half, rra backward.  This keeps rotations cheap.
**
** After pb the node lands on top of B — B grows in a "mostly descending"
** order because we push lower-ranked chunks first.
*/
void	push_chunk(t_stack **a, t_stack **b, t_op_count *counts)
{
	int	pushed;
	int	pos;
	int	remaining;
    int size_a;

    size_a = stack_size(*a);
	pushed = 0;
	remaining = counts->chunk_max - counts->chunk_min + 1;
	while (pushed < remaining && *a)
	{
		pos = 0;
		{
			t_stack *tmp = *a;
			while (tmp && !(tmp->rank >= counts->chunk_min && tmp->rank <= counts->chunk_max))
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
			int back = size_a - pos;
			while (back-- > 0)
				rra(a, counts);
		}
		pb(a, b, counts);
		size_a--;
		pushed++;
	}
}

/*
** STEP 3 helper — find the position of the node with the highest rank
** currently in B.  We'll rotate B to bring it to the top, then pa.
*/
int	find_max_rank_pos(t_stack *b, int size_b)
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

/*
** STEP 3 — pull everything back from B to A in descending rank order
** (so A ends up sorted ascending, smallest on top).
**
** Each iteration:
**   • find the position of the current maximum in B
**   • rotate B (forward or backward, whichever is shorter) to bring it up
**   • pa
*/
void	pull_back(t_stack **a, t_stack **b, t_op_count *counts)
{
	int	size_b;
	int	pos;
	int	back;

	while (*b)
	{
		size_b = stack_size(*b);
		pos = find_max_rank_pos(*b, size_b);
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

/*
** MAIN ENTRY — O(n * sqrt(n)) chunk sort.
**
** Algorithm outline:
**   1. Rank all nodes (O(n²) setup, not counted in operation cost).
**   2. Compute chunk_size = sqrt(n), giving ~sqrt(n) chunks.
**   3. For each chunk [i*chunk_size .. (i+1)*chunk_size - 1]:
**        push_chunk → moves those ranks to B (O(n) rotations per chunk,
**        sqrt(n) chunks → O(n * sqrt(n)) total push operations).
**   4. pull_back → for each of the n elements in B, one O(sqrt(n))
**        scan+rotate to find the max → O(n * sqrt(n)) total pull ops.
**
** Total Push_swap operations: O(n * sqrt(n)).
*/
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