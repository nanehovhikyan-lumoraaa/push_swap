/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:32:49 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 14:34:22 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *st)
{
	int	size;

	size = 0;
	while (st)
	{
		size++;
		st = st->next;
	}
	return (size);
}

int	is_sorted(t_stack *a) // smallest on top, largest on bottom
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*stack_min(t_stack *st)
{
	t_stack	*min;

	if (!st)
		return (NULL);
	min = st;
	while (st)
	{
		if (st->n < min->n)
			min = st;
		st = st->next;
	}
	return (min);
}

int	get_position(t_stack *st, t_stack *node) // գտնել ինդեքսը
{
	int pos;

	pos = 0;
	while (st)
	{
		if (st == node)
			return (pos);
		pos++;
		st = st->next;
	}
	return (-1);
}

void	free_stack(t_stack **st)
{
	t_stack *tmp;

	while (*st)
	{
		tmp = (*st)->next;
		free(*st);
		*st = tmp;
	}
	*st = NULL;
}