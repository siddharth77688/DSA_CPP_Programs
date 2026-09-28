#include <bits/stdc++.h>
using namespace std;
long long maxSubarraySum(vector<int>& a, int k) {
    int n = a.size();

    long long pref = 0;
    long long ans = LLONG_MIN;

    // value -> minimum prefix sum before this value appeared
    unordered_map<long long, long long> mp;

    for (int j = 0; j < n; j++) {

        // i = j is allowed when k == 0
        if (mp.count((long long)a[j] - k)) {
            ans = max(ans, pref + a[j] - mp[a[j] - k]);
        }

        if (mp.count((long long)a[j] + k)) {
            ans = max(ans, pref + a[j] - mp[a[j] + k]);
        }

        // prefix sum including a[j]
        pref += a[j];

        // This value can become the starting point for future j
        // prefix before i is pref - a[i]
        long long before = pref - a[j];

        if (!mp.count(a[j]))
            mp[a[j]] = before;
        else
            mp[a[j]] = min(mp[a[j]], before);
    }

    return ans;
}

int main() {
    vector<int> a = {1, 5, -5, 8, 8, 8, 10, 15};
    long long ans1 = maxSubarraySum(a, 5);
    long long ans2 = maxSubarraySum(a, 10); 
    cout<<"Judging ...."<<"\n"<<"\n";
    ans1 == 34 ? cout <<"Test Case  1 : Passed" << "\n" : cout <<"Test Case  1 : Failed" << "\n";
    ans2 == 49 ? cout <<"Test Case  2 : Passed" << "\n" : cout <<"Test Case  2 : Failed" << "\n";

    return 0;
}