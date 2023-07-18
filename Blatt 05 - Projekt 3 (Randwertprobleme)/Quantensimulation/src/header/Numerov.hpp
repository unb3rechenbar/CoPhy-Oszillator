typedef struct {
    double u[s][d];
    double S[d];
    double maxfS[d];
} Lsng;

/*
    Definiere den Numerov Schritt.
*/
void numerovstep(double t, Lsng* L, double (*k)(double,double)) {
    Lsng L_save = *L;
    
    /*
        Löse die DGL per Numerov für alle d Startwerte.
    */
    for (int i = 0; i < d; i++) {
        L->u[i][0] = ((2 * L->u[1][i] - L->u[1][i] * pow(h, 2) * pow(k(t, L->S[i]), 2)) - L->u[1][i] * (1 + pow(h, 2) / 12. * pow(k(t - h, L->S[i]), 2))) * pow(1 + pow(h, 2) / 12. * pow(k(t + h, L->S[i]), 2), -1);
    }

    L->u[0][1] = L_save.u[0][0];
    L->u[1][1] = L_save.u[1][0];
}
