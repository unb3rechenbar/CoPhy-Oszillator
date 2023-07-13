
/*
    Implementiere die Ladungsverteilung.
*/
double rho(double t) {
    return exp(-t)/(8 * M_PI);
}

/*
    Implementiere die rechte Seite der Differentialgleichung.
*/
double F(double t, Lsng* L) {
    return -t * rho(t) / eps;
}
