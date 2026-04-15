/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 17:16:59 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 17:33:21 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)(s1);
	str2 = (unsigned char *)(s2);
	i = 0;
	while (str1[i] && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
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
		tmp = ft_strjoin(spaced, argv[i]);
		result = tmp;
		if (!result)
			return (NULL);
		i++;
	}
	return (result);
}

void	free_stack(t_stack **st)
{
	t_stack	*tmp;

	while (*st)
	{
		tmp = (*st)->next;
		free(*st);
		*st = tmp;
	}
	*st = NULL;
}

void	free_and_exit(t_stack **a, t_stack **b)
{
	write(2, "Error\n", 6);
	free_stack(a);
	free_stack(b);
	exit(1);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}
