/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:04:19 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 15:28:15 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_node(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->n = n;
	new->rank = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

static int	add_to_stack(t_stack **st, char *val)
{
	t_stack	*new_node;

	if (is_number(val))
	{
		new_node = create_node(ft_atoi(val));
		if (!new_node)
			return (0);
		stack_add_back(st, new_node);
	}
	return (1);
}

t_stack	*parse(char *str)
{
	char	**mat;
	t_stack	*st;
	int		i;

	mat = ft_split(str, ' ');
	if (!mat)
		return (NULL);
	st = NULL;
	i = 0;
	while (mat[i])
	{
		if (!add_to_stack(&st, mat[i]))
		{
			free_stack(&st);
			break ;
		}
		i++;
	}
	free_mat(mat);
	return (st);
}
