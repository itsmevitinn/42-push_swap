/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 11:42:44 by vsergio           #+#    #+#             */
/*   Updated: 2022/08/03 15:53:52 by vsergio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"
#include <stdlib.h>
void	sa(int stack[], int index);
void	pb(int stacka[], int *stackb);
int	check_duplicated(int stack[], int len);
int	main(void)
{
	int stacka[] = {0, 4, 9, 3, 8, 6, 7, 1, 5, 2, 'a'};
	int *stackb;
	int index;
	int temp;
	index = 0;
	int len;
	len = sizeof(stacka) / 4;
	printf("len da stack: %i\n", len);
	pb(stacka, stackb);
	printf("Valor stackb: %i\n", stackb[0]);
	if (check_duplicated(stacka, len) == 0)
		return (0);
	while(stacka[index] < len)
	{
		if (stacka[index] < stacka[index + 1])
		{
			index++;
			write(1, "next\n", 5);
		}
		else
		{
			sa(stacka, index);
			index = 0;
		}
	}
	int rato = 0;
	while(stacka[rato] != 'a')
		printf("valor stacka: %i\n", stacka[rato++]);
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

void	pb(int stacka[], int *stackb)
{
	int *tempa;
	int *tempb;
	int indexstacka;
	int indextempa;
	int indexstackb;
	int lenstacka;
	int lenstackb;
	tempb = malloc(150);
	tempa = malloc(150);
	// lenstacka = sizeof(stacka) / 4;
	lenstackb = sizeof(stackb) / 4;
	indexstacka = 0;
	indextempa = 0;
	indexstackb = 1;
	while(stacka[indexstacka] != 'a')
	{
		tempa[indextempa] = stacka[indexstacka];
		indexstacka++;
		indextempa++;
	}
	while(stackb[indexstackb] < lenstackb)
	{
		tempb[indexstackb] = stackb[indexstackb];
		indexstackb++;
	}
	tempb[0] = stacka[0];
	stacka = tempa;
	write(1, "pb\n", 3);
}

int	check_duplicated(int stack[], int len)
{
	int index;
	
	index = 0;

	while (stack[index] < len)
	{
		if (stack[index] == stack[index + 1])
		{
			printf("Duplicated numbers at position [%i] and [%i] in stack\n", index, index + 1);
			return (0);
		}
		index++;
	}
	return (1);
}
