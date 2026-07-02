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
	return (-1); /*isso retorna um caso de erro, -1 é convenção pq não é um indice valido
				   provavelmente vamos fazer um security-guard com esse valor dps*/	
}

void	set_stack_indexes(t_list *lst_a)
{
	int		size; // quant de nó na lst
	int		*sorted; // array auxiliar
	t_list	*current; // ponteiro copia, somente para andar pela lst e fazer a leitura 
	int		i; // contador para passar o array

	size = lst_size(lst_a); // para pegar o tamanho da lst inteira
	sorted = malloc(sizeof(int) * size); // mallocando o aux array
	if (!sorted)
		return ; // security guard pra falha da mallocaria
	current = lst_a; // aponta pra cabeça da lst
	i = 0;
	while (current)
	{
		sorted[i] = current -> content; // sorted[i] recebe o conteudo(content) do nó atual(current) !! usa tradutor se não souber ler !! 
		current = current -> next; // passamos de nó
		i++;
	}
	sort_array(sorted, size); // chama a função que ordena o array auxiliar
	current = lst_a; // fazendo current voltar na cbç da lst ||| "resetando" o loop da lst
	while (current)
	{                          // vou explicar esse loop na ultima linha
		current -> index = find_rank(sorted, size, current -> content);
		current = current -> next; 
	}
	free(sorted); // damos free no malloc e também ja "excluimos" o array auxiliar
}

/*current -> index  --  o nó atual vai salvar em sua struct o indice de ordenação
  find_rank(sorted, size, current -> content) -- como a prototipação pede, vamos passar a lista já ordenada(sorted) pelas outras funções, depois o tamanho(size) do array
  e por ultimo parametro o conteudo(content) atual (current) do nó que estamos passando pelo loop
  current = current -> next   --  passamos de nó */