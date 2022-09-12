/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vitor <vsergio@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:59:15 by Vitor             #+#    #+#             */
/*   Updated: 2022/09/11 22:07:12 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	free_nodes(node_list **stack_a, node_list **stack_b)
{
	node_list *next;

	while(*stack_a)
	{
		next = (*stack_a)->next;
		free(*stack_a);
		*stack_a = next;
	}
	free(stack_a);
	while(*stack_b)
	{
		next = (*stack_b)->next;
		free(*stack_b);
		*stack_b = next;
	}
	free(stack_b);
}
