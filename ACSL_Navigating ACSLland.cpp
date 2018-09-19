#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

void input (char path[][2], char car[5], char road[5], double gasPrice[5], int i) {
    cout << "Start: ";
    cin >> path[i][0];
    cout << "End: ";
    cin >> path[i][1];
    cout << "Vehicle: ";
    cin >> car[i];
    cout << "Road: ";
    cin >> road[i];
    cout << "Average gas price: ";
    cin >> gasPrice[i];
    cout << endl;
}

void distanceCalc (char path[][2], int distance[5], int i) {
    string cities = "ABCDEFG";
    int citiesDistance[6] = {450, 140, 120, 320, 250, 80};
    int temp1 = cities.find(path[i][0]);
    int temp2 = cities.find(path[i][1]);

    distance[i] = 0;
    for (int j=temp1; j<temp2; j++) {
        distance[i] += citiesDistance[j];
    }
}

void timeCalc (int distance[5], char road[5], int time[5], int timeCarry[5], int i) {
    int mph;
    double timetemp, timecarrytemp;

    if (road[i] == 'I') {
        mph = 65;
    }
    else if (road[i] == 'H') {
        mph = 60;
    }
    else if (road[i] == 'M') {
        mph = 55;
    }
    else if (road[i] == 'S') {
        mph = 45;
    }
    timetemp = double(distance[i])/double(mph);

    double temp = timetemp-int(timetemp);
    time[i] = int(timetemp);
    timecarrytemp = temp*60;
    timeCarry[i] = int(timecarrytemp+.5);

    if (timeCarry[i] == 60) {
        timeCarry[i] = timeCarry[i] - 60;
        time[i]++;
    }
}

void gasCalc (int distance[5], char car[5], double gasPrice[5], double finalPrice[5], int i) {
    double mpg;
    if (car[i] == 'C') {
        mpg = 28;
    }
    else if (car[i] == 'M') {
        mpg = 25;
    }
    else if (car[i] == 'F') {
        mpg = 22;
    }
    else if (car[i] == 'V') {
        mpg = 20;
    }

    double gallon = int(distance[i])/mpg;
    finalPrice[i] = gallon*gasPrice[i];
}

void output (int distance[5], int time[5], int timeCarry[5], double finalPrice[5], int i) {
    cout << distance[i] << ", ";
    if (time[i] < 10) {
        cout << "0";
    }
    cout << time[i] << ":";
    if (timeCarry[i] < 10) {
        cout << "0";
    }
    cout << timeCarry[i] << ", ";
    cout.setf(ios::showpoint|ios::fixed);
    cout << setprecision(2) << "$" << finalPrice[i] << endl << endl;
}

int main () {
    char path[5][2];
    char car[5];
    char road[5];
    double gasPrice[5];

    int distance[5];
    int time[5];
    int timeCarry[5];
    double finalPrice[5];

    for (int i=0; i<5; i++) {
        input(path, car, road, gasPrice, i);
        distanceCalc(path, distance, i);
        timeCalc(distance, road, time, timeCarry, i);
        gasCalc(distance, car, gasPrice, finalPrice, i);
        output(distance, time, timeCarry, finalPrice, i);
    }
}
