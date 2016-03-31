#include "Calculator.h"

CCalculator::CCalculator()
{

}

bool CCalculator::ReadFromFile(string nameOfFile)
{
    ifstream ifs(nameOfFile);
    if (!ifs.is_open())
    {
        cout << "Error, cant open the file: " << nameOfFile << endl;
        return false;
    }
    else
    {
        string str;
        while (getline(ifs, str))
        {
            input.push_back(str);
        }
        if (input.size() == 0)
        {
            cout << "Error, the input file is empty " << endl;
            return false;
        }
    }
    return true;
}

bool CCalculator::SeparateInstructions()
{
    string str;
    for (int i = 0; i < input.size(); ++i)
    {
        stringstream sStream(input[i]);
        sStream >> str;
        if (str == "var")
        {
            sStream >> str;
            variables.insert(pair<string, string>(str, "nan"));
        }
        else if (str == "let")
        {
        }
        else if (str == "fn")
        {
        }
        else if (str == "print")
        {
            sStream >> str;
            Print(str);
        }
        else if (str == "printvars")
        {
            PrintVars();
        }
        else if (str == "printfns")
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

void CCalculator::ProcessInputData()
{

}

void CCalculator::Print(string identifier)
{
    auto position = variables.find(identifier);
    if (position != variables.end())
    {
        cout << setprecision(2) << position->second << endl;
    }
}

void CCalculator::PrintVars()
{
    for (auto it = variables.begin(); it != variables.end(); ++it)
    {
        cout << it->first << ":" << setprecision(2) << it->second << endl;
    }
}

void CCalculator::PrintFunctions()
{

}