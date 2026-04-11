/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhovhiky <nhovhiky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:05:03 by nhovhiky          #+#    #+#             */
/*   Updated: 2026/04/11 15:59:52 by nhovhiky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float compute_disorder(t_stack *a){
    int mistakes;
    int total_pairs;
    t_stack *cur;
    t_stack *cmp;
    cur = a;
    
    total_pairs = stack_size(a)*(stack_size(a) - 1)/2;
    mistakes = 0;
    
    while(cur->next){
        cmp = cur->next;
        while(cmp){
            if(cmp->n < cur->n)
                mistakes++;
            cmp = cmp->next;
        }
        cur = cur->next;
    }
    return ((float)mistakes/total_pairs); 
}

void adaptive(float disorder, t_stack **a, t_stack **b, t_op_count *counts){
    if(disorder<0 || disorder>1){
        write(2, "Error", 5);
        return;
    }
       
    if(disorder < 0.2)
        insertion_sort(a, b, counts);
    else if(disorder >= 0.2 && disorder < 0.5)
        chunk_sort(a, b, counts);
    else
        radix_sort(a, b, counts);
}