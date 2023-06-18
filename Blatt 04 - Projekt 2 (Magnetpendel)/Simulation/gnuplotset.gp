set xlabel 'x'; 
set ylabel 'y';
 
set xrange [-2:2]
set yrange [-2:2]

Magnetorte = "0 1\n0.866 -0.5\n-0.866 -0.5"

set terminal png; 

set output 'img/trcs/$(VERFAHREN)-$(STARTX)-$(STARTY)-$(STARTdX)-$(STARTdY).png'; 

plot 'Magnetorte.dat' with points pointtype 7 pointsize 1 title "Magnetorte"
plot '/tmp/data/Magnetpendel/velocityverletsol.dat' using 2:3
