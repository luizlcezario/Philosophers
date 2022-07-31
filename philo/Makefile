NAME = philo
CC = clang
INCLUDE = -I include
CFLAGS = -Wall -Werror -Wextra
SRC = init_philo.c main.c philo.c
SOURCE = $(addprefix src/, $(SRC))
OBJ = $(SOURCE:.c=.o)
OBJDIR = obj/

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

$(OBJ): $(OBJDIR) $(SOURCE)
	$(CC) $(CFLAGS) $(INCLUDE) -c $(SOURCE)
	mv $(OBJ) $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re