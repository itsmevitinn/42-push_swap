/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:56:08 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/02 12:03:03 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int greb_middle_b(node_list **stack_a, int len);
void print_stack(node_list **stack_a, node_list **stack_b);
void bubble_sort(int *ordened, int len);
void sort_100(node_list **stack_a, node_list **stack_b, int len);
int greb_middle(node_list **stack_a, int len);

int main(int argc, char **argv)
{
	node_list **stack_a;
	node_list **stack_b;
	int *int_numbers;
	int indexargv;
	int indexnode;
	int indexnumbers;

	indexnode = 0;
	stack_a = malloc(sizeof(node_list));
	stack_b = malloc(sizeof(node_list));
	int_numbers = malloc(sizeof(int) * argc - 1);
	indexargv = 1;
	indexnumbers = 0;
	while (indexargv < argc)
	{
		int_numbers[indexnumbers] = ft_atoi(argv[indexargv]);
		insert_last_node(stack_a, int_numbers[indexnumbers]);
		indexnumbers++;
		indexargv++;
	}
	check_errors(stack_a);
	if ((argc - 1) == 3)
	{
		sort_3(stack_a);
		exit(EXIT_SUCCESS);
	}
	else if ((argc - 1) == 5)
	{
		sort_5(stack_a, stack_b, argc - 1);
		exit(EXIT_SUCCESS);
	}
	else if ((argc - 1) == 6)
	{
		sort_100(stack_a, stack_b, argc - 1);
		*stack_b = NULL;
		// ft_bzero(*stack_b, sizeof(node_list));
		print_stack(stack_a, stack_b);
		exit(EXIT_SUCCESS);
	}
	get_index(stack_a);
	radix_sort(stack_a, stack_b);
	return (0);
}

void sort_3(node_list **stack_a)
{
	int highest_value;
	int highest_position;
	int smallest_value;
	int smallest_position;

	while (!check_order(stack_a))
	{
		highest_value = pick_highest(stack_a, 3);
		highest_position = find_position(stack_a, highest_value);
		smallest_value = pick_smallest(stack_a, 3);
		smallest_position = find_position(stack_a, smallest_value);
		if (highest_position == 2 && smallest_position == 1)
		{
			reverse_rotate(stack_a, 'a');
			swap(stack_a, 'a');
		}
		else if (highest_position == 3 && smallest_position == 2)
			swap(stack_a, 'a');
		else if (highest_position == 2 && smallest_position == 3)
			reverse_rotate(stack_a, 'a');
		else if (highest_position == 1 && smallest_position == 2)
			rotate(stack_a, 'a');
		else if (highest_position == 1 && smallest_position == 3)
		{
			rotate(stack_a, 'a');
			swap(stack_a, 'a');
		}
	}
}

void sort_5(node_list **stack_a, node_list **stack_b, int len)
{
	int small_value;
	int smallest_position;
	int half;
	int counter;

	counter = 0;
	while (counter < 2)
	{
		half = len / 2;
		small_value = pick_smallest(stack_a, len);
		smallest_position = find_position(stack_a, small_value);
		while (smallest_position > half)
		{
			if (smallest_position == len)
			{
				reverse_rotate(stack_a, 'a');
				push(stack_a, stack_b, 'b');
				len--;
				break;
			}
			reverse_rotate(stack_a, 'a');
			smallest_position++;
		}
		while (smallest_position <= half)
		{
			if (smallest_position == 1)
			{
				push(stack_a, stack_b, 'b');
				len--;
				break;
			}
			rotate(stack_a, 'a');
			smallest_position--;
		}
		counter++;
	}
	if (!check_order(stack_a))
		sort_3(stack_a);
	while (*stack_b != NULL)
		push(stack_a, stack_b, 'a');
}

void print_stack(node_list **stack_a, node_list **stack_b)
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

void	organize_b(node_list **stack_a, node_list **stack_b, int value)
{
	int middle;
	int len_b;

	len_b = count_len(stack_b);
	middle = greb_middle_b(stack_b, count_len(stack_b));
	if (value < middle)
	{
		push(stack_a, stack_b, 'b');
		if (len_b > 1)
			rotate(stack_b, 'b');
	}
	else
		push(stack_a, stack_b, 'b');
}

void sort_100(node_list **stack_a, node_list **stack_b, int len)
{
	int smallest_position;
	int smallest_value;
	int highest_position;
	int highest_value;
	int second_position;
	int second_value;
	int middle;
	int half;
	int counter;
	
	counter = 0;
	while (!check_order(stack_a) && len > 3)
	{
		counter = 0;
		len = count_len(stack_a);
		middle = greb_middle(stack_a, len);
		while (counter < len)
		{
			if ((*stack_a)->value < middle)
				organize_b(stack_a, stack_b, (*stack_a)->value);
			else
				rotate(stack_a, 'a');
			counter++;
		}
	}
	if (len == 3)
		sort_3(stack_a);
	len = count_len(stack_b);
	half = len / 2;
	while(*stack_b != NULL && len > 0)
	{
		// len = count_len(stack_b);
		highest_value = pick_highest(stack_b, len);
		highest_position = find_position(stack_b, highest_value);
		if (len > 1)
		{
			second_value = pick_second_highest(stack_b, len, highest_value);
			second_position = find_position (stack_b, second_value);
		}
		if (which_is_better(highest_position, second_position, len) == 1)
		{
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
		else
		{
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
					reverse_rotate(stack_b, 'b');
					push(stack_a, stack_b, 'a');
					len--;
					break;		
				}
				reverse_rotate(stack_b, 'b');
				highest_position++;
			}
		}
	}
}

// void print_stack(node_list **stack_a, node_list **stack_b)
// {
// 	node_list *current_a;
// 	node_list *current_b;

// 	current_a = *stack_a;
// 	current_b = *stack_b;
// 	ft_printf("STACK A\n");
// 	while (current_a)
// 	{
// 			ft_printf("%i ", current_a->value);
// 			ft_printf("index: %i\n", current_a->index);
// 			current_a = current_a->next;
// 	}
// 	ft_printf("\n");
// 	ft_printf("STACK B\n");
// 	while (current_b)
// 	{
// 			ft_printf("%i ", current_b->value);
// 			ft_printf("index: %i\n", current_b->index);
// 			current_b = current_b->next;
// 	}
// }

int greb_middle_b(node_list **stack_a, int len)
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

void radix_sort(node_list **stack_a, node_list **stack_b)
{
	int box;
	int highest_bit;
	int run_numbers;
	int next_bit;
	int len;

	next_bit = 0;
	highest_bit = get_highest_bit(stack_a);
	while (next_bit < highest_bit)
	{
		len = count_len(stack_a);
		run_numbers = 0;
		while (run_numbers < len && !check_order(stack_a))
		{
			if ((((*stack_a)->index >> next_bit) & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			run_numbers++;
		}
		while (*stack_b != NULL)
			push(stack_a, stack_b, 'a');
		next_bit++;
	}
}
