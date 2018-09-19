//Daniel Zhu

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int num;
    vector<int> sequence;

    cout << "Input: ";
    cin >> num;

    int temp = 10;
    int numval = num;
    do {
        sequence.push_back((numval%temp)/(temp/10));
        numval = numval - (numval%temp);
        temp*=10;
    } while (numval>0);

    reverse(sequence.begin(), sequence.end());

    int length = sequence.size();
    do {
        temp = 0;

        for (int x=length; x>0; x--) {
            temp+= sequence[sequence.size()-x];
        }
        sequence.push_back(temp);
    } while(temp <num);

    if (sequence[sequence.size()-1] == num) {
        cout << "Yes, Position: " << sequence.size() << endl;
    }
    else if (sequence[sequence.size()-1] != num) {
        cout << "No" << endl;
    }
}
