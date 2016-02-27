#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> FindText(ifstream &inputFile, string &inputString)
{
    int lineCounter = 1;
    string str;
    vector<int> numbersOfStrings;
    while (getline(inputFile, str) != NULL)
    {
        if (str.find(inputString) != string::npos)
        {
            numbersOfStrings.push_back(lineCounter);
        }
        ++lineCounter;
    }
    return numbersOfStrings;
}

void OutputResult(vector<int> numbersOfStrings)
{
    for (int i = 0; i < numbersOfStrings.size(); ++i)
    {
        cout << numbersOfStrings[i] << endl;
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout <<
        "Number parameters is wrong. The first param which you should put into command line is a filename and the second is string which you want to find" <<
        endl;
        return 1;
    }
    ifstream inputFile(argv[1]);
    if (inputFile == NULL)
    {
        cout << "Can't open file " << argv[1] << endl;
        return 1;
    }
    string inputString = argv[2];
    vector<int> result = FindText(inputFile, inputString);
    if (result.size() == 0)
    {
        cout << "Text not found" << endl;
        return 1;
    }
    else
    {
        OutputResult(result);
    }
    return 0;
}
