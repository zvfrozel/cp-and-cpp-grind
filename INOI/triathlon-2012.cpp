#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<pii> rest_then_cobol(n);

    int t1, t2, t3;
    for (int i=0; i<n; i++) {
        cin >> t1 >> t2 >> t3;
        rest_then_cobol.push_back({t2+t3, t1});
    }

    // Simple sort works
    sort(rest_then_cobol.begin(), rest_then_cobol.end(), greater<pii>());

    // Max extraction
    int maxtime = 0, ctime = 0;
    for (int i=0; i<n; i++) {
        auto [rest, cobol] = rest_then_cobol[i];
        // cout << cobol << " " << rest << "\n";
        ctime += cobol;
        maxtime = max(maxtime, ctime+rest);
    }
    cout << maxtime;
}
