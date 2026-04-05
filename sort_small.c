#include "push_swap.h"
// insertion sort wastes operations on small cases
void	sort_two(t_stack **a)       // 0 or 1 operation
{
	if ((*a)->n > (*a)->next->n)
		sa(*a);
}                  

void	sort_three(t_stack **a)         // at most 2 operations
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->n;
	mid = (*a)->next->n;
	bot = (*a)->next->next->n;
	if (top < mid && mid < bot)
		return ;
	if (top < mid && top < bot)
	{
		ra(a);
		sa(*a);
		rra(a);
		return ;
	}
	if (top > mid && top > bot)
	{
		ra(a);
		return ;
	}
	if (top > mid && mid < bot && top < bot)
	{
		sa(*a);
		return ;
	}
	if (top < mid && top > bot)
	{
		rra(a);
		return ;
	}
	if (top > mid && top > bot && mid > bot)
	{
		sa(*a);
		ra(a);
	}
}

// for 4 or 5 elements
void	sort_five(t_stack **a, t_stack **b)
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
			ra(a);
			rot--;
		}
		while (rot < 0)
		{
			rra(a);
			rot++;
		}
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		pos = get_position(*a, stack_min(*a));
		rot = best_rotation(pos, size);
		while (rot > 0)
		{
			ra(a);
			rot--;
		}
		while (rot < 0)
		{
			rra(a);
			rot++;
		}
		pa(a, b);
	}
}