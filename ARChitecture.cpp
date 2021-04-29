#include <iostream>
#include <vector>
#include <sstream>
#include <math.h>
using namespace std;


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
 
  vector<vector<vector<int>>> room(H, vector<vector<int>>(3, vector<int>(2, 0)));

  int solution = 0;
  int maxH;
  //base case
  room[H - h][0][0] = 1;
  int k = 1;
  for (int i = 1; i < n; i++)
  {
    if ((i * (h - 1) + 1) <= H){
      maxH = i * (h - 1) + 1;
      maxH = H-maxH - h + 1;
    }
    else {
      maxH = 0;
    }
    for (int j = H - h - i; j >= maxH ; j--)
    {
      if (j < 0)
      {
        break;
      }
      else
      { 
        if(k == 0){
          room[j][k][0] = mod_sub(mod_add(room[j + 1][k][0] , room[j + 1][2][0], 1000000007) , room[j + h][2][0],1000000007);
          room[j][1][0] = 0;
          room[j][1][1] = 0;
        }
        else{
          room[j][k][0] = mod_sub(mod_add(room[j + 1][k][0] , room[j + 1][k - 1][0], 1000000007) , room[j + h][k-1][0],1000000007);
          if(k == 1){
            room[j][2][0] = 0;
            room[j][2][1] = 0;
          }

          if(k == 2){
              room[j][0][0] = 0;
              room[j][0][1] = 0;
          }
        }
      }
    }

    if(maxH <= 0){
      maxH = 1;
    }
    for(int j = maxH; j < H-h+1; j++){
      if(j+h <= H){
        if(k == 0){
          room[j][k][1] = mod_add(mod_add(room[j - 1][k][1] , room[j - 1][2 ][1],1000000007) , room[j - 1][2][0],1000000007);
          room[j][1][0] = 0;
          room[j][1][1] = 0;
        }
        else{
          room[j][k][1] = mod_add(mod_add(room[j - 1][k][1] , room[j - 1][k -1 ][1],1000000007) , room[j - 1][k -1][0],1000000007);
          if(k == 1){
            room[j][2][0] = 0;
            room[j][2][1] = 0;
          }

          if(k == 2){
              room[j][0][0] = 0;
              room[j][0][1] = 0;
            }
        }
        if(j-h >=0){
          if(k == 0){
            room[j][k][1] = mod_sub(room[j][k][1],room[j-h][2][1],1000000007 );
            room[j][k][1] = mod_sub(room[j][k][1],room[j-h][2][0],1000000007 );
            room[j][1][0] = 0;
            room[j][1][1] = 0;
          }
          else{
            room[j][k][1] = mod_sub(room[j][k][1],room[j-h][k-1][1],1000000007 );
            room[j][k][1] = mod_sub(room[j][k][1],room[j-h][k-1][0],1000000007 );
            if(k == 1){
              room[j][2][0] = 0;
              room[j][2][1] = 0;
            }

            if(k == 2){
              room[j][0][0] = 0;
              room[j][0][1] = 0;
            }

          }
          
        }
      }
    }
    solution = mod_add(room[H - h][k][1], solution, 1000000007);
    
    if(k == 2){
      k = 0;
    }
    else if(k == 1){
      k++;
    }

    else if(k == 0){
      k++;
    }
    
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