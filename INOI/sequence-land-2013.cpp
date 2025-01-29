#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ids;
int n, k;

bool related(int a, int b) {
    int common = 0;
    int i = 0, j = 0;
    int p = ids[a].size(), q = ids[b].size();

    while (i < p && j < q) {
        if (ids[a][i] < ids[b][j]) i++;
        else if (ids[a][i] > ids[b][j]) j++;
        else { // i = j
            i++;
            j++;
            common++;
        }
    }
    return (common >= k);
}

int main () {
    cin >> n >> k;

    ids.assign(n, {}); // FB: Should have use resize
    int p;
    for (int i=0; i<n; i++) {
        cin >> p;
        ids[i].assign(p, 0); // FB: Should have used reserve + push_back
        for (int j=0; j<p; j++) {
            cin >> ids[i][j];
        }
        sort(ids[i].begin(), ids[i].end()); // Sort cause why not
    }
    // ids[0] is the president

    vector<bool> fam(n, false);
    fam[0] = true; // Initially, only the president is part of the extended family
    // stack<int> q = {0};
    stack<int> q;
    q.push(0);
    // Family members whose relative have not yet been added
    // both LIFO and FIFO work, we use LIFO

    // FB: Use queue instead of stack as BFS more predictable/less recursion than DFS
    // No recursion issues here but BFS would be generally more memory-efficient
    // (especially for large/wide graphs)

    while (!q.empty()) {
        int c = q.top();
        q.pop();
        for (int i=0; i<n; i++) {
            if (!fam[i] && related(c, i)) {
                fam[i] = true;
                // cout << c << " " << i << "\n";
                q.push(i);
            }
        }
    }

    int count = 0;
    for (auto x : fam) {
        if (x) count++;
    }
    cout << count;
    return 0;
}
