#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) 
{
    bool isPartOfString = false;
    char line[255];
    int counter = 0;
    int counterLines = 1;
    vector<int> lineNumbers;
    string inputString;

    if (argc != 3) 
    {
        printf("\nNumber parameters is wrong");
        return -1;
    }

    FILE *Fin;
    Fin = fopen(argv[1], "r");
    if (Fin == NULL)
    {
        printf("\nCan not open file %s", argv[1]);
        return -1;
    }
    inputString = argv[2];

    while (fgets(line, 255, Fin) != NULL) 
    {
        string str(line);
        for (int i = 0; i < str.size(); ++i) 
        {
            if (str[i] == inputString[counter])
            {
                ++counter;
                if (counter == inputString.size())
                {
                    counter = 0;
                    if (isPartOfString) 
                    {
                        lineNumbers.push_back(counterLines - 1);
                        isPartOfString = false;
                    }
                    lineNumbers.push_back(counterLines);
                }
            }
            else
            {
                counter = 0;
                isPartOfString = false;
            }
        }
        if (counter > 0)
        {
            isPartOfString = true;
        }
        ++counterLines;
    }
    fclose(Fin);
    if (lineNumbers.size() != 0) 
    {
        if(lineNumbers[lineNumbers.size() - 1] == counterLines - 1) 
        {
            lineNumbers[lineNumbers.size() - 1] += -1;
        }
        for (int i = 0; i < lineNumbers.size(); ++i)
        {
            printf("%d\n", lineNumbers[i]);
        }
        return 0;
    }
    else 
    {
        printf("Text not found");
        return 1;
    }
}
