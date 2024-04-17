#include <iostream>
#include "test.h"
#include "word_search.h"
using namespace std;

int main(int argc, char **argv) {

    char **arr = nullptr;
    ifstream wordFile;
    ifstream gridFile;
    int numRows = 0;
    int numCols = 0;
    string output;
    if (argc < 3) {
        cout << "Please specify filename on command line\n";
        cout << "Format: ./word_search <grid file name> <word list file name>\n";
        exit(1);
    }
    wordFile.open(argv[2]);
    if (wordFile.fail()) {
        cout << "Failed to open file\n";
        exit(1);
    }

    count(argv[1], gridFile, numRows, numCols);

    arr = new char *[numRows]; // array
    for (int i = 0; i < numRows; i++)
        arr[i] = new char[numCols];
    fillGrid(argv[1], arr, numRows, numCols, gridFile);
    string line;
    // cout<<"array: " << endl;
    print(arr, numRows, numCols);
    cout << "Found coordinates: " << endl;
    while (getline(wordFile, line)) {
        int endRow = 0;
        int endCol = 0;
        line.erase(remove_if(line.begin(), line.end(), ::isspace), line.end());
        if (line.length() > 0) {
            search(arr, numRows, numCols, line, endRow, endCol);
            cout << line << ": " << endRow << "," << endCol << endl;
            output += to_string(endRow) + "," + to_string(endCol) + "\n";
        }
    }
    if (argc > 3) {
        vector<Coordinate> expectedCoordinates;
        if (strcmp(argv[3],"testAbc")==0) {
            expectedCoordinates = {
                    {0,  0},
                    {1,  0}};
        }
        if (strcmp(argv[3],"testAnimal")==0){
            expectedCoordinates = {
                    {9, 1},
                    {8, 8},
                    {4, 3},
                    {6, 8},
                    {0, 3},
                    {3, 5},
                    {3, 1},
                    {9, 3},
                    {7, 10},
                    {5, 1},
                    {5, 11},
                    {8, 9},
                    {7, 11},
                    {7, 6},
                    {13, 6},
                    {4, 12},
                    {7, 12},
                    {13, 10},
                    {4, 10},
                    {11, 1},
                    {1, 0},
                    {10, 11},
                    {8, 6},
                    {-1, -1},
                    {6, 6},
                    {12, 6}
            };
        }
        if (strcmp(argv[3],"testAfrica")==0) {
            expectedCoordinates = {
                    {6,  1},
                    {1,  3},
                    {5,  8},
                    {0,  9},
                    {5,  5},
                    {6,  3},
                    {3,  6},
                    {4,  12},
                    {6,  13},
                    {12, 4},
                    {4,  10},
                    {0,  7},
                    {13, 0},
                    {0,  13},
                    {5,  7},
                    {4,  5},
                    {5,  9},
                    {11, 6},
                    {13, 7},
                    {0,  0},
                    {1,  3},
                    {0,  1},
                    {2,  6},
                    {9,  0},
                    {3,  11},
                    {1,  9},
                    {0,  1},
                    {2,  4},
                    {2,  2},
                    {14, 0}
            };
        }
        vector<Coordinate> actualCoordinates = parseOutput(output);
        compareCoordinates(actualCoordinates, expectedCoordinates);
    }
    //  de-allocate dynamically-created array

    for (int j = 0; j < numRows; j++)
        delete[] arr[j];

    delete[] arr;
    wordFile.close();
    return 0;
}
