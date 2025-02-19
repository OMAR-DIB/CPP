NAME    = trap

CC      = c++
CFLAGS  = -Wall -Wextra -Werror -std=c++98

SRC     = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp
OBJ     = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all re clean fclean