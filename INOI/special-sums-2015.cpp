#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll SWAG_MIN = LLONG_MIN / 2; // Much greater than LLONG_MIN, much less than INT_MIN

void go() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }

    ll ms_eqeq, ms_eqne, ms_neeq, ms_nene, ms_cycl;
    // Max sum starting at 0 ending before k
    // Max sum starting after 0 ending before k
    // Max sum starting at 0 ending at k
    // Max sum starting after 0 ending at k
    // Max sum with a cycle!

    // Degenerate case n=1:
    if (n == 1) {
        cout << a[0];
        return;
    }
    // Base case k=1:
    ms_eqeq = ms_cycl = a[0]+a[1];
    ms_eqne = ms_neeq = ms_nene = SWAG_MIN;
    // We iteratively compute for k, where k goes from 2...n
    for (int k=2; k<n; k++) {
        ms_eqne = max(ms_eqne, ms_eqeq);
        ms_nene = max(ms_nene, ms_neeq);
        ms_eqeq = ms_eqeq+a[k]-a[k-1]+b[k-1];
        ms_neeq = ms_neeq+a[k]-a[k-1]+b[k-1];
        ms_neeq = max(ms_neeq, a[k-1]+a[k]);
        ms_cycl = max(ms_cycl+b[k], ms_eqne+a[k]-a[0]+b[0]);
        ms_cycl = max(ms_cycl, a[0]+a[k]);
        // cout << ms_eqeq << " " << ms_eqne << " " << ms_neeq << " " << ms_nene << " " << ms_cycl << "\n";
    }

    ll max_elem = *max_element(a.begin(), a.end());
    cout << max({ms_eqeq, ms_eqne, ms_neeq, ms_nene, ms_cycl, max_elem});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    go();
    return 0;
}
