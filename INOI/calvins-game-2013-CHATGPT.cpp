#include <bits/stdc++.h>
using namespace std;

vector<int> score_memo, backscore_memo;

int backscore(int k, vector<int>& v) {
    if (backscore_memo[k] != -1) return backscore_memo[k];

    if (k == 0) return 0;
    if (k == 1) return backscore_memo[k] = v[0];

    return backscore_memo[k] = max(
        v[k - 1] + backscore(k - 1, v), v[k - 2] + backscore(k - 2, v)
    );
}

int score(int k, vector<int>& v) {
    if (score_memo[k] != -1) return score_memo[k];

    int n = v.size();
    int s = backscore(k, v);

    if (k < n - 1) s = max(s, score(k + 1, v) + v[k + 1]);
    if (k < n - 2) s = max(s, score(k + 2, v) + v[k + 2]);

    return score_memo[k] = s;
}

int main() {
    int n, k;
    cin >> n >> k;
    k--;  // Zero indexing

    vector<int> squares(n);
    for (int i = 0; i < n; i++) cin >> squares[i];

    score_memo.assign(n, -1);
    backscore_memo.assign(n, -1);

    cout << score(k, squares);
    return 0;
}
