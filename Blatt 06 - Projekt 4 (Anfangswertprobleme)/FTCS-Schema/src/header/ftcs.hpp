void ftcs(double t, Lsng* L, FILE** file) {
	printf("u(%g,0)=%g  ", t, L->ux[0]);

	for (int i = 1; i < nx - 1; i++) {
		// Werte F aus und erzeuge damit neues delta v(x) im Zeitargument
		F(t, i, L);

		// Aktualisiere v(x)(t_n + dt) als v an x zum nächsten Zeitschritt
		L->ux[i] += dt * L->dut;

		// Gibt die aktuelle Position aus
		printf("u(%g,%g)=%g  ", t, i * dx, L->ux[i]);
	}

	printf("u(%g,%g)=%g\n", t, nx * dx, L->ux[nx]);

	L->ux[0] = 0.0;
	L->ux[nt] = 0.0;
}
