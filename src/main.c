/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:27:32 by ssukhova          #+#    #+#             */
/*   Updated: 2024/07/09 19:16:59 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (validate_input(argc, argv) != 0)
	{
		print_usage();
		return (WRONG_INPUT);
	}
	if (init_data(&data, argc, argv) != 0)
		return (MALLOC_ERROR);
	init_philos(&data);
	init_forks(&data);
	if (run_threads(&data) != 0)
		return (MALLOC_ERROR);
	if (join_threads(&data) != 0)
		return (MALLOC_ERROR);
	free_data(&data);
	return (0);
}
