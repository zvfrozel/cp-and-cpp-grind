// This sol (priority queue) runs way faster than the dp solution and much less memory overhead

#include <bits/stdc++.h>
using namespace std;

#define INF 2.88e8

int main() {
    int c, f;
    cin >> c >> f;

    vector<vector<int>> dist(c, vector<int>(c, INF));

    for (int i=0; i<c; i++) {
        dist[i][i] = 0;
    }

    int x, y, p;
    for (int i=0; i<f; i++) {
        cin >> x >> y >> p;
        x--;
        y--;
        dist[x][y] = dist[y][x] = p;
    }

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int root=0; root<c; root++) {
        // Djikstra analog on each root?
        for (int dest=0; dest<c; dest++) {
            q.push({dist[root][dest], dest});
        }

        while (!q.empty()) {
            auto [d, city] = q.top();
            q.pop();

            if (dist[root][city] < d) {
                continue; // The city has been covered away
            } else if (dist[root][city] > d) {
                cout << "WTF algorithm broke" << "\n";
            }

            for (int dest=0; dest<c; dest++) {
                int new_d = d + dist[city][dest];
                if (new_d < dist[root][dest]) {
                    dist[root][dest] = dist[dest][root] = new_d;
                    q.push({new_d, dest}); // {old_d, dest} will have been covered away

                    // cout << "root = " << root << " city = " << city << " dest = " << dest;
                    // cout << "\n" << q.top().first << " " << q.top().second << "\n";
                }
            }
        }
    }
    // for (int i=0; i<c; i++) {
    //     for (int j=0; j<c; j++) {
    //         cout << dist[i][j] << "  ";
    //     }
    //     cout << "\n";
    // }
    vector<int> maxdist(c);
    for (int i=0; i<c; i++) {
        maxdist[i] = *max_element(dist[i].begin(), dist[i].end());
    }
    cout << *max_element(maxdist.begin(), maxdist.end());
}
