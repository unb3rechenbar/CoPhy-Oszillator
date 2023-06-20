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
    .u = {0.0, 1.5},
    .du = {-15.0, 0.0}
};

/*
    Setze die Startwerte der Lösungsverfahren und importiere sie. 
*/
const double T = 200;
const double wh = 0.001;
const int n = (int) T/wh;
const double h = T/n;

// Importiere Verfahren
#include "header/Verfahren.hpp"

/*
    Initialisiere die Systemgleichungen. Definiere zunächst Magnetanzahl und Orte.
*/
const int s = 3; // Anzahl der Magnete
R2 Magnetorte[s]; // Orte der Magnete initialisieren

const double m = 1; // Masse des Pendels
const double k = 0.5; // Federkonstante
const double g = 0.2; // Dämpfungsparameter

const double z = 0.25; // Abhebung von Magnettisch

#include "header/Systemgleichungen.hpp"

/*
    Definiere das Gitter, auf welchem das Pendel simuliert werden soll, um die Konvergenzorte zu identifizieren.
*/
const int G = 500;
const int rG = 5; // Radius des Gitters
const int dG = 2*rG + 1; // Durchmesser des Gitters
const double mind = 0.001; // Mindestabstand der Konvergenzorte
int found = 0; // Flag, ob ein Konvergenzort gefunden wurde


int main() {

    printf("--- Magnetpendelsimulation ---\n");
    
    /*
        Berechne die Orte auf dem Einheitskreis iterativ.
    */
    for (int i = 0; i < s; i++) {
        Magnetorte[i].x = sin(2 * i * M_PI/s);
        Magnetorte[i].y = cos(2 * i * M_PI/s);
    }

    printf("--- Orte der Magneten ---\n");
    for (int i = 0; i < s; i++) {
        printf("Magnet %d: (%g, %g)\n", i, Magnetorte[i].x, Magnetorte[i].y);
    }

    FILE* datei;

    /*
        Löse die Systemgleichungen mithilfe von leapfrog und schreibe in die Datei "../data/leapfrogsol.dat" (LeapFrog) oder "../data/velocityverletsol.dat" (Velocity Verlet). Wähle das Verfahren aus.
    */
    printf("--- Verfahrenswahl ---\n");
    int Verfahren = 0;
    printf("Wähle das Lösungsverfahren. Wähle (1) LeapFrog, (2) VelocityVerlet, oder (3) bilde Konvergenzbild.\n");
    scanf("%d", &Verfahren);

    // Verfahren = 2;

    

    switch (Verfahren) {
        case 1: {
            datei = fopen("/tmp/data/Magnetpendel/leapfrogsol.dat", "w");

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
            datei = fopen("/tmp/data/Magnetpendel/velocityverletsol.dat", "w");

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
        case 3: {
            datei = fopen("/tmp/data/Magnetpendel/konvergenz.dat", "w");

            /*
                Nutze hier explizit keine bedingte Schleife, sodaß möglicherweise rausdriftende Lösungen nicht zu Endlosschleifen führen.
            */

            for (int i = 0; i < G - 1; i++) {
                for (int j = 0; j < G - 1; j++) {
                    // Ordne Lösungsgitter zu
                    L.u.x = (double)dG / G * i - rG;
                    L.u.y = (double)dG / G * j - rG;

                    L.du.x = 0.0;
                    L.du.y = 0.0;

                    // Speichere Startwerte
                    Lsng startL = L;

                    // Eulerstarter
                    Lsng pastL = L;
                    L.u = pastL.u + pastL.du * h/2;
                    L.du = pastL.du + F(0, &L).ddu * h/2;

                    // Iteriere über die Zeitstützen und prüfe Magnetabstände
                    for (int k = 1; k < n; k++) {
                        verletstep(k * h, &L, &pastL, F);

                        // printf("i = %d, j = %d, k = %d\n", i, j, k);

                        for (int l = 0; l < s; l++) {
                            if (pNorm(L.u - Magnetorte[l]) < mind) {
                                fprintf(datei, "%g\t%g\t%g\t%g\t%g\t%d\n", i*h, startL.u.x, startL.u.y, startL.du.x, startL.du.y, l);
                                found = 1;
                                break;
                            }
                        }
                        if (found) {
                            found = 0;
                            break;
                        }
                    }
                }
            }
            break;
        }
        default: {
            printf("Verfahren nicht definiert.\n");
            return 1;
        }
    }

    fclose(datei);
    return 0;
}