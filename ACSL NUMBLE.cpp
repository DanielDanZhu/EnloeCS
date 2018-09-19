/*
Completed:
If stringlength is 1 or 2
Output
Input

Not Completed:
NONE
Ties
Ordering
Other string lengths
*/
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

void input (string inputs[5], string inputstrings[5], int inputstringints[5], int inputlengths[5]) {
    string tempstring;

    cout << "Please enter five lines of input:" << endl;

    for (int y=0; y<5; y++) {
        getline (cin, inputs[y]);

        tempstring = inputs[y][9];
        inputstrings[y] = inputs[y].substr(0,7);
        inputstringints[y] = atoi(inputstrings[y].c_str());
        inputlengths[y] = atoi(tempstring.c_str());
    }
}

void calculations(string inputstrings[5], int inputlengths[5], string unorderedoutputs[5], string ties[5]) {
    string tempstring, letter1, letter2;
    int temp1, temp2, temp3, temp4;

    for (int u=0; u<5; u++) {
        tempstring = inputstrings[u];

        if (inputlengths[u] == 1) {
            if (tempstring.find("5") != string::npos) {
                unorderedoutputs[u] = "5";
            }
            else {
                unorderedoutputs[u] = "NONE";
            }
        }
        else if (inputlengths[u] == 2) {
            int largestmult = 0;
            for (int x=0; x<7; x++) {
                for (int c=0; c<7; c++) {
                    if (x!=c) {

                        letter1 = tempstring[x];
                        temp1 = atoi(letter1.c_str());

                        letter2 = tempstring[c];
                        temp2 = atoi(letter2.c_str());
                        if ((temp1 + temp2) % 5 == 0) {
                            if (temp1 + temp2 > largestmult) {
                                largestmult = temp1 + temp2;
                                unorderedoutputs[u] = letter1 + letter2;
                            }
                        }
                    }
                }
            }
        }
        else if (inputlengths[u] == 3) {

        }
        else if (inputlengths[u] == 4) {

        }
        else if (inputlengths[u] == 5) {

        }
        else if (inputlengths[u] == 6) {

        }
        else if (inputlengths[u] == 7) {

        }
    }
}

//void ordersort

void output (string unorderedoutputs[5]) {
    for (int h=0; h<5; h++) {
        cout << unorderedoutputs[h] << endl;
    }
}

int main() {
    string inputs[5];
    string inputstrings[5];
    string unorderedoutputs[5];
    string ties[5];
    string outputs[5];
    int inputstringints[5];
    int inputlengths[5];

    input (inputs, inputstrings, inputstringints, inputlengths);
    calculations (inputstrings, inputlengths, unorderedoutputs, ties);
    output (unorderedoutputs);
}
