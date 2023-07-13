typedef struct {
    double u[s];
} Lsng;

/*
    Implementiere das Numerov Verfahren.
*/
void numerovstep(double t, Lsng* L, double (*F)(double, Lsng*)) {
    

    double uneu = pow(h,2) * (F(t + h, L) + 10 * F(t, L) + F(t - h, L)) / 12. + 2 * L->u[0] - L->u[1];

    L->u[1] = L->u[0];
    L->u[0] = uneu;
}
