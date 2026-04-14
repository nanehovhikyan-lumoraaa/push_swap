/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valod.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/13 17:10:11 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/14 14:00:23 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp_strict(char *s1, char *s2)
{
	if(ft_strlen(s1) != ft_strlen(s2))
		return -1;
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

char *join_all_args(int argc, char **argv)
{
    char *result;
    char *tmp;
    char *spaced;
    int i = 1;

    result = ft_strdup("");
    while (i < argc)
    {
        spaced = ft_strjoin(result, " "); // Add space before next arg
        free(result);
        tmp = ft_strjoin(spaced, argv[i]);
        free(spaced);
        result = tmp;
        if (!result) return (NULL);
        i++;
    }
    return (result);
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

int is_flag(char *str, int *bench)
{
	if(str[0] != '-' || str[1] != '-')
		return 0;
	
	if(!ft_strcmp_strict(str, "--adaptive") || !ft_strcmp_strict(str, "--simple") || !ft_strcmp_strict(str, "--complex")
		|| !ft_strcmp_strict(str, "--medium") || !ft_strcmp_strict(str, "--bench")){
		if(!ft_strcmp_strict(str, "--bench"))
			*bench = 1;
		return 1;
	}
	return 0;
}

int has_dup(char **mat)
{
	int i;
	int j;
	
	i = 0;
	while(mat[i])
	{
		j = i + 1;
		while(mat[j])
		{
			if(is_valid_num_range(mat[i]) && is_valid_num_range(mat[j]) 
				&& ft_atoi(mat[i]) == ft_atoi(mat[j]))
				return 1;
			j++;
		}
		i++;
	}
	return 0;
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

int is_valid(char *str, char **flag, int *bench)
{
	char **mat;
	int i;
	
	mat = ft_split(str, ' ');
	if (!mat)
        return (0);
	i = 0;
	while(mat[i])
	{
		if(!is_valid_num_range(mat[i]) && !is_flag(mat[i], bench))
		{
			free_mat(mat);
			return 0;
		}
		else if(is_flag(mat[i], bench))
		{
			if(ft_strcmp_strict(mat[i], "--bench") != 0)
            {	
				free(*flag); // flag is always adaptive by default
				*flag = ft_strdup(mat[i]);
				if (!*flag) 
            	{
                	free_mat(mat);
                	return (0);
            	}
			}
		}
		i++;
	}
	if(has_dup(mat))
	{
		free_mat(mat);
		return 0;
	}
	free_mat(mat);
	return (1);
}

