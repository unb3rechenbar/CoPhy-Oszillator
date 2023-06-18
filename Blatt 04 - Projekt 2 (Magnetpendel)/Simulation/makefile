CC = g++
CFLAGS = -g -Wall
SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))
RM = rm

BIN = bin/main
SUBMITNAME = PROJEKT.zip

TMP = /tmp/data/Magnetpendel

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

run: $(BIN)
	mkdir -p $(TMP)
	./$(BIN)

.PHONY gpxy: run
	gnuplot -e "set xlabel 'x'; set ylabel 'y'; set xrange [-2:2]; set yrange [-2:2]; set terminal png; set output 'img/trcs/$(VERFAHREN)-$(STARTX)-$(STARTY)-$(STARTdX)-$(STARTdY).png'; plot 'Magnetorte.dat' with points pointtype 7 pointsize 1 title 'Magnetorte', '$(TMP)/velocityverletsol.dat' using 2:3 title 'Trajektorie'"
