NAME := Zombie

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

CPP_FILES := main.cpp Zombie.cpp zombieHorde.cpp

OBJ_FILES := $(CPP_FILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)

v: 
	valgrind --leak-check=full ./$(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re v
