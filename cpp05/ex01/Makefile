CC := c++

CPPFLAGS ?= -Wall -Wextra -Werror -std=c++98 -pedantic
LDFLAGS ?=

SRC := main.cpp \
       Bureaucrat.cpp \
       Form.cpp

OBJ := $(SRC:.cpp=.o)

HDR := Bureaucrat.hpp Form.hpp

NAME := Form

.PHONY: fclean clean re

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
