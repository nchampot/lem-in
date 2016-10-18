SRC = main.c errors.c reader.c ants.c get_next_line.c set_values.c room.c

OBJ = $(SRC:.c=.o)

LIB = libft/

NAME = lem-in

CC = clang

all : $(NAME)

$(NAME): $(OBJ)
	 @echo Libft compilation ...
	 @make -C $(LIB)
	 @echo Generating lem_in
	 @$(CC) $(OBJ) $(LIB)libft.a -o $(NAME) -Wall -Wextra -Werror

re : fclean all

clean :
	@rm -f $(OBJ)
	@make clean -C $(LIB)

fclean : clean
	 @rm -f $(NAME)
	 @make fclean -C $(LIB)
