#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template <typename K, typename V>
struct PairHash {
    size_t operator()(const pair<K, V>& p) const {
        auto h1 = hash<K>{}(p.first);
        auto h2 = hash<V>{}(p.second);
        return h1 ^ h2;
    }
};

int main() {
    ll n;
    cin >> n;
    unordered_map<pair<ll, ll>, ll, PairHash<ll, ll>> k;
    ll count = 0;
    ll i = 1;
    ll sum = 0;

    while (i <= n) {
        ll number;
        cin >> number;
        sum = sum + number;

        ll focus_sum = sum - number;
        ll g = focus_sum - number;
        count = count + k[{number, g}];

        k[{number, sum}]++;
        
        i++;
    }

    cout << count << endl;

    return 0;
}