# ifndef PHILO
# define PHILO

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef pthread_mutex_t t_mutex;
typedef struct s_philo  t_philo;

typedef struct s_env
{
	int number;
	int start_time;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int times_to_eat_each;
	t_mutex *forks;
	// p to global mutex printf 
	t_philo *philo;

} t_env;

typedef struct s_philo
{
	int id;
	int meals;
	pthread_t thread;
	t_env *env;
	t_mutex fork;
	t_mutex *rigth;
	t_mutex *left;
	struct timeval last_eating; 

} t_philo;



t_philo *philos_init(t_env *env);
int env_init(t_env *env, int argc, char **argv);
int	ft_atoi(const char *str);
unsigned long get_time(void);

#endif