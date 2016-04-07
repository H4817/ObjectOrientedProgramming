#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

void WriteToFile(const string &dict, const vector<string> &changes)
{
    ofstream ofs;
    ofs.open(dict, ios_base::app);
    for (int i = 0; i < changes.size(); ++i)
    {
        if (i % 2 == 0)
        {
            ofs << changes[i] << "-";
        }
        else
        {
            ofs << changes[i] << '\n';
        }
    }
}

void AppendChanges(vector<string> &changes, bool isFileExist = 0, string dict = "dictionary.txt",
                   string word = "")
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
        for (; ;)
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
                        WriteToFile(dict, changes);
                }
                break;
            }
            changes.push_back(str);
        }
    }
}

bool IsWordInDictionary(const map<string, string> &dict, const string &word)
{
    bool isWordFound = false;
    auto position = dict.find(word);
    if (position != dict.end())
    {
        cout << position->second << endl;
        isWordFound = true;
    }
    return isWordFound;
}


map<string, string> CreateNewAssociatedArray(const string &dict)
{
    ifstream ifs;
    ifs.open(dict, ios_base::in);
    map<string, string> mapDictionary;
    if (!ifs.is_open())
    {
        cout << "Error, cant open file: " << dict << "\n";
    }
    else
    {
        size_t separatorPos;
        string buf;
        while (getline(ifs, buf))
        {
            separatorPos = buf.find_first_of("-");
            mapDictionary.emplace(buf.substr(0, separatorPos), buf.substr(separatorPos + 1, buf.size()));
        }
    }
    return mapDictionary;
}

int MakeTranslate(const string &dict, vector<string> &changes)
{
    map<string, string> dictMap = CreateNewAssociatedArray(dict);
    if (dictMap.size() == 0)
    {
        cout << "Error, input is wrong. Correct format: word-translate" << '\n';
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
        if (!IsWordInDictionary(dictMap, str))
        {
            AppendChanges(changes, 1, dict, str);
        }
    }
    if (changes.size() != 0)
    {
        cout << "Save the file? (Y/N) " << endl;
        cin >> str;
        if (str == "Y" || str == "y") WriteToFile(dict, changes);
    }
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
