#include <iostream>

using namespace std;

class ThreeNums{
private:
    int a, b, c;
public:
    ThreeNums();
    void input();
    void operator -();
    void operator +(ThreeNums);
    void display();
};

ThreeNums::ThreeNums(){
    a=b=c=0;
}

void ThreeNums::input(){
    cout<<"Part a? "<<endl;
    cin>>a;
    cout<<"Part b? "<<endl;
    cin>>b;
    cout<<"Part c? "<<endl;
    cin>>c;
    cout<<endl;
}

void ThreeNums::operator -(){
    a=-a;
    b=b;
    c=-c;
}

void ThreeNums::operator+(ThreeNums tn){
    cout<<"a: "<<a+tn.a<<endl;
    cout<<"b: "<<b+tn.b<<endl;
    cout<<"c: "<<c+tn.c<<endl;
    cout<<endl;
}

void ThreeNums::display(){
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;
    cout<<"c: "<<c<<endl;
    cout<<endl;
}

int main(){
    ThreeNums tn1, tn2;

    tn1.input();
    tn2.input();
    -tn1;
    tn1.display();
    -tn2;
    tn2.display();
    tn1+tn2;

    return 0;
}
