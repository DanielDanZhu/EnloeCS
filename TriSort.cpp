#include "H:\C++\MyFunctions.h"

using namespace std;

const int num = 30;

int main() {
    ofstream sortfile;
    sortfile.open("H://C++/trisort.txt");

    srand (time(NULL));

    int intarray[num];
    char chararray[num];
    double doubarray[num];

    for (int h=0; h<num; h++) {
        intarray[h] = (rand()%32001);
    }
    for (int j=0; j<num; j++) {
        chararray[j] = char(rand()%255);
    }
    for (int k=0; k<num; k++) {
        doubarray[k] = (double(rand()%32000))/32000;
    }

    for (int l=0; l<num; l++) {
        cout << intarray[l] << " ";

        if ((l+1)%10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    for (int y=0; y<num; y++) {
        cout << chararray[y] << " ";

        if ((y+1)%10 == 0) {
            cout << endl;
        }
    }
    cout << endl;
    for (int q=0; q<num; q++) {
        cout.setf(ios::showpoint|ios::fixed);
        cout << setprecision(4) << doubarray[q] << " ";

        if ((q+1)%10 == 0) {
            cout << endl;
        }
    }

    Bubblesort(intarray, num);
    Bubblesort(chararray, num);
    Bubblesort(doubarray, num);

    for (int l=0; l<num; l++) {
        sortfile << intarray[l] << " ";

        if ((l+1)%10 == 0) {
            sortfile << endl;
        }
    }
    sortfile << endl;
    for (int y=0; y<num; y++) {
        sortfile << chararray[y] << " ";

        if ((y+1)%10 == 0) {
            sortfile << endl;
        }
    }
    sortfile << endl;
    for (int q=0; q<num; q++) {
        sortfile.setf(ios::showpoint|ios::fixed);
        sortfile << setprecision(4) << doubarray[q] << " ";

        if ((q+1)%10 == 0) {
            sortfile << endl;
        }
    }
    sortfile.close();

    return 0;
}
