#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;

void zvfrozel() {
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    vvll dp_a(n, vll(k, LLONG_MAX)); // dp_a[m][c] = Max sum from 0,...,m start with suma and c filps
    vvll dp_b(n, vll(k, LLONG_MAX)); // dp_a[m][k] = Max sum from 0,...,m start with sumb and c filps
    dp_a[0][0] = a[0];
    dp_b[0][0] = b[0];

    for (int m=0; m<=n-2; m++) {
        for (int c=0; c<=min(m, k-1); c++) {
            if (c%2 == 0) {
                dp_a[m+1][c] = min(dp_a[m+1][c], dp_a[m][c] + a[m+1]);
                dp_b[m+1][c] = min(dp_b[m+1][c], dp_b[m][c] + b[m+1]);
                if (c < k-1) {
                    dp_a[m+1][c+1] = min(dp_a[m+1][c+1], dp_a[m][c] + b[m+1]);
                    dp_b[m+1][c+1] = min(dp_b[m+1][c+1], dp_b[m][c] + a[m+1]);
                }
            } else if (c%2 == 1) {
                dp_a[m+1][c] = min(dp_a[m+1][c], dp_a[m][c] + b[m+1]);
                dp_b[m+1][c] = min(dp_b[m+1][c], dp_b[m][c] + a[m+1]);
                if (c < k-1) {
                    dp_a[m+1][c+1] = min(dp_a[m+1][c+1], dp_a[m][c] + a[m+1]);
                    dp_b[m+1][c+1] = min(dp_b[m+1][c+1], dp_b[m][c] + b[m+1]);
                }
            }
        }
    }

    ll min_a = LLONG_MAX, min_b = LLONG_MAX;
    for (int i=0; i<k; i++) {
        // cout << dp_a[n-1][i] << " ";
        min_a = min(min_a, dp_a[n-1][i]);
    }
    // cout << "\n";
    for (int i=0; i<k; i++) {
        // cout << dp_b[n-1][i] << " ";
        min_b = min(min_b, dp_b[n-1][i]);
    }
    // cout << "\n";
    cout << min(min_a, min_b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    zvfrozel();
    return 0;
}
