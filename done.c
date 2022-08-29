#include "push_swap.h"
#include <stdio.h>

void	sort_values(int *array);
void sort_5(node_list **stack_a, node_list **stack_b, int len);
void print_stack_a(node_list **stack_a);
void	radix_sort(node_list **stack_a, node_list **stack_b);
int get_highest_bit(node_list **stack);
void sort_3(node_list **stack_a);
void get_index(node_list **stack_a);
void sort_temp(node_list **temp);
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

int get_highest_bit(node_list **stack)
{
	node_list *temp;
	int highest;
	int bits;
	int size;

	bits = 0;
	temp = *stack;
	highest = -2147483648;
	while (temp != NULL)
	{
		if (highest < temp->value)
			highest = temp->value;
		temp = temp->next;
	}
	while(highest >> bits != 0)
		bits++;
	return (bits);
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

void	radix_sort(node_list **stack_a, node_list **stack_b)
{
	int box;
	int highest_bit;
	int run_numbers;
	int next_bit;
	int len;

	next_bit = 0;
	highest_bit = get_highest_bit(stack_a);
	while(next_bit < highest_bit)
	{
		len = count_len(stack_a);
		run_numbers = 0;
		while(run_numbers < len)
		{
			if ((((*stack_a)->index >> next_bit) & 1) == 1)
				rotate(stack_a, 'a');
			else
				push(stack_a, stack_b, 'b');
			run_numbers++;
		}
		while(*stack_b != NULL)
			push(stack_a, stack_b, 'a');
		next_bit++;
	}
}

int find_position(node_list **stack, int value)
{
	node_list *temp;
	int position;

	temp = *stack;
	position = 0;
	while (temp)
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
	return (1);
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
	while (temp->next != NULL)
	{
		next = temp->next;
		if (temp->value < next->value)
			temp = temp->next;
		else
			return (0);
	}
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
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
			printf("index: %i ", current_a->index);
			current_a = current_a->next;
		}
		if (current_b)
		{
			printf("%i", current_b->value);
			printf("index: %i ", current_b->index);
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
		printf("sa\n");
	else
		printf("sb\n");
}

void push(node_list **stack_a, node_list **stack_b, char type)
{
	node_list *temp_sender;
	if (type == 'a')
	{
		temp_sender = (*stack_b)->next;
		insert_first_node(stack_a, *stack_b);
		*stack_b = temp_sender;
		printf("pa\n");
	}
	else if (type == 'b')
	{
		temp_sender = (*stack_a)->next;
		insert_first_node(stack_b, *stack_a);
		*stack_a = temp_sender;
		printf("pb\n");
	}
}

void sort_temp(node_list **temp)
{
	node_list **temp_b;
	node_list *next;
	int small_value;
	int len;

	temp_b = malloc(sizeof(node_list *));
	while (*temp != NULL)
	{
		len = count_len(temp);
		small_value = pick_smallest(temp, len);
		while ((*temp)->value != small_value)
			rotate(temp, 'a');
		push(temp, temp_b, 'b');
	}
	while (*temp_b != NULL)
		push(temp, temp_b, 'a');
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
		printf("rb\n");
	else if (type == 'a')
		printf("ra\n");
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
		printf("rrb\n");
	else if (type == 'a')
		printf("rra\n");
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
	new_node->index = 0;
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
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

void	get_index(node_list **stack_a)
{
	node_list *highest_node;
	node_list *temp;
	int highest_value;
	int min_value;
	int len;

	min_value = -2147483648;
	len = count_len(stack_a);
	while(len)
	{
		highest_node = NULL;
		highest_value = min_value;
		temp = *stack_a;
		while(temp)
		{
			if (temp->value == min_value && temp->index == 0)
				temp->index = 1;
			else if (temp->value > highest_value && temp->index == 0)
			{
				highest_value = temp->value;
				highest_node = temp;
				temp = *stack_a;
			}
			else
				temp = temp->next;
		}
		if (highest_node != NULL)
			highest_node->index = len; 
		len--;
	}
}
