#include "ft_push_swap.h"

void	put_str_fd(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}

void	put_nbr_fd(int n)
{
	char	c;

	if (n < 0)
	{
		write(2, "-", 1);
		n = -n;
	}
	if (n >= 10)
		put_nbr_fd(n / 10);
	c = (n % 10) + '0';
	write(2, &c, 1);
}

void	print_double_2dec(double n)
{
	int	total;
	int	whole;
	int	frac;

	total = (int)(n * 10000 + 0.5);
	whole = total / 100;
	frac = total % 100;
	put_nbr_fd(whole);
	write(2, ".", 1);
	if (frac < 10)
		write(2, "0", 1);
	put_nbr_fd(frac);
}
