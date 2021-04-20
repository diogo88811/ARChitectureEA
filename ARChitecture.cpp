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
  //int room[H][n][2];
  vector<vector<vector<int> > > room (H,vector<vector<int> >(n,vector <int>(2,0)));

  int solution = 0;

  for (int i = 0; i < H; i++)
  {
    for (int j = 0; j < n; j++)
    {
      room[i][j][0] = 0;
      room[i][j][1] = 0;
    }
  }

  //base case
  room[H - h][0][0] = 1;
  
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < H; j++)
    {
      if (room[j][i][0] >= 1)
      { // going up
        for (int k = 0; k < h - 1; k++)
        {
          if(j - k - 1 >= 0){
            room[j - k - 1][i + 1][0] = mod_add(room[j - k - 1][i + 1][0],room[j][i][0],1000000007);
          }
          
        }

        for (int k = 0; k < h-1; k++)
        {
          if((j + k + 1) < H-h+1){
            
            room[j + k + 1][i + 1][1] = mod_add(room[j + k + 1][i + 1][1],room[j][i][0],1000000007);
          }
        }
      }
      if (room[j][i][1] >= 1)
      { //going down
        for (int k = 0; k < h-1; k++)
        {
          if((j + k + 1) < H-h+1){
            room[j + k + 1][i + 1][1] = mod_add(room[j + k + 1][i + 1][1],room[j][i][1],1000000007);
          }
          
        }
      }
    }
  }

  for(int i = 0; i < n; i++){
    solution = mod_add(room[H-h][i][1], solution,1000000007);
  }

  cout << mod_abs(solution,1000000007) << endl;

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