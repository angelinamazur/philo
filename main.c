/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:36:26 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/07 20:59:12 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_monitor(void *data)
{
	t_env	*env;
	int		i;
	int		j;

	env = (t_env *)data;
	i = 0;
	while (1)
	{
		pthread_mutex_lock(&env->mute_last_eating);
		if (env->philo[i].last_eating && \
			get_time() - env->philo[i].last_eating
			> (unsigned long)env->time_to_die)
		{
			print_info(&env->philo[i], "died");
			j = 0;
			while (j < env->number)
			{
				pthread_mutex_lock(&env->mute_signal);
				env->philo[j].signal = 1;
				pthread_mutex_unlock(&env->mute_signal);
				j++;
			}
			pthread_mutex_unlock(&env->mute_last_eating);
			return (NULL);
		}
		pthread_mutex_unlock(&env->mute_last_eating);
		i++;
		if (i == env->number)
			i = 0;
	}
}

void	simulation(t_env *env)
{
	int			i;
	pthread_t	*threads;
	pthread_t	monitor;

	i = 0;
	threads = (pthread_t *)malloc(sizeof(pthread_t) * env->number);
	if (!threads)
		return ;
	while (i < env->number)
	{
		pthread_create(&threads[i], NULL, ft_philo, &env->philo[i]);
		i++;
	}
	pthread_create(&monitor, NULL, ft_monitor, env);
	i = 0;
	pthread_join(monitor, NULL);
	while (i < env->number)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}

int	main(int argc, char **argv)
{
	t_env	*env;
	int		i;

	env = malloc(sizeof(t_env));
	if (!env)
		return (0);
	i = 0;
	if (check_args(argc, argv))
	{
		free(env);
		write(1, "Error\n", 6);
		return (0);
	}
	if (!(env_init(env, argc, argv)))
	{
		free(env);
		write(1, "Error\n", 6);
		return (1);
	}
	philos_init(env);
	simulation(env);
	clean_all(env);
	return (0);
}
