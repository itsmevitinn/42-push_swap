/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_with_second.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:56:08 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/06 12:03:29 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_with_second.h"

int main(int argc, char **argv)
{
	node_list **stack_a;
	node_list **stack_b;
	int indexargv;

	stack_a = malloc(sizeof(node_list));
	stack_b = malloc(sizeof(node_list));
	indexargv = 1;
	while (indexargv < argc)
	{
		insert_last_node(stack_a, ft_atoi(argv[indexargv]));
		indexargv++;
	}
	check_errors(stack_a);
	if ((argc - 1) == 2)
		sort_2(stack_a);
	else if ((argc - 1) == 3)
		sort_3(stack_a);
	else if ((argc - 1) <= 5)
		sort_5(stack_a, stack_b, argc - 1);
	else if ((argc - 1) < 350)
	{
		sort_100(stack_a, stack_b, argc - 1);
		*stack_b = NULL;
	}
	else if ((argc - 1) >= 350)
	{
		get_index(stack_a);
		radix_sort(stack_a, stack_b);
	}
	// print_stacks(stack_a, stack_b);
	return (0);
}

void	organize_b(node_list **stack_a, node_list **stack_b, int value)
{
	int middle;
	int len_b;

	len_b = count_len(stack_b);
	middle = greb_middle(stack_b, count_len(stack_b));
	if (value < middle)
	{
		push(stack_a, stack_b, 'b');
		if (len_b > 1)
			rotate(stack_b, 'b');
	}
	else
		push(stack_a, stack_b, 'b');
}

void bubble_sort(int *ordened, int len)
{
	int i;
	int temp;

	i = 0;
	len--;
	while (i < len)
	{
		if (ordened[i] > ordened[i + 1])
		{
			temp = ordened[i];
			ordened[i] = ordened[i + 1];
			ordened[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int greb_middle(node_list **stack_a, int len)
{
	node_list *temp;
	int *ordened;
	int middle;
	int i;
	int *new;
	int half;

	half = len / 2;
	i = 0;
	ordened = malloc(sizeof(int) * len);
	temp = *stack_a;
	while (i < len && temp)
	{
		ordened[i] = temp->value;
		temp = temp->next;
		i++;
	}
	bubble_sort(ordened, len);
	return (ordened[half - 1]);
}
