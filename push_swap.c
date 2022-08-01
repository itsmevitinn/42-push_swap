/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:42:44 by vsergio           #+#    #+#             */
/*   Updated: 2022/08/01 17:33:01 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
void	sa(int stack[], int index);
void	check_duplicated(int stack[]);
int	main(void)
{
	int stack[] = {0, 4, 3, 3, 8, 6, 7, 1, 5, 2, 'a'};
	int index;
	int temp;
	index = 0;
	int len;
	len = sizeof(stack) / 4;
	printf("len da stack: %i\n", len);
	check_duplicated(stack);
	while(stack[index] < len)
	{
		if (stack[index] < stack[index + 1])
		{
			index++;
			write(1, "next\n", 5);
		}
		else
		{
			sa(stack, index);
			index = 0;
		}
	}
	int rato = 0;
	while(stack[rato] != 'a')
		printf("Resultado: %i\n", stack[rato++]);
	return(0);
}

void	sa(int stack[], int index)
{
	int temp;

	temp = stack[index];
	stack[index] = stack[index + 1];
	stack[index + 1] = temp;
	write(1, "sa\n", 3);
}

void	sb(int stack[])
{
	int temp;
	int index;

	index = 0;

	temp = stack[index];
	stack[index] = stack[index + 1];
	stack[index + 1] = temp;
	write(1, "sb\n", 3);
}

void	ss(int stack[], int index)
{
	sa(stack, index);
	sb(stack);
	write(1, "ss\n", 3);
}

void	check_duplicated(int stack[], int len)
{
	int index;
	
	index = 0;

	while (stack[index] < len)
	{
		if (stack[index] == stack[index + 1])
			printf("Duplicated numbers at stack[%i] and stack[%i]", index, index + 1);
		index++;
	}
}
