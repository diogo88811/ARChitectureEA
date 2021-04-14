#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;

void print(vector<vector<int>> line, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << line[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int ntestCases, n, h, H, numbers;
    vector<vector<int>> line;
    vector<int> aux;

    cin >> ntestCases;

    for (int i = 0; i < ntestCases; i++)
    {
        aux.clear();
        for (int k = 0; k < 3; k++)
        {
            cin >> numbers;
            aux.push_back(numbers);
        }
        line.push_back(aux);
    }
    print(line, ntestCases);
}