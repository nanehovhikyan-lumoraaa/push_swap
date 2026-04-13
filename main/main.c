/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 18:04:02 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/13 22:36:12 by nhovhiky         ###   ########.fr       */
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
    t_op_count counts;
    t_stack *a;
    t_stack *b;
    char *str;
    
    bench = 0;
    if(argc < 2)
        return 0;

    zerofy_counts(&counts);
    
    flag = ft_strdup("--adaptive");         // we have t heap allocate it first, so that in valildationn fucntion the free() works
    str = join_all_args(argc, argv);
    if(!str)                // Check if join failed
    {
        free(flag);
        return 0;
    }
    if(!is_valid(str, &flag, &bench))
    {
        write(2, "Error\n", 6);
        free(flag);
        free(str);
        return 0;
    }
    
    a = parse(str);
    b = NULL;
    // code will be added soon
    free(flag);
    free(str);          // str is malloced after parsing
    free_stack(&a);
    free_stack(&b);
    return (0);
}