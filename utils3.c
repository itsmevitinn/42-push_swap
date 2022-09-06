/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:33:00 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/06 11:37:34 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_with_second.h"

void	check_second(node_list **stack_a, node_list **stack_b, int highest_value, int highest_position, int len) 
{
	int second_position;
	int second_value;
	int half;

	half = len/2;
	second_value = pick_second_highest(stack_b, len, highest_value);
	second_position = find_position (stack_b, second_value);
	if (which_is_better(highest_position, second_position, len) == 1 && len > 1)
	{
		// ft_printf("pegou segundo maior: %i\n", second_value);
		while(second_position <= half)
		{
			if (second_position == 1)
			{
				push(stack_a, stack_b, 'a');
				len--;
				break;
			}
			rotate(stack_b, 'b');
			second_position--;
		}
		while(second_position > half)
		{
			if (second_position == len)
			{
				if (len > 1)
					reverse_rotate(stack_b, 'b');
				push(stack_a, stack_b, 'a');
				len--;
				break;		
			}
			reverse_rotate(stack_b, 'b');
			second_position++;
		}
		highest_position = find_position(stack_b, highest_value);
		half = len / 2;
		while(highest_position <= half)
		{
			if (highest_position == 1)
			{
				push(stack_a, stack_b, 'a');
				len--;
				break;		
			}
			rotate(stack_b, 'b');
			highest_position--;
		}
		while(highest_position > half)
		{
			if (highest_position == len)
			{
				if (len > 1)
					reverse_rotate(stack_b, 'b');
				push(stack_a, stack_b, 'a');
				len--;
				break;		
			}
			reverse_rotate(stack_b, 'b');
			highest_position++;
		}
		swap(stack_a, 'a');
	}
}
