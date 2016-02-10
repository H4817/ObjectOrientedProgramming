#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("\nNumber parameters is wrong");
        return -1;
    }
    char *numb = *&argv[1];
    double A = atof(numb);
    numb = *&argv[2];
    double B = atof(numb);
    numb = *&argv[3];
    double C = atof(numb);
    double Discriminant = B * B - 4 * A * C;
    if (A == 0) {
        printf("\nError, it's a not quadratic equation");
        return -1;
    }
    if (Discriminant > 0) {
        double x1 = (-B + sqrt(Discriminant)) / (2 * A);
        double x2 = (-B - sqrt(Discriminant)) / (2 * A);
        printf("Roots of equation: %6.4f %6.4f\n", x1, x2);
    }
    else if (Discriminant == 0) {
        double x = -B / (2 * A);
        printf("Root of equation: %6.4f\n", x);
    }
    else {
        printf("\nThere is no real root");
    }
    return 0;
}
