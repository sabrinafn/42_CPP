NAME := megaphone

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

CPP_FILES := megaphone.cpp

OBJ_FILES := $(CPP_FILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $< -o $(NAME)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
