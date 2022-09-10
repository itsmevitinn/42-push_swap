/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsergio <vsergio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 08:59:49 by vsergio           #+#    #+#             */
/*   Updated: 2022/09/10 19:13:52 by Vitor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_atoi_numbers(char *string);
int	ft_atoi_push(char *str)
{
	long int	res;
	int			sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\r'
		|| *str == '\v' || *str == '\f')
			str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (!check_atoi_numbers(str))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		if (res > 2147483647)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		else if (res < -2147483648)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		str++;
	}
	return (sign * res);
}

int	check_atoi_numbers(char *string)
{
	char *temp;

	temp = string;
	while (*temp)
	{
		if (*temp >= '0' && *temp <= '9')
			temp++;
		else
			return (0);
	}
	return (1);
}
