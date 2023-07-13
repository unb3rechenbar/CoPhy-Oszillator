#include <iostream>
#include <math.h>

/*
    Initialisiere das Numerov Verfahren. 
*/
const double T = 20;
const double wh = 0.001;
const int n = (int) T/wh;
const double h = T/n;

const int s = 2; // Zu speichernde Schritte in die Vergangenheit

#include "header/Numerov.hpp"


/*
    Initialisiere die Systemgleichungen. 
*/
const double eps = 0.1;
#include "header/Systemgleichungen.hpp"

/*
    Definiere die analytische Lösung.
*/
double v(double t) {
    return -exp(-t) / (8 * M_PI * eps) * (1. + t/2.) + 1. / (4 * M_PI * eps);
}



int main() {
    printf("--- Ladungssimulation ---\n");

    FILE* datei;
    datei = fopen("/tmp/data/Ladungssimulation/numerovsol.dat", "w");

    /*
        Löse die Systemgleichungen mithilfe des Numerov Verfahrens.
    */

    Lsng L = {
        v(T - h),
        v(T)
    };

    for (int i = 2; i < n; i++) {
        numerovstep(T - i * h, &L, F);
        fprintf(datei, "%f %f\n", i * h, L.u[0]);
    }

    fclose(datei);
    return 0;
}