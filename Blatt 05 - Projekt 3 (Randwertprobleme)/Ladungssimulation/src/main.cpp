#include <iostream>
#include <math.h>

/*
    Initialisiere das Numerov Verfahren. 
*/
const double T = 100;
const double wh = 0.001;
const int n = (int) T/wh;
const double h = T/n;

#include "header/Numerov.hpp"


/*
    Initialisiere die Systemgleichungen. 
*/

#include "header/Systemgleichungen.hpp"



int main() {
    printf("--- Ladungssimulation ---\n");

    FILE* datei;
    datei = fopen("/tmp/data/Ladungssimulation/numerovsol.dat", "w");

    /*
        Löse die Systemgleichungen mithilfe des Numerov Verfahrens.
    */


    return 0;
}