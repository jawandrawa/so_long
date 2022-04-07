SRCS =  so_long.c\
		init.c\
		moves.c\
		./gnl/get_next_line.c \
		./gnl/get_next_line_utils.c \
		errors.c \
		utils.c

OBJS = ${SRCS:.c=.o}

HDRS = so_long.h\
		get_next_line.h

NAME = so_long

cc = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror 

%.o: %.c
	$(CC) $(CFLAGS) -Ilmx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(OBJS)  -lmlx -framework OpenGL -framework Appkit -o $(NAME)


all: ${NAME}

norminette:
	norminette $(SRCS)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
