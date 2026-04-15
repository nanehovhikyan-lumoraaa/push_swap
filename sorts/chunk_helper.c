/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:43:02 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 16:13:44 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (i > 46340)
			break ;
		i++;
	}
	return (i - 1);
}
