# Shell Skript zum Aufteilen der Simulation in mehrere Threads
radius=5            # Einheiten von Zentrum aus
aufloesung=100      # Gitterbreite und -höhe

# Ermittle Anzahl der CPU Kerne
num_cores=$(nproc)

# Pfad zur bin Datei
bin_path="bin/main"

# Schleife über die Anzahl der CPU Kerne
for i in $(seq $num_cores)
do
# 	taskset -c $i $bin_path &
	./bin/main 1 2
done

# Warte auf Vervollständigung der Tasks
wait
