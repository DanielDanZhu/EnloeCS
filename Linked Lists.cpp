#include <iostream>

using namespace std;

class ListNode {
    private:
        int data;
        ListNode *next;
    public:
        ListNode(int d, ListNode *n) {
            data = d;
            next = n;
        }
        int getData() {return data;}
        ListNode *getNext() {return (next);}
        void setNext(ListNode *n) {next = n;}
};

class List {
    private:
        ListNode *first;
    public:
        List() {first = NULL;}
        void print() {
            ListNode *current = first;
            cout << "List: ";
            while (current != NULL) {
                cout << current -> getData() << " ";
                current = current -> getNext();
            }
            cout << endl << endl;
        }
        void insert(int x) {
            if (first == NULL) {
                first = new ListNode(x,NULL);
            }
            else {
                ListNode *current = first;

                if (x < first->getData()) {
                    current = new ListNode(x,first);
                    first = current;
                }
                else {
                    int truefalse = 0;
                        do {
                            if (current->getNext() == NULL) {
                                current->setNext(new ListNode(x,NULL));
                                truefalse = 1;
                            }
                            else if (x >= current->getData() && x <= current->getNext()->getData()) {
                                ListNode *newbie;
                                newbie = new ListNode(x,current->getNext());
                                current->setNext(newbie);
                                truefalse = 1;
                            }
                            current = current->getNext();
                        } while (truefalse == 0);
                }

                /*while (current -> getNext() != NULL) {
                    current = current -> getNext();
                }
                current -> setNext(new ListNode(x,NULL));*/
            }
        }
        void menu() {
            int prompt, value;
            do {
                cout << "Menu:" << endl;
                cout << "<1> Enter values" << endl;
                cout << "<2> Print" << endl;
                cout << "<3> End Program" << endl;
                cout << "Enter: ";
                cin >> prompt;
                cout << endl;

                if (prompt == 1) {
                    string ask;
                    cout << "Input your list (-1 to end)" << endl;
                    do {
                        cout << "Enter: ";
                        cin >> value;
                        if (value != -1) {
                            insert(value);
                        }
                        /*cout << "Continue?";
                        cin >> ask;*/
                    } while (value != -1);
                    cout << endl;
                }
                else if (prompt == 2) {
                    print();
                }
            } while (prompt != 3);
        }
};

int main() {
    List l;
    l.menu();
    return 0;
}
