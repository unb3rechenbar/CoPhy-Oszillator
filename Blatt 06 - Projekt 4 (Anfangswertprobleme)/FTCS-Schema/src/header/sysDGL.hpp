double w(double x) {
	return exp(-pow(x - x0, 2) / pow(2 * sig, 2));
}


void F(double t, int x_ind, Lsng *L) {
	L->dut = D * (L->ux[x_ind + 1] - 2 * L->ux[x_ind] + L->ux[x_ind - 1]);
}
