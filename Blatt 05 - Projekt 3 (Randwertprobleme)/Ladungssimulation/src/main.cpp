#include <iostream>
#include <math.h>

/*
    Initialisiere das Numerov Verfahren. 
*/
const double T = 15;
const double wh = 1;
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
    printf("\n--- Ladungssimulation ---\n\n -----------------------\n");

    printf("| Konfiguration:\t|\n");
    printf("|\t T = %g\t\t|\n", T);
    printf("|\t h = %g\t|\n", h);
    printf("|\t n = %d\t|\n", n);
    printf("|\t s = %d\t\t|\n", s);
    printf("|\t eps = %g\t|\n -----------------------\n\n", eps);


    FILE* datei;
    datei = fopen("/tmp/data/numerov.dat", "w");

    /*
        Löse die Systemgleichungen mithilfe des Numerov Verfahrens.
    */

    Lsng L = {
        v(T - h),
        v(T)
    };

    printf(" -------------------------------\n");
    printf("| Startwerte:\t\t\t|\n");
    printf("|\t u(T) = %g\t|\n", L.u[1]);
    printf("|\t u(T-h) = %g\t|\n -------------------------------\n\n", L.u[0]);

    printf("Programmfortschritt:\n");;

    printf("\t-> Start des Numerov Verfahrens\n");
    for (int i = 2; i < n; i++) {
        numerovstep(T - i * h, &L, &F);
        fprintf(datei, "%g %g %g %g\n", T - i * h, L.u[0], v(T - i * h), fabs(L.u[0] - v(T - i * h)));
    }
    printf("\t-> Ende des Numerov Verfahrens\n");

    fclose(datei);
    printf("\t-> Daten in /tmp/data/numerov.dat geschrieben\n");
    printf("\n--- Ende der Simulation ---\n\n");
    return 0;
}