# Kompiler Informationen
CC = g++
STD_CFLAGS = -g -Wall -lalgo		# Standardflags
OPT_CFLAGS = 			# Optimierungsflags

# Projektabhängige Flags
PRJ_CFLAGS = 

# Quellcode Pfade
SRC_PATH = src
OBJ_PATH = obj
BIN_PATH = bin

# Temporärer Outputpath
TMP_PATH = /tmp/data/

# Quellcode Dateien
SRC_FILES = $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES = $(patsubst $(SRC_PATH)/%.cpp, $(OBJ_PATH)/%.o, $(SRC_FILES))

# Zielpfad und Projektname
TARGET = $(BIN_PATH)/main
SUBMITNAME = PROJEKT.zip

# Remove Befehl
RM = rm

# Standard Befehl
all: $(TARGET)

# Erstelle aus den Quellcode Dateien die Objekt Dateien
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp
	@mkdir -p $(OBJ_PATH)
	$(CC) $(STD_CFLAGS) $(OPT_CFLAGS) $(PRJ_CFLAGS) -c $< -o $@

# Erstelle aus den Objekt Dateien das ausführbare Programm
$(TARGET): $(OBJ_FILES)
	@mkdir -p $(BIN_PATH)
	$(CC) $(STD_CFLAGS) $(OPT_CFLAGS) $(PRJ_CFLAGS) $(OBJ_FILES) -o $@

# --- Optionen ---

# Lösche alle Objekt Dateien und das ausführbare Programm
clean:
	$(RM) -r bin/* obj/*

# Lösche bisheriges Zip Archiv und erstelle ein neues mit der Binärdatei
submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN_PATH)

# Führe das Programm aus und erstelle ggf. den Output Ordner
run: $(TARGET)
	mkdir -p $(TMP_PATH)
	./$(TARGET)


# --- Projektspezifische Befehle ---
.PHONY gp: clean run
	gnuplot -p -e "set xlabel 'Radius'; set ylabel 'Lösung'; p '$(TMP_PATH)/numerov.dat' u 1:2 w l title 'Numerov', '$(TMP_PATH)/numerov.dat' u 1:3 w l title 'Analytisch'"