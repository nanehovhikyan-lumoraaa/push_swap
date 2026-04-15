/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:10:34 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 17:33:44 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

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
