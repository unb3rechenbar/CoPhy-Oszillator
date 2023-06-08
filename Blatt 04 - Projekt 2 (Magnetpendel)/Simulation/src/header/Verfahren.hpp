void leapfrogstep(double t, Lsng* L, dLsng (*F)(double,Lsng*)) {
    dLsng at = F(t + h, L);
    L->du += at.ddu * h;        // Geschwindigkeit zu t + h/2
    L->u += L->du * h;          // Position zu t + h
}

void verletstep(double t, Lsng* L, Lsng* pastL, dLsng (*F)(double,Lsng*)) {
    Lsng tempL;       // Erzeuge temporäre Lösungsstruktur
    tempL.u = L->u * 2 - pastL->u + F(t, L).ddu * h * h; // Berechne Position zu t + h
    tempL.du = (tempL.u - pastL->u) / (2 * h);            // Berechne Geschwindigkeit zu t + h/2

    *pastL = *L;    // Speichere alte Lösung
    *L = tempL;     // Überschreibe alte Lösung mit neuer Lösung
}