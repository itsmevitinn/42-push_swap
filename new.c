#include "push_swap.h"
#include <stdio.h>
void ft_bubblesort(node_list **stack_a, node_list **stack_b);
node_list *new_swap(node_list *node1, node_list *node2);
void create_list(node_list **stack, int value);
node_list *get_last(node_list *stack);
void rra(node_list **stack_a);
void print_stack_b(node_list **stack_b);
void sa(node_list **stack_list);
void print_stack_a(node_list **stack_a);
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
	ft_bubblesort(stack_a, stack_b);
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
	int checker;

	temp = *stack;
	checker = 0;

	while(temp->next != NULL)
	{
		next = temp->next;
		if (temp->value < next->value)
			checker++;
		else
			return (0);
		temp = temp->next;
	}
	write(2, "ERROR\n", 6); // handle this before doing bubble_sort + handle duplicated numbers
	return (1); //exit instead return when ordened
}

void ft_bubblesort(node_list **stack_a, node_list **stack_b)
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
		// print_stack_a(stack_b);
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
		// print_stack_a(stack_a);
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

void print_stack_a(node_list **stack_a)
{
	node_list *current;
	current = *stack_a;
	while (current)
	{
		printf("Valores dos nos da stack_a: %i\n", current->value);
		current = current->next;
	}
	write(1, "\n", 1);
}

void print_stack_b(node_list **stack_b)
{
	node_list *current;
	current = *stack_b;
	while (current)
	{
		printf("Valores dos nos da stack_b: %i\n", current->value);
		current = current->next;
	}
	write(1, "\n", 1);
}

node_list *new_swap(node_list *node1, node_list *node2)
{
	node_list *third;
	third = node2->next;

	node2->next = node1;
	node1->next = third;
	write(1, "sa\n", 3);
	return (node2);
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
	node_list **receiver;
	node_list *new_sender;
	if (type == 'a')
	{
		new_sender = (*stack_b)->next;
		receiver = stack_a;
		insert_first_node(receiver, *stack_b);
		*stack_b = new_sender;
		write(1, "pa\n", 3);
	}
	else if (type == 'b')
	{
		new_sender = (*stack_a)->next;
		receiver = stack_b;
		insert_first_node(receiver, *stack_a);
		*stack_a = new_sender;
		write(1, "pb\n", 3);
	}
}

void rotate(node_list **stack)
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
}

void reverse_rotate(node_list **stack)
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
}

void ss(node_list **stack_a, node_list **stack_b)
{
	swap(stack_a, 'a');
	swap(stack_b, 'b');
}

void ra(node_list **stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void rb(node_list **stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void rr(node_list **stack_a, node_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void rra(node_list **stack_a)
{
	reverse_rotate(stack_a);
	printf("rra\n");
}

void rrb(node_list **stack_b)
{
	reverse_rotate(stack_b);
	printf("rrb\n");
}

void rrr(node_list **stack_a, node_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
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
