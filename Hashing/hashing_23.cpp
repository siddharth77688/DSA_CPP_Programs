#include <bits/stdc++.h>
using namespace std;


int minCost(vector<int> v){

    unordered_map<int,int> map;

    for(auto i:v){
        map[i]++;
    }
    
     int c =0;

    for(auto e:map){
        if(e.second % 3 ==0){
            c += e.second /3;
        }
        else if(e.second % 2 ==0){
            c+=e.second /2;
        }else{
            return -1;
        }
    }

    return c;
}


int main() {
    int n;
    cout<<"enter n ";
    cin>>n;

    vector<int> v(n);

    for(int i=0; i<n;i++){
        cout<<"enter "<<i<<" th position - ";
        cin>>v[i];
    }
    cout<<"answer - "<<minCost(v);
    return 0;
}