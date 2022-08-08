#include "push_swap.h"
#include <stdio.h>
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
		printf("Inteiro do array depois do atoi[%i]: %i\n", indexnumbers, numbers[indexnumbers]);
		node[indexnode] = insert_node(hash, numbers[indexnumbers], "sapo");
		printf("Indice dos nos criados: node[%i]\n", node[indexnode]);
		indexnode++;
		indexnumbers++;
	}
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

node_list	*create_node(int key, char *value)
{
	node_list *node;
	node = malloc(sizeof(node_list));
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}

char	*grepvalue(hash_list *hash, int key)
{
	int index_node = do_hash(key, hash);
	while (hash->list[index_node])
	{
		if (hash->list[index_node]->key == key)
			printf("Value index[%i]: %s\n", index_node, hash->list[index_node]->value);
			// return hash->list[index_node]->value;
		hash->list[index_node] = hash->list[index_node]->next;
	}
	return (0);
}

int	insert_node(hash_list *hash, int key, char *value)
{
	node_list *node;
	int index_node;
	index_node = key;
	// index_node = do_hash(key, hash);
	node = hash->list[index_node];
	if (!node)
		hash->list[index_node] = create_node(key, value);
	else
		node->next = create_node(key, value);
	return (index_node);
}
