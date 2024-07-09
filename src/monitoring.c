/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:25:57 by ssukhova          #+#    #+#             */
/*   Updated: 2024/07/03 15:43:03 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

bool	check_philo_full(t_data *data, t_philo *philo)
{
	return (get_nb_meals_philo_had(philo) >= data->nb_meals);
}

bool	check_philo_died(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (get_time() - get_last_eat_time(philo) > get_die_time(data)
		&& get_philo_state(philo) != EATING)
	{
		set_philo_state(philo, DEAD);
		return (true);
	}
	return (false);
}

void	notify_all_philos(t_data *data)
{
	int	i;
	int	nb_philos;

	i = 0;
	nb_philos = get_nb_philos(data);
	while (i < nb_philos)
	{
		set_philo_state(&data->philos[i], DEAD);
		i++;
	}
}

int	run_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	data->start_time = get_time();
	i = 0;
	while (i < nb_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL, &routine,
				&data->philos[i]))
			return (1);
		i++;
	}
	if (pthread_create(&data->monit_all_alive, NULL, &all_alive_routine, data))
		return (1);
	if ((data->nb_meals > 0) && pthread_create(&data->monit_all_full,
			NULL, &all_full_routine, data))
		return (1);
	return (0);
}

int	join_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nb_philos(data);
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if ((data->nb_meals > 0) && pthread_join(data->monit_all_full, NULL))
		return (1);
	i = 0;
	while (i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
		i++;
	}
	return (0);
}
