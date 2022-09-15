/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vitor <vsergio@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:59:15 by Vitor             #+#    #+#             */
/*   Updated: 2022/09/14 21:49:43 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	insert_first_node(t_node **stack, t_node *first)
{
	first->next = *stack;
	*stack = first;
}

void	with_quotes(t_node **stack_a, t_node **stack_b, char **splitted)
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

void	no_quotes(t_node **stack_a, t_node **stack_b, char **argv, int i)
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

int	get_highest_bit(t_node **stack)
{
	t_node	*temp;
	int		highest;
	int		bits;

	bits = 0;
	temp = *stack;
	highest = -2147483648;
	while (temp != NULL)
	{
		if (highest < temp->value)
			highest = temp->value;
		temp = temp->next;
	}
	while (highest >> bits != 0)
		bits++;
	return (bits);
}
