#include <bits/stdc++.h>
using namespace std;

int sum(int i){
    string s = to_string(i);
    int a=0;
    for(char c : s){
        a += c-'0';
    }
    return a;
}

int calCost(vector<int> v){

    unordered_map<int,int> mp;


    for(int i:v){
        int c = sum(i);

        mp[c] = mp[c]+ i;
    }

    int maxi = INT_MIN;

    for(auto e:mp){
        maxi = max(e.second,maxi);
    }
    return maxi;
  
}


int main() {
    int n;
    cout<<"enter the size of vector -";
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n;i++){
        cout<<"enter "<<i<<"th position -";
        cin>>v[i];
    }
    cout<<calCost(v);
    return 0;
}