//#include "H:\C++\MyFunctions.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <vector>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

class Piece{
    private:
        int x, y, color, king, active;
    public:
        Piece() {
            x=-1;
            y=-1;
            color=0;
            king=0;
            active=1;
        }
        int getx() {return x;}
        int gety() {return y;}
        int getColor() {return color;}
        int getKing() {return king;}
        int getActive() {return active;}
        void set(int x_pos, int y_pos, int c) {x=x_pos; y=y_pos; color=c;}
        void set(int x_pos, int y_pos) {x=x_pos; y=y_pos;}
        void seta(int a) {active = a;}
        void setk(int k) {king = k;}
        void display() {
            if (king == 0 && color == 0) {
                SetConsoleTextAttribute(console, 9);
                cout << "b";
                SetConsoleTextAttribute(console, 7);
            }
            else if (king == 1 && color == 0) {
                SetConsoleTextAttribute(console, 9);
                cout << "B";
                SetConsoleTextAttribute(console, 7);
            }
            else if (king == 0 && color == 1) {
                SetConsoleTextAttribute(console, 12);
                cout << "r";
                SetConsoleTextAttribute(console, 7);
            }
            else if (king == 1 && color == 1) {
                SetConsoleTextAttribute(console, 12);
                cout << "R";
                SetConsoleTextAttribute(console, 7);
            }
        }
};

class Board {;
    private:
        Piece list[24];
        int x1, x2, y1, y2;
        int status, redp, bluep, winner;
        int drawOffer, drawAccept, concede;
        int inRange(int x, int y) { ///Prevents jumping off board
            if (x<=8 && x>=1 && y<=8 && y>=1) {
                return 1;
            }
            else {
                return 0;
            }
        }
        int spaceEmpty(int x, int y) { ///Prevents jumping into a piece
            int h=0;
            for (int g=0; g<24; g++) {
                if (list[g].getActive() == 1 && list[g].getx() == x && list[g].gety() == y) {
                    return 0;
                    h=1;
                }
            }
            if (h==0) {
                return 1;
            }
        }
        int pAtLoc(int x, int y) { ///Prevents jumping own pieces
            for (int k=0; k<24; k++) {
                if (list[k].getActive() == 1 && list[k].getx() == x && list[k].gety() == y) {
                    return list[k].getColor();
                }
            }
        }

