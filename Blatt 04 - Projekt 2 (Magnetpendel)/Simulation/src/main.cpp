#include<iostream>
#include<cmath>

/*
    Führe die Grundstruktur als R^2 Tupel ein und definiere alle nötigen Operatoren der R^2 Vektoren. 
*/
struct R2{
    double x;
    double y;

    // Punktweise Multiplikation
    R2 operator*(const R2& other) const {
        R2 result;
        result.x = x * other.x;
        result.y = y * other.y;
        return result;
    }

    // Punktweise Multiplikation mit Skalar von rechts
    R2 operator*(const double& other) const {
        R2 result;
        result.x = x * other;
        result.y = y * other;
        return result;
    }


    // Punktweise Addition
    R2 operator+(const R2& other) const {
        R2 result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }

    // Punktweise Subtraktion
    R2 operator-(const R2& other) const {
        R2 result;
        result.x = x - other.x;
        result.y = y - other.y;
        return result;
    }

    // Punktweise Division
    R2 operator/(const R2& other) const {
        R2 result;
        result.x = x / other.x;
        result.y = y / other.y;
        return result;
    }

    // Division durch Skalar
    R2 operator/(const double& other) const {
        R2 result;
        result.x = x / other;
        result.y = y / other;
        return result;
    }

    /*
        Definition derselben Operatoren in abgekürzter Schreibweise
    */
    void operator*=(const R2& other) {
        x *= other.x;
        y *= other.y;
    }
    void operator+=(const R2& other) {
        x += other.x;
        y += other.y;
    }
    void operator-=(const R2& other) {
        x -= other.x;
        y -= other.y;
    }
    void operator/=(const double& other) {
        x /= other;
        y /= other;
    }
};

// Skalarprodukt auf R^2
double scpr(R2 a, R2 b) {
    return a.x*b.x + a.y*b.y;
}


/*
    Definiere die Lösungsstruktur. Sie ist dabei von der Form (u(t),u'(t))\in(\R^2)^2. 
*/
typedef struct {
    R2 u;
    R2 du;
} Lsng;
typedef struct {
    R2 du;
    R2 ddu;
} dLsng;

/*
    Initialisiere die Lösung. Beachte dabei, daß die Ortskomponente zur Geschwindigkeitskomponente um h/2 verschoben ist. Die erste Iteration übernimmt für die Geschwindigkeit also Euler. 
*/
Lsng L = {
    .u = {0.0, 0.0},
    .du = {0.0, 0.0}
};

/*
    Setze die Startwerte der Lösungsverfahren und importiere sie. 
*/
const double T = 10;
const double wh = 0.01;
const int n = (int) T/wh;
const double h = T/n;

// Importiere Verfahren
#include "header/Verfahren.hpp"

/*
    Initialisiere die Systemgleichungen. Definiere zunächst Magnetanzahl und Orte.
*/
const int s = 3; // Anzahl der Magnete
const R2 Magnetorte[s] = {{0.5,-0.5}, {0,0.5}, {-0.5,-0.5}}; // Orte der Magnete
const double m = 1; // Masse des Pendels
#include "header/Systemgleichungen.hpp"


int main() {
    printf("--- Magnetpendelsimulation ---\n");

    FILE* datei;

    /*
        Löse die Systemgleichungen mithilfe von leapfrog und schreibe in die Datei "../data/leapfrogsol.dat" (LeapFrog) oder "../data/velocityverletsol.dat" (Velocity Verlet). Wähle das Verfahren aus.
    */
    int Verfahren = 0;
    printf("Wähle das Lösungsverfahren. Wähle (1) LeapFrog, (2) VelocityVerlet.\n");
    scanf("%d", &Verfahren);

    switch (Verfahren) {
        case 1: {
            datei = fopen("./data/leapfrogsol.dat", "w");

            // leapfrog Verschiebung durch Euler initialisieren:
            L.du += F(0, &L).ddu * h/2;

            // Initiale Werte schreiben
            fprintf(datei, "0\t%g\t%g\t\t\n", L.u.x, L.u.y);
            fprintf(datei, "%g\t\t\t%g\t%g\n", h/2, L.du.x, L.du.y);
            
            for (int i = 1; i < n; i++) {
                leapfrogstep(i*h, &L, F);
                fprintf(datei, "%f\t%f\t%f\t\t\n", i*h, L.u.x, L.u.y);
                fprintf(datei, "%f\t\t\t%f\t%f\n", i * h + h/2, L.du.x, L.du.y);
            }
            break;
        }
        case 2: {
            datei = fopen("./data/velocityverletsol.dat", "w");

            // Eulerstarter
            Lsng pastL = L;
            L.u = pastL.u + pastL.du * h/2;
            L.du = pastL.du + F(0, &L).ddu * h/2;

            // Gebe initiale Werte aus
            fprintf(datei, "0\t%g\t%g\t%g\t%g\n", pastL.u.x, pastL.u.y, pastL.du.x, pastL.du.y);
            fprintf(datei, "%g\t%g\t%g\t%g\t%g\n", h, L.u.x, L.u.y, L.du.x, L.du.y);

            // Iteriere über die Zeitstützen
            for (int i = 1; i < n; i++) {
                verletstep(i*h, &L, &pastL, F);
                fprintf(datei, "%g\t%g\t%g\t%g\t%g\n", i*h, L.u.x, L.u.y, L.du.x, L.du.y);
            }
            break;
        }
        default: {
            printf("Verfahren nicht definiert.\n");
            return 1;
        }
    }

    fclose(datei);
}