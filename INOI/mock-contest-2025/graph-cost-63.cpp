#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;

vi a;

ll weight(ll x, ll y) {
    return max(a[x], a[y])*abs(y-x);
}

void zvfrozel() {
    int n, x, y;
    cin >> n >> x >> y;
    x = 0, y = n-1; // Subtasks 1-3
    a.clear();
    a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    ll wsp = 0;
    int rock = *min_element(a.begin(), a.end());
    // cout << rock << " rock\n";
    // Keep going to lower vals till you reach rock, then go up

    ll currx = 0;
    if (a[currx] != rock) {
        for (ll i=1; i<n; i++) {
            if (a[i] < a[currx]) {
                wsp += weight(i, currx);
                currx = i;
                // cout << i << " " << a[i] << " x jump\n";
                if (a[i] == rock) {
                    break;
                }
            }
        }
    }
    ll curry = n-1;
    if (a[curry] != rock) {
        for (ll i=n-2; i>=0; i--) {
            if (a[i] < a[curry]) {
                wsp += weight(i, curry);
                curry = i;
                // cout << i << " " << a[i] << " y jump\n";
                if (a[i] == rock) {
                    break;
                }
            }
        }
    }

    wsp += weight(currx, curry);
    cout << wsp << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i=0; i<t; i++) {
        zvfrozel();
    }
    return 0;
}

// Scored 63/100
// Subtasks 1, 2, 3
