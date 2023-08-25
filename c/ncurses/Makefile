
BIN_NAME = prog
$(BIN_NAME): main.c
	gcc -lncurses -o $(BIN_NAME) $^

.PHONY: run

run: $(BIN_NAME)
	./$(BIN_NAME)
