#include "push_swap.h"

// Հաշվարկում է ամենաշահավետ ճանապարհը դեպի pos ինդեքսով անդամը
// Rule: If the element is in the first half → rotate forward (positive). 
// If it's in the second half → rotate backward (negative, shorter path).
int	best_rotation(int pos, int size)        
{
	if (pos <= size / 2)
		return (pos);
	return (pos - size);
}

void helper_rot(t_stack **b, int rot)
{
	while (rot > 0)			// These loops actually rotate stack B until the “best position” is on top.
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

// This function's job: find the best position in Stack B to insert the current top 
// of Stack A, then rotate Stack B to put that position on top.
// This function doesn't move the val to the top of B
void	rotate_to_top(t_stack **b, int val, int size)
{
	t_stack	*current;			
	t_stack	*best;				
	int		best_pos;			
	int		rot;

	current = *b;				// a pointer to walk through stack B
	best = NULL;				// will hold the best node we find
	best_pos = -1;				// will hold that node's position/index
	while (current)	// find the largest element that is smaller than a's top 	 
	{
		if (current->n < val)		// val = the number currently on top of Stack A that we're about to push. We're looking for the largest number in B that is still smaller than val.
		{
			if (best == NULL || current->n > best->n)
			{
				best = current;				// best points to the largest number in B that is still smaller than val.
				best_pos = get_position(*b, current);			// best_pos is its position (index) in the stack.
			}
		}
		current = current->next;
	}
	if (best == NULL)			// If no element in B is smaller than val, that means val is the smallest number seen so far. 
		best_pos = get_position(*b, stack_min(*b));				// So instead of inserting above a smaller number, we just put it above the minimum in B.
	rot = best_rotation(best_pos, size);
	helper_rot(b, rot);
}

// the main insertion sort
void	insertion_sort(t_stack **a, t_stack **b)
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
	pb(a, b);				// We seed Stack B with 2 elements to give rotate_to_top something to work with.r
	pb(a, b);				// now B has 2 elements and A has size - 2 elements.
	while (*a)
	{
		rotate_to_top(b, (*a)->n, stack_size(*b));			// rotate Stack B so that the correct insertion point rises to the top.
		pb(a, b);					// Because we just rotated B to the right position, the number lands exactly where it maintains B's descending order.
	}
	while (*b)		// At this point Stack A is completely empty and Stack B holds all the numbers in descending order (biggest on top, smallest on bottom).
		pa(a, b);
}




// Look through stack B.
// Find the largest number smaller than the one we’re about to push (val).
// If none exist, use the smallest number in B instead.
// Rotate stack B so that this “best spot” is at the top.
// Now when we push val from A to B, it lands exactly where it should.