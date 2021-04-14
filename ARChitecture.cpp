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
    cout << "isto é um teste de merda\n";
}

int mod_abs(int a, int mod) {
  return ((a % mod) + mod) % mod;
}

int mod_add(int a, int b, int mod) {
  return (mod_abs(a, mod) + mod_abs(b, mod)) % mod;
}

int mod_sub(int a, int b, int mod) {
  return mod_add(a, -b, mod);
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