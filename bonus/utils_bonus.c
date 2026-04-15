/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:13:46 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 17:32:20 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	is_valid(char *str)
{
	char	**mat;
	int		i;

	mat = ft_split(str, ' ');
	if (!mat)
		return (0);
	i = 0;
	while (mat[i])
	{
		if (!is_valid_num_range(mat[i]))
		{
			free_mat(mat);
			return (0);
		}
		i++;
	}
	if (has_dup(mat))
	{
		free_mat(mat);
		return (0);
	}
	free_mat(mat);
	return (1);
}

int	has_dup(char **mat)
{
	int	i;
	int	j;

	i = 0;
	while (mat[i])
	{
		j = i + 1;
		while (mat[j])
		{
			if (ft_atoi(mat[i]) == ft_atoi(mat[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

t_stack	*parse(char *str)
{
	char	**mat;
	t_stack	*st;
	t_stack	*new_node;
	int		i;

	new_node = NULL;
	i = 0;
	st = NULL;
	mat = ft_split(str, ' ');
	if (!mat)
		return (NULL);
	while (mat[i])
	{
		new_node = create_node(ft_atoi(mat[i]));
		if (!new_node)
		{
			free_mat(mat);
			free_stack(&st);
			return (NULL);
		}
		stack_add_back(&st, new_node);
		i++;
	}
	free_mat(mat);
	return (st);
}
