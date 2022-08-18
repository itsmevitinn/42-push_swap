#include "push_swap.h"
#include <stdio.h>
void ft_bubblesort(node_list **stack_a, node_list **stack_b, int len);
node_list *new_swap(node_list *node1, node_list *node2);
void create_list(node_list **stack, int value);
node_list *get_last(node_list *stack);
void rra(node_list **stack_a);
void sa(node_list **stack_list);
void print_stacks(node_list **stack_a, node_list **stack_b);
void ra(node_list **stack_a);
void sb(node_list **stack_list);
void insert_last(node_list **stack, node_list *new_node);
void pa(node_list **stack_a, node_list **stack_b);
void insert_last_node(node_list **stack, int value);
void insert_first_node(node_list **stack, node_list *first);
void pb(node_list **stack_a, node_list **stack_b);
void check_errors(int *numbers);
void push(node_list **stack_a, node_list **stack_b, char type);
void swap(node_list **stack_list, char type);
int check_order(node_list **stack);
void reverse_rotate(node_list **stack, char type);


int main(int argc, char **argv)
{
	node_list **stack_a;
	node_list **stack_b;
	int *int_numbers;
	int indexargv;
	int indexnumbers;

	stack_a = malloc(sizeof(node_list) * argc - 1);
	stack_b = malloc(sizeof(node_list) * argc - 1);
	int_numbers = malloc(sizeof(int) * argc - 1);
	indexargv = 1;
	indexnumbers = 0;
	while (indexargv < argc)
	{
		int_numbers[indexnumbers] = ft_atoi(argv[indexargv]);
		check_errors(int_numbers);
		insert_last_node(stack_a, int_numbers[indexnumbers]);
		// printf("Array de inteiros do atoi[%i]: Valor do no: %i\n", indexnumbers, int_numbers[indexnumbers]);
		indexnumbers++;
		indexargv++;
	}
	// sa(stack_a);
	// print_stack_a(stack_a);
	check_order(stack_a);
	ft_bubblesort(stack_a, stack_b, argc - 1);
	// print_stack_a(stack_a);
	// print_stack_b(stack_b);
	return (0);

	// print_stack_a(stack_a);
	// while(first)
	// {
	// 	if (first->value > first->next->value)
	//
	// 	first = first->next;
	// }
	// pb(stack_a, stack_b);
	// print_stack_a(stack_a);
	// print_stack_b(stack_b);
	// pb(stack_a, stack_b);
	// print_stack_a(stack_a);
	// print_stack_b(stack_b);
	// pa(stack_a, stack_b);
	// print_stack_b(stack_b);
	// print_stack_a(stack_a);
	// ra(stack_a);
	// print_stack_a(stack_a);
	// ra(stack_a);
	// print_stack_a(stack_a);
	// rra(stack_a);
	// print_stack_a(stack_a);
}

// void	ft_bubblesort(node_list **stack_a, node_list **stack_b)
// {
// 	// node_list *temp;

// 	// temp = *stack_a;
// 	if (*stack_a == NULL|| stack_a == NULL)
// 		write(2, "Error\n", 6);
// 	while((*stack_a)->next != NULL)
// 	{
// 		if ((*stack_a)->value > (*stack_a)->next->value)
// 			new_swap(*stack_a, (*stack_a)->next);
// 		else
// 			*stack_a= (*stack_a)->next;
// 	}
// }
int check_order(node_list **stack)
{
	node_list *temp;
	node_list *next;

	temp = *stack;
	next = (*stack)->next;
	while(temp->next != NULL)
	{
		while(next)
		{
			if (temp->value != next->value)
				next = next->next;	
			else
			{
				write(2, "Error\n", 6);
				exit(EXIT_FAILURE);
			};
		}
		temp = temp->next;
		next = temp->next;
	}
	temp = *stack;
	while(temp->next != NULL)
	{
		next = temp->next;
		if (temp->value < next->value)
			temp = temp->next;
		else
			return (0);
	}
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void ft_bubblesort(node_list **stack_a, node_list **stack_b, int len)
{
	pick_small(stack_a);

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
		print_stacks(stack_a, stack_b);
	}

	void	pick_small(node_list **stack_a)
	{
		while(*stack_a && *stack_a->value < (*stack_a)->next->value)
			*stack_a = (*stack_a)->next;
		printf("Smallest value in stack: %i\n", (*stack_a)->value);
	}

	// interrupter_b = 1;
	// while(interrupter_b)
	// {
	// 	interrupter_b = 0;
	// while (*stack_b != NULL)
	// {
	// 	if ((*stack_b)->next == NULL)
	// 	{
	// 		push(stack_a, stack_b, 'a');
	// 		break;
	// 	}
	// 	node_list *next;
	// 	next = (*stack_b)->next;
	// 	if ((*stack_b)->value < next->value)
	// 	{
	// 		swap(stack_b, 'b');
	// 		// interrupter_b = 1;
	// 	}
	// 	else
	// 		push(stack_a, stack_b, 'a');
	// }
	// }
	// write(1, "bubble\n", 7);
}

// void	ft_bubblesort(node_list **stack_a, node_list **stack_b)
// {
// 	node_list **list;
// 	int interrupter;

// 	interrupter = 1;

// 	while(interrupter)
// 	{
// 		list = stack_a;
// 		interrupter = 0;
// 		while((*list)->next != NULL)
// 		{
// 			node_list *first;
// 			node_list *second;
// 			first = *list;
// 			second = first->next;
// 			if (first->value > second->value)
// 			{
// 				*list = new_swap(first, second);
// 				interrupter = 1;
// 			}
// 			list = &(*list)->next;
// 		}
// 	}
// 	// write(1, "bubble\n", 7);
// }

void check_errors(int *numbers)
{
	int i;

	i = 0;
	while (numbers[i])
	{
		if (numbers[i] == numbers[i + 1] || numbers[i] > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
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
		if(current_a)
		{
			printf("%i ", current_a->value);
			current_a = current_a->next;	
		}
		if(current_b)
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

// char	*grepvalue(hash_list *hash, int number)
// {
// 	int index_node = do_hash(number, hash);
// 	while (hash->list[index_node])
// 	{
// 		if (hash->list[index_node]->value == number)
// 			printf("Value index[%i]: %i\n", index_node, hash->list[index_node]->value);
// 			// return hash->list[index_node]->value;
// 		hash->list[index_node] = hash->list[index_node]->next;
// 	}
// 	return (0);
// }

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

node_list *get_last(node_list *stack)
{
	node_list *current;
	current = stack;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
