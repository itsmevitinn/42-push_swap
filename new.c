#include "push_swap.h"
#include <stdio.h>
void	ft_bubblesort(node_list **stack_a, node_list **stack_b);
node_list	*new_swap(node_list *node1, node_list *node2);
void	create_list(node_list **stack, int value);
node_list	*get_last(node_list *stack);
void	rra(node_list **stack_a);
void	print_stack_b(node_list **stack_b);
void	sa(node_list **stack_list);
void	print_stack_a(node_list **stack_a);
void	ra(node_list **stack_a);
void	sb(node_list **stack_list);
void	insert_last(node_list **stack, node_list *new_node);
void	pa(node_list **stack_a, node_list **stack_b);
void	insert_last_node(node_list **stack, int value);
void	insert_first_node(node_list **stack, node_list *first);
void	pb(node_list **stack_a, node_list **stack_b);
void	check_errors(int *numbers);

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
	ft_bubblesort(stack_a, stack_b);
	// print_stack_a(stack_a);
	// print_stack_b(stack_b);
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
void	ft_bubblesort(node_list **stack_a, node_list **stack_b)
{
	node_list **list;
	int interrupter;

	interrupter = 1;

	while(interrupter)
	{
		list = stack_a;
		interrupter = 0;
		while((*list)->next != NULL)
		{
			node_list *first;
			node_list *second;
			first = *list;
			second = first->next;
			if (first->value > second->value)
			{
				*list = new_swap(first, second);
				interrupter = 1;
			}
			list = &(*list)->next;
		}
	}
	// write(1, "bubble\n", 7);
}

void	check_errors(int *numbers)
{
	int i;

	i = 0;
	while(numbers[i])
	{
		if(numbers[i] == numbers[i + 1] || numbers[i] > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	print_stack_a(node_list **stack_a)
{
	node_list *current;
	current = *stack_a;
	while(current)
	{
		printf("Valores dos nos da stack_a: %i\n", current->value);
		current = current->next;
	}
	write(1, "\n", 1);
}

void	print_stack_b(node_list **stack_b)
{
	node_list *current;
	current = *stack_b;
	while(current)
	{
		printf("Valores dos nos da stack_b: %i\n", current->value);
		current = current->next;
	}
	write(1, "\n", 1);
}

node_list	*new_swap(node_list *node1, node_list *node2)
{
	node_list *third;
	third = node2->next;

	node2->next = node1;
	node1->next = third;
	write(1, "sa\n", 3);
	return(node2);
}

node_list	*swap(node_list **stack_list)
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
	return (*stack_list);
}

void	push(node_list **sender, node_list **receiver)
{
	node_list *new_sender;
	new_sender = (*sender)->next;
	insert_first_node(receiver, *sender);
	*sender = new_sender;
}

void	rotate(node_list **stack)
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

void	reverse_rotate(node_list **stack)
{
	node_list *prev;
	node_list *last;
	node_list *first;

	first = *stack;
	last = *stack;
	while(last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = first;
	*stack = last;
}

void	sa(node_list **stack_a)
{
	swap(stack_a);
	printf("sa\n");
	print_stack_a(stack_a);
}

void	sb(node_list **stack_b)
{
	swap(stack_b);
	printf("sb\n");
}

void	ss(node_list **stack_a, node_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(node_list **stack_a, node_list **stack_b)
{
	push(stack_b, stack_a);
	printf("pa\n");
}

void	pb(node_list **stack_a, node_list **stack_b)
{
	node_list *next_a;
	next_a = (*stack_a)->next;
	insert_first_node(stack_b, *stack_a);
	*stack_a = next_a;
	printf("pb\n");
}

void	ra(node_list **stack_a)
{
	rotate(stack_a);
	printf("ra\n");
}

void	rb(node_list **stack_b)
{
	rotate(stack_b);
	printf("rb\n");
}

void	rr(node_list **stack_a, node_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(node_list **stack_a)
{
	reverse_rotate(stack_a);
	printf("rra\n");
}

void	rrb(node_list **stack_b)
{
	reverse_rotate(stack_b);
	printf("rrb\n");
}

void	rrr(node_list **stack_a, node_list **stack_b)
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

void	insert_last_node(node_list **stack, int value)
{
	node_list *new_node;
	node_list *temp;
	new_node = malloc(sizeof(node_list));
	new_node->value = value;
	new_node->next = NULL;
	if(*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = new_node;
}

void	insert_first_node(node_list **stack, node_list *first)
{
	first->next = *stack;
	*stack = first;
}

node_list	*get_last(node_list *stack)
{
	node_list *current;
	current = stack;
	while(current->next != NULL)
		current = current->next;
	return(current);
}
