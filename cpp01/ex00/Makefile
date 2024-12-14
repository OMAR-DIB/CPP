# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable
NAME = zombie

# Source Files
SRCS = main.cpp zombie.cpp newZombie.cpp randomChump.cpp

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Build Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all