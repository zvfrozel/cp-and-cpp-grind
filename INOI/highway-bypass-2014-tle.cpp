#include <bits/stdc++.h>
using namespace std;

#define MOD 20011
using vvi = vector<vector<int>>;

int r, c, d;
vvi roadmap, memo, memod, memor; // Make roadmap a bool vector but sure

int numdown(int x, int y);
int numright(int x, int y);
// Function prototypes

int chkmemo(int x, int y, vvi& memo) {
    // Edge cases and memoized cases and invalidated cases
    if (x < 0 || y < 0) return 0;
    if (x == 0 && y == 0) return 1;
    if (!roadmap[y][x]) return 0;
    return memo[y][x];
}

int numgoodpaths(int x, int y) {
    // numpaths but no speeding allowed
    int k = chkmemo(x, y, memo);
    if (k != -1) return k;
    return (numdown(x, y) + numright(x, y)) % MOD;
}

int numdown(int x, int y) {
    // good paths but last move increased the y-coordinate
    int k = chkmemo(x, y, memo);
    if (k != -1) return k;
    int ans = numgoodpaths(x, y-1);
    for (int i=1; i<d+1; i++) {
        if (y-i < 0 || !roadmap[y-i][x]) return ans;
    } // otherwise, now there is a possiblity of speeding that is a good path until (x, y-1)
    return (ans - numright(x, y-d-1) + MOD) % MOD;
}

int numright(int x, int y) {
    // good paths but last move increased the x-coordinate
    int k = chkmemo(x, y, memo);
    if (k != -1) return k;
    int ans = numgoodpaths(x-1, y);
    for (int i=1; i<d+1; i++) {
        if (x-i < 0 || !roadmap[y][x-i]) return ans;
    } // otherwise, now there is a possiblity of speeding that is a good path until (x, y-1)
    return (ans - numdown(x-d-1, y) + MOD) % MOD;
}

int main() {
    cin >> r >> c >> d;

    roadmap.resize(r);
    for (int i=0; i<r; i++) {
        roadmap[i].resize(c);
        for (int j=0; j<c; j++) {
            cin >> roadmap[i][j];
        }
    }

    memo.assign(r, vector<int>(c, -1));
    memod = memor = memo;
    cout << numgoodpaths(c-1, r-1);
    return 0;
}

// Time limit exceeded, use DP rather than recursion
