EXEC = bsq
FLAGS = -Wall -Wextra -Werror
PATH_SRC = ./srcs/
SRC = $(PATH_SRC)main.c $(PATH_SRC)check.c $(PATH_SRC)ft_putstr.c $(PATH_SRC)ft_strcpy.c \
	$(PATH_SRC)ft_strlen.c $(PATH_SRC)ft_atoi.c $(PATH_SRC)error.c $(PATH_SRC)parsing.c $(PATH_SRC)sort.c
OBJ = $(SRC:.c=.o)
CC = gcc

all: $(EXEC)

$(EXEC) : $(OBJ) 
	$(CC) $(FLAGS) $(OBJ) -o $(EXEC)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(EXEC)

.PHONY: all clean fclean