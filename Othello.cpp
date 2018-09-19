#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Piece {
    private;
        int x,y;
        int color;
    public;
        Piece() {x = y = color = -1;}
        int getx() {return x;}
        int gety() {return y;}
        int getColor() {return color;}
        void set(int x_pos, int y_pos, int c) {x=x_pos; y=y_pos; color=c;}
        void setColor(int c) {color=c;}
        void display() {
            if (color == 0) {
                cout << "B"
            }
            else if (color == 1) {
                cout << "W";
            }
            else if (color == -1) {
                cout << " ";
            }
        }
};

class Board {
    private:
        vector<piece> list;
        int x1, y1;
        int spaceLeft, redp, blackp, winner;

        int inRange(int x, int y) {
            if (x>=1 && x<=8 && y>=1 && y<=8) {
                return 1;
            }
            return 0;
        }
        int spaceEmpty(int x, int y) {
            for (int g=0; g<list.size(); g++) {

            }
        }
        void display() {

        }
};

int main() {

}
