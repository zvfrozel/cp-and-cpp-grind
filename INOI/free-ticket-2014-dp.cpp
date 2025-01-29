#include <bits/stdc++.h>
using namespace std;

#define INF 2.88e8

int dist_memo[230][230][231]; // C^3 space complexity but who cares
// dist_memo[i][j][k] = cheapest route from i to j passing through cities only from {0, ..., k-1}

int compute_dist(int i, int j, int k) {
    int d = dist_memo[i][j][k];
    if (d != -1) {
        return d;
    }

    int d1 = compute_dist(i, j, k-1);
    int d2 = compute_dist(i, k-1, k-1);
    int d3 = compute_dist(j, k-1, k-1);
    // cout << i << j << k << " " << d1 << " " << d2 << " " << d3 << "\n";
    d = min(d1, d2+d3);

    dist_memo[i][j][k] = dist_memo[j][i][k] = d;
    return d;
}

int main() {
    int c, f;
    cin >> c >> f;

    // Initialize dist_memo
    for (int i=0; i<c; i++) {
        dist_memo[i][i][0] = 0;
        for (int j=0; j<c; j++) {
            if (i != j) {
                dist_memo[i][j][0] = INF;
            }
            for (int k=1; k<(c+1); k++) {
                dist_memo[i][j][k] = -1;
            }
        }
    }

    int x, y, p;
    for (int i=0; i<f; i++) {
        cin >> x >> y >> p;
        x--;
        y--;
        dist_memo[x][y][0] = dist_memo[y][x][0] = p;
    }

    int max_dist = 0;
    for (int i=0; i<c; i++) {
    for (int j=0; j<c; j++) { // Could start from j=i+1
        max_dist = max(max_dist, compute_dist(i, j, c));
        // cout << i << " " << j << " " << dist_memo[i][j][c+1] << "\n";
    }
    }
    cout << max_dist;
}
