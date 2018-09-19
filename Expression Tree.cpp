#include <iostream>
#include <string>

using namespace std;

class BNode {
    private:
        char data;
        int value;
        BNode *left;
        BNode *right;
        int depth;

    public:
        BNode(int da, BNode *l, BNode *r, int v, int de) {
            data = da;
            left = l;
            right = r;
            value = v;
            depth = de;
        }
        char getData() {return data;}
        BNode *getLeft() {return (left);}
        BNode *getRight() {return (right);}
        void setLeft(BNode *l) {left = l;}
        void setRight(BNode *r) {right = r;}
        void setVal(int v) {value = v;}
};

class ExTree {
    private:
        BNode *root;
        string input;
    public:
        ExTree() {
            root = NULL;
        }
        void inputFunc() {
            cout << "Enter your expression: ";
            cin >> input;
            cout << endl;
        }
        void setTree() {
            root = new BNode(input[0], NULL, NULL, -9999, 0);
            BNode *current = root;
            // && ((int(current->getData())<48 || int(current->getLeft()->getData())>57))

            for (int x=1; x<input.size(); x++) {
                BNode *newbie = new BNode(input[x], NULL, NULL, -9999, 0);
                do {
                    if (current->getLeft() != NULL && ((int(current->getLeft()->getData())>=48 && int(current->getData())<=57))) {
                        if (current->getRight() != NULL) {
                            current = current->getRight();
                        }
                        else {
                            current->setRight(newbie);
                            current = root;
                        }
                    }
                    else if (current->getLeft() != NULL && ((int(current->getLeft()->getData())<48 || int(current->getData())>57))) {
                        if (current->getLeft()->getLeft() == NULL || current->getLeft()->getRight() == NULL) {
                            current = current->getLeft();
                        }
                        else {
                            if (current->getRight() != NULL) {
                                current = current->getRight();
                            }
                            else {
                                current->setRight(newbie);
                                current = root;
                            }
                        }
                    }
                    else if (current->getLeft() == NULL) {
                        current->setLeft(newbie);
                        current = root;
                    }
                } while (current != root);
                //printInfix(current);
                //cout << endl;
            }
        }
        void printInfix (BNode *curr) {
            if (curr->getLeft() != NULL) {
                printInfix(curr->getLeft());
            }
            cout << curr->getData();
            if (curr->getRight() != NULL) {
                printInfix(curr->getRight());
            }
        }
        void execute() {
            inputFunc();
            setTree();
            BNode *current = root;
            printInfix(current);
        }

};

int main() {
    ExTree waka;
    waka.execute();
}
