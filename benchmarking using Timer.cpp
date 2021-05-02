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



int main(){
    Timer timer;
    int val=0;
    for(int i=0;i<1000;i++){
        val+=2;
    }
    cout<<val<<endl;
}