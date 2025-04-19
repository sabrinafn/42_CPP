NAME := Fixed

CPP := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

CPP_FILES := main.cpp Fixed.cpp Point.cpp bsp.cpp

OBJ_FILES := $(CPP_FILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CPP) $(FLAGS) -c $<

$(NAME): $(OBJ_FILES)
	$(CPP) $(FLAGS) $(OBJ_FILES) -o $(NAME)

v:
	valgrind --leak-check=full ./$(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re v