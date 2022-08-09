#include "push_swap.h"
#include <stdio.h>
void	sa(node_list **list);
int	insert_node(hash_list *hash, int value, int index_node);
int main(int argc, char **argv)
{
	int *numbers;
	int i;
	int indexnumbers;
	int indexargv;
	int *node;
	int indexnode;
	hash_list *hash;
	indexnode = 0;
	hash = malloc(sizeof(hash_list));
	hash = create_hash_list(argc - 1);
	numbers = malloc(sizeof(int) * argc - 1);
	node = malloc(sizeof(int) * argc - 1);
	i = 0;
	indexnumbers = 0;
	indexargv = 1;
	while (i < --argc)
	{
		numbers[indexnumbers] = ft_atoi(argv[indexargv++]);
		printf("Array de inteiros do atoi[%i]: Valor: %i\n", indexnumbers, numbers[indexnumbers]);
		node[indexnode] = insert_node(hash, numbers[indexnumbers], indexnode);
		printf("Indice na lista dos nos criados: node[%i]\n", node[indexnode]);
		indexnode++;
		indexnumbers++;
	}
	// sa(hash->list);
	// node_list *valor;
	// valor = hash->list[0];
	hash->list[0] = hash->list[2];
	printf("Valor do no apos troca: %i\n", hash->list[3]->value);
	// hash_list *hash;
	// int key; //here must be type int, because will be some number of array
	// int key2; //here must be type int, because will be some number of array
	// char *value;
	// char *value2;
	// int index_node1;
	// int index_node2;
	// hash = malloc(sizeof(hash_list));
	// key = 570;
	// key2 = 570;
	// value = "sapo";
	// value2 = "rato";
	// index_node1 = insert_node(hash, key, value);
	// index_node2 = insert_node(hash, key2, value2);
	// printf("First index: %i, second index: %i\n", index_node1, index_node2);
	// char *ret1 = grepvalue(hash, key);
	// char *ret2 = grepvalue(hash, key2);
	// printf("VALOR KEY1: %s\n", ret1);
	// printf("VALOR KEY2: %s\n", ret2);
}

void	sa(node_list **list)
{
	node_list *temp;
	temp = list[1];
	list[0] = list[1];
	list[1] = temp;
}

void	sb(node_list **list)
{
	node_list *temp;
	temp = list[1];
	list[0] = list[1];
	list[1] = temp;
}

node_list	*create_node(int number)
{
	node_list *node;
	node = malloc(sizeof(node_list));
	node->value = number;
	node->next = NULL;
	return (node);
}

char	*grepvalue(hash_list *hash, int number)
{
	int index_node = do_hash(number, hash);
	while (hash->list[index_node])
	{
		if (hash->list[index_node]->value == number)
			printf("Value index[%i]: %i\n", index_node, hash->list[index_node]->value);
			// return hash->list[index_node]->value;
		hash->list[index_node] = hash->list[index_node]->next;
	}
	return (0);
}

int	insert_node(hash_list *hash, int value, int index_node)
{
	node_list *node;
	node = hash->list[index_node];
	if (!node)
		hash->list[index_node] = create_node(value);
	else
		node->next = create_node(value);
	return (index_node);
}
