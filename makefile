CC = g++-13
CFLAGS = -g -Wall -I /usr/local/include
SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
RM = rm

BIN = bin/main
SUBMITNAME = PROJEKT.zip

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r bin/* obj/*

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)

.PHONY gp: all
	./$(BIN) | tail -n +3 | gnuplot -p -e "plot '-'"
