CC = g++
CFLAGS = -g -Wall -I$(CPP_ALGLIB_HEADER) -L$(DYLD_LIBRARY_PATH) -lalgo
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
