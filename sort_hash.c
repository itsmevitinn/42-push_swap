#include "push_swap.h"
#include <stdio.h>

index_list *create_stack_list(int len_number)
{
	// node_list *node;
	index_list *create;
	int i;

	// node = malloc(sizeof(node_list));
	// node->key = 320;
	// node->value = "Arroz";
	// node->next = NULL;
	
	create = (index_list *)malloc(sizeof(index_list));
	create->list_size = len_number;
	create->list = (node_list **)malloc(create->list_size * sizeof(node_list *));

	i = 0;
	while (i < create->list_size)
	{
		create->list[i] = NULL;
		i++;
	}
	printf("Tamanho da indextable: %i\n", create->list_size);
	return (create);
}

//int	do_hash(int number, hash_list *size_hash) // here need to have *hash as parameter, to do hash dinamically
//{
	// int random_hash;
	// int i;

	// i = 0;
	// random_hash = 5381;
	// random_hash = ((random_hash << 5) + random_hash) + number;
	// char *stringnumber;
	// int i;
	// int total;

	// stringnumber = ft_itoa(number);
	// printf("Valor array em string: %s\n", stringnumber);
	// i = 0;
	// total = 0;
	// while (stringnumber[i])
	// {
	// 	total += stringnumber[i++] % size_hash->index_size;
	// 	printf("Valor total: %i\n", total);
	// }
	// if (number > size_hash->index_size)
	// {
	// 	printf("Valor number: %i\n", number);
	// 	int total;
	// 	total = number % size_hash->index_size;
	// 	total += size_hash->index_size;
	// 	return (total);
	// }
	//return (number % size_hash->index_size);  // return must do module accordingly to hash size
//}
// int main(void)
// {
// 	int number[] = {-2, -5, 7, 10, 11, 20, 100, 580, 581, 'a'};
// 	int len_number;
// 	int i;
// 	hash_list *size_hash;

// 	len_number = sizeof(number) / 2;
// 	i = 0;
// 	size_hash = malloc(sizeof(hash_list));
// 	size_hash = create_hash_list(len_number);

// 	printf("Size da hash: %i\n", size_hash->index_size);

// 	while(size_hash->list[i])
// 	{
// 		printf("Valor: %s\n", size_hash->list[i++]->value);
// 	}
// 	i = 0;
// 	while(number[i] != 'a')
// 		printf("Indices das hashs: %i\n", do_hash(number[i++], size_hash));
// }
