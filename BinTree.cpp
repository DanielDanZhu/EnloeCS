#include <iostream>

using namespace std;

class BNode {
    private:
        char data;
        BNode *left;
        BNode *right;
        int depth;
    public:
        BNode(int da, BNode *l, BNode *r, int de) {
            data = da;
            left = l;
            right = r;
            depth = de;
        }
        char getData() {return data;}
        BNode *getLeft() {return (left);}
        BNode *getRight() {return (right);}
        void setLeft(BNode *l) {left = l;}
        void setRight(BNode *r) {right = r;}
};

class binTree {
    private:
        BNode *root;
        string input;
        int depth;
    public:
        binTree() {
            root = NULL;
            depth = 0;
        }
        void inputFunc (string &input) {
            cout << "Enter a string: ";
            cin >> input;
            cout << endl;
        }
        void setTree (string input) {
            root = new BNode(input[0], NULL, NULL, 0);
            BNode *curr = root;

            for (int i=1; i<input.size(); i++) {
                curr = root;
                int stop = 0;
                int depthcount = 1;

                while (stop == 0) {
                    if (int(input[i]) <= curr->getData()) {
                        if (curr->getLeft() == NULL) {
                            BNode *newbie = new BNode(input[i], NULL, NULL, depthcount);
                            curr->setLeft(newbie);
                            stop = 1;
                        }
                        else {
                            curr = curr->getLeft();
                            depthcount++;
                        }
                    }
                    else {
                        if (curr->getRight() == NULL) {
                            BNode *newbie = new BNode(input[i], NULL, NULL, depthcount);
                            curr->setRight(newbie);
                            stop = 1;
                        }
                        else {
                            curr = curr->getRight();
                            depthcount++;
                        }
                    }
                    if (depthcount > depth) {
                        depth = depthcount;
                    }
                }
            }
        }
        void print (BNode *curr) {
            if (curr->getLeft() != NULL) {
                print(curr->getLeft());
            }
            cout << curr->getData();
            if (curr->getRight() != NULL) {
                print(curr->getRight());
            }
        }
        void execute() {
            inputFunc(input);
            setTree(input);
            BNode *curr = root;
            cout << "Sorted String: ";
            print(curr);
            cout << endl;
            //cout << endl << "        Depth: " << depth << endl;
        }
};

int main() {
    binTree b;
    b.execute();
}
