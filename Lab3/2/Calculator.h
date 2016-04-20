#pragma once


#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <boost/format.hpp>

#pragma message tests
#pragma message decomposite CCalculator class
#pragma message use std::unordered_map<string, double>

using namespace std; //  remove from .h to .cpp

class CCalculator
{
public:
    CCalculator();

    bool ReadFromFile(const string &nameOfFile);

    bool SeparateInstructions();

    void ProcessInputData();

    void CreateNewVariable(const string & identifier, const string & value = "nan");

    void Print(const string & identifier);

    void PrintVars();

    void DoLet(const string &identifier, const string &value);

    //bool IsArgumentsCorrect(string identifier, string value);
    //bool IsIdentifierCorrect(string identifier);

    bool IsIdentifierInVariableList(const string & identifier);

    bool IsIdentifierInFunctionList(const string & identifier);

    void Fn(const string & identifier, const string & value1, const string & sign = "", const string & value2 = "");

    void PrintFunctions();

private:
    vector <string> m_operators;
    vector <string> m_input;
    map <string, string> m_variables; // TODO: use unordered_map
    map <string, string> m_functions;
    pair <map<string, string>, map<string, string>> m_data;
};

