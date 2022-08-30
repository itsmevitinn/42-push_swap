#include "push_swap.h"
#include <stdio.h>

int pick_smallest(node_list **stack, int len);
int get_pivot(node_list **stack);
int count_len(node_list **stack);
int pick_highest(node_list **stack, int len);
int check_order(node_list **stack);
void rotate(node_list **stack, char type);
int find_position(node_list **stack, int smallest);
void ft_bubblesort(node_list **stack_a, node_list **stack_b, int len);
node_list *get_last(node_list *stack);
void print_stacks(node_list **stack_a, node_list **stack_b);
void insert_last_node(node_list **stack, int value);
void insert_first_node(node_list **stack, node_list *first);
void push(node_list **stack_a, node_list **stack_b, char type);
void swap(node_list **stack_list, char type);
int check_errors(node_list **stack);
void reverse_rotate(node_list **stack, char type);
void ft_mergesort(node_list **stack_a, node_list **stack_b, int len);

int main(int argc, char **argv)
{
	node_list **stack_a;
	node_list **stack_b;
	int *int_numbers;
	int indexargv;
	int indexnode;
	int indexnumbers;
	
	indexnode = 0;
	stack_a = malloc(sizeof(node_list) * argc - 1);
	stack_b = malloc(sizeof(node_list) * argc - 1);
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
	ft_mergesort(stack_a, stack_b, argc - 1);
	print_stacks(stack_a, stack_b);
	// ft_bubblesort(stack_a, stack_b, argc - 1);
	return (0);
}

void ft_mergesort(node_list **stack_a, node_list **stack_b, int len)
{
	// node_list *second;
	int small_value;
	// int highest_value;
	// int highest_position;
	int half;
	int pivot;
	int position_pivot;
	int smallest_position;

	while (!check_order(stack_a))
	{
		pivot = get_pivot(stack_a);
		while((*stack_a)->value != pivot)
		{
			len = count_len(stack_a);
			half = len/2;
			small_value = pick_smallest(stack_a, len);
			position_pivot = find_position(stack_a, pivot);
			if(pivot == small_value && position_pivot == len)
			{
				reverse_rotate(stack_a, 'a');
				push(stack_a, stack_b, 'b');
				break; // or return (0);
			}
			else if (pivot == small_value && position_pivot != len)
			{
				while((*stack_a)->value != pivot)
				{
					if ((*stack_a)->value > pivot)
						rotate(stack_a, 'a');
				}
				break; // or return (0);
			}
			smallest_position = find_position(stack_a, small_value);
			while (smallest_position > half)
			{
				if (smallest_position == len)
				// if (get_pivot() == len)
				{
					reverse_rotate(stack_a, 'a');
					push(stack_a, stack_b, 'b');
					// len--;
					break;
				}
				reverse_rotate(stack_a, 'a');
				smallest_position++;
			}
			while(smallest_position <= half)
			{
				// if ((*stack_a)->value == small_value)
				if (smallest_position == 1)
				{
					push(stack_a, stack_b, 'b');
					// len--;
					break;
				}
				rotate(stack_a, 'a');
				smallest_position--;
			}
		}
	}
	// len_a = count_len(stack_a);
	// half_a = len_a/2;
	// while (*stack_a != NULL)
	// {
	// 	highest_value = pick_smallest(stack_a, len_a);
	// 	highest_position = find_position(stack_a, highest_value);
	// 	while (highest_position > half_a)
	// 	{
	// 		if (highest_position == len_a)
	// 		{
	// 			reverse_rotate(stack_a, 'a');
	// 			push(stack_a, stack_b, 'b');
	// 			len_a--;
	// 			break;
	// 		}
	// 		reverse_rotate(stack_a, 'a');
	// 		highest_position++;
	// 	}
	// 	while(highest_position <= half_a)
	// 	{
	// 		if (highest_position == 1)
	// 		{
	// 			push(stack_a, stack_b, 'b');
	// 			len_a--;
	// 			break;
	// 		}
	// 		rotate(stack_a, 'a');
	// 		highest_position--;
	// 	}
	// }

	// while (!check_order(stack_a))
	// {
	// 	small_a = pick_small(stack_a);
	// 	position_a = find_position(stack_a, small_a);
	// 	// printf("menor valor: %i\n", small_a);
	// 	// printf("posicao menor: %i\n", position_a);
	// 	second = (*stack_a)->next;
	// 	if((*stack_a)->value > second->value)
	// 		rotate(stack_a, 'a');
	// 	else
	// 	{
	// 		swap(stack_a, 'a');
	// 		rotate(stack_a, 'a');
	// 	}
	// }
	while(*stack_b != NULL)
		push(stack_a, stack_b, 'a');
}

int find_position(node_list **stack, int value)
{
	node_list *temp;
	int position;

	temp = *stack;
	position = 0;
	while(temp)
	{
		if (temp->value == value)
		{
			position++;
			break;
		}
		position++;
		temp = temp->next;
	}
	return (position);
}

int check_order(node_list **stack)
{
	node_list *temp;
	node_list *next;

	temp = *stack;
	while (temp->next != NULL)
	{
		next = temp->next;
		if (temp->value < next->value)
			temp = temp->next;
		else
			return (0);
	}
	return(1);
}

