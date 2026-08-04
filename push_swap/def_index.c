#include "ft_push_swap.h"

static void	sort_array(int *array, int size)  //basicamente um insertion sort  -  acredito que ainda vamos precisar implementar outro algoritimo (O(N²))
{                                            //para trabalhar especificamente com a struct, esse é o sort mais simples que tem e o mais facil pra trabalhar com array
	int	i; // anda pra frente --- controla loop externo
	int	j; // controla o loop interno
	int	temp; // var aux para o swap dos valores que vão ser trocados  --- necessaria pra nao perder nenhum lado dos swapados

	i = 0;
	while (i < size)
	{
		j = i;  // cada volta do while "reseta" o valor de j para o valor de i
		while (j > 0 && array[j - 1] > array[j]) // o j > 0 é para garantir que tem um elemento à esquerda no array para comparação
		{                                        // array[j - 1] > array[j] é para verificar se o elemento à esquerda é maior que o da direita (isso significa que os indices comparados ainda estão desordenados)
			temp = array[j - 1]; //guarda o valor do indice à esquerda do array 
			array[j - 1] = array[j]; //indice j - 1 recebe o valor de j
			array[j] = temp; // j recebe o valor que estava armazenado na temp
			j--; //decrementa o contador para repetir o loop de checagem
		}
		i++; //incrementa o contador do loop externo
	}
}

static int	find_rank(int *sorted, int size, int value) /*array já ordenado (*sorted), tamanho do array(size) e valor à procurar(value)*/
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == value) // verifica se o indice do array ordenado corresponde ao valor procurado
			return (i); // retornamos o indice respectivo do valor procurado no array JA ORDENADO
		i++;
	}
	return (-1); /*isso retorna um caso de erro, -1 é uma convenção, pois array[-1] não é um indice valido
				   --- provavelmente vamos fazer um security-guard em outra func com esse valor dps*/	
}

static void	fill_sorted(t_list *lst_a, int *sorted, int size)
{
	t_list	*current;
	int		i;

	current = lst_a;
	i = 0;
	while (i < size)
	{
		sorted[i] = current -> content;
		current = current -> next;
		i++;
	}
}

static void	fill_indexes(t_list *lst_a, int *sorted, int size)
{
	t_list	*current;
	int		i;

	current = lst_a;
	i = 0;
	while (i < size)
	{
		current -> index = find_rank(sorted, size, current -> content);
		current = current -> next;
		i++;
	}
}

void	set_stack_indexes(t_list *lst_a)
{
	int		size; // quant de nó na lst
	int		*sorted; // array auxiliar

	size = lst_size(lst_a); // para pegar o tamanho da lst inteira
	sorted = malloc(sizeof(int) * size); // mallocando o aux array
	if (!sorted)
		return ; // security guard pra falha da mallocaria do bagulho
	fill_sorted(lst_a, sorted, size);
	sort_array(sorted, size);
	fill_indexes(lst_a, sorted, size);
	free(sorted);
}
