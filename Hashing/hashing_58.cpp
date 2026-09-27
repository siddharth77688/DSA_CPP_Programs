#include <bits/stdc++.h>
 
using namespace std;
typedef long long int ll ; 
 
int main() {
    ll n ; 
    cin>>n ; 
    ll i = 1 ; ll answer = -1e18;
    unordered_map <ll,ll> kk ; 
    ll sum = 0 ; 
    while(i<=n){
        ll yy ; cin>>yy;
 
        answer = max(answer,yy);
        if(kk.find(yy)==kk.end()){
            kk[yy] = sum ; 
        } 
        else{
 
            ll gg = sum + yy - kk[yy] ; 
            //cout<<gg<<"\n";
            answer = max(answer,gg);
            kk[yy] = min(kk[yy],sum);
 
        }
        sum = sum + yy ; 
 
 
        // cout<<sum<<" "<<i;
        // cout<<"\n";
 
        i++;
    }
    cout<<answer ; 
 
 
    return 0 ; 
}