#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> v){

    map<int,int> mp;

    for(auto i:v){
        mp[i]++;
    }

    int p=0,c=0;

    for(auto e=mp.rbegin(); e != mp.rend(); e++){
        int i = e->second;
       
        c+= (p+i);
         p += e->second;
    }

    return c;
}
int main() {
    vector<int> v(5);

    for(int i=0; i<5;i++){
        cout<<"enter "<<i<<"th position -";
        cin>>v[i];
    }
    cout<<minCost(v);
    return 0;
}