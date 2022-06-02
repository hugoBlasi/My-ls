NAME	=	my_ls
CC	=	gcc
SRC	=	my_putchar.c \
		my_putcharspace.c \
		my_putnbr.c \
		my_strcmp.c \
		my_strcpy.c \
		LS.c \
		LS_A.c \
		LS_a.c \
		LS_l.c \
		LS_1.c \
		LS_r.c \
		my_putchar_.c \
		exec.c \


OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-W -Wall -Werror -Wextra

$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all	:	$(NAME)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all