/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vitor <vsergio@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:59:15 by Vitor             #+#    #+#             */
/*   Updated: 2022/09/13 10:55:56 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	free_nodes(node_list **stack_a, node_list **stack_b)
{
	node_list	*next;

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
}

void	write_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
