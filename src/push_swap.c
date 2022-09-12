/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:56:08 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/12 17:54:30 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	node_list	**stack_a;
	node_list	**stack_b;
	int			indexargv;

	if (argc == 1)
		return (0);
	stack_a = malloc(sizeof(node_list));
	stack_b = malloc(sizeof(node_list));
	indexargv = 1;
	while (indexargv < argc)
		insert_last_node(stack_a, ft_atoi_push(argv[indexargv++]));
	duplicated_or_ordened(stack_a, stack_b);
	choose_algorithm(stack_a, stack_b, argc);
	free_nodes(stack_a, stack_b);
	return (0);
}

void	choose_algorithm(node_list **stack_a, node_list **stack_b, int argc)
{
	if ((argc - 1) == 3)
		sort_3(stack_a);
	else if ((argc - 1) <= 5)
		sort_smalls(stack_a, stack_b, argc - 1);
	else if ((argc - 1) < 350)
		sort_larger(stack_a, stack_b, argc - 1);
	else if ((argc - 1) >= 350)
	{
		get_index(stack_a, count_len(stack_a), 1);
		radix_sort(stack_a, stack_b);
	}
}

void	organize_b(node_list **stack_a, node_list **stack_b, int value)
{
	int	middle;
	int	len_b;

	len_b = count_len(stack_b);
	middle = greb_middle(stack_b, count_len(stack_b));
	if (value < middle)
	{
		push(stack_a, stack_b, 'b');
		if (len_b > 1)
			rotate(stack_b, 'b', len_b);
	}
	else
		push(stack_a, stack_b, 'b');
}

void	bubble_sort(int *ordened, int len)
{
	int	temp;
	int	i;

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

int	greb_middle(node_list **stack_a, int len)
{
	node_list	*temp;
	int			*ordened;
	int			half;
	int			i;
	int			middle;

	temp = *stack_a;
	ordened = malloc(sizeof(int) * len);
	half = len / 2;
	i = 0;
	while (i < len && temp)
	{
		ordened[i] = temp->value;
		temp = temp->next;
		i++;
	}
	bubble_sort(ordened, len);
	middle = ordened[half - 1];
	free(ordened);
	return (middle);
}
