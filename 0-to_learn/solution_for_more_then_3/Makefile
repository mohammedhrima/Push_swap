CC = cc
SAN = -fsanitize=address -fsanitize=undefined -g3
SRC = ""
LIB = ../Libft/libft.a
OUT = ./a.out
RM = rm -rf
msg = ""

$(OUT):
	@$(CC) $(LIB) $(SRC)
	@$(OUT)
	@$(RM) $(OUT)

all: $(OUT)

san:$(SRC)
	@$(CC) $(SAN) $(LIB) $(SRC)
	@$(OUT)
	@$(RM) $(OUT)

clean:
	@$(RM) $(OUT)

re: clean all
