/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:41:47 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/30 22:30:54 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// unsigned long get_time(void)
// {
// 	struct timeval	tv;

// 	gettimeofday(&tv, NULL);
// 	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
// }

int env_init(t_env *env, int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		env->start_time = get_time();
		env->number = ft_atoi(argv[1]);
		env->time_to_die = ft_atoi(argv[2]) * 1000;
		env->time_to_eat = ft_atoi(argv[3]) * 1000;
		env->time_to_sleep = ft_atoi(argv[4]) * 1000;
		env->times_to_eat_each = -1;
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
		env->philo[i].id = i + 1;
		env->philo[i].meals = i;
		pthread_mutex_init(&env->philo[i].fork, NULL);
		env->philo[i].rigth = &env->philo[i].fork;
		env->philo[i].left = env->philo[i + 1].rigth;
		i++;
	}
	return (env->philo);
}


// t_philo *philos_init(t_env *env)
// {
	
// 	// t_philo *philo;
// 	int i;
	 
// 	// philo = (t_philo *)malloc(sizeof(t_philo) * env->number);
// 	// if(!philo)
// 	// 	return(0);
// 	i = 0;
// 	while (i < env->number)
// 	{
// 		env->philo[i].id = i + 1;
// 		// pthread_mutex_init(&philo[i].fork, NULL);
// 		// philo[i].rigth = &philo[i].fork;
// 		// philo[i].left = philo[i + 1].rigth;
// 		i++;
// 	}
// 	return (env->philo);
// }

// void forks_init(t_env *env)
// {
// 	int i;
	
// 	env->forks = (pthread_mutex_t *) malloc (sieof(pthread_mutex_t) * env->number);
// 	if (!env->forks)
// 		return(0);
	
// }
// philo->env.time_to_die