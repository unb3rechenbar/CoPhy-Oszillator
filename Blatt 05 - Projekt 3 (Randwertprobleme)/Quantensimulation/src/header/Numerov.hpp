typedef struct {
    double u[s][d];
    double S[d]:
} Lsng;

/*
    Definiere den Numerov Schritt.
*/
void numerovstep(double t, Lsng* L, double (*k)(double,double), double (*R)(double)) {
    double un[d] = L->u[0];
    
    for (i = 0; i < d; i++) {
        L->u[0][i] = L->u[0][i] * (2 - (5. / 6.) * pow(h, 2) * pow(k(t, L->S[i]), 2)) - L->u[1][i] * (1 + (1. / 12.) * pow(h, 2) * pow(k(t - h, L->S[i]), 2)) * pow(1 + (pow(h, 2) / 12) * pow(k(t + h, L->S[i]), 2), -1);
    }

    L->u[1] = un;
}
