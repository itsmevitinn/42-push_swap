/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:54 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/10 19:50:52 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	check_order_b(node_list **stack_a, node_list **stack_b)
{
	node_list	*temp;

	temp = *stack_b;
	while (temp->next != NULL)
	{
		if (temp->value > (temp->next)->value)
			temp = temp->next;
		else
			return (0);
	}
	while (*stack_b != NULL)
		push(stack_a, stack_b, 'a');
	return (1);
}

int	check_order_a(node_list **stack_a)
{
	node_list	*temp;

	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->value < (temp->next)->value)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

void	duplicated_or_ordened(node_list **stack_a)
{
	node_list	*temp;
	node_list	*next;

	temp = *stack_a;
	next = (*stack_a)->next;
	while (temp->next != NULL)
	{
		while (next)
		{
			if (temp->value != next->value)
				next = next->next;
			else
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			}
		}
		temp = temp->next;
		next = temp->next;
	}
	if (check_order_a(stack_a) == 1)
		exit(EXIT_FAILURE);
}

void	send_to_a(node_list **stack_a, node_list **stack_b, int pos, int len)
{
	int	half;

	half = len / 2;
	while (pos <= half)
	{
		if (pos == 1)
		{
			push(stack_a, stack_b, 'a');
			break ;
		}
		rotate(stack_b, 'b', len);
		pos--;
	}
	while (pos > half)
	{
		if (pos == len)
		{
			reverse_rotate(stack_b, 'b', len);
			push(stack_a, stack_b, 'a');
			break ;
		}
		reverse_rotate(stack_b, 'b', len);
		pos++;
	}
}

void	insert_first_node(node_list **stack, node_list *first)
{
	first->next = *stack;
	*stack = first;
}
