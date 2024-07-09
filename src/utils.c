/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:27:55 by ssukhova          #+#    #+#             */
/*   Updated: 2024/07/03 16:04:03 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_msg(t_data *data, int id, char *msg)
{
	uint64_t	time;

	time = get_time() - get_start_time(data);
	pthread_mutex_lock(&data->mut_print);
	if (get_keep_iter(data))
		printf("%" PRIu64 " %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}

void	print_usage(void)
{
	printf("\t\tWRONG INPUT!\n\n");
	printf("./philo nb_philos time_to_die time_to_eat time_to_sleep \
		number_of_times_each_philosopher_must_eat (optional argument)\n");
	printf("Example:\n\n");
	printf("./philo 4 800 200 200 5\n\n");
	printf("nb_philos: 1-200\n");
	printf("time_to_die:0+\n");
	printf("time_to_eat:0+\n");
	printf("time_to_sleep:0+\n");
	printf("number_of_times_each_philosopher_must_eat: 0+\n");
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	else
		return (0);
}
