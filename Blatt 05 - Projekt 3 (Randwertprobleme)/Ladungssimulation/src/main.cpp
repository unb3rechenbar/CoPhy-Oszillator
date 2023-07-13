#include <iostream>
#include <math.h>

/*
    Initialisiere das Numerov Verfahren. 
*/
const double T = 50;
const double wh = 0.01;
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
    return -exp(-t) / (8 * M_PI * eps) * (1 + t/2) + 1 / (4 * M_PI * eps);
}



int main() {
    printf("\n--- Ladungssimulation ---\n\n");

    FILE* datei;
    datei = fopen("/tmp/data/numerov.dat", "w");

    /*
        Löse die Systemgleichungen mithilfe des Numerov Verfahrens.
    */

    Lsng L = {
        v(T - h),
        v(T)
    };

    printf("-> Startwerte: u(T) = %g, u(T-h) = %g\n", L.u[1], L.u[0]);

    printf("-> Start des Numerov Verfahrens\n");
    for (int i = 2; i < n; i++) {
        numerovstep(T - i * h, &L, &F);
        fprintf(datei, "%g %g %g\n", T - i * h, L.u[0], v(T - i * h));
    }
    printf("-> Ende des Numerov Verfahrens\n");

    fclose(datei);
    printf("-> Daten in /tmp/data/numerov.dat geschrieben\n");
    printf("\n--- Ende der Simulation ---\n\n");
    return 0;
}