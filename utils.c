/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:53:22 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/05 23:15:38 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int count_len(node_list **stack)
{
	node_list *temp;
	int len;

	temp = *stack;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

int find_position(node_list **stack, int value)
{
	node_list *temp;
	int position;

	temp = *stack;
	position = 0;
	while (temp)
	{
		if (temp->value == value)
		{
			position++;
			break;
		}
		position++;
		temp = temp->next;
	}
	return (position);
}

void insert_last_node(node_list **stack, int value)
{
	node_list *new_node;
	node_list *last;
	new_node = malloc(sizeof(node_list));
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	last = *stack;
	last = get_last(last);
	last->next = new_node;
}

void print_stacks(node_list **stack_a, node_list **stack_b)
{
	node_list *current_a;
	node_list *current_b;

	current_a = *stack_a;
	current_b = *stack_b;
	write(1, "\n", 1);
	while (current_a || current_b)
	{
		if (current_a)
		{
			ft_printf("%i ", current_a->value);
			current_a = current_a->next;
		}
		if (current_b)
		{
			ft_printf("%i", current_b->value);
			current_b = current_b->next;
		}
		ft_printf("\n");
	}
	ft_printf("- -\na b\n");
}

int get_highest_bit(node_list **stack)
{
	node_list *temp;
	int highest;
	int bits;
	int size;

	bits = 0;
	temp = *stack;
	highest = -2147483648;
	while (temp != NULL)
	{
		if (highest < temp->value)
			highest = temp->value;
		temp = temp->next;
	}
	while(highest >> bits != 0)
		bits++;
	return (bits);
}
