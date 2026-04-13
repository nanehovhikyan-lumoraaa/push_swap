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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total;
	char	*final;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	total = ft_strlen(s1) + ft_strlen(s2) + 2;
	final = (char *)malloc(sizeof(char) * total);
	if (!final)
	{
		return (NULL);
	}
	ft_strlcpy(final, s1, total);
	ft_strlcat(final, " ", total);
	ft_strlcat(final, s2, total);
	return (final);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len1;
	size_t	len2;

	len2 = 0;
	len1 = ft_strlen(src);
	while (len2 < size && dst[len2] != '\0')
		len2++;
	if (len2 == size)
	{
		return (size + len1);
	}
	i = 0;
	while (src[i] != '\0' && (len2 + i + 1) < size)
	{
		dst[len2 + i] = src[i];
		i++;
	}
	dst[len2 + i] = '\0';
	return (len2 + len1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
	{
		return (len);
	}
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
