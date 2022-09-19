NAME		= philo
HEADER		= -I ./include/
SRCDIR		= srcs
SOURCES		= main.c end.c philo.c utils.c routines.c monitor.c init_philo.c 
SRCS		= $(addprefix $(SRCDIR)/, $(SOURCES))

OBJDIR		= objs
OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

GCC			= clang
CFLAGS		= -g3 -Wall -Werror -Wextra
RM			= rm -rf
VAL			= valgrind --tool=helgrind --history-level=approx

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) 
	$(GCC) $(OBJS) $(HEADER) -o $@ -lpthread

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(GCC) -c $(CFLAGS) $(HEADER) $< -o $@

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

test: re
	./$(NAME) 4 399 200 200 7

re: fclean all

.PHONY: all clean fclean re
