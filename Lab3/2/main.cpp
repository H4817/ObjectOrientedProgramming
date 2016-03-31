#include <iostream>
#include "Calculator.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Error, you have to put a filename into the command line" << endl;
        return 1;
    }
    else
    {
        CCalculator calc;
        calc.ReadFromFile(argv[1]);
        calc.SeparateInstructions();
    }
}
