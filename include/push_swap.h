#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct node
{
	int			index;
	int 		value;
	struct node *next; 
}				node_list;

node_list	*get_last(node_list *stack);
void		send_second(node_list **stack_a, node_list **stack_b, int second_position, int len);
void		send_highest(node_list **stack_a, node_list **stack_b, int highest_position, int len);
void		sort_b(node_list **stack_a, node_list **stack_b, int len);
void		check_second(node_list **stack_a, node_list **stack_b, int highest_value, int highest_position, int len); 
void		organize_b(node_list **stack_a, node_list **stack_b, int value);
void		bubble_sort(int *ordened, int len);
void		sort_2(node_list **stack_a);
void		sort_3(node_list **stack_a);
void		sort_5(node_list **stack_a, node_list **stack_b, int len);
void		sort_100(node_list **stack_a, node_list **stack_b, int len);
void		radix_sort(node_list **stack_a, node_list **stack_b);
void		get_index(node_list **stack_a);
void		print_stacks(node_list **stack_a, node_list **stack_b);
void		insert_last_node(node_list **stack, int value);
void		push(node_list **stack_a, node_list **stack_b, char type);
void		swap(node_list **stack_list, char type);
void		rotate(node_list **stack, char type);
void		reverse_rotate(node_list **stack, char type);
int 		check_order_b(node_list **stack);
int			greb_middle(node_list **stack_a, int len);
int			which_is_better(int highest_position, int second_position, int len);
int 		pick_second_highest(node_list **stack, int len, int highest_value);
int			get_highest_bit(node_list **stack);
int 		pick_smallest(node_list **stack, int len);
int			count_len(node_list **stack);
int			pick_highest(node_list **stack, int len);
int			check_order(node_list **stack);
int			find_position(node_list **stack, int smallest);
int			check_errors(node_list **stack);
#endif
