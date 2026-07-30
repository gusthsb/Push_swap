#include "ft_push_swap.h"

int	lst_size(t_list *lst) /*não precisa de ponteiro duplo quando a função só faz a leitura da lst*/
{								  /* *lst faz uma copia do ENDEREÇO de memoria, content continua sendo o original */
	int		size;
	t_list	*start;

	if (!lst)
		return (0);
	size = 1;
	start = lst;
	lst = lst -> next;
	while (lst != start)
	{
		size++;
		lst = lst -> next; // Passamos de nó e armazenamos essa operação
	}
	return (size); // retornamos o tamanho da lst, baseado na quantidade de vezes que o size recebeu +1;
}