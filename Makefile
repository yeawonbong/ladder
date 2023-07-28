NAME = ladder

SRCS = ./ladder.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

clean :
	rm -f $(NAME)

re : clean all
