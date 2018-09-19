#include "H:\C++\MyFunctions.h"

using namespace std;

class Tower {
    private:
        Stack s1, s2, s3;
        int num;
        int num_moves;
    public:
        Tower(int num) {
            for (int x=num; x>0; x--) {
                s1.insert(x);
            }
        }
        void move1(Stack &s, Stack &e) {
            int value = s.getLast();
            s.remove();
            e.insert(value);
            display();
        }
        void move2(Stack &s, Stack &e, Stack &t) {
            move1(s, t);
            move1(s, e);
            move1(t, e);
        }
        void move3(Stack &s, Stack &e, Stack &t) {
            move2(s, t, e);
            move1(s, e);
            move2(t, e, s);
        }
        void move4(Stack &s, Stack &e, Stack &t) {
            move3(s, t, e);
            move1(s, e);
            move3(t, e, s);
        }
        void move5(Stack &s, Stack &e, Stack &t) {
            move4(s, t, e);
            move1(s, e);
            move4(t, e, s);
        }
        void move6(Stack &s, Stack &e, Stack &t) {
            move5(s, t, e);
            move1(s, e);
            move5(t, e, s);
        }
        void display() {
            cout << "S1: ";
            s1.print();
            cout << "S2: ";
            s2.print();
            cout << "S3: ";
            s3.print();
            cout << endl;
            int v;
            cin >> v;
            cout << endl;
        }
        void execute(int &num) {
            display();
            if (num==1) {
                move1(s1, s3);
            }
            else if (num==2) {
                move2(s1, s3, s2);
            }
            else if (num==3) {
                move3(s1, s3, s2);
            }
            else if (num==4) {
                move4(s1, s3, s2);
            }
            else if (num==5) {
                move5(s1, s3, s2);
            }
            else if (num==6) {
                move6(s1, s3, s2);
            }
        }
};

int main () {
    int num;
    cout << "How many discs: ";
    cin >> num;

    Tower d(num);
    d.execute(num);

    return 0;
}
