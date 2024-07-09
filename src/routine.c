/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:26:05 by ssukhova          #+#    #+#             */
/*   Updated: 2024/07/03 15:53:41 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	update_last_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}

void	*all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		nb_philos;

	data = (t_data *)data_p;
	nb_philos = get_nb_philos(data);
	while (get_keep_iter(data))
	{
		usleep(1000);
		i = 0;
		while (i < nb_philos)
		{
			if (!check_philo_full(data, &data->philos[i]))
				break ;
			i++;
		}
		if (i == nb_philos)
		{
			set_keep_iterating(data, false);
			notify_all_philos(data);
		}
	}
	return (NULL);
}

void	*all_alive_routine(void *data_p)
{
	t_data	*data;
	t_philo	*philos;
	int		i;
	int		nb_philos;

	data = (t_data *)data_p;
	philos = data->philos;
	nb_philos = get_nb_philos(data);
	while (get_keep_iter(data))
	{
		i = 0;
		while (i < nb_philos)
		{
			if (check_philo_died(&philos[i]) && get_keep_iter(data))
			{
				print_msg(data, philos[i].id, DIED);
				set_keep_iterating(data, false);
				notify_all_philos(data);
				break ;
			}
			i++;
		}
		usleep(1000);
	}
	return (NULL);
}
