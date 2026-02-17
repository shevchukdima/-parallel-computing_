#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>

using namesapce std;

using Matrix = vecor<vector<int>>;

void fillMatrix(Matrix& matrix, int N)
{
    randome_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1,1000);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            matrix[i][j] = dist(gen);
}


