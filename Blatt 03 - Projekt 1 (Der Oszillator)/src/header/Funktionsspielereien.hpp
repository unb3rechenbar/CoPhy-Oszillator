// Weierstraß Funktion
// f(x) = sum(0,inf) (a^k * cos(2*pi*b^k*x)) mit k = 0,1,2,3,...

int kmax = 100;
double Weierstraß(double t, double a, double b) {
    double sum = 0;
    for (int k = 0; k < kmax; k++) {
        sum += pow(a,k) * cos(2 * M_PI * pow(b,k) * t);
    }
    return sum;
}