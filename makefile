CC = g++
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

.PHONY gpx: all
	./$(BIN) | tail -n +3 | gnuplot -p -e "set xlabel 'Zeit'; set ylabel 'Ort'; set terminal png; set output 'LaTeX/Bilddateien/$(V)A$(A)-$(H)-$(G)-x.png'; plot '-' using 1:2"

.PHONY gpxv: all
	./$(BIN) | tail -n +3 | gnuplot -p -e "set xlabel 'Ort'; set ylabel 'Geschwindigkeit'; set terminal png; set output 'LaTeX/Bilddateien/$(V)A$(A)-$(H)-$(G)-xv.png'; plot '-' using 2:3"

.PHONY gpv: all
	./$(BIN) | tail -n +3 | gnuplot -p -e "set xlabel 'Zeit'; set ylabel 'Geschwindigkeit'; set terminal png; set output 'LaTeX/Bilddateien/$(V)A$(A)-$(H)-$(G)-v.png'; plot '-' using 1:3"

.PHONY gpe: all
	./$(BIN) | tail -n +3 | gnuplot -p -e "set xlabel 'Zeit'; set ylabel 'Energie'; set terminal png; set output 'LaTeX/Bilddateien/$(V)A$(A)-$(H)-E.png'; plot '-' using 1:4"
