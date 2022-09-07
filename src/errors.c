/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:54 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/07 12:41:19 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int check_order_b(node_list **stack)
{
	node_list *temp;
	node_list *next;

	temp = *stack;
	while (temp->next != NULL)
	{
		next = temp->next;
		if (temp->value > next->value)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int check_order(node_list **stack)
{
	node_list *temp;
	node_list *next;

	temp = *stack;
	while (temp->next != NULL)
	{
		next = temp->next;
		if (temp->value < next->value)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

int check_errors(node_list **stack)
{
	node_list *temp;
	node_list *next;

	temp = *stack;
	next = (*stack)->next;
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
			};
		}
		temp = temp->next;
		next = temp->next;
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		next = temp->next;
		if (temp->value < next->value)
			temp = temp->next;
		else
			return (0);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

