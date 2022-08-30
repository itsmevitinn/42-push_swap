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

