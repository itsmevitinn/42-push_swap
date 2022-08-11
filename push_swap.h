#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int 		value;
	struct node *next; 
}				node_list;

typedef struct hash 
{
	int 		index_size;
	node_list	**list;
}				hash_list;


int	ft_strlen(const char *str);
// int	insert_node(hash_list *hash, int value, int index_node);
int	ft_strncmp(const char *str1, const char *str2, int n);
int	do_hash(int key, hash_list *size_hash); // here must be type int
char	*grepvalue(hash_list *hash, int key);
// node_list	*create_node();
char	*ft_itoa(int n);
int	ft_atoi(char *str);
hash_list *create_stack_list(int len_number);

#endif
