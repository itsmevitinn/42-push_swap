#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define HASH_SIZE 100

# include <stdlib.h>

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

int	ft_strlen(const char *str);
int	insert_node(hash_list *hash, char *key, char *value);
int	ft_strncmp(const char *str1, const char *str2, int n);
int	do_hash(char *key);
node_list	*create_node(char *key, char *value);

#endif
