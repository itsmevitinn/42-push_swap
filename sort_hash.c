#include "push_swap.h"
#include <stdio.h>

hash_list *create_hash_list(int len_number)
{
	node_list *node;
	hash_list *create;
	int i;

	node = malloc(sizeof(node_list));
	node->key = 320;
	node->value = "Arroz";
	node->next = NULL;
	
	create = (hash_list *)malloc(sizeof(hash_list));
	create->index_size = len_number;
	create->list = (node_list **)malloc(create->index_size * sizeof(node_list *));

	i = 0;


	while (i < create->index_size)
	{
		create->list[i] = node;
		i++;
	}
	printf("Tamanho da hashtable: %i\n", create->index_size);
	return (create);
}

int	do_hash(int number) // here need to have *hash as parameter, to do hash dinamically
{
	int random_hash;
	int i;

	i = 0;
	random_hash = 5381;
	random_hash = ((random_hash << 5) + random_hash) + number;
	return (random_hash % 101);  // return must do module accordingly to hash size
}
int main(void)
{
	int number[] = {-2, -5, 7, 'a'};
	int len_number;
	int i;
	hash_list *size_hash;

	len_number = sizeof(number) / 2;
	i = 0;
	size_hash = malloc(sizeof(hash_list));
	size_hash = create_hash_list(len_number);

	while(size_hash->list[i])
	{
		printf("Valor: %s\n", size_hash->list[i++]->value);
	}

	// while(number[i] != 'a')
	// 	printf("Indices das hashs: %i\n", do_hash(number[i++], size_hash));
}
