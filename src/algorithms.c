/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:27:04 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/14 16:40:53 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/push_swap.h"

void	sort_b(node_list **stack_a, node_list **stack_b, int len)
{
	int	highest_pos;
	int	second_pos;

	while (*stack_b != NULL && len > 0)
	{
		if (check_order_b(stack_a, stack_b) == 1)
			break ;
		highest_pos = find_position(stack_b, 'h');
		if (len > 1)
			second_pos = find_position(stack_b, 'o');
		if (which_is_better(highest_pos, second_pos, len) == 1 && len > 1)
		{
			send_a(stack_a, stack_b, second_pos, len);
			len -= 1;
			highest_pos = find_position(stack_b, 'h');
			send_a(stack_a, stack_b, highest_pos, len);
			len -= 1;
			swap(stack_a, 'a');
		}
		else
		{
			send_a(stack_a, stack_b, highest_pos, len);
			len -= 1;
		}
	}
}

void	sort_3(node_list **stack_a)
{
	int	highest_position;
	int	smallest_position;

	while (!check_order_a(stack_a))
	{
		highest_position = find_position(stack_a, 'h');
		smallest_position = find_position(stack_a, 's');
		if (highest_position == 2 && smallest_position == 1)
		{
			reverse_rotate(stack_a, 'a', count_len(stack_a));
			swap(stack_a, 'a');
		}
		else if (highest_position == 3 && smallest_position == 2)
			swap(stack_a, 'a');
		else if (highest_position == 2 && smallest_position == 3)
			reverse_rotate(stack_a, 'a', count_len(stack_a));
		else if (highest_position == 1 && smallest_position == 2)
			rotate(stack_a, 'a', count_len(stack_a));
		else if (highest_position == 1 && smallest_position == 3)
		{
			rotate(stack_a, 'a', count_len(stack_a));
			swap(stack_a, 'a');
		}
	}
}

void	sort_smalls(node_list **stack_a, node_list **stack_b, int len)
{
	int			smallest_position;
	int			counter;
	node_list	*next;

	counter = 0;
	if (len == 2)
	{
		next = (*stack_a)->next;
		if ((*stack_a)->value > next->value)
			swap(stack_a, 'a');
	}
	else
	{
		while (counter < 2 && !check_order_a(stack_a))
		{
			smallest_position = find_position(stack_a, 's');
			send_b(stack_a, stack_b, smallest_position, len);
			len -= 1;
			counter++;
		}
		if (!check_order_a(stack_a))
			sort_3(stack_a);
		while (*stack_b != NULL)
			push(stack_a, stack_b, 'a');
	}
}

void	sort_larger(node_list **stack_a, node_list **stack_b, int len)
{
	int	middle;
	int	counter;

	counter = 0;
	while (!check_order_a(stack_a))
	{
		counter = 0;
		len = count_len(stack_a);
		middle = greb_middle(stack_a, len);
		if (len == 3)
			break ;
		while (counter < len)
		{
			if ((*stack_a)->value < middle)
				organize_b(stack_a, stack_b, (*stack_a)->value);
			else
				rotate(stack_a, 'a', len);
			counter++;
		}
	}
	if (len == 3 && !check_order_a(stack_a))
		sort_3(stack_a);
	len = count_len(stack_b);
	sort_b(stack_a, stack_b, len);
}

void	radix_sort(node_list **stack_a, node_list **stack_b)
{
	int	highest_bit;
	int	run_numbers;
	int	next_bit;
	int	len;

	next_bit = 0;
	highest_bit = get_highest_bit(stack_a);
	while (next_bit < highest_bit)
	{
		len = count_len(stack_a);
		run_numbers = 0;
		while (run_numbers < len && !check_order_a(stack_a))
		{
			if ((((*stack_a)->index >> next_bit) & 1) == 1)
				rotate(stack_a, 'a', len);
			else
				push(stack_a, stack_b, 'b');
			run_numbers++;
		}
		while (*stack_b != NULL)
			push(stack_a, stack_b, 'a');
		next_bit++;
	}
}
