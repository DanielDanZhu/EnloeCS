#include <iostream>
#include <fstream>

using namespace std;

int main(){
    cout<<"Least to Greatest:"<<endl;
    int values[10],temp,count=0;
    ifstream infile;
    infile.open("S://Public/Wright/CompSci/BubbleSortTest.txt");
        while(infile.good()){
            infile>>values[count];
            count++;
        }
    infile.close();
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
        if(values[i]<values[j]){
           temp=values[j];
           values[j]=values[i];
           values[i]=temp;
        }
        }
    }
    count=0;
    while(count<10){
        cout<<values[count]<<endl;
        count++;
    }
    cout<<"Greatest to Least: "<<endl;
    infile.open("H://Computer Science/bubblesort.txt");
        while(infile.good()){
            infile>>values[count];
            count++;
        }
    infile.close();
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
        if(values[i]>values[j]){
           temp=values[j];
           values[j]=values[i];
           values[i]=temp;
        }
        }
    }
    count=0;
    while(count<10){
        cout<<values[count]<<endl;
        count++;
    }

return 0;
}
