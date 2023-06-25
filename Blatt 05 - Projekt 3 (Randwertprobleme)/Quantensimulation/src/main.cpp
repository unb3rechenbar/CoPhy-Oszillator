#include <iostream>
#include <math.h>

/*
    Initialisiere die Shooting Methode. 
*/
const double T = 100;
const double wh = 0.001;
const int n = (int) T/wh;
const double h = T/n;

#include "header/Shooting.hpp"


/*
    Initialisiere die Systemgleichungen. 
*/
const int n = 1;
#include "header/Systemgleichungen.hpp"



int main() {
    printf("--- Quantensimulation ---\n");

    FILE* datei;
    datei = fopen("/tmp/data/Quantensimulation/shootingsol.dat", "w");

    /*
        Löse die Systemgleichungen mithilfe der Shooting Methode.
    */

    

    return 0;
}