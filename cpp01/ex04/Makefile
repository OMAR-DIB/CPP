# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Executable
NAME = out

# Source Files
SRCS = main.cpp replace.cpp

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