#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ids;
int n, k;

bool related(int a, int b) {
    int common = 0, i = 0, j = 0;
    int size_a = ids[a].size(), size_b = ids[b].size();
    while (i < size_a && j < size_b) {
        if (ids[a][i] < ids[b][j]) i++;
        else if (ids[a][i] > ids[b][j]) j++;
        else if (++common >= k) return true;  // Early exit
        else i++, j++;
    }
    return false;
}

int main() {
    cin >> n >> k;
    ids.resize(n);

    for (auto &v : ids) {
        int p;
        cin >> p;
        v.reserve(p);
        for (int j = 0, val; j < p; j++) {
            cin >> val;
            v.push_back(val);
        }
        sort(v.begin(), v.end());  // Sorting for efficient lookup
    }

    vector<bool> fam(n, false);
    queue<int> q;
    fam[0] = true, q.push(0);

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        for (int i = 0; i < n; i++) {
            if (!fam[i] && related(c, i)) fam[i] = true, q.push(i);
        }
    }

    cout << count(fam.begin(), fam.end(), true);  // Count true values
}
