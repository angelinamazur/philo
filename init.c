/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:41:47 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/04 22:24:27 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int env_init(t_env *env, int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		env->start_time = get_time();
		env->number = ft_atoi(argv[1]);
		env->time_to_die = ft_atoi(argv[2]);
		env->time_to_eat = ft_atoi(argv[3]);
		env->time_to_sleep = ft_atoi(argv[4]);
		env->times_to_eat_each = -1;
		pthread_mutex_init(&env->mute_print, NULL);
		pthread_mutex_init(&env->mute_last_eating, NULL);
		pthread_mutex_init(&env->mute_signal, NULL);
		env->fork = (t_mutex *)malloc(sizeof(t_mutex) * env->number);
		if(!env->fork)
			return (0);
		env->philo = (t_philo *)malloc(sizeof(t_philo) * env->number);
		if(!env->philo)
			return(0);
		while(i < env->number)
		{
			pthread_mutex_init(&env->fork[i], NULL);
			i++;
		}
		if (argc == 6)
		env->times_to_eat_each = ft_atoi(argv[5]);
	if (env->number < 0 || env->time_to_die < 0 || env->time_to_eat < 0 || env->time_to_sleep < 0
		|| (env->times_to_eat_each != -1 && env->times_to_eat_each < 0))
		return (0);
	return (1);
	}
	return (0);
}

t_philo *philos_init(t_env *env)
{
	int i;
	i = 0;
	while (i < env->number)
	{
		
		env->philo[i].env = env;
		env->philo[i].last_eating = env->start_time;
		env->philo[i].signal = 0;
		env->philo[i].id = i + 1;
		env->philo[i].meals = 0;
		if (i + 1 == env->number)
		{
			env->philo[i].right = &env->fork[i];
			env->philo[i].left = &env->fork[0];
		}
		else 
		{
			env->philo[i].right = &env->fork[i];
			env->philo[i].left = &env->fork[i + 1];
		}
		i++;
	}
	return (env->philo);
}
