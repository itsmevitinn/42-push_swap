#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define HASH_SIZE 100

typedef struct node
{
	char 		*key;
	char 		*value;
	struct node *next; 
}				node_list;

typedef struct hash 
{
	node_list	*list[HASH_SIZE];
}				hash_list;

#endif
