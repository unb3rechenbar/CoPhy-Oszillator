typedef struct {
    double u[d][s];
    double S[d];
} Lsng;

/*
    Definiere den Numerov Schritt.
*/
void numerovstep(double t, Lsng* L, double (*k)(double,double)) {
    double uneu[d] = {0., 0.};
    
    /*
        Löse die DGL per Numerov für alle d Startwerte.
    */
    for (int i = 0; i < d; i++) {
        uneu[i] = (L->u[i][0] * (2 - 5./6.  * pow(h, 2) * pow(k(t, L->S[i]), 2)) - L->u[i][1] * (1 + (pow(h, 2) / 12.) * pow(k(t - h, L->S[i]), 2))) * pow(1 + pow(h, 2) / 12. * pow(k(t + h, L->S[i]), 2), -1);
    }
    // printf("u0 = %g u1 = %g\n", L->u[0][0], L->u[1][0]);

    // 0 -> u(t_n), 1 -> u(t_n-1)
    L->u[0][1] = L->u[0][0];    // Erster Startwert, n-1er Wert wird zu ntem Wert
    L->u[0][0] = uneu[0];       // Erster Startwert, nter Wert wird zu neuem Wert
    L->u[1][1] = L->u[1][0];    // Zweiter Startwert, n-1er Wert wird zu ntem Wert
    L->u[1][0] = uneu[1];       // Zweiter Startwert, nter Wert wird zu neuem Wert
}
