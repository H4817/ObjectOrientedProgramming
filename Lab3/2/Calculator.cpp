#include "Calculator.h"

CCalculator::CCalculator()
        : m_operators({"+", "-", "*", "/"})
{

}

bool CCalculator::ReadFromFile(const string &nameOfFile)
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
            m_input.push_back(str);
        }
        if (m_input.size() == 0)
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
    for (int i = 0; i < m_input.size(); ++i)
    {
        stringstream sStream(m_input[i]);
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
                DoLet(str.substr(0, position), str.substr(position + 1, str.size() - position));
            }
        }
        else if (str == "fn")
        {
            sStream >> str;
            auto position = str.find(
                    "=");
            if (position != string::npos)
            {
                string subStr = str.substr(position + 1, str.size() - position);
                for (size_t i = 0; i < m_operators.size(); ++i)
                {
                    auto pos = subStr.find(m_operators[i]);
                    if (pos != string::npos)
                    {
                        Fn(str.substr(0, position), str.substr(position + 1, pos), subStr.substr(pos, 1),
                           subStr.substr(pos + 1, subStr.length() - pos));
                        break;
                    }
                }
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
            PrintFunctions();
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
    if (!IsIdentifierInVariableList(identifier) && !IsIdentifierInFunctionList(identifier))
    {
        m_variables.insert(pair<string, string>(identifier, value));
    }
    else
    {
        cout << "Error, cant create a new variable. '" << identifier << "' is already exist." << endl;
    }
}

bool CCalculator::IsIdentifierInVariableList(const string &identifier)
{
    return m_variables.find(identifier) != m_variables.end();
}

bool CCalculator::IsIdentifierInFunctionList(const string &identifier)
{
    return m_functions.find(identifier) != m_functions.end();
}

void CCalculator::DoLet(const string &identifier, const string &value)
{
    auto position = m_variables.find(identifier);
    if (position == m_variables.end())
    {
        m_variables.insert(pair<string, string>(identifier, value));
    }
    else
    {
        if (!isdigit(value[0]) && value[0] != '-')
        {
            auto pos = m_variables.find(value);
            if (pos != m_variables.end())
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
    std::map<std::string, std::string>::iterator pos1;
    std::map<std::string, std::string>::iterator pos2;
    bool isError = false;
    if (IsIdentifierInVariableList(value1))
    {
        pos1 = m_variables.find(value1);
    }
    else if (IsIdentifierInFunctionList(value1))
    {
        pos1 = m_functions.find(value1);
    }
    else
    {
        cout << "value is not found: " << value1 << endl;
        isError = true;
    }
    if (IsIdentifierInVariableList(value2))
    {
        pos2 = m_variables.find(value2);
    }
    else if (IsIdentifierInFunctionList(value2))
    {
        pos2 = m_functions.find(value2);
    }
    else
    {
        cout << "value is not found: " << value2 << endl;
        isError = true;
    }
    if (!isError)
    {
        if (sign == "+")
        {
            m_functions.insert(pair<string, string>(identifier, (to_string(
                    atof(pos1->second.c_str()) + atof(pos2->second.c_str())))));
        }
        else if (sign == "-")
        {
            m_functions.insert(pair<string, string>(identifier, (to_string(
                    atof(pos1->second.c_str()) - atof(pos2->second.c_str())))));
        }
        else if (sign == "*")
        {
            m_functions.insert(pair<string, string>(identifier, (to_string(
                    atof(pos1->second.c_str()) * atof(pos2->second.c_str())))));
        }
        else if (sign == "/")
        {
            m_functions.insert(pair<string, string>(identifier, (to_string(
                    atof(pos1->second.c_str()) / atof(pos2->second.c_str())))));
        }
    }
    else
    {
        m_functions.insert(pair<string, string>(identifier, "nan"));
    }
}

void CCalculator::Print(const string &identifier)
{
    auto position = m_variables.find(identifier);
    (position != m_variables.end()) ? cout << setprecision(2) << position->second << endl : cout << "Not found: " <<
                                                                                            identifier << endl;
}

void CCalculator::PrintVars()
{
    for (auto it = m_variables.begin(); it != m_variables.end(); ++it)
    {
        cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        cout << it->first << ":" << setprecision(2) << it->second << endl;
    }
}

void CCalculator::PrintFunctions()
{
    for (auto it = m_functions.begin(); it != m_functions.end(); ++it)
    {
        cout << it->first << ":" << setprecision(2) << atof(it->second.c_str()) << endl;
    }
}
