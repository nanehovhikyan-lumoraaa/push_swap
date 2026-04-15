/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:33:34 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 14:34:25 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
	{
		return ((char *)(big));
	}
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
			{
				return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total;
	char	*final;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	total = ft_strlen(s1) + ft_strlen(s2) + 2;
	final = (char *)malloc(sizeof(char) * total);
	if (!final)
	{
		return (NULL);
	}
	ft_strlcpy(final, s1, total);
	ft_strlcat(final, " ", total);
	ft_strlcat(final, s2, total);
	return (final);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	len2 = 0;
	len1 = ft_strlen(src);
	while (len2 < size && dst[len2] != '\0')
		len2++;
	if (len2 == size)
	{
		return (size + len1);
	}
	i = 0;
	while (src[i] != '\0' && (len2 + i + 1) < size)
	{
		dst[len2 + i] = src[i];
		i++;
	}
	dst[len2 + i] = '\0';
	return (len2 + len1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
	{
		return (len);
	}
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}