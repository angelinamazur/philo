NAME = philo

SRCS =  init.c main.c ft_atoi.c ft_get_time.c print.c

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