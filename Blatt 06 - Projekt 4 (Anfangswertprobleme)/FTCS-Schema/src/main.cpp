#include<stdio.h>
#include<math.h>

const int T = 1;
const double wdt = 0.001;
const double wdx = 0.001;

const int nt = (int) T / wdt;
const int nx = (int) T / wdx;
const double dt = T / nt;
const double dx = T / nx;


typedef struct {
    double ux[nx];
    double ut;
	double dut;
} Lsng;

/*
    Initialisiere Systemgleichungen.
*/
const double D = 0.1;
const double x0 = 0.5;
const double sig = 0.02;

#include "header/sysDGL.hpp"


/*
    Initialisiere forward-time-centered-space Schema.
*/
#include "header/ftcs.hpp"



int main() {
	FILE* file;
	fopen("/tmp/data/dispersion.dat", "w");

	Lsng L = {
		{0.0},
		0.0,
		0.0
	};

	for (int i = 0; i < nx; i++) {
		L.ux[i] = w(i * dx);
	}

	for (int j = 0; j < nt; j++) {
		ftcs(j * dt, &L, &file);
	}

	fclose(file);
	return 0;
}
