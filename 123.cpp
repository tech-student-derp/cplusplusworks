#include<iostream>
#include<limits>
using namespace std;
int main(){
    int n,g,sum=0,hi=-1,lo=101;
    float avg;
    cout<<"Enter number of students: ";
    while(!(cin>>n)&&n>0){
        cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Invalid number. Try again: ";
    }
    for(int i=1;i<=n;++i){
        cout<<"Enter grade of student "<<i<<": ";
        while(!(cin>>g)||g<0||g>100){
            cin.clear();cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Invalid grade. Try again: ";
        }
        sum+=g;if(g>hi)hi=g;if(g<lo)lo=g;
    }
    avg=(float)sum/n;
    cout<<"Average: "<<avg<<"\nHighest: "<<hi<<"\nLowest: "<<lo<<"\nRemark: ";
    if(avg>=90)cout<<"Excellent";
    else if(avg>=75)cout<<"Good";
    else cout<<"Needs Improvement";
    return 0;
}
