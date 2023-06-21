set style data points

set xrange [-6:6]
set yrange [-6:6]

Magnetorte = "0 1\n0.866 -0.5\n-0.866 -0.5"

set cbrange [0:5]
set palette defined (0 "red", 1 "blue", 2 "green", 3 "pink", 4 "yellow", 5 "black")

plot 'Magnetorte.dat' with points pointtype 7 pointsize 1 title "Magnetorte"
plot '/tmp/data/Magnetpendel/konvergenz.dat' using 2:3:6 with points palette

# Live-Update
while (1) {
    pause 0.1  # Wartezeit in Sekunden
    replot
}