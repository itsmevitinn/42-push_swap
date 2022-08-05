#include "push_swap.h"

int	do_hash(int number)
{
	int random_hash;
	int i;

	i = 0;
	random_hash = 5381;
	random_hash = ((random_hash << 5) + random_hash) + number;
	return (random_hash % HASH_SIZE);
}
#include <stdio.h>
int main(void)
{
	int number[] = {-2, -5, 7, 'a'};
	int i;

	i = 0;
	while(number[i] != 'a')
		printf("Indices das hashs: %i\n", do_hash(number[i++]));
}
