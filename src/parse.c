/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:27:40 by ssukhova          #+#    #+#             */
/*   Updated: 2024/07/09 19:30:14 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_atoi(char *str)
{
	int		count;
	long	result;
	int		sign;

	count = 0;
	result = 0;
	sign = 1;
	while (str[count] == '\r' || str[count] == '\t' || str[count] == ' '
		|| str[count] == '\f' || str[count] == '\v' || str[count] == '\n')
		count++;
	if (str[count] == '-')
	{
		sign = -1;
		count++;
	}
	else if (str[count] == '+')
		count++;
	if (!(str[count] >= '0' && str[count] <= '9'))
		return (0);
	while (str[count] >= '0' && str[count] <= '9')
		result = result * 10 + (str[count++] - '0');
	return (result * sign);
}

int	validate_input(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (WRONG_INPUT);
	if (validate_numbers(argc, argv) != 0)
		return (WRONG_INPUT);
	if (validate_values(argc, argv) != 0)
		return (WRONG_INPUT);
	return (0);
}

int	validate_numbers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (WRONG_INPUT);
			j++;
		}
		i++;
	}
	return (0);
}

int	validate_values(int argc, char **argv)
{
	int	i;

	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (WRONG_INPUT);
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
		return (WRONG_INPUT);
	i = 2;
	while (i < 5)
	{
		if (ft_atoi(argv[i]) < 60)
			return (WRONG_INPUT);
		i++;
	}
	return (0);
}
