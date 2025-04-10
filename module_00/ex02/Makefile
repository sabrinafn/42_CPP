NAME := account

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

HPP_HEADER := account.hpp

CPP_FILES := tests.cpp Account.cpp

OBJ_FILES := $(CPP_FILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)

run: $(NAME)
	./$(NAME) > output.log

clean:
	rm -f $(OBJ_FILES)
	rm -f output.log

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re run
