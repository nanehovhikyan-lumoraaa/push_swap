/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:04:02 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/15 15:53:25 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	zerofy_counts(t_op_count *count)
{
	count->sa = 0;
	count->sb = 0;
	count->pa = 0;
	count->ra = 0;
	count->rra = 0;
	count->pb = 0;
	count->rb = 0;
	count->rrb = 0;
	count->ss = 0;
	count->rr = 0;
	count->rrr = 0;
	count->total = 0;
	count->chunk_max = 0;
	count->chunk_min = 0;
}

static int	init_data(int ac, char **av, char **str, t_data *d)
{
	*str = join_all_args(ac, av);
	if (!*str)
	{
		free(d->flag);
		return (0);
	}
	if (!is_valid(*str, &d->flag, &d->bench))
	{
		write(2, "Error\n", 6);
		free(d->flag);
		free(*str);
		return (0);
	}
	return (1);
}

static void	execute_sort(t_stack **a, t_stack **b, t_op_count *c, char *f)
{
	double	dis;

	dis = compute_disorder(*a);
	if (!ft_strcmp_strict(f, "--simple"))
		insertion_sort(a, b, c);
	else if (!ft_strcmp_strict(f, "--medium"))
		chunk_sort(a, b, c);
	else if (!ft_strcmp_strict(f, "--complex"))
		radix_sort(a, b, c);
	else
		adaptive(dis, a, b, c);
}

int	main(int argc, char **argv)
{
	t_data d;
	t_stack *a;
	t_stack *b;
	char *str;

	if (argc < 2)
		return (0);
	zerofy_counts(&d.counts);
	d.flag = ft_strdup("--adaptive");
	d.bench = 0;
	if (!init_data(argc, argv, &str, &d))
		return (0);
	a = parse(str);
	free(str);
	b = NULL;
	if (!a || is_sorted(a))
	{
		free(d.flag);
		return (free_stack(&a), 0);
	}
	execute_sort(&a, &b, &d.counts, d.flag);
	if (d.bench)
		print_bench(&d.counts, compute_disorder(a), d.flag);

	free(d.flag);
	free_stack(&a);
	free_stack(&b);
	return (0);
}