#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void display(vector<int>hand) {
    sort(hand.begin(), hand.end());

    cout << "Your Hand:" << endl;
    for (int p=0; p<hand.size(); p++) {
        if (hand[p+1] != hand[p]) {
            cout << hand[p] << " ";
        }
        else {
            cout << hand[p];
        }
    }
    cout << endl << endl;
}

vector<int> laydown(vector<int> &hand) {
    int counter = 0;
    int setcounter = 0;
    int temp;

    sort(hand.begin(), hand.end());

    for (int o=0; o<hand.size(); o++) {
        if (hand[o] != hand[o-1] || o==0) {
            counter = 1;
        }
        else {
            counter++;

            if (counter >= 4) {
                temp = hand[o];
                setcounter = counter;
            }
        }
    }

    for (int u=0; u<hand.size(); u++) {
       if (hand[u] == temp && setcounter >= 4) {
            hand.erase(hand.begin()+u);
            u--;
       }
    }

    if (setcounter >= 4) {
        cout << "Laid down " << setcounter << " " << temp << "s" << endl;
    }

    return hand;
}

vector<int> play (vector<int> &askhand, vector<int> &givehand, int turn) {
    int askvalue;
    int havecount = 0;
    int haveyesno = 0;

    if (turn == 1) {
        cout << "What card would you like to ask for?" << endl;
        cin >> askvalue;
        cout << endl;
    }
    else {
        askvalue = askhand[rand()%askhand.size()];
        cout << "The computer asked for " << askvalue << endl;
    }

    for (int j=0; j<givehand.size(); j++) {
        if (givehand[j] == askvalue) {
            haveyesno = 1;
        }
    }

    if (haveyesno == 0) {
        if (turn == 1) {
            cout << "You drew a card" << endl << endl;
        }
        else {
            cout << "The computer drew a card" << endl;
        }
        askhand.push_back(rand()%5);
    }
    else if (haveyesno == 1) {
        for (int d=0; d<givehand.size(); d++) {
            if (givehand[d] == askvalue) {
                havecount++;
                givehand.erase(givehand.begin()+d);
                d--;
            }
        }
        if (turn == 0) {
            if (havecount == 1) {
                cout << "You gave the computer a " << askvalue << endl;
            }
            else {
                cout << "You gave the computer " << havecount << " " << askvalue << "s" << endl;
            }
        }
        else if (turn == 1) {
            if (havecount == 1) {
                cout << "The computer gave you a " << askvalue << endl;
            }
            else {
                cout << "The computer gave you " << havecount << " " << askvalue << "s" << endl;
            }
        }
        for (int k=0; k<havecount; k++) {
            askhand.push_back(askvalue);
        }
        givehand.push_back(rand()%5);
    }

    return askhand, givehand;
}

int main () {
    vector<int> hhand, chand;

    srand (time(NULL));

    int turn = (rand()%2);

    if (turn == 0) {
        cout << "The computer is going first" << endl << endl;
    }
    else {
        cout << "You are going first" << endl << endl;
    }

    for (int i=0; i<7; i++) {
        hhand.push_back(rand()%5);
        chand.push_back(rand()%5);
    }

    do {
        if (turn == 1) {
            if (chand.size() != 0) {
                cout << "------------------------------------------------------------" << endl;
                cout << "Your turn:" << endl << endl;
                display (hhand);
                display (chand);
                play (hhand, chand, turn);
                laydown(hhand);

                turn = 0;
            }
        }
        else {
            if(hhand.size() != 0) {
                cout << "------------------------------------------------------------" << endl;
                cout << "Computer turn:" << endl << endl;
                play (chand, hhand, turn);
                laydown(chand);

                turn = 1;
            }
        }
    } while (hhand.size() != 0 && chand.size() != 0);

    if (hhand.size() == 0) {
        cout << endl << "You won!" << endl;
    }
    else {
        cout << endl << "The computer won the battle but Potter won the war." << endl;
    }

    return 0;
}
