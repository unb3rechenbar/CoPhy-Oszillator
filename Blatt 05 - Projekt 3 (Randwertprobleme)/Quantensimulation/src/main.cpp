#include <iostream>
#include <math.h>

#define H_CONST 1   // 6.62607015 * pow(10, -34)
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


void f(Lsng* L) {
    L->u[0][0] = pow(L->S[0] - 1., 3);
    L->u[1][0] = pow(L->S[1] - 1., 3);

    printf("%g -> %g\n", L->S[0], L->u[0][0]);
}


int main() {
    // printf("--- Quantensimulation ---\n");

    FILE* datei;
    datei = fopen("/tmp/data/shootingsol.dat", "w");

    Lsng L = {
        .u = {{6., 6.45645}, {6.45645, 6.45645}},
        .S = {6., 6.45645}
    };

    // printf("%g\n", L.u[0][0]);

    /*
        Löse die Systemgleichungen mithilfe der Shooting Methode.
    */
    /*
        Schritt 1: Lege ein äquidistantes Gitter über die Bedingungsfunktion und prüfe die Lagen der Nullstellen durch Vorzeichenwechsel.
    */
    const int testn = 1000;

    double testP[testn][2] = {{0., 0.}};

    for (int i = 0; i < 10; i++) {
        newton(&L);
        f(&L);
    }
 
    // for (int i = 0; i < testn; i++) {
    //     printf("p [] '-' w l\n");
    //     for (int j = 0; j < testn; j++) {
    //         printf("%g %g\n", j * 0.1, testP[j][0]);
    //     }
    //     printf("e\n");
	// 
    //     for (int j = 2; j < 100; j++) {
    //         numerovstep(j * 0.1, &L, &k);
    //     }
    //     testP[i][0] = L.S[0];
    //     testP[i][1] = L.u[0][0];
	// 
    //     L.S[0] += 0.1;
    //     printf("%g %g\n", L.S[0], L.u[0][0]);
	// 
    //     L.u[0][0] = 0.;
	// 
    //     if (i != 0 && testP[i][1] * testP[i - 1][1] < 0) {
    //         printf("Vorzeichenwechsel bei %g.\n", testP[i][0]);
    //     }
    // }

    // for (int i = 0; i < 10; i++) {
    //     if (i == 10 - 1) {
    //         for (int iu = 2; iu < 100; iu++) {
    //             numerovstep(iu * h, &L, &k);
    //             printf("%g, (%g,%g)\n", iu * h, L.u[0][0], L.u[1][0]);
    //             fprintf(datei, "%g %g\n", iu * h, L.u[0][0]);
    //         }
    //     } else {
    //         for (int iu = 2; iu < 10; iu++) {
    //             numerovstep(iu * h, &L, &k);
    //         }
    //         newton(&L);
    //     }
    // }

    fclose(datei);
    return 0;
}
