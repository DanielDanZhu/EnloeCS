#include <iostream>
#include <iomanip>
#include <string.h.>
#include <cstdlib>
#include <math.h>

using namespace std;

class Node {
    private:
        Node* left;
        Node* right;
        char data;
        int value;
        int num;
        Node* end;
    public:
        char getdata();
        void setleft(Node *n);
        void setright(Node *n);
        Node* getright() {return right;};
        Node* getleft() {return left;};
        Node(char a);
        int getvalue();
        void setvalue(int a);
        void setnum(int a);
        int getnum();
        void setend(Node *n);
        Node* getend();
};

Node::Node(char a) {
    left=NULL;
    right=NULL;
    data=a;
    value=NULL;
    num=0;
}

char Node::getdata() {
    return data;
}

void Node::setleft(Node *n) {
    left=n;
}

void Node::setright(Node *n) {
    right=n;
}
void Node::setvalue(int a) {
    value=a;
}
int Node::getvalue() {
    return value;
}
void Node::setnum(int a) {
    num=a;
}
int Node::getnum() {
    return num;
}
Node* Node::getend() {
    return end;
}
void Node::setend(Node *n) {
    end=n;
}

int number(char a) {
    if ((a!='+') and (a!='-') and (a!='/') and (a!='*') and (a!='^') and (a!='%')) {
        return 1;
    }
    else {
        return 0;
    }
}

int convert(char a) {
    string x=" 123456789";
    int b=x.find(a);
    return b;
}


void operate(Node* a,Node* b,Node* c) {
    cout << b->getvalue() << endl << c->getvalue() << endl;
    if (a->getdata()=='+') {
        a->setvalue(b->getvalue()+c->getvalue());
    }
    else if (a->getdata()=='-') {
        a->setvalue(b->getvalue()-c->getvalue());
    }
    else if (a->getdata()=='*') {
        a->setvalue(b->getvalue()*c->getvalue());
    }
    else if (a->getdata()=='%') {
        a->setvalue(b->getvalue()%c->getvalue());
    }
    else if (a->getdata()=='/') {
        if ((c->getdata()=='0') or (c->getvalue()==0)) {
            cout<<"undefined"<<endl;
        }
        else {
            a->setvalue(b->getvalue()/c->getvalue());
        }
    }
    else if (a->getdata()=='^') {
        int x=b->getvalue();
        int y=c->getvalue();
        a->setvalue(pow(x,y));
    }
}


class Etree{
    private:

    public:
        Node *root;
        Node *last;
        Etree();
        void printPrefix(Node *start);
        void print(Node *start);
        void printPostfix(Node *start);
        void insert(char a[],int b,int i,Node *n);
        void evaluate(Node *n);
        void check(Node *n,char a);
};

Etree::Etree() {
    root=NULL;
    last=NULL;
}

void Etree::printPrefix(Node *start) {
    Node *cur;
    cur = start;

    cout<<cur->getdata();
    if ((cur->getleft()!=NULL)) {
        printPrefix(cur->getleft());
    }
    if (cur->getright()!=NULL) {
        printPrefix(cur->getright());
    }
}

void Etree::print(Node *start) {
    Node *cur;
    cur=start;

    if ((cur->getleft()!=NULL)) {
        print(cur->getleft());
    }
    cout<<cur->getdata();
    if (cur->getright()!=NULL) {
        print(cur->getright());
    }
}

void Etree::printPostfix(Node *start) {
    Node *cur;
    cur = start;

    if ((cur->getleft()!=NULL)) {
        printPostfix(cur->getleft());
    }
    if (cur->getright()!=NULL) {
        printPostfix(cur->getright());
    }
    cout<<cur->getdata();
}


void Etree::insert(char a[],int b,int i,Node *n) {
    int j=b;
    if (root==NULL) {
        Node *e=new Node(a[i]);
        root=e;
        last=root;
        last->setend(root);
    }
    else {
        Node *cur;
        cur=n;
        Node *y=new Node(a[i]);
        int b=0;
        if (last->getleft()==NULL) {
            if (number(y->getdata())==1) {
                y->setvalue(convert(a[i]));
                if (y->getvalue()==-1) {
                    y->setvalue(0);
                }
            }
            last->setleft(y);
            y->setend(last);
            if (number(y->getdata())==0) {
                last=y;
            }
        }
        else if (last->getright()==NULL) {
            if (number(y->getdata())==1) {
                y->setvalue(convert(a[i]));
                if (y->getvalue()==-1) {
                    y->setvalue(0);
                }
            }
            last->setright(y);
            y->setend(last);
            if (number(y->getdata())==0) {
                last=y;
            }
        }
        else {
            last=last->getend();
            insert(a,b,i,last);
        }
    }
}

void Etree::evaluate(Node *n) {
    Node *cur=n;
    if (cur->getleft()->getvalue()==NULL) {
        evaluate(cur->getleft());
        operate(cur,cur->getleft(),cur->getright());
    }
    if (cur->getright()->getvalue()==NULL) {
        evaluate(cur->getright());
        operate(cur,cur->getleft(),cur->getright());
    }
    if ((cur->getright()->getvalue()!=NULL) and (cur->getleft()->getvalue()!=NULL)) {
        operate(cur,cur->getleft(),cur->getright());
    }
}



int main() {
    Etree e;
    string input;
    cin>>input;
    char input2[input.length()];
    Node* n;
    for (int i=0;i<input.length();i++) {
        input2[i]=input[i];
    }
    for (int i=0;i<input.length();i++) {
        e.insert(input2,input.length(),i,e.root);
    }
    cout << endl << "Prefix: ";
    e.printPrefix(e.root);
    cout << endl << endl << "Infix: ";
    e.print(e.root);
    cout<<endl<<endl << "Postfix: ";
    e.printPostfix(e.root);
    cout << endl << endl;
    e.evaluate(e.root);
    cout<<endl<<setprecision(6)<<e.root->getvalue();

    return 0;
}
