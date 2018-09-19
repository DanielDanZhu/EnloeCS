#include <iostream>

using namespace std;

void input (int &term, int &seed, int &seed1) {
    cout << "Enter your first seed: ";
    cin >> seed;
    cout << "Enter your second seed: ";
    cin >> seed1;
    cout << "Enter the term in the sequence you want to see: ";
    cin >> term;
}

int fib(int &seed, int &seed1, int &term) {
    int temp;
    term--;

    if (term == 0) {
        return seed;
    }
    else {
        temp = seed + seed1;
        seed = seed1;
        seed1 = temp;
        fib(seed, seed1, term);
    }
}

int main() {
    int term, seed, seed1;

    input (term, seed, seed1);
    fib (seed, seed1, term);

    cout << seed << endl;
}
