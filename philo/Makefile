NAME = philo
CC = gcc
INCLUDE = -pthread -I include
CFLAGS = -Wall -Werror -Wextra
SRC = init_philo.c main.c philo.c utils.c monitor.c routines.c
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
	./$(NAME) 5 500 200 200 5

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re