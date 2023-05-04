// Euler Methode
double EulerSchrittX(double x, double v, double t, double dt, double m, double gamma, double k) {
    double x_neu = x + dt * v;
    return x_neu;
}
double EulerSchrittV(double x, double v, double t, double dt, double m, double gamma, double k) {
    double v_neu = v + dt * f(x, v, t, m, gamma, k);
    return v_neu;
}

// Runge-Kutter Methode
double RungeKuttaX(double x, double v, double t, double dt, double m, double gamma, double k) {
    double x_neu[s] = {0};
    for (int i = 0; i < s; i++) {
        x_neu[i] = x + KuttaGewichte[i] * dt * v;
    }
    double x_sum = 0;
    for (int i = 0; i < s; i++) {
        x_sum += KuttaGewichte[i] * x_neu[i];
    }
    return x_sum;
}
double RungeKuttaV(double x, double v, double t, double dt, double m, double gamma, double k) {
    double v_neu[s] = {0};
    for (int i = 0; i < s; i++) {
        v_neu[i] = v + KuttaGewichte[i] * dt * f(x, v, t, m, gamma, k);
    }
    double v_sum = 0;
    for (int i = 0; i < s; i++) {
        v_sum += KuttaGewichte[i] * v_neu[i];
    }
    return v_sum;
}


// leap-frog Methode
double leapFrogX(double x, double v, double t, double dt, double m, double gamma, double k) {
    double x_neu = x + (dt / 2) * v;
    double v_neu = v + dt * f(x, v, t + dt * (1/2), m, gamma, k);
    x_neu += v_neu * (dt / 2);
    return x_neu;
}
double leapFrogV(double x, double v, double t, double dt, double m, double gamma, double k) {
    double v_neu = v + dt * f(x, v, t + dt * (1/2), m, gamma, k);
    return v_neu;
}