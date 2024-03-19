#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <string>
using namespace std;
vector<int> stats;
set<int> calls;
int timee=0;

void displayStats(int numFloors){
    cout<<"Analysis:"<<endl<<endl;
    cout<<"Elevator running time:"<<timee<<" seconds."<<endl;
    cout<<"Frequency of calls from each floor:"<<endl;
    for(int i=1; i<=numFloors;i++){
        cout<<"Floor "<<i<<": "<<stats[i]<<" calls"<<endl;
    }
}

void passangerRequests(int numFloors, int liftCapacity){
    int fl;
    for(int i=0;i<liftCapacity;i++){
        fl=rand()%numFloors+1;
        calls.insert(fl);
        cout<<"Passanger called from:"<<fl<<" "<<i<<endl;
    }
    cout<<endl<<"..."<<endl<<endl;
}

void processTime(){
    int top=*calls.rbegin();
    timee+=15*top*2;//15 секунд требуется дляпреодоления 1го этажа
    timee+=7*(calls.size()-1);//7 секунд требуется для остановки и высадки пассажиров
}

void expStat(){
    while(!calls.empty()){
        int top=*calls.rbegin();
        stats[top]++;
        calls.erase(top);    
    }
}
    
int main(){
    srand((unsigned) time(NULL)); 
    int numFloors, simulationTime, liftCapacity;
    cout<<"Welcome to elevator simulation!"<<endl<<"Input number of floors:";
    cin>>numFloors;
    cout<<"Input maximum number passenger per trip:";
    cin>>liftCapacity;
    cout<<"Input Simulation time:";
    cin>>simulationTime;
    simulationTime=simulationTime*60;   //из минуты в секунды
    
    for(int i=0;i<numFloors;i++)        //заполнение вектора статистики нулями
        stats.push_back(0);

    cout<<endl<<"Initializating simulation..."<<endl<<endl;

    while(simulationTime>timee){
        passangerRequests(numFloors,liftCapacity);
        processTime();
        expStat();
    }
    
    cout<<"Simulation complited..."<<endl<<endl;
    displayStats(numFloors);
    cout<<endl<<"Thank you for using elevator simulation!!!";
}