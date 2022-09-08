/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:54 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/08 17:07:14 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	check_order(node_list **stack_a, node_list **stack_b, char type)
{
	node_list	*temp;
	node_list	*next;

	if (type == 'a')
		temp = *stack_a;
	else if (type == 'b')
		temp = *stack_b;
	while (temp->next != NULL)
	{
		next = temp->next;
		if (type == 'a')
		{
			if (temp->value < next->value)
				temp = temp->next;
			else
				return (0);
		}
		else if (type == 'b')
		{
			if (temp->value > next->value)
				temp = temp->next;
			else
				return (0);
		}
	}
	if (type == 'b')
		while (*stack_b != NULL)
			push(stack_a, stack_b, 'a');
	return (1);
}

void	duplicated_and_ordened(node_list **stack_a, node_list **stack_b)
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
	if (check_order(stack_a, NULL, 'a') == 1)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
