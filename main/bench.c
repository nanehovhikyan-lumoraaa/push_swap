#include "push_swap.h"

char	*get_flag(char *flag, double disorder)
{
	if (!ft_strcmp_strict(flag, "--simple"))
		return ("Simple / O(n^2)");
	if (!ft_strcmp_strict(flag, "--medium"))
		return ("Medium / O(n*sqrt(n))");
	if (!ft_strcmp_strict(flag, "--complex"))
		return ("Complex / O(n log n)");
	if(disorder < 0.2)
        return ("Adaptive / O(n^2)");
    else if(disorder >= 0.2 && disorder < 0.5)
        return ("Adaptive / O(n*sqrt(n))");
    else
        return ("Adaptive / O(n log n)");
}

void    ft_putchar_fd(char c, int fd)
{
    if (fd < 0)
    {
        return ;
    }
    write(fd, &c, 1);
}

void    ft_putnbr_fd(int n, int fd)
{
    char    c;

    if (fd < 0)
    {
        return ;
    }
    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return ;
    }
    if (n < 0)
    {
        write(fd, "-", 1);
        n = -n;
    }
    if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
    }
    c = (n % 10) + '0';
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    if (s == NULL || fd < 0)
    {
        return ;
    }
    write(fd, s, ft_strlen(s));
}

void	write_double_dis(double disorder, int fd)
{
	if((int)disorder == 1)
	{
		write(fd, "100.00%\n", 8);
		return ;
	}
	double percent = disorder * 100;
	ft_putnbr_fd((int)(percent), fd);
	write(fd, ".", 1);
	// 0.4005 
	// percent = 4005
	ft_putnbr_fd((int)(percent * 10) % 10, fd);  // Prints '0'
    ft_putnbr_fd((int)(percent * 100) % 10, fd); // Prints '5'
    write(fd, "%\n", 1);
}

void	print_bench(t_op_count *counts, double disorder, char *flag)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	write_double_dis(disorder, 2);
	write(2, "\n", 1);

	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(get_flag(flag, disorder), 2);
	ft_putchar_fd('\n', 2);

	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(counts->total, 2);
	ft_putchar_fd('\n', 2);

	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(counts->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(counts->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(counts->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(counts->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(counts->pb, 2);
	ft_putchar_fd('\n', 2);

	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(counts->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(counts->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(counts->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(counts->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(counts->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(counts->rrr, 2);
	ft_putchar_fd('\n', 2);
}