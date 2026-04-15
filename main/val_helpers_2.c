/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_helpers_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:52:35 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 15:58:51 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *str, int *bench)
{
	if (str[0] != '-' || str[1] != '-')
		return (0);
	if (!ft_strcmp_strict(str, "--adaptive") || !ft_strcmp_strict(str,
			"--simple") || !ft_strcmp_strict(str, "--complex")
		|| !ft_strcmp_strict(str, "--medium") || !ft_strcmp_strict(str,
			"--bench"))
	{
		if (!ft_strcmp_strict(str, "--bench"))
			*bench = 1;
		return (1);
	}
	return (0);
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
			if (is_valid_num_range(mat[i]) && is_valid_num_range(mat[j])
				&& ft_atoi(mat[i]) == ft_atoi(mat[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_mat(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}

char	*join_all_args(int argc, char **argv)
{
	char	*result;
	char	*tmp;
	char	*spaced;
	int		i;

	i = 1;
	result = ft_strdup("");
	while (i < argc)
	{
		spaced = ft_strjoin(result, " ");
		free(result);
		tmp = ft_strjoin(spaced, argv[i]);
		free(spaced);
		result = tmp;
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}
