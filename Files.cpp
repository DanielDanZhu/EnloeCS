#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
    int count=0;
    double scores[10],top=0,bottom=11,avg=0;
    ifstream infile;
    infile.open("S://Public/Wright/Comp Sci Stuff/project17test.txt");
        while(infile.good()){
            infile>>scores[count];
            count++;
        }

    infile.close();
    for(int i=0;i<10;i++){
        if(scores[i]>top){
            top=scores[i];
        }
        else if(scores[i]<bottom){
            bottom=scores[i];
        }
        avg+=scores[i];

    }
    avg=(avg-top-bottom)/8;
    cout<<setprecision(2);
    cout.setf(ios::showpoint|ios::fixed);
    cout<<"Highest Score: "<<top<<endl;
    cout<<"Lowest Score: "<<bottom<<endl;
    cout<<"Average without High and Low Scores: "<<avg;
return 0;
}
