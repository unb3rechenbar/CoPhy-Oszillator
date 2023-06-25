set style data points

set xrange [-6:6]
set yrange [-6:6]

set cbrange [0:5]
set palette defined (0 "red", 1 "blue", 2 "green", 3 "pink", 4 "yellow", 5 "black")

plot 'data/bartsol500-6.dat' using 2:3:6 with points palette

# Live-Update
# while (1) {
#     pause 0.1  # Wartezeit in Sekunden
#     replot
# }