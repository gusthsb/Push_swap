#include "ft_push_swap.h"

static int	lst_size(t_list *lst) /*não precisa de ponteiro duplo quando a função só faz a leitura da lst*/
{								  /* *lst faz uma copia do ENDEREÇO de memoria, content continua sendo o original */
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst -> next;
	}
	return (size);
}

static void	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i;
		while (j > 0 && array[j - 1] > array[j])
		{
			temp = array[j - 1];
			array[j - 1] = array[j];
			array[j] = temp;
			j--;
		}
		i++;
	}
}