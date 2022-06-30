/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:36:26 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/06/30 22:35:30 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

// int is_died(t_philo philo)
// {
// 	// calculate time 
// }

// void *ft_test(void *data)
// {
// 	printf("hi");
// 	return(0);
// }

void	ft_usleep(int time_to_wait)
{
	unsigned long	time;

	time = get_time();
	while (get_time() < time + (unsigned long)time_to_wait)
		usleep(100);
}



void *ft_philo(void *data) // pointer to one elem 
{
	t_philo	*philo;
	philo = (t_philo *)data;

	printf("id: %d", philo->id);

	if (philo->id % 2 == 1)
		ft_usleep(50);
	while(philo->meals < philo->env->times_to_eat_each || philo->env->times_to_eat_each == -1)
	// {
	// 	pthread_mutex_lock left
	// 	pthread_mutex_lock right
	// 	printf("philo %d eating",  );
	// 	usleep (time_to_eat)
	// 	pthread_mutex_unlock left
	// 	pthread_mutex_unlock right
	// 	printf("philo %d sleeping",  );
	// 	usleep (time_to_sleep);
	// 	printf("philo %d thinking",  );
	// }
	return (0);
}

void simulation(t_env *env)
{
	int i;
	i = 0;
	// pthread_t *thread;

	// thread = (pthread_t *)malloc(sizeof(pthread_t) * philo->env->number);
	// if (!thread)
	// 	return ;
	while (i < env->number)
	{
		pthread_create(&env->philo[i].thread, NULL, ft_philo, &env->philo[i]);
		pthread_detach(env->philo[i].thread);
		i++;
	}
	printf("here");
	i = 0;
	while (1)
	{
		// if some one is died 
		// all have eaten == times_to_eat_each
		while(i < philo->env->number)
		{
			if(is_died(philo[i]))
		}

		
	// 	i++;
	// 	if (i == philo->env->number)
	// 		i = 0;		
	// }
}

int main(int argc, char **argv)
{
	t_env *env;
	t_philo *philo;
	int i;

	env = malloc(sizeof(t_env));
	if(!env)
		return (0);
	i = 0;
	if(!(env_init(env, argc, argv)))
		return (1);
	philo = (t_philo *)malloc(sizeof(t_philo) * env->number);
	if(!philo)
		return(0);
	if(!(philos_init(env)))
		return (1);
	// printf("env->number %d\n", env->number);
	simulation(env);
	return(0);
}