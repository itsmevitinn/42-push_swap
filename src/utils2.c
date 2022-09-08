/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:19 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/08 18:25:17 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	which_is_better(int highest_position, int second_position, int len)
{
	int	half;
	int	actions_second;
	int	actions_highest;

	half = len / 2;
	actions_highest = how_many_actions(highest_position, half, len);
	actions_second = how_many_actions(second_position, half, len);
	if (actions_second < actions_highest)
		return (1);
	else
		return (0);
}

int	pick_second_highest(node_list **stack, int len, int highest_value)
{
	node_list	*temp;
	int			highest;
	int			counter;
	int			limiter;

	limiter = 0;
	counter = 0;
	temp = *stack;
	highest = -2147483648;
	while (temp != NULL && limiter < len)
	{
		if (highest < temp->value && temp->value < highest_value)
		{
			highest = temp->value;
			counter++;
		}
		temp = temp->next;
		limiter++;
	}
	return (highest);
}

int	pick_value(node_list **stack, int len, char type)
{
	node_list	*temp;
	int			value;

	temp = *stack;
	if (type == 's')
		value = 2147483647;
	else if (type == 'h')
		value = -2147483648;
	while (temp != NULL)
	{
		if (type == 's')
		{
			if (value > temp->value)
				value = temp->value;
		}
		else if (type == 'h')
		{
			if (value < temp->value)
				value = temp->value;
		}
		temp = temp->next;
	}
	return (value);
}

void	get_index(node_list **stack_a, int len, int index)
{
	node_list	*smallest_node;
	node_list	*temp;
	int			smallest_value;

	while (index <= len)
	{
		smallest_node = NULL;
		smallest_value = 2147483647;
		temp = *stack_a;
		while (temp)
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
			smallest_node->index = index++;
	}
}
