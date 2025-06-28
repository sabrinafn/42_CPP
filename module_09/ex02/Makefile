NAME := PmergeMe

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98 -g3

CPPFILES := main.cpp PmergeMe.cpp

OBJFILES := $(CPPFILES:.cpp=.o)

all: $(NAME)

GREEN  = \033[32m
RED    = \033[31m
RESET  = \033[0m

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(NAME)

v: all
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) 9 8 7 6 5 4 3 2 1

test: all
	@echo "\n===== SUCCESSFUL TESTS ====="
	@echo "$(GREEN)Input: 3 5 9 7 4 $(RESET)"
	@./$(NAME) 3 5 9 7 4
	@echo "\n$(GREEN)Input: 42 $(RESET)"
	@./$(NAME) 42
	@echo "\n$(GREEN)Input: 100 9 8 7 6 5 4 3 2 1 $(RESET)"
	@./$(NAME) 100 9 8 7 6 5 4 3 2 1
	@echo "\n$(GREEN)Input: 1 2 3 4 5 $(RESET)"
	@./$(NAME) 1 2 3 4 5

	@echo "\n ===== 3000 ELEMENTS TEST ====="
	@echo "$(GREEN)Input: \`shuf -i 1-100000 -n 3000 | tr \"\\\n\" \" \"\` $(RESET)"
	@echo "output was redirected to the file 3000.txt"
	@./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "` > 3000.txt

	@echo "\n===== ERROR TESTS ====="
	@echo "$(RED)Input: 3 5 9 7 4 a $(RESET)"
	@./$(NAME) 3 5 9 7 4 a
	@echo "$(RED)Input: \"-1\" \"2\" $(RESET)"
	@./$(NAME) "-1" "2"
	@echo "$(RED)Input: 3 1 4 2 3 $(RESET)"
	@./$(NAME) 3 1 4 2 3
	@echo "$(RED)Input: \"\"$(RESET)"
	@./$(NAME) ""
	@echo "$(RED)Input: \"9 1 56 832 92 0 43\"$(RESET)"
	@./$(NAME) "9 1 56 832 92 0 43"
	@echo "$(RED)Input: \"\" 3 2$(RESET)"
	@./$(NAME) "" 3 2
	@echo "$(RED)Input: 42 \"\"$(RESET)"
	@./$(NAME) 42 ""

clean: 
	rm -f $(OBJFILES)
	rm -f 3000.txt

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all v clean fclean re