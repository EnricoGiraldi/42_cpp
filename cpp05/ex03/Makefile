CC := c++

CPPFLAGS ?= -Wall -Wextra -Werror -std=c++98 -pedantic
LDFLAGS ?= 

SRC := main.cpp \
       Bureaucrat.cpp \
       AForm.cpp \
       ShrubberyCreationForm.cpp \
       RobotomyRequestForm.cpp \
       PresidentialPardonForm.cpp \
       Intern.cpp

OBJ := $(SRC:.cpp=.o)

HDR := Bureaucrat.hpp \
       AForm.hpp \
       ShrubberyCreationForm.hpp \
       RobotomyRequestForm.hpp \
       PresidentialPardonForm.hpp \
       Intern.hpp

NAME := Intern

.PHONY: fclean clean re all

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LDFLAGS) $(OBJ) -o $@

%.o: %.cpp $(HDR)
	$(CC) $(CPPFLAGS) -c $< -o $@

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJ)

re: fclean all
