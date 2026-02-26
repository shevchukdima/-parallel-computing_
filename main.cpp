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

void sequentail(Matrix& matrix, int N)
{
    for (int j = 0; j < N; j++)
    {
        int min_val = matrix[0][j];

        for (int i = 1; i < N; i++)
        {
            if (matrix[i][j] < min_val)
                min_val = matrix[i][j];
        }

        matrix[N - 1 - j][j] = min_val;
    }
}


int main()
{
    int N = 2000;




}