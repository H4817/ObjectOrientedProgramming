#include <iostream>
#include <vector>

using namespace std;

const int AMOUNT_LINES = 3;
const int AMOUNT_COLUMN = 3;

struct Data {
    double Matrix[AMOUNT_LINES][AMOUNT_COLUMN];
    double MatrixOfMinors[AMOUNT_LINES][AMOUNT_COLUMN];
    double TransposeCofactorMatrix[AMOUNT_LINES][AMOUNT_COLUMN];
    FILE *matrixFile;
    char line[255];
    double determinant;
    int linesCounter = 0;
    int columnCounter = 0;
};

void CalculatingDeterminant(Data &data) {
    for (int i = 0; i < AMOUNT_COLUMN; ++i) {
        vector<double> partOfMatrix;
        for (int linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter) {
            for (int columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter) {
                if (columnCounter != i && linesCounter != 0) {
                    partOfMatrix.push_back(data.Matrix[linesCounter][columnCounter]);
                    if (partOfMatrix.size() == 4) {
                        double currentMinor = ((partOfMatrix[0] * partOfMatrix[3]) -
                                               (partOfMatrix[1] * partOfMatrix[2]));
                        data.MatrixOfMinors[data.linesCounter][i] = currentMinor;
                        if (i % 2 == 0) {
                            data.determinant += (currentMinor * data.Matrix[data.linesCounter][i]);
                        }
                        else {
                            data.determinant -= (currentMinor * data.Matrix[data.linesCounter][i]);
                        }
                    }
                }
            }
        }
    }
    if (data.determinant == 0) {
        printf("Impossible to create reverse matrix, determinant == 0");
        exit(EXIT_FAILURE);
    }
    ++data.linesCounter;
}

void CalculatingMatrixOfMinors(Data &data) {
    for (int i = 0; i < AMOUNT_COLUMN; ++i) {
        vector<double> partOfMatrix;
        for (int linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter) {
            for (int columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter) {
                if (columnCounter != i && linesCounter != data.linesCounter) {
                    partOfMatrix.push_back(data.Matrix[linesCounter][columnCounter]);
                    if (partOfMatrix.size() == 4) {
                        data.MatrixOfMinors[data.linesCounter][i] = ((partOfMatrix[0] * partOfMatrix[3]) -
                                                                     (partOfMatrix[1] * partOfMatrix[2]));
                    }
                }
            }
        }
    }
    if (data.linesCounter < AMOUNT_LINES) {
        ++data.linesCounter;
        CalculatingMatrixOfMinors(data);
    }
}

void CalculatingCofactorMatrix(Data &data) {
    for (int linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter) {
        for (int columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter) {
            if (linesCounter % 2 == 0 && columnCounter % 2 != 0) {
                data.MatrixOfMinors[linesCounter][columnCounter] = -data.MatrixOfMinors[linesCounter][columnCounter];
            }
            else if (linesCounter % 2 != 0 && columnCounter % 2 == 0) {
                data.MatrixOfMinors[linesCounter][columnCounter] = -data.MatrixOfMinors[linesCounter][columnCounter];
            }
        }
    }
}

void CalculatingTransposeCofactorMatrix(Data &data) {
    for (int linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter) {
        for (int columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter) {
            data.TransposeCofactorMatrix[linesCounter][columnCounter] = data.MatrixOfMinors[columnCounter][linesCounter];
        }
    }
}

void MultiplyingMatrixByDeterminant(Data &data) {
    for (int linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter) {
        for (int columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter) {
            data.TransposeCofactorMatrix[linesCounter][columnCounter] *= 1 / data.determinant;
        }
    }
}

void OutputResult(Data &data) {
    for (int linesCounter = 0; linesCounter < AMOUNT_LINES; ++linesCounter) {
        for (int columnCounter = 0; columnCounter < AMOUNT_COLUMN; ++columnCounter) {
            printf("%.3f ", data.TransposeCofactorMatrix[linesCounter][columnCounter]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    Data data;
    if (argc != 2) {
        printf("\nNumber parameters is wrong");
        return -1;
    }
    data.matrixFile = fopen(argv[1], "r");
    if (data.matrixFile == NULL) {
        printf("\nCan not open file %s", argv[1]);
        return -1;
    }
    while (fgets(data.line, 255, data.matrixFile) != NULL) {
        string str(data.line);
        string buf;
        data.columnCounter = 0;
        for (int counter = 0; counter < str.size() + 5555; ++counter) {
            if (str[counter] != '\t') {
                buf += str[counter];
            }
            else {
                data.Matrix[data.linesCounter][data.columnCounter] = atof(buf.c_str());
                ++data.columnCounter;
                buf = "";
            }
        }
        ++data.linesCounter;
    }
    data.linesCounter = 0;

    CalculatingDeterminant(data);
    CalculatingMatrixOfMinors(data);
    CalculatingCofactorMatrix(data);
    CalculatingTransposeCofactorMatrix(data);
    MultiplyingMatrixByDeterminant(data);
    OutputResult(data);

    fclose(data.matrixFile);
    return 0;
}
