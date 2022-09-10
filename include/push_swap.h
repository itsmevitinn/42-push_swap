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
int			pick_second_highest(node_list **stack);
void		send_to_a(node_list **stack_a, node_list **stack_b, int pos, int len);
void		send_to_b(node_list **stack_a, node_list **stack_b, int pos, int len);
int			find_position_second(node_list **stack, int value);
void		sort_b(node_list **stack_a, node_list **stack_b, int len);
void		organize_b(node_list **stack_a, node_list **stack_b, int value);
void		choose_algorithm(node_list **stack_a, node_list **stack_b, int argc);
void		bubble_sort(int *ordened, int len);
void		sort_3(node_list **stack_a);
void		sort_smalls(node_list **stack_a, node_list **stack_b, int len);
void		sort_larger(node_list **stack_a, node_list **stack_b, int len);
void		radix_sort(node_list **stack_a, node_list **stack_b);
void		get_index(node_list **stack_a, int len, int index);
void		insert_first_node(node_list **stack, node_list *first);
void		insert_last_node(node_list **stack, int value);
void		push(node_list **stack_a, node_list **stack_b, char type);
void		swap(node_list **stack_list, char type);
void		rotate(node_list **stack, char type, int len);
void		reverse_rotate(node_list **stack, char type, int len);
void		duplicated_or_ordened(node_list **stack_a);
int			how_many_actions(int position, int half, int len);
int			check_order_b(node_list **stack_a, node_list **stack_b);
int			check_order_a(node_list **stack_a);
int			greb_middle(node_list **stack_a, int len);
int			which_is_better(int highest_position, int second_position, int len);
int			get_highest_bit(node_list **stack);
int			count_len(node_list **stack);
int			pick_value(node_list **stack, char type);
int			find_position(node_list **stack, char type);
#endif
