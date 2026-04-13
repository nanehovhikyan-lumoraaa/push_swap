// sa -> swap the top 2 elements of stack A
// ra -> Rotate stack A up (top goes to bottom)
// rra -> Reverse rotate stack A (bottom comes to top)
// pb -> Push top of A → onto B
// pa -> Push top of B → back onto A

#include "push_swap.h"
// insertion sort wastes operations on small cases

void	sort_two(t_stack **a, t_op_count *counts)       // 0 or 1 operation
{
	if ((*a)->n > (*a)->next->n)
		sa(*a, counts);
}                  

void	sort_three(t_stack **a, t_op_count *counts)         // at most 2 operations
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->n;
	mid = (*a)->next->n;
	bot = (*a)->next->next->n;
	if (top < mid && mid < bot)			// case 1 -> Already sorted
		return ;						// Example: [1, 2, 3] → do nothing
	else if (top < mid && top < bot && mid > bot)	// case 5: [1, 3, 2] 
	{		
		sa(*a, counts);							// swap → [3, 1, 2] 
		ra(a, counts);							// rotate → [1, 2, 3]
	}
	else if (top > mid && mid < bot && top < bot)	// Case 2: [2,1,3]
	{
		sa(*a, counts);
	}
	else if (top > mid && mid > bot)			// case 3: [3, 2, 1]
	{
		sa(*a, counts);									// [2, 3, 1]
		rra(a, counts);									// [1, 2, 3]
	}
	else if (top > mid && top > bot && mid < bot)	// case 4: [3, 1, 2]
	{
		ra(a, counts);
	}
	else if (top < mid && top > bot && mid > bot)	// Case 6: [2,3,1]
	{
		rra(a, counts);
	}
}

// for 4 or 5 elements
// The strategy here is:
// Push the smallest elements to stack b until only 3 remain in a, sort those 3, 
// then push everything back from b to a.
void	sort_five(t_stack **a, t_stack **b, t_op_count *counts)
{													// example a = [3, 1, 4, 2], b = []
	int	size;
	int	pos;
	int	rot;

	size = stack_size(*a);				// 4 or 5
	while (size > 3)
	{
		pos = get_position(*a, stack_min(*a));			// 0 = top, 1 = second, etc.
		rot = best_rotation(pos, size);					// If rot > 0 → rotate forward (ra) that many times. If rot < 0 → reverse rotate (rra) that many times.
		while (rot > 0)
		{
			ra(a, counts);					// [1, 4, 2, 3]
			rot--;
		}
		while (rot < 0)					// for backward rotations (rra) the rot would be negative
		{
			rra(a, counts);
			rot++;
		}						// Now the minimum is at the top of stack a.
		pb(a, b, counts);				// push top of a → top of b. 	After:a = [4, 2, 3], b = [1]
		size--;
	}
	sort_three(a, counts);
	while (*b)
        pa(a, b, counts);           
}




// // helper: apply up to 2 ops
// static void do_ops(t_stack **a,
//                    void (*op1)(t_stack **),
//                    void (*op2)(t_stack **),
//                    void (*swap)(t_stack *))
// {
//     if (op1) op1(a);
//     if (swap) swap(*a);
//     if (op2) op2(a);
// }

// void sort_three(t_stack **a)
// {
//     int top = (*a)->n;
//     int mid = (*a)->next->n;
//     int bot = (*a)->next->next->n;

//     if (top < mid && mid < bot) return;                 // [1,2,3]
//     else if (top > mid && mid < bot && top < bot)       // [2,1,3]
//         do_ops(a, NULL, NULL, sa);
//     else if (top > mid && mid > bot)                    // [3,2,1]
//         do_ops(a, NULL, rra, sa);
//     else if (top > mid && top > bot && mid < bot)       // [3,1,2]
//         do_ops(a, ra, NULL, NULL);
//     else if (top < mid && top < bot && mid > bot)       // [1,3,2]
//         do_ops(a, ra, NULL, sa);
//     else if (top < mid && top > bot && mid > bot)       // [2,3,1]
//         do_ops(a, rra, NULL, NULL);
// }
