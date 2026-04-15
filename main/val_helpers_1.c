/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_helpers_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 14:49:21 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 15:58:14 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp_strict(char *s1, char *s2)
{
	if (ft_strlen(s1) != ft_strlen(s2))
		return (-1);
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)(s1);
	str2 = (unsigned char *)(s2);
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (str1[i] && i < (n - 1) && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
