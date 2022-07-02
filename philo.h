# ifndef PHILO
# define PHILO

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef pthread_mutex_t t_mutex;
typedef struct s_philo  t_philo;

typedef struct s_env
{
	int number;
	unsigned long start_time;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int times_to_eat_each;
	t_mutex mute_print;
	t_mutex *fork;
	t_philo *philo;

} t_env;

typedef struct s_philo
{
	int id;
	int meals;
	pthread_t thread;
	// t_mutex fork;
	t_mutex *right;
	t_mutex *left;
	unsigned long last_eating;
	t_env *env;

} t_philo;

// typedef struct s_env
// {
// 	t_mutex mute_print;
// 	t_philo *philo;
// } t_env;

// typedef struct s_philo
// {
// 	int number;
// 	int start_time;
// 	int time_to_die;
// 	int time_to_eat;
// 	int time_to_sleep;
// 	int times_to_eat_each;
// 	int id;
// 	int meals;
// 	pthread_t thread;
// 	t_mutex fork;
// 	t_mutex *right;
// 	t_mutex *left;
// 	unsigned long last_eating;
// 	t_env *env;

// } t_philo;





t_philo *philos_init(t_env *env);
int env_init(t_env *env, int argc, char **argv);
int	ft_atoi(const char *str);
unsigned long get_time(void);
void print_info(t_philo *philo, char *msg);

#endif