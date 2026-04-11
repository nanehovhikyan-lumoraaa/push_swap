/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:04:02 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/11 23:57:00 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// valod -> null(invalod), flag(adaptive, ....)

void zerofy_counts(t_op_count *count){
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

int main(int argc, char **argv){
    char *flag;
    int bench;
    t_op_count *counts;
    t_stack *a;
    t_stack *b;
    
    if(argc < 2)
        return 0;
    
    zerofy_counts(&counts);
    
    flag = valod(argc, argv, &bench);
    
    if(!flag)
        return 0;       // valod already write the error massage
    a = parse(argc, argv); // in parse there's a create st function which is used for b
    b = create_stack(0);
    if (!a || !b)
    {
        free_stack(&a);
        free_stack(&b);
        return (0);
    }
    if (ft_strcmp(flag, "simple") == 0)
        insertion_sort(&a, &b, &counts);
    else if (ft_strcmp(flag, "medium") == 0)
        chunk_sort(&a, &b, &counts);
    else if (ft_strcmp(flag, "complex") == 0)
        radix_sort(&a, &b, &counts);
    else // "adaptive" is the default
        adaptive(compute_disorder(a), &a, &b, &counts);

    if (bench)
        print_bench(&counts, flag, compute_disorder(a));
    free_stack(&a);
    free_stack(&b);
    return (0);
}