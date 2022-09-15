/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 16:37:43 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/14 21:51:23 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_rato
{
	int				index;
	int				value;
	struct s_rato	*next;
}				t_node;

t_node		*get_last(t_node *stack);
void		send_a(t_node **stack_a, t_node **stack_b, int pos, int len);
void		send_b(t_node **stack_a, t_node **stack_b, int pos, int len);
void		sort_b(t_node **stack_a, t_node **stack_b, int len);
void		organize_b(t_node **stack_a, t_node **stack_b, int value);
void		sort(t_node **stk_a, t_node **stk_b, int argc, char **split);
void		bubble_sort(int *ordened, int len);
void		sort_3(t_node **stack_a);
void		sort_smalls(t_node **stack_a, t_node **stack_b, int len);
void		sort_larger(t_node **stack_a, t_node **stack_b, int len);
void		radix_sort(t_node **stack_a, t_node **stack_b);
void		get_index(t_node **stack_a, int len, int index);
void		insert_first_node(t_node **stack, t_node *first);
void		insert_last_node(t_node **stack, int value);
void		push(t_node **stack_a, t_node **stack_b, char type);
void		swap(t_node **stack_list, char type);
void		rotate(t_node **stack, char type, int len);
void		reverse_rotate(t_node **stack, char type, int len);
void		free_and_error(t_node **a, t_node **b, char **splitted);
void		free_all(t_node **stack_a, t_node **stack_b, char **splitted);
void		dup_or_ordened(t_node **stack_a, t_node **stack_b, char **split);
void		with_quotes(t_node **stack_a, t_node **stack_b, char **splitted);
void		no_quotes(t_node **stack_a, t_node **stack_b, char **argv, int i);
int			pick_second_highest(t_node **stack);
int			how_many_actions(int position, int half, int len);
int			check_order_b(t_node **stack_a, t_node **stack_b);
int			check_order_a(t_node **stack_a);
int			greb_middle(t_node **stack_a, int len);
int			which_is_better(int highest_position, int second_position, int len);
int			get_highest_bit(t_node **stack);
int			count_len(t_node **stack);
int			pick_value(t_node **stack, char type);
int			find_position(t_node **stack, char type);
#endif
