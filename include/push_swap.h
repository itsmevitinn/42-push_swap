/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:37:43 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/14 16:49:00 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct j_list
{
	int			index;
	int 		value;
	struct node *next; 
}				t_node;

node_list	*get_last(t_node *stack);
void		send_a(t_node **stack_a, t_list **stack_b, int pos, int len);
void		send_b(t_node **stack_a, node_list **stack_b, int pos, int len);
void		sort_b(t_node **stack_a, node_list **stack_b, int len);
void		organize_b(t_node **stack_a, node_list **stack_b, int value);
void		sort(node_list **stk_a, node_list **stk_b, int argc, char **split);
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
void		free_all(node_list **stack_a, node_list **stack_b, char **splitted);
void		dup_or_ordened(node_list **stack_a, node_list **stack_b, char **split);
void		with_quotes(node_list **stack_a, node_list **stack_b, char **splitted);
void		no_quotes(node_list **stack_a, node_list **stack_b, char **argv, int i);
int			pick_second_highest(node_list **stack);
int			how_many_actions(int position, int half, int len);
int			check_order_b(node_list **stack_a, node_list **stack_b);
int			check_order_a(node_list **stack_a);
int			greb_middle(node_list **stack_a, int len);
int			which_is_better(int highest_position, int second_position, int len);
int			get_highest_bit(node_list **stack);
int			count_len(node_list **stack);
int			pick_value(node_list **stack, char type);
int			find_position(node_list **stack, char type);
void		free_and_error(node_list **a, node_list **b, char **splitted);
#endif
