CC = cc
SAN = -fsanitize=address -fsanitize=undefined -g3
SRC = push_swap.c
LIB = ../Libft/libft.a
OUT = ./push_swap
RM = rm -rf

$(OUT):
	@echo compilling $(SRC)
	@$(CC) $(LIB) $(SRC) -o $(OUT)

all: $(OUT)

san:$(SRC)
	@$(CC) $(SAN) $(LIB) $(SRC) -o $(OUT)

checker:


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