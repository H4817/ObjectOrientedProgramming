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
            CreateNewVariable(str);
        }
        else if (str == "let")
        {
            sStream >> str;
            auto position = str.find(
                    "=");
            if (position != string::npos)
            {
                Let(str.substr(0, position), str.substr(position + 1, str.size() - position));
            }
        }
        else if (str == "fn")
        {
            sStream >> str;
            auto position = str.find(
                    "=");
            if (position != string::npos)
            {
                Fn(str.substr(0, position), str.substr(position + 1, str.size() - position));
            }
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

void CCalculator::CreateNewVariable(const string &identifier, const string &value)
{
    variables.insert(pair<string, string>(identifier, value));
}

void CCalculator::Let(string identifier, string value)
{
    auto position = variables.find(identifier);
    if (position == variables.end())
    {
        variables.insert(pair<string, string>(identifier, value));
    }
    else
    {
        if (!isdigit(value[0]) && value[0] != '-')
        {
            auto pos = variables.find(value);
            if (pos != variables.end())
            {
                position->second = pos->second;
            }
        }
        else
        {
            position->second = value;
        }
    }
}

void CCalculator::Fn(const string &identifier, const string &value1, const string &sign, const string &value2)
{
    if (sign != "" && value2 != "")
    {
        functions.insert(pair<string, string>(identifier, value2));
    }
    else
    {
        auto pos = variables.find(value1);
        if (pos != variables.end())
        {
            functions.insert(pair<string, string>(identifier, pos->second));
        }
        pos = functions.find(value1);
        if (pos != functions.end())
        {
            functions.insert(pair<string, string>(identifier, pos->second));
        }
    }
}

void CCalculator::Print(string identifier)
{
    auto position = variables.find(identifier);
    (position != variables.end()) ? cout << setprecision(2) << position->second << endl : cout << "Not found: " <<
                                                                                          identifier << endl;
}

void CCalculator::PrintVars()
{
    for (auto it = variables.begin(); it != variables.end(); ++it)
    {
        cout << it->first << ":" << setprecision(2) << it->second << endl;
    }
}


