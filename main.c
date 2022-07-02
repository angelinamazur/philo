/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 15:36:26 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/02 21:11:55 by ptoshiko         ###   ########.fr       */
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
	printf("here1");

	t_philo	*philo;
	philo = (t_philo *)data;
	printf("times %d\n", philo->env->times_to_eat_each);


	// printf("id: %d", philo->id);

	// philo->meals < philo->env->times_to_eat_each || 

	if (philo->id % 2 == 1)
		ft_usleep(50);
	// while (philo->env->times_to_eat_each)
	
	// while(philo->meals < philo->env->times_to_eat_each || philo->env->times_to_eat_each == -1)
	while(1)
	{
		// printf("id philo %d", philo->id);
		// printf("fork");
		printf("philo %d wants %p\n", philo->id, philo->left);
		pthread_mutex_lock(philo->left);
		print_info(philo, "has taken a fork");
		printf("philo %d wants %p\n", philo->id, philo->right);
		pthread_mutex_lock (philo->right);
		print_info(philo, "has taken a fork");
		philo->last_eating = get_time();
		print_info(philo, "is eating");
		printf("eat-time %d\n", philo->env->time_to_eat);
		ft_usleep(philo->env->time_to_eat);
		// printf("eat-time %d\n", philo->env->time_to_eat);
		
		printf("philo %d down %p\n", philo->id, philo->left);
		pthread_mutex_unlock(philo->left);
		printf("philo %d down %p\n", philo->id, philo->right);
		pthread_mutex_unlock (philo->right);
		print_info(philo, "is sleeping");
		ft_usleep(philo->env->time_to_sleep);
		print_info(philo, "is sleeping");
		philo->meals++;
	}
	return (0);
}

void simulation(t_env *env)
{
	int i;
	i = 0;
	
	while (i < env->number)
	{
		pthread_create(&env->philo[i].thread, NULL, ft_philo, &env->philo[i]);
		// pthread_detach(env->philo[i].thread);
		i++;
	}
	i = 0;
	while(i < env->number)
	{
		pthread_join(env->philo[i].thread, NULL);
		i++;
	}
	// while (1)
	// {
	// 	// if some one is died 
	// 	// all have eaten == times_to_eat_each
	// 	while(i < env->number)
	// 	{
	// 		if(is_died(env->philo[i]))
				
	// 	}

		
	// 	i++;
	// 	if (i == philo->env->number)
	// 		i = 0;		
	// }
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
	env->philo = (t_philo *)malloc(sizeof(t_philo) * env->number);
	if(!env->philo)
		return(0);
	if(!(philos_init(env)))
		return (1);
	// // printf("env->number %d\n", env->number);
	simulation(env);
	return(0);
}