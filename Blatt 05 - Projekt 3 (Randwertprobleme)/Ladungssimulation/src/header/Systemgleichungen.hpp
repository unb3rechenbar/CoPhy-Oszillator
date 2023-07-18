
/*
    Implementiere die Ladungsverteilung.
*/
double rho(double t) {
    return exp(-t)/(8 * M_PI);
}

/*
    Implementiere die rechte Seite der Differentialgleichung in zweiter Ordnung.
*/
double dF(double t, Lsng* L) {
    return -t * rho(t) / eps;
}

/*
    Implementiere die rechte Seite der Differentialgleichung in erster Ordnung.
*/
void F(double t, Lsng* L) {
    L->duO1.x = L->uO1.y;
    L->duO1.y = dF(t, L);
}