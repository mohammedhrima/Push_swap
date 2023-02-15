CC = cc
SAN = -fsanitize=address -fsanitize=undefined -g3
SRC = push_swap3.c
SRC2 = checker.c
LIB = ../Libft/libft.a
OUT = ./push_swap
OUT2 = ./checker
RM = rm -rf

$(OUT): $(SRC)
	@echo compilling $(SRC)
	@$(CC) $(LIB) $(SRC) -o $(OUT)

$(OUT2): $(SRC2)
	@echo compilling $(SRC2)
	@$(CC) $(LIB) $(SRC2) -o $(OUT2)

all: $(OUT)

san:$(SRC)
	@$(CC) $(SAN) $(LIB) $(SRC) -o $(OUT)

bonus:
	@$(CC) $(SAN) -g3 $(LIB) $(SRC2) -o $(OUT2)

test:
	./tester/tester_push_swap.sh 1 100

py:
	@python3 number_generator.py

clean:
	@$(RM) $(OUT) 

fclean: clean
re: clean all

#tester number_of_tests len_of_numbers
#>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
#verify compilation