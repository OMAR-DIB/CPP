NAME = be
VAR_FILE = Hello_shrubbery

SRCS =  main.cpp					\
		core/Bureaucrat.cpp 		\
		core/Form.cpp				\
		core/RobotomyRequestForm.cpp \
		core/PresidentialPardonForm.cpp \
		core/ShrubberyCreationForm.cpp \
		core/Intern.cpp \

OBJDIR = objs
OBJCS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJDIR): 
	mkdir -p $(OBJDIR)

$(NAME): 	$(OBJDIR) $(OBJCS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJCS)

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJCS)
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(VAR_FILE)

re: fclean all

.PHONY: all clean fclean re