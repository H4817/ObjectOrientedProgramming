#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

double CalculateDiscriminant(const double &a, const double &b, const double &c)
{
    return b * b - 4 * a * c;
}

vector<double> CalculateRootsOfEquation(const double &a, const double &b, const double &c)
{
    double discriminant = CalculateDiscriminant(a, b, c);
    vector<double> roots;
    if (a == 0)
    {
        return roots;
    }
    else if (discriminant > 0)
    {
        roots.push_back((-b + sqrt(discriminant)) / (2 * a));
        roots.push_back((-b - sqrt(discriminant)) / (2 * a));
        return roots;
    }
    else if (discriminant == 0)
    {
        roots.push_back(-b / (2 * a));
        return roots;
    }
    else
    {
        return roots;
    }
}

bool OutputResult(const double &discriminant, const double &a, vector<double> roots)
{
    if (a == 0)
    {
        cout << "Error, it's a not quadratic equation, a == 0" << endl;
        return false;
    }
    if (discriminant > 0)
    {
        cout << setprecision(4) << roots[0] << " " << roots[1] << endl;
        return true;
    }
    else if (discriminant == 0)
    {
        cout << setprecision(4) << roots[0] << endl;
        return true;
    }
    else if (discriminant < 0)
    {
        cout << "There is no real root, discriminant < 0" << endl;
        return false;
    }
    else
    {
        cout << "There is no real root, input is wrong" << endl;
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
    char *numb = argv[1];
    double a = atof(numb);
    numb = argv[2];
    double b = atof(numb);
    numb = argv[3];
    double c = atof(numb);
    double discriminant = CalculateDiscriminant(a, b, c);
    vector<double> roots = CalculateRootsOfEquation(a, b, c);
    OutputResult(discriminant, a, roots);
    return 0;
}
