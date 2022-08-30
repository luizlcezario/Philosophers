NAME = philo
CC = gcc
INCLUDE = -pthread -I include
CFLAGS = -Wall -Werror -Wextra 
SRC = init_philo_bonus.c main.c philo_bonus.c utils_bonus.c \
		end_bonus.c \monitor_bonus.c routines_bonus.c
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

test: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 5 500 200 200 5


clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re