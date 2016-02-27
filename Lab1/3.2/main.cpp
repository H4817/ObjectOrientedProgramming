#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const size_t AMOUNT_LINES = 3;
const size_t AMOUNT_COLUMN = 3;

double CalculateDeterminant(double matrix[AMOUNT_LINES][AMOUNT_COLUMN])
{
    double determinant = NULL;
    for (size_t i = 0; i < AMOUNT_COLUMN; ++i)
    {
        vector<double> partOfMatrix;
        for (size_t linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter)
        {
            for (size_t columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter)
            {
                if (columnCounter != i && linesCounter != 0)
                {
                    partOfMatrix.push_back(matrix[linesCounter][columnCounter]);
                    if (partOfMatrix.size() == 4)
                    {
                        double currentMinor = ((partOfMatrix[0] * partOfMatrix[3]) -
                                               (partOfMatrix[1] * partOfMatrix[2]));
                        if (i % 2 == 0)
                        {
                            determinant += (currentMinor * matrix[0][i]);
                        }
                        else
                        {
                            determinant -= (currentMinor * matrix[0][i]);
                        }
                    }
                }
            }
        }
    }
    return determinant;
}

void CalculateMatrixOfMinors(double matrix[AMOUNT_LINES][AMOUNT_COLUMN],
                             double (&matrixOfMinors)[AMOUNT_LINES][AMOUNT_COLUMN], size_t &g_linesCounter)
{
    for (size_t i = 0; i < AMOUNT_COLUMN; ++i)
    {
        vector<double> partOfMatrix;
        for (size_t linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter)
        {
            for (size_t columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter)
            {
                if (columnCounter != i && linesCounter != g_linesCounter)
                {
                    partOfMatrix.push_back(matrix[linesCounter][columnCounter]);
                    if (partOfMatrix.size() == 4)
                    {
                        matrixOfMinors[g_linesCounter][i] = ((partOfMatrix[0] * partOfMatrix[3]) -
                                                             (partOfMatrix[1] * partOfMatrix[2]));
                    }
                }
            }
        }
    }
    if (g_linesCounter < AMOUNT_LINES)
    {
        ++g_linesCounter;
        CalculateMatrixOfMinors(matrix, matrixOfMinors, g_linesCounter);
    }
}

void CalculateCofactorMatrix(double (&matrixOfMinors)[AMOUNT_LINES][AMOUNT_COLUMN])
{
    for (size_t linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter)
    {
        for (size_t columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter)
        {
            if (linesCounter % 2 == 0 && columnCounter % 2 != 0)
            {
                matrixOfMinors[linesCounter][columnCounter] = -matrixOfMinors[linesCounter][columnCounter];
            }
            else if (linesCounter % 2 != 0 && columnCounter % 2 == 0)
            {
                matrixOfMinors[linesCounter][columnCounter] = -matrixOfMinors[linesCounter][columnCounter];
            }
        }
    }
}

void CalculateTransposeCofactorMatrix(double matrixOfMinors[AMOUNT_LINES][AMOUNT_COLUMN],
                                      double (&transposeCofactorMatrix)[AMOUNT_LINES][AMOUNT_COLUMN])
{
    for (size_t linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter)
    {
        for (size_t columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter)
        {
            transposeCofactorMatrix[linesCounter][columnCounter] = matrixOfMinors[columnCounter][linesCounter];
        }
    }
}

void MultiplyMatrixByDeterminant(double (&transposeCofactorMatrix)[AMOUNT_LINES][AMOUNT_COLUMN], double determinant)
{
    for (size_t linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter)
    {
        for (size_t columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter)
        {
            transposeCofactorMatrix[linesCounter][columnCounter] *= 1 / determinant;
        }
    }
}

void OutputResult(double transposeCofactorMatrix[AMOUNT_LINES][AMOUNT_COLUMN])
{
    for (size_t linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter)
    {
        for (size_t columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter)
        {
            cout << setprecision(3) << transposeCofactorMatrix[linesCounter][columnCounter] << '\t';
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    double matrix[AMOUNT_LINES][AMOUNT_COLUMN];
    double matrixOfMinors[AMOUNT_LINES][AMOUNT_COLUMN];
    double transposeCofactorMatrix[AMOUNT_LINES][AMOUNT_COLUMN];
    size_t g_linesCounter = 0;
    ifstream inputFile(argv[1]);
    if (argc != 2)
    {
        cout << "Number parameters is wrong" << endl;
        return -1;
    }
    if (inputFile == NULL)
    {
        cout << "Can not open file " << argv[1] << endl;
        return -1;
    }
    for (size_t i = 0; i < AMOUNT_LINES; i++)
    {
        for (size_t j = 0; j < AMOUNT_COLUMN; j++)
        {
            inputFile >> matrix[i][j];
        }
    }

    double determinant = CalculateDeterminant(matrix);
    if (determinant != 0)
    {
        CalculateMatrixOfMinors(matrix, matrixOfMinors, g_linesCounter);
        CalculateCofactorMatrix(matrixOfMinors);
        CalculateTransposeCofactorMatrix(matrixOfMinors, transposeCofactorMatrix);
        MultiplyMatrixByDeterminant(transposeCofactorMatrix, determinant);
        OutputResult(transposeCofactorMatrix);
    }
    else
    {
        cout << "Impossible to create reverse matrix, determinant == 0" << endl;
        return -1;
    }

    return 0;
}
