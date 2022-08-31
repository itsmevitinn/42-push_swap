/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:19 by vsergio           #+#    #+#             */
/*   Updated: 2022/08/30 23:59:41 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pick_highest(node_list **stack, int len)
{
	node_list *temp;
	int highest;
	int counter;
	int limiter;

	limiter = 0;
	counter = 0;
	temp = *stack;
	highest = -2147483648;
	while (temp != NULL && limiter < len)
	{
		if (highest < temp->value)
		{
			highest = temp->value;
			counter++;
		}
		temp = temp->next;
		limiter++;
	}
	return (highest);
}

int pick_highest_middle(node_list **stack, int len, int middle)
{
	node_list *temp;
	int highest;
	int counter;
	int limiter;

	limiter = 0;
	counter = 0;
	temp = *stack;
	highest = -2147483648;
	while (temp != NULL && limiter < len)
	{
		if (highest < temp->value && temp->value > middle)
		{
			highest = temp->value;
			counter++;
		}
		temp = temp->next;
		limiter++;
	}
	return (highest);
}


int pick_smallest_middle(node_list **stack, int len, int middle)
{
	node_list *temp;
	int smallest;
	int counter;
	int limiter;

	limiter = 0;
	counter = 0;
	temp = *stack;
	smallest = 2147483647;
	while (temp != NULL && limiter < len)
	{
		if (smallest > temp->value && temp->value < middle)
		{
			smallest = temp->value;
			counter++;
		}
		temp = temp->next;
		limiter++;
	}
	return (smallest);
}

int pick_smallest(node_list **stack, int len)
{
	node_list *temp;
	int smallest;
	int counter;
	int limiter;

	limiter = 0;
	counter = 0;
	temp = *stack;
	smallest = 2147483647;
	while (temp != NULL && limiter < len)
	{
		if (smallest > temp->value)
		{
			smallest = temp->value;
			counter++;
		}
		temp = temp->next;
		limiter++;
	}
	return (smallest);
}


void	get_index(node_list **stack_a)
{
	node_list *smallest_node;
	node_list *temp;
	int	smallest_value;
	int len;
	int index;

	index = 1;
	len = count_len(stack_a);
	while(index <= len)
	{
		smallest_node = NULL;
		smallest_value = 2147483647;
		temp = *stack_a;
		while(temp)
		{
			if (temp->value == -2147483648 && temp->index == 0)
				temp->index = 1;
			else if (temp->value < smallest_value && temp->index == 0)
			{
				smallest_value = temp->value;
				smallest_node = temp;
				temp = *stack_a;
			}
			else
				temp = temp->next;
		}
		if (smallest_node != NULL)
			smallest_node->index = index; 
		index++;
	}
}

