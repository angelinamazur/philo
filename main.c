/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:36:26 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/05 19:04:52 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// void	ft_usleep(int time_to_wait)
// {
// 	unsigned long	time;

// 	time = get_time();
// 	while (get_time() < time + (unsigned long)time_to_wait)
// 		usleep(100);
// }

void *ft_philo(void *data) // pointer to one elem 
{
	t_philo	*philo;
	philo = (t_philo *)data;
	if (philo->id % 2 == 1)
		ft_usleep(50);
	pthread_mutex_lock(&philo->env->mute_signal);
	while((philo->meals < philo->env->times_to_eat_each && !philo->signal)|| (philo->env->times_to_eat_each == -1 && !philo->signal))
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
	pthread_mutex_unlock(&philo->env->mute_signal);
	return (NULL);
}

void * ft_monitor (void *data)
{
	t_env	*env;
	env = (t_env *)data;
	int i;
	int j;
	
	i = 0;
	while (1)
	{
		// if (env->times_to_eat_each > 0 && env->philo[i].meals >= env->times_to_eat_each))
		// ft_usleep(10);	
		pthread_mutex_lock(&env->mute_last_eating); 
		if(env->philo[i].last_eating && get_time() - env->philo[i].last_eating > (unsigned long)env->time_to_die)
		{
			print_info(&env->philo[i], "died");
			j = 0;
			while(j < env->number)
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

void simulation(t_env *env)
{
	int i;
	pthread_t *threads;
	pthread_t monitor;
	i = 0;
	
	threads = (pthread_t *)malloc(sizeof(pthread_t) * env->number);
	if (!threads)
		return;
	
	while (i < env->number)
	{
		pthread_create(&threads[i], NULL, ft_philo, &env->philo[i]);
		i++;
	}
	pthread_create(&monitor, NULL, ft_monitor, env);
	// check here 
	
	i = 0;
	pthread_join(monitor, NULL);
	while(i < env->number)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}

int main(int argc, char **argv)
{
	t_env *env;
	int i;

	env = malloc(sizeof(t_env));
	if(!env)
		return (0);
	i = 0;
	if(!(env_init(env, argc, argv)))
		return (1);
	if(!(philos_init(env)))
		return (1);
	simulation(env);
	// while (i < env->number)
	// {
	// 	printf("count %d\n", env->philo[i].meals);
	// 	i++;
	// }
	clean_all(env);
	return(0);
}
