#include "push_swap.h"
#include <stdio.h>
// int main(void)
// {
// 	hash_list *hash;
// 	int key; //here must be type int, because will be some number of array
// 	int key2; //here must be type int, because will be some number of array
// 	char *value;
// 	char *value2;
// 	int index_node1;
// 	int index_node2;
// 	hash = malloc(sizeof(hash_list));
// 	key = 570;
// 	key2 = 570;
// 	value = "sapo";
// 	value2 = "rato";
// 	index_node1 = insert_node(hash, key, value);
// 	index_node2 = insert_node(hash, key2, value2);
// 	printf("First index: %i, second index: %i\n", index_node1, index_node2);
// 	char *ret1 = grepvalue(hash, key);	
// 	char *ret2 = grepvalue(hash, key2);
// 	printf("VALOR KEY1: %s\n", ret1);
// 	printf("VALOR KEY2: %s\n", ret2);
// }

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
	int index_node = do_hash(key);
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
	index_node = do_hash(key);
	node = hash->list[index_node];
	if (!node)
		hash->list[index_node] = create_node(key, value);
	else
		node->next = create_node(key, value);
	return (index_node);
}
