/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:04:19 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/13 18:51:25 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// the input can come in 2 formats and we must handle both:
// 1. ./push_swap 2 1 3 4
// 2. ./push_swap "2 1 3 4"

// When a user types:
//./push_swap 1 2 3
// The subject requirements state that 1 should be at the top of the stack, 2 in the middle, 
// and 3 at the bottom.

#include "push_swap.h"

// Helper to initialize an empty stack for B
// t_stack	*create_stack(int n)            //used in main()
// {
// 	(void)n;
// 	return (NULL);
// }

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	// If the string was just "+" or "-", it's not a valid number
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

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
        if(is_number(mat[i]))
        {
            new_node = create_node(ft_atoi(mat[i]));
            if(!new_node)
            {
                free_mat(mat);
                free_stack(st);
                return NULL;
            }
            stack_add_back(&st, new_node);
        }
        i++;
    }
    free_mat(mat);
    return st;
}