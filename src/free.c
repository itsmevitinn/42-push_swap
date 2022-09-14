/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vitor <vsergio@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:59:15 by Vitor             #+#    #+#             */
/*   Updated: 2022/09/14 16:16:09 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	free_all(node_list **stack_a, node_list **stack_b, char **splitted)
{
	node_list	*next;
	int			i;

	while (*stack_a)
	{
		next = (*stack_a)->next;
		free(*stack_a);
		*stack_a = next;
	}
	free(stack_a);
	while (*stack_b)
	{
		next = (*stack_b)->next;
		free(*stack_b);
		*stack_b = next;
	}
	free(stack_b);
	if (splitted)
	{
		i = 0;
		while (splitted[i])
			free(splitted[i++]);
		free(splitted);
	}
}

void	with_quotes(node_list **stack_a, node_list **stack_b, char **splitted)
{
	char	**temp;

	temp = splitted;
	while (*temp)
	{
		if (ft_atoi_push(*temp) == 2147483650)
			free_and_error(stack_a, stack_b, splitted);
		insert_last_node(stack_a, ft_atoi_push(*temp++));
	}
}

void	no_quotes(node_list **stack_a, node_list **stack_b, char **argv, int i)
{
	int	indexargv;

	indexargv = 1;
	while (indexargv < i)
	{
		if (ft_atoi_push(argv[indexargv]) == 2147483650)
			free_and_error(stack_a, stack_b, NULL);
		insert_last_node(stack_a, ft_atoi_push(argv[indexargv++]));
	}
}

void	free_and_error(node_list **a, node_list **b, char **splitted)
{
	free_all(a, b, splitted);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
