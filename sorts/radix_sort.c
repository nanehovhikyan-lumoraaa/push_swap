/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 12:51:12 by marvin            #+#    #+#             */
/*   Updated: 2026/04/11 12:58:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bits_size(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

static void	radix_sort_helper(t_stack **a, t_stack **b, int bit, t_op_count *counts)
{
	int	size;
    size = stack_size(*a);
    while (size--)
    {
        if ((((*a)->rank >> bit) & 1) == 1)
            ra(a, counts);
        else
            pb(a, b, counts);
    }
}

void	radix_sort(t_stack **a, t_stack **b, t_op_count *counts)
{
	int	size;
	int	bits_size;
	int	bit;

	size = stack_size(*a);
	bits_size = get_bits_size(size); // how many bits are needed?
	bit = 0;
	while (bit < bits_size)
	{
		radix_sort_helper(a, b, bit, counts);
		while (*b)
			pa(a, b, counts);
		bit++;
	}
}
