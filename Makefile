NAME = philo

SRCS =  init.c main.c ft_atoi.c time.c print.c clean_all.c philo_life.c check_args.c ft_strcmp.c

HEADER = philo.h 

OBJS = ${SRCS:%.c=%.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -g -fsanitize=thread

.PHONY : all clean fclean re

all : $(NAME)

$(NAME):	$(OBJS) $(HEADER) 
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f ${OBJS}

fclean : clean
	@rm -f $(NAME)

re : fclean all