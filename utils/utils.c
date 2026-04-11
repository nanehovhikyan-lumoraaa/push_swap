#include "push_swap.h"

int	stack_size(t_stack *st)
{
	int	size;

	size = 0;
	while (st)
	{
		size++;
		st = st->next;
	}
	return (size);
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

t_stack	*stack_min(t_stack *st)
{
	t_stack	*min;

	if (!st)
		return (NULL);
	min = st;
	while (st)
	{
		if (st->n < min->n)
			min = st;
		st = st->next;
	}
	return (min);
}

int	get_position(t_stack *st, t_stack *node)        // գտնել ինդեքսը
{
	int	pos;

	pos = 0;
	while (st)
	{
		if (st == node)
			return (pos);
		pos++;
		st = st->next;
	}
	return (-1);
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


char	*ft_strstr(const char *big, const char *little)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
	{
		return ((char *)(big));
	}
	while (big[i] != '\0')
	{
		j = 0;
		while (big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
			{
				return ((char *)(big + i));
			}
		}
		i++;
	}
	return (NULL);
}
