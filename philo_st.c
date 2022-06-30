#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "philo.h"

typedef struct data
{
	t_mutex *p_mutex;
	int *num;
} t_data

typedef pthread_mutex_t t_mutex;

void *ft_test(void *data)
{
	int *num = data;
	printf("hi");
	return(0);
}

int main(int argc, char **argv)
{
	int tmp;
	pthread_t t1;
	t_mutex mutex;
	t_data data;
	data.p_mutex = &mutex;
	data.num = &tmp;

	pthread_mutex_init(&mutex, NULL);
	pthread_create(&t1, NULL, ft_test, &data);
	void *returned;
	pthread_join(t1, &returned);
	return(0);
}



// pthread_mutex_t mutex;
// void *routine()
// {
// 	printf("TEst\n");
// 	sleep(3);
// 	printf("TEst two\n");
// }

// int main(int argc, char **argv)
// {
// 	pthread_t t1, t2;
// 	if(pthread_create(&t1, NULL, &routine, NULL) != 0)
// 		return 1;
// 	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
// 		return 2;
// 	if(pthread_join(t1, NULL);
// 	pthread_join(t2, NULL);
// 	return(0);
// }

