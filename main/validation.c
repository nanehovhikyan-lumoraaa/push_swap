/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:10:11 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 16:25:04 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_limit(char *num, char sign)
{
	int		len;
	char	*limit;

	if (sign == '-')
		limit = "2147483648";
	else
		limit = "2147483647";
	len = ft_strlen(num);
	if (len < 10)
		return (1);
	if (len > 10)
		return (0);
	if (ft_strncmp(num, limit, 10) > 0)
		return (0);
	return (1);
}

int	is_valid_num_range(char *str)
{
	char	*num;
	int		i;

	if (!str || str[0] == '\0')
		return (0);
	if (str[0] == '+' || str[0] == '-')
		num = str + 1;
	else
		num = str;
	i = 0;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (check_limit(num, str[0]));
}

static int	process_element(char *item, char **flag, int *bench)
{
	if (!is_valid_num_range(item) && !is_flag(item, bench) && !is_flag(item,
			bench))
		return (0);
	else if (is_flag(item, bench))
	{
		if (ft_strcmp_strict(item, "--bench") != 0)
		{
			free(*flag);
			*flag = ft_strdup(item);
			if (!*flag)
				return (0);
		}
	}
	return (1);
}

int	is_valid(char *str, char **flag, int *bench)
{
	char	**mat;
	int		i;
	int		status;

	mat = ft_split(str, ' ');
	if (!mat)
		return (0);
	i = 0;
	status = 1;
	while (mat[i] && status)
	{
		status = process_element(mat[i], flag, bench);
		i++;
	}
	if (has_dup(mat) && status)
		status = 0;
	free_mat(mat);
	return (status);
}
