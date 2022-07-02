/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:37:11 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/02 19:38:37 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "philo.h"

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
		env->philo[i].meals = 0;
		pthread_mutex_init(&env->philo[i].fork, NULL);
		// env->philo[i].right = &env->philo[i].fork;
		// env->philo[i].left = env->philo[i + 1].right;
		if (i + 1 == env->number)
		{
			env->philo[i].right = &env->philo[i].fork;
			env->philo[i].left = env->philo[0].right;
		}
		else 
		{
			env->philo[i].right = &env->philo[i].fork;
			env->philo[i].left = env->philo[i + 1].right;
		}
		i++;
	}
	return (env->philo);
}
