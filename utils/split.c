/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:02:09 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 14:44:57 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **res, int i)
{
	while (i >= 0)
		free(res[i--]);
	free(res);
}

char	*create_dup(char *str, int n)
{
	char	*dup;
	int		i;

	dup = (char *)malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (str[i] && i < n)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	count_words(const char *str, char charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == charset)
		{
			i++;
		}
		if (str[i] && str[i] != charset)
		{
			count++;
			while (str[i] && str[i] != charset)
			{
				i++;
			}
		}
	}
	return (count);
}

char	**fill_result(char **result, char const *s, char c)
{
	char	*start;
	int		i;

	i = 0;
	while (result && *s)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			break ;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		result[i] = create_dup(start, s - start);
		if (!result[i])
		{
			free_all(result, (i - 1));
			return (NULL);
		}
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c))
		return (NULL);
	return (result);
}
