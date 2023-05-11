#include<iostream>
#include<cmath>

// Oszillatorvariablen
const double g0 = 0;
const double m0 = 1.0;
const double k0 = 1.0;
const double w = 1.0;

// Verfahrenvariablen
const int t = 50;
const double h = 0.001;
const int n = t / h;

const int s = 2;
const double Zwischenstufe = 1 / (s + 1);
const double KuttaGewichte[s] = {0.5, 0.5};
const double Abbruchkriterium = 0.01 * k0;

// Funktionsspielereien
#include "header/Funktionsspielereien.hpp"

// Verfahrenwahlvariable
int Verfahren = 0;

// Oszillatorfunktionen
double F(double t) {
    return 0;
}

double f(double x, double v, double t, double m, double gamma, double k) {
    return (F(t) - gamma * v - k * x) / m; 
}

double E(double x, double v) {
    return m0 / 2 * pow(v,2) + k0 / 2 * pow(x,2);
}


// Einschrittverfahren
#include "header/Einschritt.hpp"

// Mehrschrittverfahren
#include "header/Mehrschritt.hpp"


int main() {
    double x0 = 0;
    double v0 = 1.0;
    double x = 0;
    double v = 0;

    std :: cout << "Wähle das Verfahren (n = "<< n << ") (1) exp. Euler, (2) Runge-Kutter, (3) leap-frog, (4) Verlet Verfahren: " << std :: endl;
    std :: cin >> Verfahren;

    switch (Verfahren) {
        case 1:
            std :: cout << "Verfahren: exp. Euler" << std :: endl;
            std :: cout << 0 << " " << x0 << " " << v0 << " " << m0/2 * pow(v0,2) + 1/2 * k0 * pow(x0,2) << std :: endl;
            for (int i = 1; i < n; i++) {
                x = EulerSchrittX(x0,v0,i * h,h,m0,g0,k0);
                v = EulerSchrittV(x0,v0,i * h,h,m0,g0,k0);

                std :: cout << i * h << " " << x << " " << v << " " << E(x,v) << std :: endl;

                x0 = EulerSchrittX(x0,v0,i * h,h,m0,g0,k0);
                v0 = EulerSchrittV(x0,v0,i * h,h,m0,g0,k0);
            }
            break;
        case 2:
            std :: cout << "Verfahren: Runge-Kutter" << std :: endl;
            std :: cout << 0 << " " << x0 << " " << v0 << std :: endl;
            for (int i = 1; i < n; i++) {
                x = RungeKuttaX(x0,v0,i * h,h,m0,g0,k0);
                v = RungeKuttaV(x0,v0,i * h,h,m0,g0,k0);

                std :: cout << i * h << " " << x << " " << v << " " << E(x,v) << std :: endl;

                x0 = RungeKuttaX(x0,v0,i * h,h,m0,g0,k0);
                v0 = RungeKuttaV(x0,v0,i * h,h,m0,g0,k0);
            }
            break;
        case 3:
            std :: cout << "Verfahren: leap-frog" << std :: endl;
            std :: cout << 0 << " " << x0 << " " << v0 << std :: endl;
            for (int i = 1; i < n; i++) {
                x = leapFrogX(x0,v0,i * h,h,m0,g0,k0);
                v = leapFrogV(x0,v0,i * h,h,m0,g0,k0);

                std :: cout << i * h << " " << x << " "  << v << " " << E(x,v) << std :: endl;

                x0 = leapFrogX(x0,v0,i * h,h,m0,g0,k0);
                v0 = leapFrogV(x0,v0,i * h,h,m0,g0,k0);
            }
            break;
        case 4:
            std :: cout << "Verfahren: Verlet" << std :: endl;
            std :: cout << 0 << " " << x0 << " " << v0 << std :: endl;
            VerletVerfahren(&f,x0,v0);
            break;
        default:
            std :: cout << "Verfahren nicht gefunden" << std :: endl;
            break;
    }
    return 0;
}
