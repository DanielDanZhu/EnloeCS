#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
cout << plusLoc << endl << exLoc << endl;
    for (int x=0; x<removedTiles.size(); x++) {
        cout << removedTiles[x] << " ";
    }
*/

int main() {
    int input, plusLoc, exLoc;
    int counter = 0;
    vector<int> removedTiles;

    cout << "Input 1: ";
    while (input != 0) {
        cin >> input;
        if (counter == 0 && input != 0) {
            plusLoc = input;
            removedTiles.push_back(input);
        }
        else if (counter == 1 && input != 0) {
            exLoc = input;
        }
        else if (input != 0) {
            removedTiles.push_back(input);
        }
        counter++;
    }

    int availableTiles[50];
    for (int x=1; x<50; x++) {
        availableTiles[x] = 1;
        for (int y=0; y<removedTiles.size(); y++) {
            if (removedTiles[y] == x) {
                availableTiles[x] = 0;
            }
        }
    }

    int currentLoc = exLoc;
    vector<int> rightPath;
    while ((currentLoc+1)%7 != 1 && availableTiles[currentLoc+1] == 1) {
        int temp = currentLoc+1;
        rightPath.push_back(temp);
        currentLoc++;
    }
    currentLoc = exLoc;
    vector<int> leftPath;
    while ((currentLoc-1)%7 != 0 && availableTiles[currentLoc-1] == 1) {
        int temp = currentLoc-1;
        leftPath.push_back(temp);
        currentLoc--;
    }
    currentLoc = exLoc;
    vector<int> upPath;
    while ((currentLoc+7) <= 49 && availableTiles[currentLoc+7] == 1) {
        int temp = currentLoc+7;
        upPath.push_back(temp);
        currentLoc = currentLoc+7;
    }
    currentLoc = exLoc;
    vector<int> downPath;
    while ((currentLoc-7) >= 1 && availableTiles[currentLoc-7] == 1) {
        int temp = currentLoc-7;
        downPath.push_back(temp);
        currentLoc = currentLoc-7;
    }

    currentLoc = exLoc;
    vector<int> upRightPath;
    while (((currentLoc+1)%7 != 1 && currentLoc+7 <= 49) && availableTiles[currentLoc+8] == 1) {
        int temp = currentLoc+8;
        upRightPath.push_back(temp);
        currentLoc = currentLoc+8;
    }
    currentLoc = exLoc;
    vector<int> upLeftPath;
    while (((currentLoc-1)%7 != 0 && currentLoc+7 <= 49) && availableTiles[currentLoc+6] == 1) {
        int temp = currentLoc+6;
        upLeftPath.push_back(temp);
        currentLoc = currentLoc+6;
    }
    currentLoc = exLoc;
    vector<int> downRightPath;
    while (((currentLoc+1)%7 != 1 && currentLoc-7 >= 1) && availableTiles[currentLoc-6] == 1) {
        int temp = currentLoc-6;
        downRightPath.push_back(temp);
        currentLoc = currentLoc-6;
    }
    currentLoc = exLoc;
    vector<int> downLeftPath;
    while (((currentLoc-1)%7 != 0 && currentLoc-7 >= 1) && availableTiles[currentLoc-8] == 1) {
        int temp = currentLoc-8;
        downLeftPath.push_back(temp);
        currentLoc = currentLoc-8;
    }

    cout << "Up path: " << upPath.size() << endl;
    cout << "Right path: " << rightPath.size() << endl;
    cout << "Down path: " << downPath.size() << endl;
    cout << "Left path: " << leftPath.size() << endl;
    cout << "Up-right path: " << upRightPath.size() << endl;
    cout << "Down-right path: " << downRightPath.size() << endl;
    cout << "Down-left path: " << downLeftPath.size() << endl;
    cout << "Up-left path: " << upLeftPath.size() << endl;
    vector<int> path = upPath;


    /*if (upPath.size()>rightPath.size() && upPath.size()>downPath.size() && upPath.size()>leftPath.size() && upPath.size()>upRightPath.size() && upPath.size()>downRightPath.size() && upPath.size()>downLeftPath.size() && upPath.size()>upLeftPath.size()) {
        for (int x=0; x<upPath.size(); x++) {
            if (x==upPath.size()-1) {
                cout << upPath[x] << endl;
            }
            else {
                cout << upPath[x] << ", ";
            }
        }
    }
    /*else if (rightPath.size()>upPath.size() && rightPath.size()>downPath.size() && rightPath.size()>leftPath.size() && rightPath.size()>upRightPath.size() && rightPath.size()>downRightPath.size() && rightPath.size()>downLeftPath.size() && rightPath.size()>upLeftPath.size()) {
        /*for (int x=0; x<rightPath.size(); x++) {
            if (x==rightPath.size()-1) {
                cout << rightPath[x] << endl;
            }
            else {
                cout << rightPath[x] << ", ";
            }
        }
   }*/
}
