#pragma once


#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class CCalculator
{
public:
    CCalculator();

    bool ReadFromFile(string nameOfFile);

    bool SeparateInstructions();

    void ProcessInputData();

    void Print(string identifier);

    void PrintVars();

    void PrintFunctions();

private:
    vector <string> input;
    map <string, string> variables;
    map<string, pair<string, double>> instructions;
};

