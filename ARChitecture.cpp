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

int mod_abs(int a, int mod)
{
  return ((a % mod) + mod) % mod;
}

int mod_add(int a, int b, int mod)
{
  return (mod_abs(a, mod) + mod_abs(b, mod)) % mod;
}

int mod_sub(int a, int b, int mod)
{
  return mod_add(a, -b, mod);
}


void play(int n, int h, int H)
{
  vector<vector<vector<int>>> room(H, vector<vector<int>>(n, vector<int>(2, 0)));

  int solution = 0;

  //base case
  room[H - h][0][0] = 1;

  for (int i = 1; i < n; i++)
  {
    for (int j = H - h - i; j >= H - h - i * h + 1; j--)
    {
      if (j < 0)
      {
        break;
      }
      else
      { 
        
        room[j][i][0] = mod_sub(mod_add(room[j + 1][i][0] , room[j + 1][i - 1][0], 1000000007) , room[j + h][i-1][0],1000000007);
      }
    }

    for(int j = 1; j < H-h+1; j++){
      if(j+h <= H){

        room[j][i][1] = mod_add(mod_add(room[j - 1][i][1] , room[j - 1][i -1 ][1],1000000007) , room[j - 1][i -1][0],1000000007);
        if(j-h >=0){
          room[j][i][1] = mod_sub(room[j][i][1],room[j-h][i-1][1],1000000007 );
          room[j][i][1] = mod_sub(room[j][i][1],room[j-h][i-1][0],1000000007 );
        }
      }
    }
    solution = mod_add(room[H - h][i][1], solution, 1000000007);
  }

  cout << mod_abs(solution, 1000000007) << endl;

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

    play(n, h, H);
  }
}