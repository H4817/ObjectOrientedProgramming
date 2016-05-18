#include <iostream>
#include "HttpUrl.h"

using namespace std;


void PrintInformationAboutUrl(const CHttpUrl &cHttpUrl)
{
    cout << "Domain: " << cHttpUrl.GetDomain() << endl;
    cout << "Port: " << cHttpUrl.GetPort() << endl;
    cout << "Document: " << cHttpUrl.GetDocument() << endl;
    cout << "Protocol: " << cHttpUrl.GetProtocol() << endl;
    cout << "Url: " << cHttpUrl.GetURL() << endl;
}

void WorkWithUser()
{
    cout << "Type some commands or press q for exit" << endl;
    string str;
    for (; ;)
    {
        cout << "> ";
        cin >> str;
        if (str == "q")
        {
            break;
        }
        else
        {
            CHttpUrl cHttpUrl(str);
            PrintInformationAboutUrl(cHttpUrl);
        }
    }
}

int main()
{
    WorkWithUser();
  //  CHttpUrl cHttpUrl("https://www.test.com:211/image/img.png");

    return 0;
}