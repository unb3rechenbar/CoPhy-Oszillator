set xlabel 'x'; 
set ylabel 'y';
 
set xrange [-10:10]
set yrange [-10:10]

Magnetorte = "0 1\n0.866 -0.5\n-0.866 -0.5"

set terminal png; 

set output 'img/Farbbild.png'; 

plot 'Magnetorte.dat' with points pointtype 7 pointsize 1 title "Magnetorte"
plot '/tmp/data/Magnetpendel/konvergenz.dat' using 1:2