int check_errors(node_list **stack)
{
	node_list *temp;
	node_list *next;

	temp = *stack;
	next = (*stack)->next;
	while (temp->next != NULL)
	{
		while (next)
		{
			if (temp->value != next->value)
				next = next->next;
			else
			{
				write(2, "Numeros duplicados\n", 19);
				exit(EXIT_FAILURE);
			};
		}
		temp = temp->next;
		next = temp->next;
	}
	temp = *stack;
	// while (temp->next != NULL)
	// {
	// 	next = temp->next;
	// 	if (temp->value < next->value)
	// 		temp = temp->next;
	// 	else
	// 		return (0);
	// }
	// write(2, "Stack ordenada\n", 15);
	// exit(EXIT_FAILURE);
	return (0);
}

void ft_bubblesort(node_list **stack_a, node_list **stack_b, int len)
{
	while (!check_order(stack_a))
	{
		while (*stack_a != NULL)
		{
			if ((*stack_a)->next == NULL)
			{
				push(stack_a, stack_b, 'b');
				break;
			}
			node_list *next;
			next = (*stack_a)->next;
			if ((*stack_a)->value > next->value)
				swap(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
		}
		while (*stack_b != NULL)
		{
			if ((*stack_b)->next == NULL)
			{
				push(stack_a, stack_b, 'a');
				break;
			}
			node_list *next;
			next = (*stack_b)->next;
			if ((*stack_b)->value < next->value)
				swap(stack_b, 'b');
			else
				push(stack_a, stack_b, 'a');
		}
	}
}

int pick_highest(node_list **stack, int len)
{
	node_list *temp;
	int highest;
	int counter;
	int limiter;

	limiter = 0;
	counter = 0;
	temp = *stack;
	highest = -2147483648;
	while (temp != NULL && limiter < len)
	{
		if (highest < temp->value)
		{
			highest = temp->value;
			counter++;
		}
		temp = temp->next;
		limiter++;
	}
	return (highest);
}

int pick_smallest(node_list **stack, int len)
{
	node_list *temp;
	int smallest;
	int counter;
	int limiter;

	limiter = 0;
	counter = 0;
	temp = *stack;
	smallest = 2147483647;
	while (temp != NULL && limiter < len)
	{
		if (smallest > temp->value)
		{
			smallest = temp->value;
			counter++;
		}
		temp = temp->next;
		limiter++;
	}
	return (smallest);
}

void print_stacks(node_list **stack_a, node_list **stack_b)
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
			printf("%i ", current_a->value);
			current_a = current_a->next;
		}
		if (current_b)
		{
			printf("%i", current_b->value);
			current_b = current_b->next;
		}
		printf("\n");
	}
	printf("- -\na b\n");
}

void swap(node_list **stack_list, char type)
{
	node_list *first;
	node_list *second;
	node_list *third;
	first = *stack_list;
	second = (*stack_list)->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack_list = second;
	if (type == 'a')
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
}

void push(node_list **stack_a, node_list **stack_b, char type)
{
	node_list *temp_sender;
	if (type == 'a')
	{
		temp_sender = (*stack_b)->next;
		insert_first_node(stack_a, *stack_b);
		*stack_b = temp_sender;
		write(1, "pa\n", 3);
	}
	else if (type == 'b')
	{
		temp_sender = (*stack_a)->next;
		insert_first_node(stack_b, *stack_a);
		*stack_a = temp_sender;
		write(1, "pb\n", 3);
	}
}

void rotate(node_list **stack, char type)
{
	node_list *first;
	node_list *second;
	node_list *last;

	second = (*stack)->next;
	first = *stack;
	first->next = NULL;
	last = get_last(second);
	last->next = first;
	*stack = second;
	if (type == 'b')
		write(1, "rb\n", 4);
	else if (type == 'a')
		write(1, "ra\n", 4);
}

void reverse_rotate(node_list **stack, char type)
{
	node_list *prev;
	node_list *last;
	node_list *first;

	first = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = first;
	*stack = last;
	if (type == 'b')
		write(1, "rrb\n", 4);
	else if (type == 'a')
		write(1, "rra\n", 4);
}

void ss(node_list **stack_a, node_list **stack_b)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
}

void rr(node_list **stack_a, node_list **stack_b)
{
	rotate(stack_a, 'a');
	rotate(stack_b, 'b');
}

void rrr(node_list **stack_a, node_list **stack_b)
{
	reverse_rotate(stack_a, 'a');
	reverse_rotate(stack_b, 'b');
}

void insert_last_node(node_list **stack, int value)
{
	node_list *new_node;
	node_list *temp;
	new_node = malloc(sizeof(node_list));
	new_node->value = value;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
		return;
	}
	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

void insert_first_node(node_list **stack, node_list *first)
{
	first->next = *stack;
	*stack = first;
}

int get_pivot(node_list **stack)
{
	node_list *current;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	return (current->value);
}

node_list *get_last(node_list *stack)
{
	node_list *current;
	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}

int count_len(node_list **stack)
{
	node_list *temp;
	int len;

	temp = *stack;
	len = 0;
	while(temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}
