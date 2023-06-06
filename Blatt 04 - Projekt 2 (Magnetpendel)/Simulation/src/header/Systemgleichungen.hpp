double pNorm(R2* v) {
    return sqrt(pow(v->x,2) + pow(v->y, 2));
}

R2 v1(double t, Lsng* L) {
    return Lsng->du;
}

R2 v2(double t, Lsng* L) {
    R2 u2;
    for (i = 0; i<s; i++) {
        u2 += (L->u - Magnetorte[i]) / pow(pNorm(&(L->u - Magnetorte[i])), 3);
    }
    return u;
}

Lsng F(double t, Lsng* L) {
    Lsng result;
    result.u = v1(t, L);
    result.du = v2(t, L);
    return result;
}