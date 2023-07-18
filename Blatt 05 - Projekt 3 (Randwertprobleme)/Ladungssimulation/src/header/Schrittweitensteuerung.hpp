/*
    Setze die Rahmenparameter
*/
const double tol = 10e-6;
const double korr = 0.9;
const double nulld = 10e-16;
const double h_max = 0.5;
const double dh_dmpfg = 10;

const double cons_h_verf = 6;
const double inv_cons_h_verf = 1/cons_h_verf;
const double cons_u_verf = 5;

const double max_h_wied = 100;

/*
    Definiere die Vorschlagsfunktion.
*/
void adapt_h(double t, double* h_curr, Lsng* L, void (*F)(double, Lsng*)) {
    Lsng hL = *L; 
    Lsng lL = *L;
    double R;

    for (int i = 0; i < max_h_wied; i++) {
        /*
            Berechne Lösung mit Lösealgorithmus und Schrittweitealgorithmus.
        */
        numerovstep(t + (*h_curr), &hL, F);
        numerovstep(t + 2 * (*h_curr), &lL, F);

        /*
            Bestimme den Abstand der beiden Lösungen und teile ihn durch die verwendete Schrittweite -> Residuum. Bestimme dann die neue Schrittweite.
        */
        R = abs(hL.u[0] - lL.u[0]) / (*h_curr);
        printf(resid, "Zeitschritt\t\tAbstand\t\tResiduum\t\tSchrittweite\t\tVorschlag\n");
        printf(resid, "%g\t\t%g\t\t%g\t\t%g\t\t%g\n", t + (*h_curr), abs(hL.u[0] - lL.u[0]), R, *h_curr, pow(korr * tol / (R + nulld), inv_cons_h_verf) * (*h_curr));
        *h_curr = fmin(fmin(h_max, dh_dmpfg * (*h_curr)), pow(korr * tol / (R + nulld), inv_cons_h_verf) * (*h_curr));

        /*
            Breche ab, wenn die Schrittweite klein genug gewählt ist.
        */
        if (R < tol) {
            break;
        }
    }
}