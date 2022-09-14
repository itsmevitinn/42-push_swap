/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:52:19 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/10 19:27:38 by Vitor            ###   ########.fr       */
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

int	pick_second_highest(t_node **stack)
{
	t_node	*temp;
	int			highest;
	int			highest_value;
	int			counter;

	highest_value = pick_value(stack, 'h');
	counter = 0;
	temp = *stack;
	highest = -2147483648;
	while (temp != NULL)
	{
		if (highest < temp->value && temp->value < highest_value)
			highest = temp->value;
		temp = temp->next;
	}
	return (highest);
}

int	pick_value(t_node **stack, char type)
{
	t_node	*temp;
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

void	get_index(t_node **stack_a, int len, int index)
{
	t_node	*smallest_node;
	t_node	*temp;
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

int	how_many_actions(int position, int half, int len)
{
	int	actions;

	actions = 0;
	while (position <= half)
	{
		if (position == 1)
		{
			actions++;
			break ;
		}
		position--;
		actions++;
	}
	while (position > half)
	{
		if (position == len)
		{
			actions += 2;
			break ;
		}
		position++;
		actions++;
	}
	return (actions);
}
