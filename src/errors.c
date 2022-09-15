/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:54 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/14 21:42:42 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	check_order_b(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

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

int	check_order_a(t_node **stack_a)
{
	t_node	*temp;

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

void	dup_or_ordened(t_node **stack_a, t_node **stack_b, char **split)
{
	t_node	*temp;
	t_node	*next;

	temp = *stack_a;
	next = (*stack_a)->next;
	while (temp->next != NULL)
	{
		while (next)
		{
			if (temp->value != next->value)
				next = next->next;
			else
				free_and_error(stack_a, stack_b, split);
		}
		temp = temp->next;
		next = temp->next;
	}
	if (check_order_a(stack_a) == 1)
	{
		free_all(stack_a, stack_b, split);
		exit(EXIT_FAILURE);
	}
}

void	send_a(t_node **stack_a, t_node **stack_b, int pos, int len)
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

void	insert_first_node(t_node **stack, t_node *first)
{
	first->next = *stack;
	*stack = first;
}
