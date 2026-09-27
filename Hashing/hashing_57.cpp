#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll; 
 
int main() {
 
    ll n ; 
    cin>>n;
    ll k;
    cin>>k;
    unordered_map <ll,ll> mp;
    ll sum = 0 ; 
    for(ll i=1;i<=n;i++){
        ll yy;
        cin>>yy;
 
        ll g = k - (yy%k) ;
        g = g%k ; 
        sum = sum + mp[g] ;
        mp[yy%k]=mp[yy%k]+1;
    }
    cout<<sum;
 
 
    return 0;
}