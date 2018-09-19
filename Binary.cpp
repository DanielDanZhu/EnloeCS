#include "H:\C++\MyFunctions.h"
using namespace std;

class Binary {
    private:
        vector<int> number;
        vector<int> sum;
    public:
        void input();
        void display();
        vector<int> getVector();
        void operator+(Binary);
        void hex();
};

void Binary::input () {
    int tempint;

    ///Inputting binary values
    cout << "number (Enter 2 to stop): " << endl;
    while (tempint != 2) {
        cin >> tempint;
        if (tempint != 2) {
            number.push_back(tempint);
        }
    }
}

void Binary::display() {
    ///Displays binary values
    for (int k=0; k<number.size(); k++) {
        cout << number[k];
    }
    cout << endl;
}

vector<int> Binary::getVector() {
    return number;
}

void Binary::operator+(Binary a2) {
    int tempint, tempint2;

    reverse(number.begin(), number.end());
    reverse(a2.number.begin(), a2.number.end());

    ///If first value has more digits
    if (number.size() > a2.number.size()) {
        while (number.size() > a2.number.size()) {
            a2.number.push_back(0);
        }
    }
    ///If second value has more digits
    if (a2.number.size() > number.size()) {
        while (a2.number.size() > number.size()) {
            number.push_back(0);
        }
    }

    for (int g=0; g<number.size(); g++) {
        tempint = number[g] + a2.number[g];

        ///If the sum of two corresponding digits is 0 or 1
        if (tempint < 2) {
            sum.push_back(tempint);
        }
        ///If the sum of two corresponding digits is 2 or 3
        else if (tempint == 2 || tempint == 3) {
            sum.push_back(tempint-2);
            if (g+1 >= number.size()) {
                sum.push_back(1);
            }
            else {
                number[g+1]++;
            }
        }
    }

    reverse(sum.begin(), sum.end());
    ///Deleting zeros from the start of the sum.
    while (sum[0] == 0) {
        sum.erase(sum.begin());
    }
    ///Displays binary sum
    cout << "Binary sum: ";
    for (int y=0; y<sum.size(); y++) {
        cout << sum[y];
    }
    cout << endl;
}

void Binary::hex() {
    vector<char>hexsum;
    char characters[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int temp = 0;
    reverse(sum.begin(), sum.end());

    do {
        ///Adds zeros if vector size less than 4
        if (sum.size() < 4) {
            while (sum.size() < 4) {
                sum.push_back(0);
            }
        }
        temp = 0;
        ///Adds partition of four in a temp variable
        for (int j=0; j<4; j++) {
            if (sum[j] == 1) {
                temp = temp + pow(2, j);
            }
        }
        hexsum.push_back(characters[temp]);
        ///Deletes current partition of four
        for (int k=0; k<4; k++) {
            sum.erase(sum.begin());
        }
    } while (sum.size() > 0);

    ///Displays hexadecimal sum
    reverse(hexsum.begin(), hexsum.end());
    while (hexsum[0] == 0) {
        hexsum.erase(hexsum.begin());
    }
    cout << "Hexadecimal sum: ";
    for (int p=0; p<hexsum.size(); p++) {
        cout << hexsum[p];
    }
    cout << endl;
}

int main() {
    Binary a1, a2;
    cout << "First ";
    a1.input();
    cout << "Second ";
    a2.input();
    cout << "First: ";
    a1.display();
    cout << "Second: ";
    a2.display();
    a1+a2;
    a1.hex();
}
