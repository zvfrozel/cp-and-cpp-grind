#include <bits/stdc++.h>
using namespace std;
#define NINF -1e9
// INT_MAX > 2e9 so safe

vector<int> memo;

int get_maxparent(int i, vector<int>& a, vector<int>& p) {
    // Maximal wealth of an ancestor. For Mr. Hojo, NINF is returned.
    if (p[i] == -2) return NINF; // Mr. Hojo
    if (memo[i] != NINF) return memo[i];
    return memo[i] = max(a[p[i]], get_maxparent(p[i], a, p));
}

int main () {
    int n;
    cin >> n;

    vector<int> a(n), p(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> p[i], p[i]--; // Zero indexing

    memo.assign(n, NINF); // default value for memo
    int max_disparity = NINF;
    for (int i=0; i<n; i++) {
        max_disparity = max(get_maxparent(i, a, p) - a[i], max_disparity);
    }
    cout << max_disparity;
}
