#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;
/*
t ≤ 20
n ≤ 500
h ≤ 500
H ≤ 60000
*/

//function to debug 
void print(int n, int h, int H){
  cout << "n -> " << n << endl;
  cout << "h -> " << h << endl;
  cout << "H -> " << H << endl;
}

//function to debug 
void printRoom(int n,int H,vector<vector<int>> room){
  for(int i = 0 ; i < H ; i++){
    for(int j = 0 ; j < n ; j ++){
      cout << room[i][j] << " ";
    }
    cout << endl;
  }
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

void play(int n, int h, int H){
  vector<vector<int>> room(H, vector<int>(n));
  printRoom(n,H,room);
}

int main()
{
    int ntestCases, n, h, H;

    cin >> ntestCases;

    for (int i = 0; i < ntestCases; i++)
    {
      cin >> n;
      cin >> h;
      cin >> H;

      play(n,h,H);

    }
    
}