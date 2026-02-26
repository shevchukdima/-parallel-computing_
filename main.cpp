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

void processColumns(Matrix& matrix, int N, int start, int end)
{
    for (int j = start; j < end; j++)
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

void parallel(Matrix& matrix, int N, int num_threads)
{
    vector<thread> threads;

    int chunk = N / num_threads;

    for (int t = 0; t < num_threads; t++)
    {
        int start = t * chunk;
        int end = (t == num_threads - 1) ? N : start + chunk;

        threads.emplace_back(processColumns,
                             ref(matrix),
                             N,
                             start,
                             end);
    }

    for (auto& th : threads)
        th.join();
}



int main()
{
    int N = 2000;




}