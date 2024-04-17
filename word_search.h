// Created by Charmaine Pasicolan

#ifndef WORDSEARCH_WORD_SEARCH_H
#define WORDSEARCH_WORD_SEARCH_H
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
void search(char **grid, int rows, int cols, string word, int &endRow,
            int &endCol) {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            bool found = true;
            if (tolower(grid[row][col]) == tolower(word[0])) { // first letter
                // cout << " found starting letter for " << word << endl;
                int r;
                // right
                for (r = 1; r < word.length(); r++) {
                    if (col + r < cols && tolower(grid[row][col + r]) ==
                                          tolower(word[r])) { // second letter
                        found = true;
                    } else {
                        found = false;
                        break;
                    }
                }
                /*	if (found) {
                                  endRow = row;
                                  endCol = col;
                                 // cout << "Word '" << word << "' found at position ("
                   << row << ", " << col << ")" << end return;
                              }*/
                // left
                if (!found) {
                    for (r = 1; r < word.length(); r++) {
                        if (col - r >= 0 &&
                            tolower(grid[row][col - r]) == tolower(word[r])) {
                            found = true;
                            // cout << "found " << word << endl;
                        } else {
                            found = false;
                            break;
                        }
                    }
                }
                if (!found) {
                    for (r = 1; r < word.length(); r++) {
                        if (row + r < rows &&
                            tolower(grid[row + r][col]) == tolower(word[r])) {
                            found = true;

                        } else {
                            found = false;
                            break;
                        }
                    }
                }
                if (!found) { // up
                    for (r = 1; r < word.length(); r++) {
                        if (row - r >= 0 &&
                            tolower(grid[row - r][col]) == tolower(word[r])) {
                            found = true;
                        } else {
                            found = false;
                            break;
                        }
                    }
                }
                if (!found) { // dright
                    for (r = 1; r < word.length(); r++) {
                        if (row + r < rows && col + r < cols &&
                            tolower(grid[row + r][col + r]) == tolower(word[r])) {
                            found = true;
                            // cout << "found dright " << word << endl;
                        } else {
                            found = false;
                            break;
                        }
                    }
                }
                if (!found) { // uright
                    for (r = 1; r < word.length(); r++) {
                        if (row + r < rows && col - r >= 0 &&
                            tolower(grid[row + r][col - r]) == tolower(word[r])) {
                            found = true;
                            // cout << "found upright " << word << endl;
                        } else {
                            found = false;
                            break;
                        }
                    }
                }
                if (!found) { // dleft
                    for (r = 1; r < word.length(); r++) {
                        if (row - r >= 0 && col + r < cols &&
                            tolower(grid[row - r][col + r]) == tolower(word[r])) {
                            found = true;
                            // cout << "found down left" << word << endl;
                        } else {
                            found = false;
                            break;
                        }
                    }
                }
                if (!found) { // upleft
                    for (r = 1; r < word.length(); r++) {
                        if (row - r >= 0 && col - r >= 0 &&
                            tolower(grid[row - r][col - r]) == tolower(word[r])) {
                            found = true;
                            // cout << "found " << word << endl;
                        } else {
                            found = false;
                            break;
                        }
                    }
                }
                if (found) {
                    endRow = row;
                    endCol = col;
                    //	cout<<row <<"," << col<<endl;
                    // cout << word << "' found at position (" << row << ", " << col <<
                    // ")" << endl;
                    return;
                }
            }
        }
    }
    endRow = -1;
    endCol = -1;
    cout << "word " << word<< " not found"<< endl;
    return;
}
//----------------------------------------------------------------------------
//counts number of rows and number of columns from the file
void count(string fileName, ifstream &gridFile, int &numRows, int &numCols) {
    string line;
    string lastLine;
    gridFile.open(fileName);
    while (getline(gridFile, line)) {
        if (line.length() > 0) {
            numRows++;
            lastLine = line;
        }
    }
    for (char letter : lastLine) {
        if (!isblank(letter)) {
            numCols++;
        }
    }

    gridFile.close();
    return;
}

void fillGrid(string fileName, char **arr, int numRows, int numCols,
              ifstream &gridFile) {
    gridFile.open(fileName);
    for (int row = 0; row < numRows; row++) {
        string line;
        getline(gridFile, line);
        int col = 0;
        for (char letter : line) {
            if (!isblank(letter)) {
                arr[row][col] = letter;
                col++;
            }
        }
    }
}
void print(char **arr, int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
}


//----------------------------------------------------------------------------

#endif //WORDSEARCH_WORD_SEARCH_H
