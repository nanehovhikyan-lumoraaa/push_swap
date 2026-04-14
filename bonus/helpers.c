/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 20:10:34 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/14 20:37:11 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"
// stack_add_back


// ft_split
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



//ft_strdup
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



// is_valid_num_range
int	is_valid_num_range(char *str)
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



// free_mat
void free_mat(char **mat)
{
	int i = 0;
	
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}



// ft_atoi
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



// create_node
t_stack *create_node(int n)
{
    t_stack *new;
    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->n = n;
    new->rank = -1;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}




// stack_add_back
void stack_add_back(t_stack **stack, t_stack *new)
{
    t_stack *last;
    
    if (!stack || !new)             // Checking the Pointer to the Pointer
        return;
    if (!*stack)                    // checking if the stack itself is empty
    {
        *stack = new;
        return;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new;
    new->prev = last;
}



// strncmp
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