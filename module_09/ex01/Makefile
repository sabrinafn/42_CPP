NAME := RPN

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98 -g3

CPPFILES := main.cpp RPN.cpp

OBJFILES := $(CPPFILES:.cpp=.o)

all: $(NAME)

GREEN  = \033[32m
RED    = \033[31m
RESET  = \033[0m


%.o: %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(NAME)

v:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

test: all
	@echo "\n===== SUCCESSFUL TESTS ====="
	@echo "$(GREEN)Input: \"3 4 +\"$(RESET)"
	@./$(NAME) "3 4 +"
	@echo "$(GREEN)Input: \"3 4 2 * +\"$(RESET)"
	@./$(NAME) "3 4 2 * +"
	@echo "$(GREEN)Input: \"7 2 - 3 1 + *\"$(RESET)"
	@./$(NAME) "7 2 - 3 1 + *"
	@echo "$(GREEN)Input: \"5 9 +\"$(RESET)"
	@./$(NAME) "5 9 +"
	@echo "$(GREEN)Input: \"6 7 *\"$(RESET)"
	@./$(NAME) "6 7 *"
	@echo "$(GREEN)Input: \"5 1 2 + 4 * + 3 -\"$(RESET)"
	@./$(NAME) "5 1 2 + 4 * + 3 -"
	@echo "$(GREEN)Input: \"3 5 8 * 7 + *\"$(RESET)"
	@./$(NAME) "3 5 8 * 7 + *"
	@echo "$(GREEN)Input: \"4 2 + 3 5 1 - * +\"$(RESET)"
	@./$(NAME) "4 2 + 3 5 1 - * +"
	@echo "$(GREEN)Input: \"8 4 2 - / 3 +\"$(RESET)"
	@./$(NAME) "8 4 2 - / 3 +"
	@echo "$(GREEN)Input: \"1 2 + 3 + 4 +\"$(RESET)"
	@./$(NAME) "1 2 + 3 + 4 +"
	@echo "$(GREEN)Input: \"2 3 * 4 *\"$(RESET)"
	@./$(NAME) "2 3 * 4 *"

	@echo "\n===== ERROR TESTS ====="
	@echo "$(RED)Input: \"10000 10000 *\"$(RESET)"
	@./$(NAME) "10000 10000 *"
	@echo "$(RED)Input: \"10 2 - 3 -\"$(RESET)"
	@./$(NAME) "10 2 - 3 -"
	@echo "$(RED)Input: \"42\"$(RESET)"
	@./$(NAME) "42"
	@echo "$(RED)Input: \"3 +\"$(RESET)"
	@./$(NAME) "3 +"
	@echo "$(RED)Input: \"3 4 + +\"$(RESET)"
	@./$(NAME) "3 4 + +"
	@echo "$(RED)Input: \"1 +\"$(RESET)"
	@./$(NAME) "1 +"
	@echo "$(RED)Input: \"3 4\"$(RESET)"
	@./$(NAME) "3 4"
	@echo "$(RED)Input: \"+ -\"$(RESET)"
	@./$(NAME) "+ -"
	@echo "$(RED)Input: \"3 0 /\"$(RESET)"
	@./$(NAME) "3 0 /"
	@echo "$(RED)Input: \"3 4 & +\"$(RESET)"
	@./$(NAME) "3 4 & +"
	@echo "$(RED)Input: \"4 5 a +\"$(RESET)"
	@./$(NAME) "4 5 a +"
	@echo "$(RED)Input: \"\"$(RESET)"
	@./$(NAME) ""
	@echo "$(RED)Input: \"    \"$(RESET)"
	@./$(NAME) "    "


clean: 
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all v clean fclean re