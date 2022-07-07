/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:11:47 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/07 21:10:44 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*cycle(t_philo	*philo)
{	
	while ((philo->meals < philo->env->times_to_eat_each && !philo->signal) || \
		(philo->env->times_to_eat_each == -1 && !philo->signal))
	{
		pthread_mutex_unlock(&philo->env->mute_signal);
		pthread_mutex_lock(philo->left);
		print_info(philo, "has taken a fork");
		if (philo->env->number == 1)
			return (NULL);
		pthread_mutex_lock (philo->right);
		print_info(philo, "has taken a fork");
		pthread_mutex_lock(&philo->env->mute_last_eating);
		philo->last_eating = get_time();
		pthread_mutex_unlock(&philo->env->mute_last_eating);
		print_info(philo, "is eating");
		ft_usleep(philo->env->time_to_eat);
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock (philo->right);
		print_info(philo, "is sleeping");
		ft_usleep(philo->env->time_to_sleep);
		print_info(philo, "is thinking");
		philo->meals++;
		pthread_mutex_lock(&philo->env->mute_signal);
	}
	return (0);
}

void	*ft_philo(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 1)
		ft_usleep(50);
	pthread_mutex_lock(&philo->env->mute_signal);
	cycle(philo);
	pthread_mutex_unlock(&philo->env->mute_signal);
	return (NULL);
}

// void	*ft_philo(void *data)
// {
// 	t_philo	*philo;

// 	philo = (t_philo *)data;
// 	if (philo->id % 2 == 1)
// 		ft_usleep(50);
// 	pthread_mutex_lock(&philo->env->mute_signal);
// 	cycle(philo);
// 	while ((philo->meals < philo->env->times_to_eat_each && !philo->signal) ||
// 		(philo->env->times_to_eat_each == -1 && !philo->signal))
// 	{
// 		pthread_mutex_unlock(&philo->env->mute_signal);
// 		pthread_mutex_lock(philo->left);
// 		print_info(philo, "has taken a fork");
// 		if (philo->env->number == 1)
// 			return (NULL);
// 		pthread_mutex_lock (philo->right);
// 		print_info(philo, "has taken a fork");
// 		pthread_mutex_lock(&philo->env->mute_last_eating);
// 		philo->last_eating = get_time();
// 		pthread_mutex_unlock(&philo->env->mute_last_eating);
// 		print_info(philo, "is eating");
// 		ft_usleep(philo->env->time_to_eat);
// 		pthread_mutex_unlock(philo->left);
// 		pthread_mutex_unlock (philo->right);
// 		print_info(philo, "is sleeping");
// 		ft_usleep(philo->env->time_to_sleep);
// 		print_info(philo, "is thinking");
// 		philo->meals++;
// 		pthread_mutex_lock(&philo->env->mute_signal);
// 	}
// 	pthread_mutex_unlock(&philo->env->mute_signal);
// 	return (NULL);
// }
