#include "ft_push_swap.h"

static int	lst_size(t_list *lst) /*não precisa de ponteiro duplo quando a função só faz a leitura da lst*/
{								  /* *lst faz uma copia do ENDEREÇO de memoria, content continua sendo o original */
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst -> next; // Passamos de nó e armazenamos essa operação
	}
	return (size); // retornamos o tamanho da lst, baseado na quantidade de vezes que o size recebeu +1;
}

char *trans(t_list **lst_en)
{
	char	*new_lst;
	int		i;
	int		len_lst;
	t_list	*current;

	if (!(*lst_en) || !lst_en)
		return (NULL);
	new_lst = malloc(lst_size(*lst_en) + 1);
	if (!new_lst)
		return (NULL);
	i = 0;
	current = *lst_en;
	while (current)
	{
		new_lst[i++] = current->content;
		current = current->next;
	}
	new_lst[i] = '\0';
	return (new_lst);
}
double	calculate_disorder(t_list **lst_a)
{
	double	mistakes;
	double	total_pairs;
	int		i;
	int		j;
	char	*new_lst;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	new_lst = trans(*lst_a);
	if (!new_lst)
		return (0.0);
	while (new_lst[i++])
	{
		j = i + 1;
		while (new_lst[j++])
		{
			total_pairs += 1;
			if (new_lst[i] > new_lst[j])
				mistakes += 1;
		}
	}
	free(new_lst);
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);	
}

