#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct node
{
	int 		 key;
	char 		*value;
	struct node *next; 
}				node_list;

typedef struct hash 
{
	int 		 index_size;
	node_list	**list;
}				hash_list;


int	ft_strlen(const char *str);
int	insert_node(hash_list *hash, int key, char *value);
int	ft_strncmp(const char *str1, const char *str2, int n);
int	do_hash(int key, hash_list *size_hash); // here must be type int
char	*grepvalue(hash_list *hash, int key);
node_list	*create_node(int key, char *value);
char	*ft_itoa(int n);
int	ft_atoi(char *str);
hash_list *create_hash_list(int len_number);

#endif
