NAME := btc

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98 -g3

CPPFILES := main.cpp BitcoinExchange.cpp

OBJFILES := $(CPPFILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(NAME)

v: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) input.txt

clean: 
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all v clean fclean re