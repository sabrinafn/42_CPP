NAME := Bureaucrat

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98 -g3

CPPFILES := main.cpp Bureaucrat.cpp Form.cpp

OBJFILES := $(CPPFILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(NAME)

v:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

clean: 
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all v clean fclean re