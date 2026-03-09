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




int main()
{

  return 0;
}