/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:56:08 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/14 16:47:13 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	node_list	**stack_a;
	node_list	**stack_b;
	char		**splitted;
	int			indexargv;

	indexargv = 1;
	if (argc == 1)
		return (0);
	stack_a = malloc(sizeof(node_list));
	stack_b = malloc(sizeof(node_list));
	if (argc == 2)
	{
		if (*argv[1] == 0)
			free_and_error(stack_a, stack_b, NULL);
		splitted = ft_split(argv[1], ' ');
		with_quotes(stack_a, stack_b, splitted);
	}
	else
		no_quotes(stack_a, stack_b, argv, argc);
	dup_or_ordened(stack_a, stack_b, splitted);
	sort(stack_a, stack_b, argc, splitted);
	free_all(stack_a, stack_b, splitted);
	return (0);
}

void	sort(node_list **stk_a, node_list **stk_b, int argc, char **split)
{
	int	countsplits;

	countsplits = 0;
	if (argc == 2)
	{
		while (*split++)
			countsplits++;
		argc = countsplits + 1;
	}
	if ((argc - 1) == 3)
		sort_3(stk_a);
	else if ((argc - 1) <= 5)
		sort_smalls(stk_a, stk_b, argc - 1);
	else if ((argc - 1) < 350)
		sort_larger(stk_a, stk_b, argc - 1);
	else if ((argc - 1) >= 350)
	{
		get_index(stk_a, count_len(stk_a), 1);
		radix_sort(stk_a, stk_b);
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
