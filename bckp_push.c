#include "push_swap.h"
#include <stdio.h>

void	sa(hash_list *hash);
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
	sa(hash);
	argc = 14;
	i = 0;
	indexnode = 0;
	indexnumbers = 0;
	while (i < --argc)
	{
		printf("Inteiro do array depois do atoi[%i]: %i\n", indexnumbers, numbers[indexnumbers]);
		printf("Indice dos nos criados: node[%i]\n", node[indexnode]);
		indexnode++;
		indexnumbers++;
	}
}

node_list	*create_node(int number)
{
	node_list *node;
	node = malloc(sizeof(node_list));
	node->value = number;
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

void	sa(node_list *node)
{
	node_list *temp;

	temp = hash->list[0];
	hash->list[0] = hash->list[1];
	hash->list[1] = temp;
	write(1, "sa\n", 3);
}