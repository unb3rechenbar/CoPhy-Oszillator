void leapfrogstep(double t, Lsng* L, dLsng (*F)(double,Lsng*)) {
    dLsng at = F(t + h, L);
    L->du += at.ddu * h;        // Geschwindigkeit zu t + h/2
    L->u += L->du * h;          // Position zu t + h
}