//Daniel Zhu

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Binary {
    private:
        vector<int>num;
        vector<int>OR;

    public:
        void input();
        void display();
        void operator!();
        void operator>(Binary);
        void operator+(Binary);
};

void Binary::input () {
    int tempint;

    ///Inputting binary values
    cout << "Input (Enter 2 to stop): " << endl;
    while (tempint != 2) {
        cin >> tempint;
        if (tempint != 2) {
            num.push_back(tempint);
        }
    }
}

void Binary::display() {
    ///Displays binary values
    for (int k=0; k<num.size(); k++) {
        cout << num[k];
    }
    cout << endl;
}

void Binary::operator!() {
    for (int x=0; x<num.size(); x++) {
        if (num[x] == 0) {
            num[x] = 1;
        }
        else if (num[x] == 1) {
            num[x] = 0;
        }
    }
}

//"void Binary::operator>() must take exactly one argument"?
void Binary::operator>(Binary) {
    int rShift;

    cout << "Move how much: ";
    cin >> rShift;

    reverse(num.begin(), num.end());
    for (int x=0; x<rShift; x++) {
        num.erase(num.begin());
        num.push_back(0);
    }
    reverse(num.begin(), num.end());
}

void Binary::operator+(Binary B2) {
    cout << endl;
    for (int x=0; x<num.size(); x++) {
        if (num[x] == 0 && B2.num[x] == 0) {
            cout << "0";
        }
        else {
            cout << "1";
        }
    }
    cout << endl;
}

int main() {
    Binary B1;
    B1.input();
    char oper;
    cout << "Which operator: ";
    cin >> oper;

    if (oper == '!') {
        !B1;
        B1.display();
    }
    else if (oper == '>') {
        Binary B2;
        B1>B2;
        B1.display();
    }
    else if (oper == '+') {
        Binary B2;
        B2.input();
        B1+B2;
    }
}
