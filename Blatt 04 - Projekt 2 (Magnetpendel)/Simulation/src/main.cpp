#include<iostream>
#include<cmath>

// Grundstruktur
struct R2{
    int x;
    int y;

    // Punktweise Multiplikation
    R2 operator*(const R2& other) const {
        R2 result;
        result.x = x * other.x;
        result.y = y * other.y;
        return result;
    }

    // Punktweise Multiplikation mit Skalar
    R2 operator*(const double& other) const {
        R2 result;
        result.x = x * other;
        result.y = y * other;
        return result;
    }

    // Punktweise Addition
    R2 operator+(const R2& other) const {
        R2 result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }

    // Punktweise Subtraktion
    R2 operator-(const R2& other) const {
        R2 result;
        result.x = x - other.x;
        result.y = y - other.y;
        return result;
    }

    // Punktweise Division
    R2 operator/(const R2& other) const {
        R2 result;
        result.x = x / other.x;
        result.y = y / other.y;
        return result;
    }
};

// Skalarprodukt auf R^2
double scpr(R2 a, R2 b) {
    return a.x*b.x + a.y*b.y;
}


/*
    Definiere die Lösungsstruktur. Sie ist dabei von der Form (u(t),u'(t))\in(\R^2)^2. 
*/
struct Lsng {
    R2 u;
    R2 du;
};

// Importiere Systemgleichungen
#include "header/Systemgleichungen.hpp"

// Importiere Verfahren
#include "header/Verfahren.hpp"

// Startwerte
Lsng L = {
    .u = {1, 2},
    .du = {3, 4}
};

const double T = 10;
const double wh = 0.01;
const int n = (int) T/wh;
const double h = T/n;


int main() {
    printf("Hello World\n");

    printf("c = (%d, %d)\n", c.x, c.y);
}