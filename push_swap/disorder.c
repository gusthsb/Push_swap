#include "ft_push_swap.h"

static int	*trans(t_list *lst_en, int *size) // precisa ser um array de int
{
	int		*new_lst; // mesma coisa
	int		i;
	t_list	*current;

	if (!lst_en)
		return (NULL);
	*size = lst_size(lst_en); 
	new_lst = malloc(sizeof(int) * (*size));
	if (!new_lst)
		return (NULL);
	i = 0;
	current = lst_en;
	while (i < *size)
	{
		new_lst[i] = current -> content;
		current = current -> next;
		i++;
	}
	return (new_lst);
}
/*mamatos é burro pq estava fazendo funções como se fosse uma string*/

double	calculate_disorder(int *lst_a, int size)
{
	double	mistakes;
	double	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			total_pairs++;
			if (lst_a[i] > lst_a[j])
				mistakes++;
			j++;
		}
		i++;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);	
}

double main_disorder(t_list *lst)
{
	int		*new_arr;
	double	value;
	int		size;

	new_arr = trans(lst, &size);
	if (!new_arr)
		return (0.0);
	value = calculate_disorder(new_arr, lst_size(lst));
	free(new_arr);
	return (value);
}
// teste disordem / lst_size
#include <stdio.h>
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = malloc(sizeof(t_list));
	node1 -> content = 4;
	node2 = malloc(sizeof(t_list));
	node2 -> content = 1;
	node3 = malloc(sizeof(t_list));
	node3 -> content = 3;
	
	node1 -> next = node2;
	node2 -> next = node3;
	node3 -> next = NULL;

	printf("Tamanho da lst = %d\n", lst_size(node1));
	printf("Desordem = %f\n", main_disorder(node1));

	free(node1);
	free(node2);
	free(node3);
	return (0);
}