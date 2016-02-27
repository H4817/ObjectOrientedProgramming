#include <iostream>
#include <fstream>

using namespace std;

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
    int lineCounter = 1;
    string inputString = argv[2];
    string str;
    bool isStringFound = false;
    while (getline(inputFile, *&str) != NULL)
    {
        if (str.find(inputString) != string::npos)
        {
            cout << lineCounter << endl;
            isStringFound = true;
        }

        ++lineCounter;
    }
    if (!isStringFound)
    {
        cout << "Text not found" << endl;
        return 1;
    }
    return 0;
}
