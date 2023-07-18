/*
    Definiere das Potential. 
*/
double V(double x) {
    if (x >= 0) {
        return x;
    } else {
        return INFINITY;
    }
};

/*
    Definiere die rechte Seite. 
*/
double k(double t, double S) {
    return (2 * M_CONST / pow(H_CONST, 2)) * (S - V(t));
}