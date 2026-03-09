#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <random>

using namespace std;

using Clock = chrono::high_resolution_clock;

void fillArray(vector<int>& data)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,1000);

    for(auto &v : data)
        v = dist(gen);
}

void sequential(const vector<int>& data, int& result)
{
    result = 0;

    for(int v : data)
        if(v % 15 == 0)
            result ^= v;
}

void workerMutex(int start,int end,
                 const vector<int>& data,
                 int& result,
                 mutex& mtx)
{
    int local = 0;

    for(int i=start;i<end;i++)
        if(data[i] % 15 == 0)
            local ^= data[i];

    lock_guard<mutex> lock(mtx);
    result ^= local;
}


int main()
{

  return 0;
}