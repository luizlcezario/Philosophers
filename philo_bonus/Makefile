NAME = philo_bonus
CC = gcc
INCLUDE = -pthread -I include
CFLAGS = -Wall -Werror -Wextra -g3
SRC = init_philo_bonus.c main_bonus.c philo_bonus.c utils_bonus.c end_bonus.c monitor_bonus.c routines_bonus.c
SOURCE = $(addprefix src/, $(SRC))
OBJDIR = obj/
OBJ =  $(addprefix $(OBJDIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

$(OBJ): $(OBJDIR) $(SOURCE)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)
	mv $(notdir ,$(OBJ)) $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

test2: re
	 valgrind --tool=helgrind --history-level=approx ./$(NAME) 4 310 200 100 7

test: re
	 valgrind --tool=helgrind --history-level=approx  ./$(NAME) 4 399 200 200 7

test3: re
	 valgrind --tool=helgrind --history-level=approx ./$(NAME) 1 500 500 600

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re