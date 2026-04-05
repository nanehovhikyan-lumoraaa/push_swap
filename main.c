#include "push_swap.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    t_stack *a = NULL;
    t_stack *b = NULL;
    t_stack *new;
    t_stack *last;
    int i = 1;

    if (argc < 2)
        return (0);
    while (i < argc)
    {
        new = malloc(sizeof(t_stack));
        if (!new)
            return (1);
        new->n = atoi(argv[i]);
        new->next = NULL;
        new->prev = NULL;

        if (!a)
            a = new;
        else
        {
            last = a;
            while (last->next)
                last = last->next;
            last->next = new;
            new->prev = last;
        }
        i++;
    }
    if (is_sorted(a))
    {
        free_stack(&a);
        return (0);
    }
    int size = stack_size(a);
    if (size == 2)
        sort_two(&a);
    else if (size == 3)
        sort_three(&a);
    else if (size <= 5)
        sort_five(&a, &b);
    else
        sort_simple(&a, &b);

    free_stack(&a);
    free_stack(&b);
    return (0);
}