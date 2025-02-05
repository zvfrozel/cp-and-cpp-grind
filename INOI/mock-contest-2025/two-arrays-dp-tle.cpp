#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;

void zvfrozel () {
    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];

    vvll dp(n, vll(k, LLONG_MAX)); // dp[m][c] = minsumcost of splitting 0, ..., m into c+1 intervals
    ll suma, sumb;

    suma = sumb = 0;
    for (int m=0; m<=n-k; m++) {
        suma += a[m];
        sumb += b[m];
        dp[m][0] = min(suma, sumb);
    }
    for (int c=0; c<k-1; c++) {
        for (int m=c; m<=n-k+c; m++) {
            suma = sumb = 0;
            for (int t=m+1; t<=n-k+c+1; t++) {
                suma += a[t];
                sumb += b[t];
                dp[t][c+1] = min(
                    dp[t][c+1],
                    dp[m][c] + min(suma, sumb)
                );
            }
        }
    }

    cout << dp[n-1][k-1];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    zvfrozel();
    return 0;
}
