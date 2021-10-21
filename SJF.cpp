
#include<iostream>
using namespace std;
int main(){
    int burstTime[]={6,8,7,3};
    int p[]={1,2,3,4}, position,i,j,temp;
    int waitingTime[4];
    int turnArountTime[4];
    int AvarageWatingTime=0, AvarageturnArountTime=0;

      for(int i=0; i<4; i++){
        cout<<"p"<<p[i] << " Burst Time "<<burstTime[i] <<endl;
    }
    cout<<endl <<endl;



    for(i=0;i<4;i++)
    {
        position=i;
        for(j=i+1;j<4;j++)
        {
            if(burstTime[j]<burstTime[position])
                position=j;
        }

        temp=burstTime[i];
        burstTime[i]=burstTime[position];
        burstTime[position]=temp;

        temp=p[i];
        p[i]=p[position];
        p[position]=temp;
    }

     waitingTime[0]=0;
    for(int i=1; i<4; i++){
        waitingTime[i] =  burstTime[i-1] + waitingTime[i-1];
    }
    for(int i=0; i<4; i++){
        turnArountTime[i] =  burstTime[i] + waitingTime[i];
    }

    for(int i=0; i<4; i++){
       AvarageWatingTime = AvarageWatingTime + waitingTime[i];
       cout << "P" << p[i] << "\tWaiting Time " << waitingTime[i] <<endl;
    }
    cout << "Average waiting time " << AvarageWatingTime/4;
    cout << "\n\n\n";
    for(int i=0; i<4; i++){
       AvarageturnArountTime = AvarageturnArountTime + turnArountTime[i];
       cout << "P" << p[i] << "\tTurn Around Time " << turnArountTime[i] <<endl;
    }
    cout << "Average turn around time " << AvarageturnArountTime/4;

return 0;
}
