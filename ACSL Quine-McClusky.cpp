#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void binChange(int a, vector<char> &b) {
    if (a==0) {
        b.push_back('0');
        b.push_back('0');
        b.push_back('0');
        b.push_back('0');
    }
    else if (a==1) {
        b.push_back('0');
        b.push_back('0');
        b.push_back('0');
        b.push_back('1');
    }
    else if (a==2) {
        b.push_back('0');
        b.push_back('0');
        b.push_back('1');
        b.push_back('0');
    }
    else if (a==3) {
        b.push_back('0');
        b.push_back('0');
        b.push_back('1');
        b.push_back('1');
    }
    else if (a==4) {
        b.push_back('0');
        b.push_back('1');
        b.push_back('0');
        b.push_back('0');
    }
    else if (a==5) {
        b.push_back('0');
        b.push_back('1');
        b.push_back('0');
        b.push_back('1');
    }
    else if (a==6) {
        b.push_back('0');
        b.push_back('1');
        b.push_back('1');
        b.push_back('0');
    }
    else if (a==7) {
        b.push_back('0');
        b.push_back('1');
        b.push_back('1');
        b.push_back('1');
    }
    else if (a==8) {
        b.push_back('1');
        b.push_back('0');
        b.push_back('0');
        b.push_back('0');
    }
    else if (a==9) {
        b.push_back('1');
        b.push_back('0');
        b.push_back('0');
        b.push_back('1');
    }
    else if (a==10) {
        b.push_back('1');
        b.push_back('0');
        b.push_back('1');
        b.push_back('0');
    }
    else if (a==11) {
        b.push_back('1');
        b.push_back('0');
        b.push_back('1');
        b.push_back('1');
    }
    else if (a==12) {
        b.push_back('1');
        b.push_back('1');
        b.push_back('0');
        b.push_back('0');
    }
    else if (a==13) {
        b.push_back('1');
        b.push_back('1');
        b.push_back('0');
        b.push_back('1');
    }
    else if (a==14) {
        b.push_back('1');
        b.push_back('1');
        b.push_back('1');
        b.push_back('0');
    }
    else if (a==15) {
        b.push_back('1');
        b.push_back('1');
        b.push_back('1');
        b.push_back('1');
    }
}

void compare(vector<char> aVec, vector<char>bVec, vector<char>&end) {
    if (aVec[0] != bVec[0] && aVec[1] == bVec[1] && aVec[2] == bVec[2] && aVec[3] == bVec[3]) {
        end = aVec;
        end[0] = 'x';
    }
    else if (aVec[0] == bVec[0] && aVec[1] != bVec[1] && aVec[2] == bVec[2] && aVec[3] == bVec[3]) {
        end = aVec;
        end[1] = 'x';
    }
    else if (aVec[0] == bVec[0] && aVec[1] == bVec[1] && aVec[2] != bVec[2] && aVec[3] == bVec[3]) {
        end = aVec;
        end[2] = 'x';
    }
    else if (aVec[0] == bVec[0] && aVec[1] == bVec[1] && aVec[2] == bVec[2] && aVec[3] != bVec[3]) {
        end = aVec;
        end[3] = 'x';
    }
    else {
        cout << endl << "NONE" << endl << endl;
    }
}

void compare2(vector<char> aVec, vector<char>bVec, vector<char>&end) {
    if (aVec[0] != bVec[0] && aVec[1] == bVec[1] && aVec[2] == bVec[2] && aVec[3] == bVec[3]) {
        end = aVec;
        end[0] = 'x';
    }
    else if (aVec[0] == bVec[0] && aVec[1] != bVec[1] && aVec[2] == bVec[2] && aVec[3] == bVec[3]) {
        end = aVec;
        end[1] = 'x';
    }
    else if (aVec[0] == bVec[0] && aVec[1] == bVec[1] && aVec[2] != bVec[2] && aVec[3] == bVec[3]) {
        end = aVec;
        end[2] = 'x';
    }
    else if (aVec[0] == bVec[0] && aVec[1] == bVec[1] && aVec[2] == bVec[2] && aVec[3] != bVec[3]) {
        end = aVec;
        end[3] = 'x';
    }
}

