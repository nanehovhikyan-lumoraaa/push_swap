#include "push_swap.h"

// Հաշվարկում է ամենաշահավետ ճանապարհը դեպի pos ինդեքսով անդամը
int	best_rotation(int pos, int size)        
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void	rotate_to_top(t_stack **b, int val, int size)
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
	while (rot > 0)
	{
		rb(b);
		rot--;
	}
	while (rot < 0)
	{
		rrb(b);
		rot++;
	}
}

// the main insertion sort
void	sort_simple(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		return (sort_two(a));
	if (size == 3)
		return (sort_three(a));
	if (size <= 5)
		return (sort_five(a, b));
	pb(a, b);
	pb(a, b);
	while (*a)
	{
		rotate_to_top(b, (*a)->n, stack_size(*b));
		pb(a, b);
	}
	while (*b)
		pa(a, b);
}