NAME = phonebook
CC =  g++ 
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = contact.cpp phone_book.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all