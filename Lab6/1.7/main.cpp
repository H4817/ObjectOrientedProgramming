#include <iostream>
#include "HttpUrl.h"

using namespace std;

int main()
{
    CHttpUrl cHttpUrl("http://www.google.com:72");
    cout << cHttpUrl.GetDomain() << endl;
    cout << cHttpUrl.GetPort() << endl;
    return 0;
}