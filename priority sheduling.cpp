#include<iostream>
using namespace std;
int main(){
    int p[]={1,2,3,4,5}, position,i,j,temp;
    int burstTime[]={10,1,2,1,5};
    int priority[]={3,1,4,5,2};
    int waitingTime[5];
    int turnArountTime[5];
    int AvarageWatingTime=0, AvarageturnArountTime=0;
    cout<< "Process\t burst time\t Priority\n";
      for(int i=0; i<5; i++){
        cout<<"p"<<p[i] << "\t   "<<burstTime[i] <<"\t\t   "<< priority[i]<<endl;
    }
    cout<<endl <<endl;

    for(i=0;i<5;i++)
    {
        position=i;
        for(j=i+1;j<5;j++)
        {
            if(priority[j]<priority[position])
                position=j;
        }

        temp=priority[i];
        priority[i]=priority[position];
        priority[position]=temp;

        temp=burstTime[i];
        burstTime[i]=burstTime[position];
        burstTime[position]=temp;

        temp=p[i];
        p[i]=p[position];
        p[position]=temp;
    }

     waitingTime[0]=0;
    for(int i=1; i<5; i++){
        waitingTime[i] =  burstTime[i-1] + waitingTime[i-1];
    }
    for(int i=0; i<5; i++){
        turnArountTime[i] =  burstTime[i] + waitingTime[i];
    }

    for(int i=0; i<5; i++){
       AvarageWatingTime = AvarageWatingTime + waitingTime[i];
       cout << "P" << p[i] << "\tWaiting Time " << waitingTime[i] <<endl;
    }
    cout << "Average waiting time " << double(AvarageWatingTime)/5;
    cout << "\n\n\n";
    for(int i=0; i<5; i++){
       AvarageturnArountTime = AvarageturnArountTime + turnArountTime[i];
       cout << "P" << p[i] << "\tTurn Around Time " << turnArountTime[i] <<endl;
    }
    cout << "Average turn around time " << double(AvarageturnArountTime)/5;

return 0;
}
