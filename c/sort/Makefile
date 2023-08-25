
BIN = sort

OBJECTS = main.o arrlib.o

$(BIN): $(OBJECTS)
	gcc -o $(BIN) $(OBJECTS)


*.o: $(addsuffix .c,$(basename $@))
	gcc -c $<

.PHONY = clean run

clean:
	rm -rf $(OBJECTS) $(BIN)

run: sort
	./sort
