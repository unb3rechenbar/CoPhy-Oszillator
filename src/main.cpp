#include<iostream>

// Oszillatorvariablen
double g0 = 0.1;
double m0 = 1;
double k0 = 1;
double w = 1;

// Verfahrenvariablen
int n = 1000;
double h = 0.1;
const int s = 2;
double Zwischenstufe = 1 / (s + 1);
double KuttaGewichte[s] = {0.5, 0.5};
double Abbruchkriterium = 0.01 * k0;

// Verfahrenwahlvariable
int Verfahren = 0;

// Ergebnisspeicher
double Ergebnisse[3][2];

// Oszillatorfunktionen
double F(double t) {
    return sin(w * t);
}

double f(double x, double v, double t, double m, double gamma, double k) {
    return (F(t) - gamma * v - k * x) / m; 
}

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


int main() {
    double x0 = 0;
    double v0 = 1;

    std :: cout << "Wähle das Verfahren (n = "<< n << ") (1) exp. Euler, (2) Runge-Kutter, (3) leap-frog: " << std :: endl;
    std :: cin >> Verfahren;

    switch (Verfahren) {
        case 1:
            std :: cout << "Verfahren: exp. Euler" << std :: endl;
            std :: cout << 0 << " " << x0 << " " << v0 << std :: endl;
            for (int i = 1; i < n; i++) {
                std :: cout << i * h << " " << " " << EulerSchrittX(x0,v0,i * h,h,m0,g0,k0) << " " << EulerSchrittV(x0,v0,i * h,h,m0,g0,k0) << std :: endl;

                x0 = EulerSchrittX(x0,v0,i * h,h,m0,g0,k0);
                v0 = EulerSchrittV(x0,v0,i * h,h,m0,g0,k0);
            }
            break;
        case 2:
            std :: cout << "Verfahren: Runge-Kutter" << std :: endl;
            std :: cout << 0 << " " << x0 << " " << v0 << std :: endl;
            for (int i = 1; i < n; i++) {
                std :: cout << i * h << " " << RungeKuttaX(x0,v0,i * h,h,m0,g0,k0) << " " << RungeKuttaV(x0,v0,i * h,h,m0,g0,k0) << std :: endl;

                x0 = RungeKuttaX(x0,v0,i * h,h,m0,g0,k0);
                v0 = RungeKuttaV(x0,v0,i * h,h,m0,g0,k0);
            }
            break;
        case 3:
            std :: cout << "Verfahren: leap-frog" << std :: endl;
            std :: cout << 0 << " " << x0 << " " << v0 << std :: endl;
            for (int i = 1; i < n; i++) {
                std :: cout << i * h << " " << leapFrogX(x0,v0,i * h,h,m0,g0,k0) << " "  << leapFrogV(x0,v0,i * h,h,m0,g0,k0) << std :: endl;

                x0 = leapFrogX(x0,v0,i * h,h,m0,g0,k0);
                v0 = leapFrogV(x0,v0,i * h,h,m0,g0,k0);
            }
            break;
        default:
            std :: cout << "Verfahren nicht gefunden" << std :: endl;
            break;
    }
    return 0;
}
