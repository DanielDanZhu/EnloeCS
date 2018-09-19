#include "H:\C++\MyFunctions.h"

using namespace std;

void quickSort (int List[], int &s, int &e) {
    int piv = s;
    s++;
    int l = s;
    int r = e;
    int temp;

    ///Only two elements, just compare
    if (s==e) {
        if (List[piv] > List[s]) {
            temp = List[piv];
            List[piv] = List[s];
            List[s] = temp;
        }
    }

    else {
        ///Moving the left position
        while (List[l] <= List[piv] && l < e) {
            l++;
        };

        ///Moving the right position
        while (List[r] > List[piv] && r > l) {
            r--;
        };

        ///High end
        if (List[l] >= List[piv] && l==e) {
            temp = e-1;
            quickSort(List, piv, temp);
        }
        ///Low pivot, no swap
        else if (r==s) {
            quickSort(List, s, e);
        }
        ///High pivot, swap
        else if (l==e) {
            temp = List[piv];
            List[piv] = List[e];
            List[e] = temp;

            temp = e-1;
            quickSort(List, piv, temp);
        }
        else {
            ///Left value smaller than right, swap l and r, quickSort again
            if (l<r) {
                temp = List[r];
                List[r] = List[l];
                List[l] = temp;

                quickSort (List, piv, e);
            }
            ///Two piles, swap pivot and quickSort both piles
            else if (l==r) {
                temp = List[piv];
                List[piv] = List[l-1];
                List[l-1] = temp;

                temp = l-2;
                quickSort (List, piv, temp);
                quickSort (List, l, e);
            }
        }
    }
}

int main () {
    const int num = 20;
    int List[num] = {};
    int start = 0;
    int ending = num-1;

    srand (time(NULL));

    ///Generates the random array
    for (int k=0; k<num; k++) {
        List[k] = (rand()%10);
    }

    ///Displaying the unsorted list
    cout << "Unsorted: ";
    for (int l=0; l<num; l++) {
        cout << List[l] << " ";
    }
    cout << endl;

    int x;
    //cin >> x;
    quickSort(List, start, ending);

    ///Displaying the sorted list
    cout << "Sorted:   ";
    for (int j=0; j<num; j++) {
        cout << List[j] << " ";
    }
    cout << endl;

    return 0;
}
