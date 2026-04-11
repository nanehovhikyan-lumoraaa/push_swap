/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:43:05 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/11 23:59:03 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	is_flag(char *arg)
// {
// 	return (arg[0] == '-' && arg[1] == '-');
// }

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}



int	is_valid_range(char *str)
{
	char	*limit;
	char	*num;
	int		len;
    int i;

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
	len = ft_strlen(num);
	if (len < 10)
		return (1);
	if (len > 10)
		return (0);
	if (str[0] == '-')
		limit = "2147483648";
	else
		limit = "2147483647";
	if (ft_strncmp(num, limit, 10) > 0)
		return (0);
	return (1);
}

// Convert string to number
int	ft_atoi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

int	has_duplicate(char **argv, int current_index)
{
	int	val;
	int	j;

	val = ft_atoi(argv[current_index]);
	j = 1;
	while (j < current_index)
	{
		if (!is_flag(argv[j]) && ft_atoi(argv[j]) == val)
			return (1);
		j++;
	}
	return (0);
}

char	*valod(int argc, char **argv, int *bench)
{
	char	*flag;
	int		i;

    *bench = 0;
	flag = "adaptive";
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]))
		{
            if (ft_strcmp(argv[i], "--bench") == 0)
				*bench = 1;
			if (ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i], "--medium") == 0
				|| ft_strcmp(argv[i], "--complex") == 0 || ft_strcmp(argv[i], "--adaptive") == 0)
				flag = argv[i] + 2;
			else
				return (write(2, "Error\n", 6), NULL);
		}
		else
		{
			if (!is_valid_range(argv[i]) || has_duplicate(argv, i))
				return (write(2, "Error\n", 6), NULL);
		}
		i++;
	}
	return (flag);
}





// int	is_numeric(char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (str[i] == '-' || str[i] == '+')
// 		i++;
// 	if (!str[i])
// 		return (0);
// 	while (str[i])
// 	{
// 		if (str[i] < '0' || str[i] > '9')
// 			return (0);
// 		i++;
// 	}
// 	return (1);
// }




// char	*check_flag(char *arg, int *bench)
// {
// 	if (ft_strstr(arg, "--bench") && arg[7] == '\0')
// 	{
// 		*bench = 1;
// 		return (NULL);
// 	}
// 	if (ft_strstr(arg, "--simple") && arg[8] == '\0')
// 		return ("simple");
// 	if (ft_strstr(arg, "--medium") && arg[8] == '\0')
// 		return ("medium");
// 	if (ft_strstr(arg, "--complex") && arg[9] == '\0')
// 		return ("complex");
// 	if (ft_strstr(arg, "--adaptive") && arg[10] == '\0')
// 		return ("adaptive");
// 	return (NULL);
// }