#include <iostream>
#include <vector>
#include <thread>
#include <random>
#include <chrono>

using namespace std;

using Matrix = vector<vector<int>>;

void fillMatrix(Matrix& matrix, int N)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            matrix[i][j] = dist(gen);
}
