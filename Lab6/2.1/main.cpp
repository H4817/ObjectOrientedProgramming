#include <iostream>
#include "StringStack.h"

using namespace std;

int main()
{
    CStringStack stringStack;
    auto item = stringStack.InitializeNode("test1");
    auto item1 = stringStack.Append(item, "test2");
    auto item2 = stringStack.Append(item1, "test3");
    stringStack.Print(item);
    return 0;
}