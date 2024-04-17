// Created by Charmaine Pasicolan on 4/17/24.

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct Coordinate {
    int x;
    int y;
};

// Function to compare two vectors of coordinates
bool compareCoordinates(const vector<Coordinate>& actual, const vector<Coordinate>& expected) {
    if (actual.size() != expected.size()) {
        cout << "Different number of coordinates found\nExpected: " << expected.size() << endl;
        cout << "Found: " << actual.size() << endl;
        return false;
    }

    for (size_t i = 0; i < actual.size(); ++i) {
        if (actual[i].x != expected[i].x || actual[i].y != expected[i].y) {
            cout << "Coordinates mismatch at index " << i << ": Expected (" << expected[i].x << "," << expected[i].y
                      << "), Actual (" << actual[i].x << "," << actual[i].y << ")\n";
            return false;
        }
    }

    cout << "Coordinates match!\n";
    return true;
}

// Function to parse the output string into coordinates
vector<Coordinate> parseOutput(const string& output) {
    vector<Coordinate> coordinates;
    istringstream iss(output);
    string token;
    while (getline(iss, token, '\n')) {
        Coordinate coord;
        istringstream tokenStream(token);
        string coordinate;
        int count = 0;
        while (getline(tokenStream, coordinate, ',')) {
            if (count == 0) {
                coord.x = stoi(coordinate);
                count++;
            } else {
                coord.y = stoi(coordinate);
            }
        }
        coordinates.push_back(coord);
    }
    return coordinates;
}

