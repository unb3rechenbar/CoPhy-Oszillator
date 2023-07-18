struct R2{
    double x;
    double y;

    // Punktweise Multiplikation
    R2 operator*(const R2& other) const {
        R2 result;
        result.x = x * other.x;
        result.y = y * other.y;
        return result;
    }

    // Punktweise Multiplikation mit Skalar von rechts
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

    // Division durch Skalar
    R2 operator/(const double& other) const {
        R2 result;
        result.x = x / other;
        result.y = y / other;
        return result;
    }

    /*
        Definition derselben Operatoren in abgekürzter Schreibweise
    */
    void operator*=(const R2& other) {
        x *= other.x;
        y *= other.y;
    }
    void operator+=(const R2& other) {
        x += other.x;
        y += other.y;
    }
    void operator-=(const R2& other) {
        x -= other.x;
        y -= other.y;
    }
    void operator/=(const double& other) {
        x /= other;
        y /= other;
    }

    /*
        Vergleich zweier R2
    */
    bool operator==(const R2& other) const {
        return x == other.x && y == other.y;
    }
};

// Skalarprodukt auf R^2
double scpr(R2 a, R2 b) {
    return a.x * b.x + a.y * b.y;
}

// Norm auf R^2
double norm(R2 a) {
    return sqrt(scpr(a, a));
}

// pNorm auf R^2
double pNorm(R2 v) {
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}