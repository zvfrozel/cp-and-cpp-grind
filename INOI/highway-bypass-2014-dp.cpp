#include <bits/stdc++.h>
using namespace std;

#define MOD 20011
using vvb = vector<vector<bool>>;
using vvi = vector<vector<int>>;

int main () {
  int r, c, d;
  cin >> r >> c >> d;

  vvb map(r, vector<bool>(c));
  vvi dp(r, vector<int>(c)); // Num paths to (x, y) without speeding
  vvi dp_r = dp; // Num paths, but last move increased x-coord
  vvi dp_d = dp; // Num paths, but last move increased y-coord
  int m;

  dp[0][0] = dp_r[0][0] = dp_d[0][0] = 1; // Base case
  for (int i=0; i<r; i++) {
    for (int j=0; j<c; j++) {
      cin >> m;
      if (m) map[i][j] = true;
      if (i == 0 && j == 0) {
        // cout << 1 << " ";
        if (!map[0][0]) {
          cout << 0;
          return 0;
        }
        continue;
      }

      if (i > 0 && map[i-1][j]) {
        dp_d[i][j] = dp[i-1][j];
        if (i >= d+1) {
          bool speeding = true;
          for (int k=2; k<=d+1; k++) {
            if (!map[i-k][j]) {
              speeding = false;
              break;
            }
          }
          if (speeding) {
            dp_d[i][j] = (dp[i-1][j] + MOD - dp_r[i-d-1][j]) % MOD;
          }
        }
      }

      if (j > 0 && map[i][j-1]) {
        dp_r[i][j] = dp[i][j-1];
        if (j >= d+1) {
          bool speeding = true;
          for (int k=2; k<=d+1; k++) {
            if (!map[i][j-k]) {
              speeding = false;
              break;
            }
          }
          if (speeding) {
            dp_r[i][j] = (dp[i][j-1] + MOD - dp_d[i][j-d-1]) % MOD;
          }
        }
      }
      dp[i][j] = (dp_r[i][j] + dp_d[i][j]) % MOD;
      // cout << dp[i][j] << " ";
      // if (j == c-1) cout << "\n";
    }
  }
  // if (!map[r-1][c-1]) {
  //   cout << 0;
  //   return 0;
  // }
  cout << dp[r-1][c-1];
  return 0;
}
