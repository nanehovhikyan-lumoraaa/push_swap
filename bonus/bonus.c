/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:40:56 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 18:01:35 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static void	rotate_ops_bonus(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "ra\n"))
		ra(a);
	else if (!ft_strcmp(op, "rb\n"))
		rb(b);
	else if (!ft_strcmp(op, "rr\n"))
		rr(a, b);
}

static void	rev_rotate_ops_bonus(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "rra\n"))
		rra(a);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(b);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(a, b);
}

static void	handle_op(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(*a);
	else if (!ft_strcmp(op, "sb\n"))
		sb(*b);
	else if (!ft_strcmp(op, "ss\n"))
		ss(*a, *b);
	else if (!ft_strcmp(op, "pa\n"))
		pa(a, b);
	else if (!ft_strcmp(op, "pb\n"))
		pb(a, b);
	else if (!ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rb\n") || !ft_strcmp(op,
			"rr\n"))
		rotate_ops_bonus(op, a, b);
	else if (!ft_strcmp(op, "rra\n") || !ft_strcmp(op, "rrb\n")
		|| !ft_strcmp(op, "rrr\n"))
		rev_rotate_ops_bonus(op, a, b);
	else
	{
		free(op);
		free_and_exit(a, b);
	}
}

void	apply_ops(t_stack **a, t_stack **b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		handle_op(op, a, b);
		free(op);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	if (argc < 2)
		return (0);
	str = join_all_args(argc, argv);
	if (!str)
		return (0);
	if (!is_valid(str))
	{
		write(2, "Error\n", 6);
		free(str);
		return (0);
	}
	a = parse(str);
	b = NULL;
	free(str);
	apply_ops(&a, &b);
	if (is_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
