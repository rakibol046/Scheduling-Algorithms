#include<iostream>
using namespace std;
int main(){
    int burstTime[]={24,3,3};
    int p[]={1,2,3};
    int waitingTime[3];
    int turnArountTime[3];
    int AvarageWatingTime=0, AvarageturnArountTime=0;
    waitingTime[0]=0;
    for(int i=1; i<3; i++){
        waitingTime[i] =  burstTime[i-1] + waitingTime[i-1];
    }
    for(int i=0; i<3; i++){
        turnArountTime[i] =  burstTime[i] + waitingTime[i];
    }

    for(int i=0; i<3; i++){
       AvarageWatingTime = AvarageWatingTime + waitingTime[i];
       cout << "P" << p[i] << "\tWaiting Time " << waitingTime[i] <<endl;
    }
    cout << "Average waiting time " << AvarageWatingTime/3;
    cout << "\n\n\n";
    for(int i=0; i<3; i++){
       AvarageturnArountTime = AvarageturnArountTime + turnArountTime[i];
       cout << "P" << p[i] << "\tTurn Around Time " << turnArountTime[i] <<endl;
    }
    cout << "Average turn around time " << AvarageturnArountTime/3;

return 0;
}
