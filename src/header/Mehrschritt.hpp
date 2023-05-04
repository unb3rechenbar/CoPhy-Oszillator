// Ergebnisspeicher
double xErgebnisse[2];
double vErgebnisse[2];


void VerletVerfahren(double (*f)(double,double,double,double,double,double), double x0, double v0) {
    xErgebnisse[0] = x0;
    vErgebnisse[0] = v0;

    xErgebnisse[1] = x0 + h * v0 + 0.5 * pow(h,2) * f(x0,v0,0,m0,g0,k0);
    vErgebnisse[1] = v0 + 0.5 * h * (f(x0,v0,0,m0,g0,k0) + f(xErgebnisse[1],vErgebnisse[1],0,m0,g0,k0));

    double Zwischenspeicher;
    for (int i = 1;i < n;i++) {
        Zwischenspeicher = xErgebnisse[1]; // Speichere x_n in Zwischenspeicher
        xErgebnisse[1] = 2 * xErgebnisse[1] - xErgebnisse[0] + pow(h,2) * f(xErgebnisse[1],vErgebnisse[1],i * h,m0,g0,k0); // Berechne x_n+1 und Speichere in erstem Ergebnisseeintrag

        vErgebnisse[0] = vErgebnisse[1]; // Speichere v_n in nulltem Ergebnisseeintrag
        vErgebnisse[1] = (xErgebnisse[1] - xErgebnisse[0]) / (2 * h); // Berechne v_n+1 und Speichere in erstem Ergebnisseeintrag

        xErgebnisse[0] = Zwischenspeicher; // Lösche x_n-1 aus nulltem Ergebnisseeintrag und ersetze durch x_n in Zwischenspeicher

        std :: cout << i * h << " " << xErgebnisse[1] << " " << vErgebnisse[1] << std :: endl; // Gebe n-tes Ergebnis aus
    }
}
