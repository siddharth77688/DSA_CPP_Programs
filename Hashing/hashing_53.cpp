#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution {
public:
    long long countStableSubarrays(vector<int>& c) {
        map<pair<ll,ll>,ll> g;
        ll sum = 0 ; ll u = 0 ; 
        for(int i=0;i<c.size();i++){
            sum = sum + (c[i]);
            ll desired_sum = sum - 2*c[i];
            if(g.contains({desired_sum,c[i]})){
                u = u + g[{desired_sum,c[i]}];
            }
            g[{sum,c[i]}]++;
        }
        ll d = c.size();
        for(int i=0;i<d-1;i++){
            //subarrays of sz == 2 of the type [0,0] got 
            //overcounted so subtracting them 
            if(c[i]==c[i+1] && c[i+1]==0){
                u-- ;
            }

        }
        return u;

    }
};