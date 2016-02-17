#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double CalculatingDiscriminant(double &A, double &B, double &C)
{
    return B * B - 4 * A * C;
}

vector<double> CalculatingRootsOfEquation(double &A, double &B, double &C, double &Discriminant)
{
    vector<double> roots;
    if (A == 0)
    {
        return roots;
    }
    else if (Discriminant > 0)
    {
        roots.push_back((-B + sqrt(Discriminant)) / (2 * A));
        roots.push_back((-B - sqrt(Discriminant)) / (2 * A));
        return roots;
    }
    else if (Discriminant == 0)
    {
        roots.push_back(-B / (2 * A));
        return roots;
    }
    else
    {
        return roots;
    }
}

bool ToOutputResult(double &Discriminant, double &A, vector<double> roots)
{
    if (A == 0)
    {
        cout << "Error, it's a not quadratic equation" << endl;
        return false;
    }
    if (Discriminant > 0)
    {
        cout << setprecision(4) << roots[0] << " " << roots[1] << endl;
        return true;
    }
    else if (Discriminant == 0)
    {
        cout << setprecision(4) << roots[0] << endl;
        return true;
    }
    else
    {
        cout << "There is no real root" << endl;
        return false;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("\nNumber parameters is wrong");
        return -1;
    }
    char *numb = *&argv[1];
    double A = atof(numb);
    numb = *&argv[2];
    double B = atof(numb);
    numb = *&argv[3];
    double C = atof(numb);
    double discriminant = CalculatingDiscriminant(A, B, C);
    vector<double> roots = CalculatingRootsOfEquation(A, B, C, discriminant);
    ToOutputResult(discriminant, A, roots);
    return 0;
}
