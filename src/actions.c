/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssukhova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:28 by ssukhova          #+#    #+#             */
/*   Updated: 2024/07/03 15:17:30 by ssukhova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_sleep(t_philo *philo)
{
	set_philo_state(philo, SLEEPING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(philo->data, philo->id, SLEEP);
	ft_usleep(get_sleep_time(philo->data));
	return (0);
}

int	think(t_philo *philo)
{
	set_philo_state(philo, THINKING);
	if (get_philo_state(philo) == DEAD)
		return (1);
	print_msg(philo->data, philo->id, THINK);
	return (0);
}
