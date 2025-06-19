NAME := RPN

CC := c++

FLAGS := -Wall -Wextra -Werror -std=c++98 -g3

CPPFILES := main.cpp RPN.cpp

OBJFILES := $(CPPFILES:.cpp=.o)

all: $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $<

$(NAME): $(OBJFILES)
	$(CC) $(FLAGS) $(OBJFILES) -o $(NAME)

v:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

test: $(NAME)
	@echo "\n===== TESTS ====="
	@echo "Test 1: 3 4 +"
	@./$(NAME) "3 4 +"
	@echo "Test 2: 3 4 2 * +"
	@./$(NAME) "3 4 2 * +"
	@echo "Test 3: 3 + (should error)"
	@./$(NAME) "3 +"
	@echo "Test 4: 3 0 / (division by zero)"
	@./$(NAME) "3 0 /"
	@echo "Test 5: Invalid token"
	@./$(NAME) "3 & 4 +"
	@echo "Test 6: Missing operator"
	@./$(NAME) "3 4"
	@echo "Test 7: Complex expression"
	@./$(NAME) "7 2 - 3 1 + *"
	@echo "Test 8: Empty input"
	@./$(NAME) ""
	@echo "Test 9: Extra operator"
	@./$(NAME) "3 4 + +"
	@echo "Test 10: Single number"
	@./$(NAME) "42"
		@echo "Test 1: Simple addition"
	@./$(NAME) "5 9 +"
	@echo "Test 2: Simple subtraction"
	@./$(NAME) "10 4 -"
	@echo "Test 3: Simple multiplication"
	@./$(NAME) "6 7 *"
	@echo "Test 4: Simple division"
	@./$(NAME) "20 4 /"
	@echo "Test 5: Combined operations"
	@./$(NAME) "5 1 2 + 4 * + 3 -"
	@echo "Test 6: Nested operations"
	@./$(NAME) "3 5 8 * 7 + *"
	@echo "Test 7: Complex expression"
	@./$(NAME) "4 2 + 3 5 1 - * +"
	@echo "Test 8: Single number (identity)"
	@./$(NAME) "99"
	@echo "Test 9: Division with parenthesis equivalent"
	@./$(NAME) "8 4 2 - / 3 +"
	@echo "Test 10: Chain addition"
	@./$(NAME) "1 2 + 3 + 4 +"
	@echo "Test 11: Chain subtraction"
	@./$(NAME) "10 2 - 3 -"
	@echo "Test 12: Chain multiplication"
	@./$(NAME) "2 3 * 4 *"
	@echo "Test 13: Large numbers"
	@./$(NAME) "10000 10000 *"
	@echo "Test 14: Missing operator (should error)"
	@./$(NAME) "3 4"
	@echo "Test 15: Not enough operands (should error)"
	@./$(NAME) "1 +"
	@echo "Test 16: No operands, only operator (should error)"
	@./$(NAME) "+"
	@echo "Test 17: Extra operator (should error)"
	@./$(NAME) "3 4 + +"
	@echo "Test 18: Division by zero (should error)"
	@./$(NAME) "3 0 /"
	@echo "Test 19: Invalid token (should error)"
	@./$(NAME) "3 4 & +"
	@echo "Test 20: Invalid character (should error)"
	@./$(NAME) "4 5 a +"
	@echo "Test 21: Empty input (should error)"
	@./$(NAME) ""
	@echo "Test 22: Only spaces (should error)"
	@./$(NAME) "    "


clean: 
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all v clean fclean re