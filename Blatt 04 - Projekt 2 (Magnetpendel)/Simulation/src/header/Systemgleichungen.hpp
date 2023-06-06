// Normdefinition
double pNorm(R2 v) {
    return sqrt(pow(v.x,2) + pow(v.y, 2));
}


/* 
    Definiere die Vektorkomponenten des zweidimensionalen DGPs.
*/
R2 v1(double t, Lsng* L) {
    return L->du;
}

R2 v2(double t, Lsng* L) {
    R2 u2;
    for (int i = 0; i < s; i++) {
        u2 += (L->u - Magnetorte[i]) / pow(pNorm(L->u - Magnetorte[i]), 3);
    }
    u2 /= m; // Division durch Masse
    return u2;
}

/*
    Definiere die rechte Seite. Sie ist dabei von der Form (u'(t),u''(t))\in(\R^2)^2. 
*/
dLsng F(double t, Lsng* L) {
    dLsng result;
    result.du = v1(t, L);
    result.ddu = v2(t, L);
    return result;
}