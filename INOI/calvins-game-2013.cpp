#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> score_memo;
unordered_map<int, int> backscore_memo;

int backscore(int k, vector<int>& v) {
    // Max score for backward phase
    if (backscore_memo.count(k)) return backscore_memo[k];

    if (k == 0) return 0;
    if (k == 1) return v[0];

    return backscore_memo[k] = max(
        v[k - 1] + backscore(k - 1, v), v[k - 2] + backscore(k - 2, v)
    );
}

int score(int k, vector<int>& v) {
    // Max score with both forward and backward phase
    if (score_memo.count(k)) return score_memo[k];

    int n = v.size();
    vector<int> sv;

    sv.push_back(backscore(k, v));
    if (k < n-1) {
        sv.push_back(score(k+1, v) + v[k+1]);
    }
    if (k < n-2) {
        sv.push_back(score(k+2, v) + v[k+2]);
    }

    int s = *max_element(sv.begin(), sv.end());
    score_memo[k] = s;
    // cout << "Score: " << k << " " << s << "\n";
    return s;
}

int main () {
    int n, k;
    cin >> n >> k;
    k--; // Zero indexing

    vector<int> squares(n);
    int c;
    for (int i=0; i<n; i++) {
        cin >> c;
        squares[i] = c;
    }

    cout << score(k, squares);
    return 0;
}