void twoInput(int num) {
    string inputLine;
    int a, b;
    cout << num << ". ";
    cin >> a >> b;
    vector<char>aVec;
    binChange(a, aVec);
    vector<char>bVec;
    binChange(b, bVec);

    vector<char> endVec;
    compare(aVec, bVec, endVec);

    if (endVec.size() == 4) {
        cout << endl;
        for (int x=0; x<endVec.size(); x++) {
            cout << endVec[x];
        }
        cout << ", ";

        if (endVec[0] == '0') {
            cout << "a";
        }
        else if (endVec[0] == '1') {
            cout << "A";
        }
        if (endVec[1] == '0') {
            cout << "b";
        }
        else if (endVec[1] == '1') {
            cout << "B";
        }
        if (endVec[2] == '0') {
            cout << "c";
        }
        else if (endVec[2] == '1') {
            cout << "C";
        }
        if (endVec[3] == '0') {
            cout << "d";
        }
        else if (endVec[3] == '1') {
            cout << "D";
        }
        cout << endl << endl;
    }
}

void fourInput(int num) {
    int a, b, c, d;
    cout << num << ". ";
    cin >> a >> b >> c >> d;

    vector<char>aVec;
    binChange(a,aVec);
    vector<char>bVec;
    binChange(b,bVec);
    vector<char>cVec;
    binChange(c,cVec);
    vector<char>dVec;
    binChange(d,dVec);

    vector<char>endVec1;
    compare2(aVec, bVec, endVec1);
    if (endVec1.size() != 4) {
        compare2(aVec, cVec, endVec1);
    }
    if (endVec1.size() != 4) {
        compare2(aVec, dVec, endVec1);
    }
    if (endVec1.size() != 4) {
        compare2(bVec, cVec, endVec1);
    }
    if (endVec1.size() != 4) {
        compare2(bVec, dVec, endVec1);
    }
    if (endVec1.size() != 4) {
        compare2(cVec, dVec, endVec1);
    }

    vector<char>endVec2;
    compare2(aVec, bVec, endVec2);
    compare2(aVec, cVec, endVec2);
    compare2(aVec, dVec, endVec2);
    compare2(bVec, cVec, endVec2);
    compare2(bVec, dVec, endVec2);
    compare2(cVec, dVec, endVec2);

    vector<char>endVecFinal;
    compare(endVec1, endVec2, endVecFinal);

    if (endVecFinal.size() == 4) {
        cout << endl;
        for (int x=0; x<endVecFinal.size(); x++) {
            cout << endVecFinal[x];
        }
        cout << ", ";

        if (endVecFinal[0] == '0') {
            cout << "a";
        }
        else if (endVecFinal[0] == '1') {
            cout << "A";
        }
        if (endVecFinal[1] == '0') {
            cout << "b";
        }
        else if (endVecFinal[1] == '1') {
            cout << "B";
        }
        if (endVecFinal[2] == '0') {
            cout << "c";
        }
        else if (endVecFinal[2] == '1') {
            cout << "C";
        }
        if (endVecFinal[3] == '0') {
            cout << "d";
        }
        else if (endVecFinal[3] == '1') {
            cout << "D";
        }
        cout << endl << endl;
    }

}

int main() {
    vector <int> function;
    int input;

    cout << "Input:" << endl;
    cout << "1. ";
    do {
        cin >> input;
        if (input != -1) {
            function.push_back(input);
        }
    }  while(input != -1);
    cout << endl;

    twoInput(2);
    twoInput(3);
    fourInput(4);
    fourInput(5);
    fourInput(6);

    return 0;
}