        void display() {
            int temp = 0;

            cout << "   The Board" << endl << "   +---+---+---+---+---+---+---+---+" << endl;
            for (int l=8; l>=1; l--) {
                    cout << " " << l << " ";
                for (int w=1; w<=8; w++) {
                    for (int g=0; g<24; g++) {
                        if (list[g].gety() == l && list[g].getx() == w && list[g].getActive() == 1) {
                            cout << "| ";
                            list[g].display();
                            cout << " ";
                            temp = 1;
                        }
                    }
                    if (temp == 0) {
                        cout << "|   ";
                    }
                    temp = 0;
                }
                cout << "|" << endl << "   +---+---+---+---+---+---+---+---+" << endl;
            }
            cout << "     1   2   3   4   5   6   7   8" << endl << endl;
        }
        int jumpAvailable() {
            if (status == 0) {
                for (int x=0; x<12; x++) {
                    if (list[x].getActive() == 1) {
                        if (list[x].getKing() == 1) {
                            if (inRange(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()+1) != list[x].getColor()) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()+1) != list[x].getColor()) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()-1) != list[x].getColor()) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()-1) != list[x].getColor()) {
                                return 1;
                            }
                        }
                        else {
                            if (inRange(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()+1) != list[x].getColor()) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()+1) != list[x].getColor()) {
                                return 1;
                            }
                        }
                    }
                }
            }
            else if (status == 1) {
                for (int x=12; x<24; x++) {
                    if (list[x].getActive() == 1) {
                        if (list[x].getKing() == 1) {
                            if (inRange(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()+1) != list[x].getColor()) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()+1) != list[x].getColor()) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()-1) != list[x].getColor()) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()-1) != list[x].getColor()) {
                                return 1;
                            }
                        }
                        else {
                            if (inRange(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()-1) != list[x].getColor()) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()-1) != list[x].getColor()) {
                                return 1;
                            }
                        }
                    }
                }
            }
            return 0;
        }
        int jumpAvailable(int x) {
            if (list[x].getActive() == 1) {
                if (list[x].getKing() == 1) {
                    if (inRange(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()+1) != list[x].getColor()) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()+1) != list[x].getColor()) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()-1) != list[x].getColor()) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()-1) != list[x].getColor()) {
                        return 1;
                    }
                }
                else if (list[x].getColor() == 0) {
                    if (inRange(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()+1) != list[x].getColor()) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()+2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()+1) != list[x].getColor()) {
                        return 1;
                    }
                }
                else if (list[x].getColor() == 1) {
                    if (inRange(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()+1,list[x].gety()-1) != list[x].getColor()) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-2,list[x].gety()-2) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 0 && pAtLoc(list[x].getx()-1,list[x].gety()-1) != list[x].getColor()) {
                        return 1;
                    }
                }
            }
            return 0;
        }
        int validJump(int x) {
            if (list[x].getActive() == 1) {
                if (list[x].getKing() == 1) {
                    if ((y2==y1+2 || y2==y1-2) && (x2==x1-2 || x2==x1+2)) {
                        if (inRange(x2,y2) == 1 && spaceEmpty(x2,y2) == 1) {
                            if (spaceEmpty((x2+x1)/2,(y2+y1)/2) == 0 && pAtLoc((x2+x1)/2,(y2+y1)/2) != list[x].getColor()) {
                                return 1;
                            }
                        }
                    }
                }
                else if (list[x].getColor() == 0) {
                    if (y2==y1+2 && (x2==x1-2 || x2==x1+2)) {
                        if (inRange(x2,y2) == 1 && spaceEmpty(x2,y2) == 1) {
                            if (spaceEmpty((x2+x1)/2,(y2+y1)/2) == 0 && pAtLoc((x2+x1)/2,(y2+y1)/2) != list[x].getColor()) {
                                return 1;
                            }
                        }
                    }
                }
                else if (list[x].getColor() == 1) {
                    if (y2==y1-2 && (x2==x1-2 || x2==x1+2)) {
                        if (inRange(x2,y2) == 1 && spaceEmpty(x2,y2) == 1) {
                            if (spaceEmpty((x2+x1)/2,(y2+y1)/2) == 0 && pAtLoc((x2+x1)/2,(y2+y1)/2) != list[x].getColor()) {
                                return 1;
                            }
                        }
                    }
                }
            }
            return 0;
        }
        void jump() {
            for (int x=0; x<24; x++) {
                if (list[x].getx()==(x1+x2)/2 && list[x].gety()==(y1+y2)/2 && list[x].getActive() == 1) {
                    list[x].seta(0);
                    if (list[x].getColor() == 0) {
                        bluep--;
                    }
                    else if (list[x].getColor() == 1) {
                        redp--;
                    }
                }
            }
        }
        int moveAvailable() {
            if (status == 0) {
                for (int x=0; x<12; x++) {
                    if (list[x].getActive() == 1) {
                        if (list[x].getKing() == 1) {
                            if (inRange(list[x].getx()+1,list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 1 ) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-1, list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 1) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()+1,list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 1 ) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-1, list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 1) {
                                return 1;
                            }
                        }
                        else {
                            if (inRange(list[x].getx()+1,list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 1 ) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-1, list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 1) {
                                return 1;
                            }
                        }
                    }
                }
            }
            else if (status == 1) {
                for (int x=12; x<24; x++) {
                    if (list[x].getActive() == 1) {
                        if (list[x].getKing() == 1) {
                            if (inRange(list[x].getx()+1,list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 1 ) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-1, list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 1) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()+1,list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 1 ) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-1, list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 1) {
                                return 1;
                            }
                        }
                        else {
                            if (inRange(list[x].getx()+1,list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 1 ) {
                                return 1;
                            }
                            else if (inRange(list[x].getx()-1, list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 1) {
                                return 1;
                            }
                        }
                    }
                }
            }
            return 0;
        }
        int moveAvailable(int x) {
            if (list[x].getActive() == 1) {
                if (list[x].getKing() == 1) {
                    if (inRange(list[x].getx()+1,list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 1 ) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()-1, list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 1) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()+1,list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 1 ) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()-1, list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 1) {
                        return 1;
                    }
                }
                else if (list[x].getColor() == 0) {
                    if (inRange(list[x].getx()+1,list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()+1) == 1 ) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()-1, list[x].gety()+1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()+1) == 1) {
                        return 1;
                    }
                }
                else if (list[x].getColor() == 1) {
                    if (inRange(list[x].getx()+1,list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()+1,list[x].gety()-1) == 1 ) {
                        return 1;
                    }
                    else if (inRange(list[x].getx()-1, list[x].gety()-1) == 1 && spaceEmpty(list[x].getx()-1,list[x].gety()-1) == 1) {
                        return 1;
                    }
                }
            }
            return 0;
        }
        int validMove(int x) {
            if (list[x].getActive() == 1) {
                if (list[x].getKing() == 1) {
                    if ((y2==y1+1 || y2==y1-1) && (x2==x1-1 || x2==x1+1)) {
                        return 1;
                    }
                }
                else if (list[x].getColor() == 0) {
                    if (y2==y1+1 && (x2==x1-1 || x2==x1+1)) {
                        return 1;
                    }
                }
                else if (list[x].getColor() == 1){
                    if (y2==y1-1 && (x2==x1-1 || x2==x1+1)) {
                        return 1;
                    }
                }
            }
        }
        void move() {
            int real = 0;
            int color = 0;
            int piecenum;
            int canmove = 0;
            int canjump = 1;
            int multJump = 0;

            do {
                canjump = 1;

                cout << "Coordinates of piece to move (10 to offer draw, 20 to concede): ";
                cin >> x1;
                if (x1 == 10) {
                    drawOffer = 1;
                }
                else if (x1 == 20) {
                    concede = 1;
                }
                if (drawOffer == 0 && concede == 0) {
                    cin >> y1;

                    for (int j=0; j<24; j++) {
                        if (list[j].getx() == x1 && list[j].gety() == y1 && list[j].getActive() == 1) {
                            real = 1;
                            if (list[j].getColor() == status) {
                                color = 1;
                                piecenum = j;
                                if (moveAvailable(j) == 1 || jumpAvailable(j) == 1) {
                                    canmove = 1;
                                    if (jumpAvailable(j) != 1 && jumpAvailable() == 1) {
                                        canmove = 0;
                                        canjump = 0;
                                    }
                                }
                            }
                        }
                    }
                    if (real == 0) {
                        cout << "No piece at that location. Please enter another." << endl << endl;
                    }
                    else if (color == 0) {
                        cout << "That is not your piece. Please enter another." << endl << endl;
                    }
                    else if (canjump == 0) {
                        cout << "You must select the piece that can jump." << endl << endl;
                    }
                    else if (canmove == 0) {
                        cout << "That piece can't move. Please enter another." << endl << endl;
                    }
                }
            } while ((real == 0 || color == 0 || canmove == 0) && drawOffer == 0 && concede == 0);

            if (drawOffer == 0 && concede == 0) {
                do {
                    canjump = 0;
                    canmove = 0;
                    if (multJump == 1) {
                        display();
                        cout << "You have another jump available! ";
                        multJump = 0;
                    }
                    cout << "Coordinates to move to: ";
                    cin >> x2;
                    cin >> y2;

                    if ((validMove(piecenum) == 1 || validJump(piecenum) == 1) && inRange(x2,y2) == 1 && spaceEmpty(x2,y2) == 1) {
                        canmove = 1;
                        if ((x2 == x1+1 || x2 == x1-1) && jumpAvailable(piecenum) == 1) {
                            cout << jumpAvailable(piecenum);
                            canmove = 0;
                        }
                    }

                    if (inRange(x2, y2) == 0) {
                        cout << "That location is not on the board." << endl << endl;
                    }
                    else if (spaceEmpty(x2,y2) == 0) {
                        cout << "There is already a piece there." << endl << endl;
                    }
                    else if (canmove == 0) {
                        cout << "Your piece cannot move there." << endl << endl;
                    }

                    if (canmove == 1) {
                        list[piecenum].set(x2, y2);
                        if (x2==x1+2 || x2==x1-2) {
                            jump();
                            canjump = 1;
                        }
                        x1 = x2;
                        y1 = y2;
                        ///Kinging
                        if (list[piecenum].getColor() == 0) {
                            if (list[piecenum].gety() == 8) {
                                list[piecenum].setk(1);
                            }
                        }
                        else if (list[piecenum].getColor() == 1) {
                            if (list[piecenum].gety() == 1) {
                                list[piecenum].setk(1);
                            }
                        }
                        if (jumpAvailable(piecenum) == 1 && canjump == 1) {
                            multJump = 1;
                        }
                    }
                } while (canmove == 0 || multJump == 1);
            }
        }
        void turn() {
            system("cls");
            display();
            if (status == 0) {
                cout << "Blue's turn:" << endl << endl;
            }
            else if (status == 1) {
                cout << "Red's turn:" << endl << endl;
            }
            move();

            if (status == 0) {
                status = 1;
            }
            else if (status == 1) {
                status = 0;
            }
        }
    public:
        Board() {
            redp = 12;
            bluep = 12;
            status = drawOffer = drawAccept = concede = 0;

            list[0].set(1, 1, 0);
            list[1].set(3, 1, 0);
            list[2].set(5, 1, 0);
            list[3].set(7, 1, 0);
            list[4].set(2, 2, 0);
            list[5].set(4, 2, 0);
            list[6].set(6, 2, 0);
            list[7].set(8, 2, 0);
            list[8].set(1, 3, 0);
            list[9].set(3, 3, 0);
            list[10].set(5, 3, 0);
            list[11].set(7, 3, 0);

            list[12].set(2, 6, 1);
            list[13].set(4, 6, 1);
            list[14].set(6, 6, 1);
            list[15].set(8, 6, 1);
            list[16].set(1, 7, 1);
            list[17].set(3, 7, 1);
            list[18].set(5, 7, 1);
            list[19].set(7, 7, 1);
            list[20].set(2, 8, 1);
            list[21].set(4, 8, 1);
            list[22].set(6, 8, 1);
            list[23].set(8, 8, 1);
        }
        void execute() {
            display();
            cout << "Who goes first? (0 for black, 1 for red)" << endl;
            cin >> status;

            if (moveAvailable() == 1 || jumpAvailable() == 1) {
                do {
                    if (drawOffer == 1) {
                        cout << "Your opponent proposed a draw. (0 to deny, 1 to accept): ";
                        cin >> drawAccept;
                        if (drawAccept == 0) {
                            turn();
                        }
                    }
                    else {
                        turn();
                    }
                    //display();
                } while (redp > 0 && bluep > 0 && (moveAvailable() == 1 || jumpAvailable() == 1) && concede == 0 && drawAccept == 0);
            }

            display();
            if (redp == 0) {
                cout << endl << "Blue has won, thanks for playing!" << endl;
            }
            else if ((moveAvailable() == 0 && jumpAvailable() == 0) && status == 1) {
                cout << endl << "Red has no more available moves, Blue has won, thanks for playing!" << endl;
            }
            else if (concede == 1 && status == 0) {
                cout << endl << "Red has conceded, Blue has won, thanks for playing!" << endl;
            }
            else if (bluep == 0) {
                cout << endl << "Red has won, thanks for playing!" << endl;
            }
            else if ((moveAvailable() == 0 && jumpAvailable() == 0) && status == 0) {
                cout << endl << "Blue has no more available moves, Red has won, thanks for playing!" << endl;
            }
            else if (concede == 1 && status == 1) {
                cout << endl << "Blue has conceded, Red has won, thanks for playing!" << endl;
            }
            else if (drawAccept == 1) {
                cout << endl << "The game has ended in a draw, thanks for playing!" << endl;
            }
        }
};

int main() {
    Board b;
    b.execute();

    return 0;
}
