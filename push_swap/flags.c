#include "ft_push_swap.h"

static int	is_flag(const char *arg)
{
	if (ft_strcmp(arg, "--simple") == 0)
		return (1);
	if (ft_strcmp(arg, "--medium") == 0)
		return (1);
	if (ft_strcmp(arg, "--complex") == 0)
		return (1);
	if (ft_strcmp(arg, "--adaptive") == 0)
		return (1);
	if (ft_strcmp(arg, "--bench") == 0)
		return (1);
	return (0);
}

void	parse_flags(int argc, char **argv, t_config *config)
{
	int	i;

	config -> strategy = "adaptive";
	config -> bench_mode = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "--simple") == 0)
			config -> strategy = "simple";
		else if (ft_strcmp(argv[i], "--medium") == 0)
			config -> strategy = "medium";
		else if (ft_strcmp(argv[i], "--complex") == 0)
			config -> strategy = "complex";
		else if (ft_strcmp(argv[i], "adaptive") == 0)
			config -> strategy = "adaptive";
		else if (ft_strcmp(argv[i], "--bench") == 0)
			config -> bench_mode = 1;
		i++;
	}
}

int	build_numeric_args(int argc, char **argv, char ***out)
{
	char	**arr;
	int		i;
	int		j;

	arr = malloc(sizeof(char *) * (argc + 1));
	if (!arr)
		return (-1);
	arr[0] = argv[0];
	i = 1;
	j = 1;
	while (i < argc)
	{
		if (!is_flag(argv[i]))
			arr[j++] = argv[i];
		i++;
	}
	arr[j] = NULL;
	*out = arr;
	return (j - 1);
}
