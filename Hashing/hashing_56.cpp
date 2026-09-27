#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


int main(){
    
    ll n ; 
    cin>>n;
    unordered_map <ll,ll> kk ;
    for(ll i=1;i<=n;i++){
        ll yy;
        cin>>yy;
        kk[yy-i] = kk[yy-i] + yy ; 
    }
    ll v = 0 ; 
    for(auto itr = kk.begin();itr!=kk.end();++itr){
        cout<<itr->first<<" "<<itr->second;
        v = max(v,itr->second);
        cout<<'\n';
    }
    cout<<v ; 
    
    return 0;
}