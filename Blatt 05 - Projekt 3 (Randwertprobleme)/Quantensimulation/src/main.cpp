#include <iostream>
#include <math.h>

#define H_CONST pow(6.62607015, -34)
#define M_CONST 1

/*
    Initialisiere die Shooting Methode. 
*/
const double T = 100;
const double wh = 0.001;
const int n = (int) T/wh;
const double h = T/n;
const double s = 2;

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