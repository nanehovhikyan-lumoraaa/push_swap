/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:13:46 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/14 21:56:38 by nhovhiky         ###   ########.fr       */
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
        //free(result);
        tmp = ft_strjoin(spaced, argv[i]);
        //free(spaced);
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

void free_and_exit(t_stack **a, t_stack **b)
{
    write(2, "Error\n", 6);
    free_stack(a);
    free_stack(b);
    exit(1);
}

int	is_sorted(t_stack *a)			// smallest on top, largest on bottom
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int is_valid(char *str)
{
	char **mat;
	int i;
	
	mat = ft_split(str, ' ');
	if (!mat)
        return (0);
	i = 0;
	while(mat[i])
	{
		if(!is_valid_num_range(mat[i]))
		{
			free_mat(mat);
			return 0;
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
			if(ft_atoi(mat[i]) == ft_atoi(mat[j]))
				return 1;
			j++;
		}
		i++;
	}
	return 0;
}

t_stack	*parse(char *str)
{
    char **mat;
    t_stack *st;
    t_stack *new_node;
    
    int i;
    new_node = NULL;
    i = 0;
    st = NULL;
    mat = ft_split(str, ' ');
    if(!mat)
        return NULL;
    while(mat[i])
    {
        new_node = create_node(ft_atoi(mat[i]));
        if(!new_node)
        {
            free_mat(mat);
            free_stack(&st);
            return NULL;
        }
        stack_add_back(&st, new_node);
    	i++;
    }
    free_mat(mat);
    return st;
}





// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	size_t	total;
// 	char	*final;

// 	if (!s1 || !s2)
// 	{
// 		return (NULL);
// 	}
// 	total = ft_strlen(s1) + ft_strlen(s2) + 2;
// 	final = (char *)malloc(sizeof(char) * total);
// 	if (!final)
// 	{
// 		return (NULL);
// 	}
// 	ft_strlcpy(final, s1, total);
// 	ft_strlcat(final, " ", total);
// 	ft_strlcat(final, s2, total);
// 	return (final);
// }