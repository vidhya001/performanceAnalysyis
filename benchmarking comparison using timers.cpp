#include<iostream>
#include<memory>
#include<chrono>
using namespace std;
class Timer{
    
    public:
    Timer(){
        auto m_StartTimepoint=chrono::high_resolution_clock::now();
    }
    
    
    ~Timer(){
        Stop();
    }
    
    void Stop(){

    auto endTimePoint=chrono::high_resolution_clock::now();
    auto start=chrono::time_point_cast<chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
    auto end=chrono::time_point_cast<chrono::microseconds>(endTimePoint).time_since_epoch().count();
    auto duration = (end-start)*0.001;
    cout<<duration<<endl;
    
        
    }
    
private:
    chrono::time_point<chrono::high_resolution_clock> m_StartTimepoint;
    
};


void fun1(){
    cout<<"fun1"<<endl;
    Timer timer1;
    return;
}
void fun2(){
    cout<<"fun2"<<endl;
    Timer timer2;
    int val=0;
    for(int i=0;i<1000;i++){
        val++;
    }
    return;
}

int main(){
    Timer timer;
    int val=0;
    fun1();
    fun2();
    
    cout<<val<<endl;
}