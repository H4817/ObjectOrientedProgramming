#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T ArraySum(std::vector<T> const &arr)
{
    T arraySum = T();
    for (auto &item : arr)
    {
        arraySum += item;
    }
    return arraySum;
}

int main()
{
    vector<string> testVec;
    testVec.push_back("Hello");
    testVec.push_back(" friend");
    testVec.push_back(".");
    cout << ArraySum(testVec) << endl;
    return 0;
}