NAME=ldynarray.a

CC=gcc
FLAGS=-Wall -Werror -Wextra

LIB_PATH=../libft/
LIB=$(LIB_PATH)libft.a

INC=dynarray.h\
	../libft/libft.h

SRCS=dynarray.c

OBJS=$(SRCS:.c=.o)

all: $(LIB) $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) $(LIB)
	ranlib $(NAME)

$(LIB):
	make -C $(LIB_PATH)

%.o: %.c $(INC)
	$(CC) $(FLAGS) -I $(LIB_PATH) $(LIB) -c $<

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
