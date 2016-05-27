#include <iostream>
#include <vector>

using namespace std;

template<typename T>
T ArraySum(std::vector<T> const &arr)
{
    try
    {
        T arraySum = T();
        for (auto it : arr)
        {
            arraySum += it;
        }
        return arraySum;
    }
    catch (std::exception const &e)
    {
        std::cout << e.what() << std::endl;
    }

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