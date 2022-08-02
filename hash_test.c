#include "push_swap.h"

int main(void)
{
	char *key;
	char *value;
	value = "sapo";
	key = "rato";
	int index_node = sort_hash(key);
	node_list *node;
	node = hash_list->list[index_node];
	hash_list->list[index_node] = create_node(key, value);
}

node_list	*create_node(char *key, char *value)
{
	node_list *node;
	node = malloc(node_list);
	node->key = key;
	node->value = value;
	node->next = NULL;
	return (node);
}
