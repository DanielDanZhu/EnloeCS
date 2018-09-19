#include<iostream>

using namespace std;

class Add {
    private:
        int a, b, c;

    public:
        //Add();
        int d;
        void input();
        void sum();
        void display();
        int geta();
        void operator-();
        void operator+(Add);
};

//Add::Add(){

void Add::input() {
    cout << "Input 3 numbers:";
    cin >> a >> b >> c;
}

void Add::sum() {
    d=a+b+c;
}

void Add::display() {
    cout << a << " " << b << " " << c << endl;
    cout << d << endl;
}

int Add::geta() {
    return a;
}

void Add::operator-() {
    a=-a;
    b=b;
    c=-c;
}

void Add::operator+(Add A2) {
    cout << a + A2.geta();
    cout << endl << "sweet";
}

int main() {
    Add a1, a2;

    a1.input();
    a1.sum();
    a1.display();
    -a1;
    a1.sum();
    a1.display();

    a2.input();
    a2.sum();
    a2.display();
    a1+a2;

    return 0;
}
