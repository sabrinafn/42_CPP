NAME := phonebook

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

HPP_HEADER := phonebook.hpp contact.hpp

CPP_FILES := main.cpp phonebook.cpp contact.cpp

OBJ_FILES := $(CPP_FILES:.cpp=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $< -o $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
