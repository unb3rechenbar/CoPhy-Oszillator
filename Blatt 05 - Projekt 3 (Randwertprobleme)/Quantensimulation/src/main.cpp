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

const int d = 2;    // Anzahl der Startwerte
const int s = 2;    // Anzahl der gespeicherten Lösungsiterationen
const int N = 100;

#include "header/Numerov.hpp"
#include "header/Nullstellen.hpp"


/*
    Initialisiere die Systemgleichungen. 
*/
#include "header/Systemgleichungen.hpp"



int main() {
    printf("--- Quantensimulation ---\n");

    FILE* datei;
    datei = fopen("/tmp/data/shootingsol.dat", "w");

    Lsng L = {
        .u = {{0., 0. + h}, {0., 0. + h}},
        .S = {4., 6.},
        .maxfS = {0., 0.}
    };

    printf("%g\n", L.u[0][0]);

    /*
        Löse die Systemgleichungen mithilfe der Shooting Methode.
    */


    for (int i = 0; i < 10; i++) {
        if (i == 10 - 1) {
            for (int iu = 2; iu < 100; iu++) {
                numerovstep(iu * h, &L, &k);
                printf("%g, (%g,%g)\n", iu * h, L.u[0][0], L.u[1][0]);
                fprintf(datei, "%g %g\n", iu * h, L.u[0][0]);
            }
        } else {
            for (int iu = 0; iu < 10; iu++) {
                numerovstep(iu * h, &L, &k);
            }
            newtonrapson(&L);
        }
    }

    fclose(datei);
    return 0;
}