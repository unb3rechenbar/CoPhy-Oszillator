/*
    Definiere das Newton Rapson Verfahren.
*/
void newtonrapson(Lsng* L) {
    double Sneu = (L->S[0] * L->u[1][0] - L->S[1] * L->u[0][0]) / (L->u[1][0] - L->u[0][0]);

    printf("S_0 = %g, S_1 = %g.\t lim u_1 = %g, lim u_2 = %G.\t f1 * E2 = %g, f2 * E1 = %g, Abstand = %g\n", L->S[0], L->S[1], L->u[1][0], L->u[1][0], L->S[0] * L->u[1][0], L->S[1] * L->u[0][0], L->u[1][0] - L->u[0][0]);

    L->S[0] = L->S[1];
    L->S[1] = Sneu;
}