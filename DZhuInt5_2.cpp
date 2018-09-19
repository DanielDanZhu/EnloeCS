//Daniel Zhu
//Period 4
//Date: 2/12/15
//Enloe HS
//Int 5 - Contest 2

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void firstInput() {
    string input;
    vector<char> atoms;

    cout << "First input: ";
    getline(cin, input);

    do {
        input.erase(0,2);
        atoms.push_back(input[0]);
    } while (input[1] != ')');

    reverse(atoms.begin(), atoms.end());
    cout << "1. '(";
    for (int t=0; t<atoms.size(); t++) {
        cout << atoms[t];
        if (t!= atoms.size()-1) {
            cout << " ";
        }
    }
    cout << ")" << endl << endl;
}

void secondInput() {
    string input;
    vector<char> atoms;
    vector<char> singles;
    vector<int> count;
    char current;
    int num = 1;

    cout << "Second input: ";
    getline(cin, input);

    do {
        input.erase(0,2);
        atoms.push_back(input[0]);
    } while (input[1] != ')');

    for (int x=0; x<atoms.size(); x++) {
        if (x != 0 && x != atoms.size()-1){
            if (atoms[x] != atoms[x-1]) {
                singles.push_back(atoms[x-1]);
                count.push_back(num);
                num = 1;
            }
            else {
                num++;
            }
        }
        if (x == atoms.size()-1) {
            if (atoms[x] != atoms[x-1]) {
                singles.push_back(atoms[x-1]);
                count.push_back(num);
                singles.push_back(atoms[x]);
                count.push_back(1);
            }
            else {
                singles.push_back(atoms[x]);
                count.push_back(num+1);
            }
        }
    }

    cout << "2. '(";
    for (int x=0; x<count.size(); x++) {
        cout << "(" << count[x] << " " << singles[x] << ")";
        if (x != count.size()-1) {
            cout << " ";
        }
    }
    cout << ")" << endl << endl;
}

void thirdInput() {
    string input;
    vector<char> atoms;
    vector<char> singles;
    vector<int> count;
    char current;
    int num = 1;

    cout << "Third input: ";
    getline(cin, input);

    do {
        input.erase(0,2);
        atoms.push_back(input[0]);
    } while (input[1] != ')');

    for (int x=0; x<atoms.size(); x++) {
        if (x != 0 && x != atoms.size()-1){
            if (atoms[x] != atoms[x-1]) {
                singles.push_back(atoms[x-1]);
                count.push_back(num);
                num = 1;
            }
            else {
                num++;
            }
        }
        if (x == atoms.size()-1) {
            if (atoms[x] != atoms[x-1]) {
                singles.push_back(atoms[x-1]);
                count.push_back(num);
                singles.push_back(atoms[x]);
                count.push_back(1);
            }
            else {
                singles.push_back(atoms[x]);
                count.push_back(num+1);
            }
        }
    }

    cout << "3. '(";
    for (int x=0; x<count.size(); x++) {
        if (count[x] != 1) {
            cout << "(" << count[x] << " " << singles[x] << ")";
        }
        else {
            cout << singles[x];
        }
        if (x != count.size()-1) {
            cout << " ";
        }
    }
    cout << ")" << endl << endl;
}

void fourthInput () {
    string input, temp;
    char num;
    vector<string> list;

    cout << "Fourth Input: ";
    getline(cin, input);

    input.erase(0,2);
    do {
        temp = input.substr(0,5);
        list.push_back(temp);
        input.erase(0,6);
    } while (input[0] == '(');
    num = input[0];
    int number = num-48;

    for (int x=list.size(); x>=1; x--) {
        if (x%number == 0) {
            list.erase(list.begin()+x-1);
        }
    }

    cout << "4. '(";
    for (int t=0; t<list.size(); t++) {
        cout << list[t] << " ";
    }
    cout << number << ")" << endl << endl;
}

void fifthInput() {
    string input, temp;
    char num;
    vector<string> list;
    vector<string> newList;

    cout << "Fourth Input: ";
    getline(cin, input);

    input.erase(0,2);
    do {
        temp = input.substr(0,5);
        list.push_back(temp);
        input.erase(0,6);
    } while (input[0] == '(');
    num = input[0];
    int number = num-48;

    reverse(list.begin(), list.end());
    for (int x=0; x<number; x++) {
        newList.push_back(list[list.size()-1]);
        list.pop_back();
    }
    reverse(list.begin(), list.end());

    cout << "5. '(";
    for (int x=0; x<newList.size(); x++) {
        cout << newList[x];
        if (x != newList.size()-1) {
            cout << " ";
        }
    }
    cout << ") '(";
    for (int x=0; x<list.size(); x++) {
        cout << list[x] << " ";
    }
    cout << number << ")" << endl << endl;
}

int main() {
    firstInput();
    secondInput();
    thirdInput();
    fourthInput();
    fifthInput();

    return 0;
}
