#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct node
{
	int			index;
	int 		value;
	struct node *next; 
}				node_list;

// typedef struct ind_list 
// {
// 	int 		list_size;
// 	node_list	**list;
// }				index_list;

node_list	*get_last(node_list *stack);
void		sort_5(node_list **stack_a, node_list **stack_b, int len);
void		radix_sort(node_list **stack_a, node_list **stack_b);
int			get_highest_bit(node_list **stack);
void		sort_3(node_list **stack_a);
void		get_index(node_list **stack_a);
int			pick_smallest(node_list **stack, int len);
int			count_len(node_list **stack);
int			pick_highest(node_list **stack, int len);
int			check_order(node_list **stack);
void		rotate(node_list **stack, char type);
int			find_position(node_list **stack, int smallest);
void		print_stacks(node_list **stack_a, node_list **stack_b);
void		insert_last_node(node_list **stack, int value);
void		push(node_list **stack_a, node_list **stack_b, char type);
void		swap(node_list **stack_list, char type);
int			check_errors(node_list **stack);
void		reverse_rotate(node_list **stack, char type);
#endif
