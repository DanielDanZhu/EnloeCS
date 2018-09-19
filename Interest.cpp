#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void input(double &princ, double &rate, double &compound) {
    cout << "Input a Principle Amount:" << endl;
    cin >> princ;
    cout << "Input a rate:" << endl;
    cin >> rate;
    cout << "How is the interest compounded?" << endl;
    cin >>  compound;
}

void math(double &amount, double &princ, double &rate, double &compound) {
    rate = rate/100;

    cout.setf(ios::showpoint|ios::fixed);
    cout << setprecision(2) << endl << "Original Value:  $" << princ << endl;

    for (int t=1; t<=10; t++) {
        amount = princ * pow((1+(rate/compound)),compound*t);
        cout.setf(ios::showpoint|ios::fixed);
        cout << setprecision(2) << setw(2) << t << ".  $" << amount << endl;
    }
}

int main() {
    double amount, princ, rate, compound;

    input (princ, rate, compound);
    math (amount, princ, rate, compound);
}
