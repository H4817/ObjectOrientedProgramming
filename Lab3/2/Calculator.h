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

    void CreateNewVariable(const string & identifier, const string & value = "nan");

    void Print(string identifier);

    void PrintVars();

    void Let(string identifier, string value);

    bool IsArgumentsCorrect(string identifier, string value);

    void Fn(const string & identifier, const string & value1, const string & sign = "", const string & value2 = "");

    void PrintFunctions();

private:
    vector <string> input;
    map <string, string> variables;
    map <string, string> functions;
};

