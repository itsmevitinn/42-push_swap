#include "push_swap.h"
#include <stdio.h>
void	sa(node_list **list);
int	insert_node(hash_list *hash, int value, int index_node);
void	pb(node_list **list_a, node_list **list_b);
int main(int argc, char **argv)
{
	hash_list *stack_a;
	hash_list *stack_b;
	int *intnumbers;
	int i;
	int indexnumbers;
	int indexargv;
	int *node;
	int indexnode;
	stack_b = malloc(sizeof(hash_list));
	stack_b = create_stack_list(argc - 2);
	stack_a = malloc(sizeof(hash_list));
	stack_a = create_stack_list(argc - 2);
	intnumbers = malloc(sizeof(int) * argc - 1);
	node = malloc(sizeof(int) * argc - 1);
	i = 0;
	indexnode = 0;
	indexnumbers = 0;
	indexargv = 1;
	while (i < --argc)
	{
		intnumbers[indexnumbers] = ft_atoi(argv[indexargv]);
		printf("Array de inteiros do atoi[%i]: Valor: %i\n", indexnumbers, intnumbers[indexnumbers]);
		node[indexnode] = insert_node(stack_a, intnumbers[indexnumbers], indexnode);
		printf("Indice na lista dos nos criados: node[%i]\n", node[indexnode]);
		indexnode++;
		indexnumbers++;
		indexargv++;
	}
	write(1, "\n", 1);
	// sa(hash->list);
	// node_list *valor;
	// valor = hash->list[0];
	insert_node(stack_b, 44, 0);
	insert_node(stack_b, 55, 1);
	int indexa = 0;
	while(indexa < 5)
	{
		printf("Valores dos indices[%i] da stack_a antes do pb: %i\n", indexa, stack_a->list[indexa]->value);
		indexa++;
	}
	write(1, "\n", 1);
	int indexb = 0;
	while(indexb < 2)
	{
		printf("Valores dos indices[%i] da stack_b antes do pb: %i\n", indexb, stack_b->list[indexb]->value);
		indexb++;
	}
	write(1, "\n", 1);
	pb(stack_a->list, stack_b->list);
	indexa = 0;
	while(indexa < 5)
	{
		printf("Valores dos indices[%i] da stack_a apos pb: %i\n", indexa, stack_a->list[indexa]->value);
		indexa++;
	}
	write(1, "\n", 1);
	indexb = 0;
	while(indexb < 3)
	{
		printf("Valores dos indices[%i] da stack_b: %i\n", indexb, stack_b->list[indexb]->value);
		indexb++;
	}
	write(1, "\n", 1);
	// printf("Valor de stack_a->list[0] apos pb: %i\n", stack_a->list[0]->value);
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

void	sa(node_list **list_a)
{
	node_list *temp;
	temp = list_a[1];
	list_a[0] = list_a[1];
	list_a[1] = temp;
}

void	sb(node_list **list_b)
{
	node_list *temp;
	temp = list_b[1];
	list_b[0] = list_b[1];
	list_b[1] = temp;
}

void	ss(node_list **list_a, node_list **list_b)
{
	sa(list_a);
	sb(list_b);
}

// void	pa(node_list **list_a, node_list **list_b)
// {
// 	
// }

void	pb(node_list **list_a, node_list **list_b)
{
	printf("Rato gordo");
	node_list **new_list_b;
	int countb;
	int countnew;
	new_list_b = malloc(40);
	countb = 1;
	countnew = 1;
	list_a[0]->value = 777;
	new_list_b[0] = list_a[0];
	while(list_b[countb])
	{
		new_list_b[countnew] = list_b[countb];
		countb++;
		countnew++;
	}
	list_b = new_list_b;
	free(list_a[0]);
	printf("Valor de countb: %i\n", countb);
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
