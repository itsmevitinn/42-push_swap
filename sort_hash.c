#include "push_swap.h"

int	do_hash(char *key)
{
	int random_hash;
	int i;

	random_hash = 4380;
	while(key[i])
	{
		random_hash = ((random_hash << 5) + random_hash) + key[i];
		i++;
	}
	return (random_hash % HASH_SIZE);
}
