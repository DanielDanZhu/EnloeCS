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
    int term1 = term - 1;
    int term2 = term - 2;

    if (term == 1) {
        return seed;
    }
    else if (term == 2) {
        return seed1;
    }
    else if (term > 2) {
        return (fib(seed, seed1, term1) + fib(seed, seed1, term2));
    }
}

int main() {
    int seed, seed1, value, term;

    input (term, seed, seed1);
    value = fib (seed, seed1, term);

    cout << value << endl;
}
