CC = cc
SAN = -fsanitize=address -fsanitize=undefined -g3
SRC = ""
LIB = ../../Libft/libft.a
OUT = ./a.out
RM = rm -rf
ARG = ""

$(OUT):
	@$(CC) $(LIB) $(SRC)
	@$(OUT) $(ARG)
	@$(RM) $(OUT)

all: $(OUT)

san:$(SRC)
	@$(CC) $(SAN) $(LIB) $(SRC)
	@$(OUT) $(ARG)
	@$(RM) $(OUT)
clean:
	@$(RM) $(OUT)

re: clean all
