SRC = main.c errors.c reader.c init.c get_next_line.c

OBJ = $(SRC:.c=.o)

LIB = libft/

NAME = lem_in

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
