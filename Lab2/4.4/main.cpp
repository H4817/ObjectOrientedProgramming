#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <cmath>

std::set<int> GeneratePrimeNumbersSet(int upperBound)
{
    std::set<int> result;
    std::vector<bool> numbers(upperBound);
    for (int i = 2; (i * i) <= upperBound; ++i)
        if (!numbers[i])
            for (int j = (i * i); j <= upperBound; j += i)
                if (!numbers[j])
                    numbers[j] = true;

    for (int k = 1; k <= upperBound; ++k)
        if (!numbers[k])
            result.insert(k);

    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Parameter numbers is wrong." << std::endl;
        return -1;
    }
    std::set<int> result = GeneratePrimeNumbersSet(atoi(argv[1]));
    std::set<int>::iterator iter;
    for (iter = result.begin(); iter != result.end(); ++iter)
    {
        printf("%d\n", *iter);
    }
    return 0;
}
