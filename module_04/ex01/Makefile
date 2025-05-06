NAME := Animal

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98

CPPFILES := main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp

OBJFILES := $(CPPFILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(NAME)

v:
	valgrind --leak-check=full ./$(NAME)

clean: 
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all v clean fclean re