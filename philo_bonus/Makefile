NAME		= philo_bonus
HEADER		= -I ./include/
SRCDIR		= srcs
SOURCES		= init_philo_bonus.c main_bonus.c philo_bonus.c utils_bonus.c \
			end_bonus.c monitor_bonus.c routines_bonus.c
SRCS		= $(addprefix $(SRCDIR)/, $(SOURCES))

OBJDIR		= objs
OBJS		= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

GCC			= clang
CFLAGS		= -Wall -Werror -Wextra
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

re: fclean all

.PHONY: all clean fclean re
