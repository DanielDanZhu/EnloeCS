#include <iostream>
#include <iomanip>

using namespace std;

void input (int &a, int &b) {
    cout << "Please enter an a value: ";
    cin >> a;
    cout << "Please enter a b value: ";
    cin >> b;
    cout << endl;
}

void power (int a, int b) {
    int avar, bvar;
    avar = a;
    bvar = b;

    //Cases involving 0
    if (a == 0 && b == 0) {
        cout << "Undeteremined" << endl;
    }
    else if (a == 0 && b < 0) {
        cout << "Undefined" << endl;
    }
    else if (a == 0) {
        cout << "0" << endl;
    }
    else if (b == 0) {
        cout << "1" << endl;
    }

    //Does the Multiplying
    if (b < 0) {
        bvar *= -1;
    }
    for (int p=bvar; p>1; p--) {
        avar = avar * a;
    }

    //Cases involving 1, -1, or a positive b value
    if (avar == 1 || avar == -1 || b > 0) {
        cout << avar << endl;
    }
    //If a is larger than one
    else if (avar > 0) {
        cout << setprecision(3) <<  "1/" << avar << " or " << 1/double(avar) << endl;
    }
    //If a is smaller than one
    else if (avar < 0) {
        cout << setprecision(3) << "-1/" << avar*-1 << " or " << 1/double(avar) << endl;
    }
}

int main() {
    int a, b;

    input (a, b);
    power (a, b);

    return 0;
}
