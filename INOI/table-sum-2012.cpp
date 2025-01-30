#include <bits/stdc++.h>
using namespace std;

// #define pii pair<int, int>?
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;

    vector<int> r1(n);
    priority_queue<pii> pq; // Max heap

    for (int i=0; i<n; i++) {
        cin >> r1[i];
        pq.push({r1[i] + i + 1, i + 1});
    }

    int score;
    for (int k=0; k<n; k++) {
        while (pq.top().second > n-k) pq.pop();
        score = pq.top().first + k;
        cout << score << " ";
        pq.push({r1[n-k-1] - k, -1}); // second can be any negative number at this point
    }

    // We treat the cyclic permutations as such:
    // 1 2 3 4
    // 1 2 3 0
    // 1 2 -1 0
    // 1 -2 -1 0
    // And then add a constant k to max_score
    // Rather than this:
    // 1234
    // 2341
    // 3412
    // 4123

    // FB: Much simpler, easier, and faster O(n) algorithm exists than all this
}
