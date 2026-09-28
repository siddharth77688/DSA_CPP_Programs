#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll max1 = LLONG_MIN, min1 = LLONG_MAX; // (a[i] + i)
    ll max2 = LLONG_MIN;                   // (i - a[i])
    ll max3 = LLONG_MIN;                   // (a[i] - i)

    for(int i = 0; i < n; i++) {
        ll val1 = a[i] + i;
        ll val2 = i - a[i];
        ll val3 = a[i] - i;

        max1 = max(max1, val1);
        min1 = min(min1, val1);
        max2 = max(max2, val2);
        max3 = max(max3, val3);
    }

    ll ans1 = (max1) - 2 * (min1);
    ll ans2 = (max2) + 2 * (max3);
    ll ans3 = (max3) + 2 * (max2);
    ll ans4 = 2 * (max1) - (min1);

    ll result = max({ans1, ans2, ans3, ans4});

    cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << "\n";
    cout << result << "\n";

    return 0;
}