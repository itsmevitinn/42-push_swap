#include "push_swap.h"
#include <stdio.h>
void	create_list(node_list **stack, int value);
node_list	*get_last(node_list *stack);
void	sa(node_list **stack_list);
void	ra(node_list **stack_a);
void	sb(node_list **stack_list);
void	insert_last(node_list **stack, node_list *new_node);
void	pa(node_list **stack_a, node_list **stack_b);
void	insert_last_node(node_list **stack, int value);
void	insert_first_node(node_list **stack, node_list *first);
void	pb(node_list **stack_a, node_list **stack_b);
int main(int argc, char **argv)
{
	node_list **stack_a;
	node_list **stack_b;
	int *int_numbers;
	int indexargv;
	int indexnumbers;
	int i;
	stack_a = malloc(sizeof(node_list) * argc - 1);
	stack_b = malloc(sizeof(node_list) * argc - 1);
	int_numbers = malloc(400);
	indexargv = 1;
	i = 0;
	indexnumbers = 0;
	while (indexargv < argc)
	{
		int_numbers[indexnumbers] = ft_atoi(argv[indexargv]);
		insert_last_node(stack_a, int_numbers[indexnumbers]);
		printf("Array de inteiros do atoi[%i]: Valor do no: %i\n", indexnumbers, int_numbers[indexnumbers]);
		indexnumbers++;
		indexargv++;
	}
	sa(stack_a);
	node_list *rato;
	rato = *stack_a;
	while(rato)
	{
		printf("Valores dos nos da stack_a: %i\n", rato->value);
		rato = rato->next;
	}
	write(1, "\n", 1);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
	ra(stack_a);
	node_list *rato2;
	rato2 = *stack_b;
	while(rato2)
	{
		printf("Valores dos nos da stack_b: %i\n", rato2->value);
		rato2 = rato2->next;
	}
	write(1, "\n", 1);
	rato = *stack_a;
	while(rato)
	{
		printf("Valores dos nos da stack_a: %i\n", rato->value);
		rato = rato->next;
	}
	write(1, "\n", 1);
}

void	swap(node_list **stack_list)
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
}

void	sa(node_list **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

void	sb(node_list **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

void	ss(node_list **stack_a, node_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(node_list **stack_a, node_list **stack_b)
{
	node_list *next_b;
	next_b = (*stack_b)->next;
	insert_first_node(stack_a, *stack_b);
	*stack_b = next_b;
	write(1, "pb\n", 3);
}

void	pb(node_list **stack_a, node_list **stack_b)
{
	node_list *next_a;
	next_a = (*stack_a)->next;
	insert_first_node(stack_b, *stack_a);
	*stack_a = next_a;
}

void	ra(node_list **stack_a)
{
	node_list *first;
	node_list *second;
	node_list *last;

	second = (*stack_a)->next;
	first = *stack_a;
	first->next = NULL;
	last = get_last(second);
	last->next = first;
	*stack_a = second;
	write(1, "ra\n", 3);
}

void	create_list(node_list **stack, int value)
{
	node_list *node;
	node = malloc(sizeof(node_list));
	node->value = value;
	node->next = NULL;
	*stack = node;
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

void	insert_last(node_list **stack, node_list *new_node)
{
	node_list *temp;
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
