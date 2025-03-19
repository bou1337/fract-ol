NAME = fractol
SRC = draw.c init.c hook.c math.c main.c ft_free.c utils.c 
OBJ = $(SRC:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
LFLAGS =-lmlx -lX11 -lXext


all: $(NAME)


$(NAME): $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ)   $(LFLAGS) -o $(NAME)


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)


fclean: clean
	rm -f $(NAME)


re: fclean all
