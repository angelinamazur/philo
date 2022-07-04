/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptoshiko <ptoshiko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:50:11 by ptoshiko          #+#    #+#             */
/*   Updated: 2022/07/04 22:14:32 by ptoshiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_info(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->env->mute_print);
	printf("%lu %d %s\n", get_time() - philo->env->start_time, philo->id, msg);	
	pthread_mutex_unlock(&philo->env->mute_print);
}

// int print_info(t_philo *philo, char *msg)
// {
// 	int res;
// 	pthread_mutex_lock(&philo->env->mute_print);
// 	if(philo->signal == 1)
// 		res = 1;
// 	if(!philo->signal)
// 	{
// 		printf("%lu %d %s\n", get_time() - philo->env->start_time, philo->id, msg);
// 		res = 0;
// 	}
		
// 	pthread_mutex_unlock(&philo->env->mute_print);
// 	return (res);
// }