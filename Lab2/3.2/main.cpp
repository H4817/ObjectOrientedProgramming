#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void WriteInFile(string dict, const vector <string> & changes)
{
    ofstream ofs;
    ofs.open(dict, ios_base::app);
    for (int i = 0; i < changes.size(); ++i)
    {
        if (i % 2 == 0)
        {
            ofs << changes[i] << " ";
        }
        else
        {
            ofs << changes[i] << '\n';
        }
    }
}

void AppendChanges(vector <string> & changes, bool isFileExist = 0, string dict = "dictionary.txt", string word = "")
{
    string str;
    if (isFileExist)
    {
        cin >> str;
        if (str != "...")
        {
            changes.push_back(word);
            changes.push_back(str);
        }
    }
    else
    {
        for (int i = 1; ; ++i)
        {
            cout << "Input any word and his translate: " << endl;
            cin >> str;
            if (str == "...")
            {
                if (changes.size() != 0)
                {
                    cout << "Save the file? (Y/N) ";
                    cin >> str;
                    if (str == "Y" || str == "y")
                        WriteInFile(dict, changes);
                }
                break;
            }
            changes.push_back(str);
        }
    }
}

bool IsWordInDictionary(string dict, string word)
{
    ifstream ifs;
    ifs.open(dict);
    if (!ifs.is_open())
    {
        cout << "Error, cant open file: " << dict << "\n";
        return 1;
    }
    int lengthOfWord = static_cast<int> (word.length());
    for (string str; getline(ifs, str);)
    {
        for (int i = 0; i < str.length(); ++i)
        {
            if (str.substr(static_cast<unsigned long> (i), static_cast<unsigned long> (lengthOfWord)) == word)
            {
                cout << str.substr(static_cast<unsigned long>(i + lengthOfWord), str.length() - (i + lengthOfWord)) <<
                endl;
                return true;
            }
        }
    }
    return false;
}

int MakeTranslate(string dict, vector <string> & changes)
{
    ifstream ifs;
    ifs.open(dict);
    if (!ifs.is_open())
    {
        cout << "Error, cant open file: " << dict << "\n";
        return 1;
    }
    string str;
    for (; ;)
    {
        cout << ">";
        cin >> str;
        if (str == "...")
        {
            break;
        }
        if (!IsWordInDictionary(dict, str))
        {
            AppendChanges(changes, 1, dict, str);
        }
    }
    if (changes.size() != 0)
    {
        cout << "Save the file? (Y/N) " << endl;
        cin >> str;
        if (str == "Y" || str == "y")
            WriteInFile(dict, changes);
    }

    ifs.close();
    return 0;
}

int main(int argc, char *argv[])
{
    vector<string> changes;
    if (argc != 2)
    {
        cout << "You forgot to pass some name of dictionary into the command line" << endl;
        AppendChanges(changes);
    }
    else
    {
        MakeTranslate(argv[1], changes);
    }

    return 0;
}
