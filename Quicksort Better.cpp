#include "H:\C++\MyFunctions.h"

using namespace std;

int main () {
    const int num = 20;
    int List[num];// = {12, 9, 2, 2, 5, 15, 20, 3, 1, 9, 8, 17, 4, 11, 7, 2, 0, 16, 10, 6};
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

    quickSort(List, start, ending);

    ///Displaying the sorted list
    cout << "Sorted:   ";
    for (int j=0; j<num; j++) {
        cout << List[j] << " ";
    }
    cout << endl;

    return 0;
}
