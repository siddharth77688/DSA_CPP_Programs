#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int maxSub(string s){
    int n = s.length();
    int cL=0 , cLC =0, cLCT =0, cT =0,cCT =0;

    vector<int> pL(n+1,0) , 
                pLC(n+1,0),
                sT(n+1,0),
                sCT(n+1,0);

    for(int i=0; i<n; i++){
        if(s[i] == 'L'){
            cL ++;
        }else if(s[i] == 'C'){
            cLC += cL;
        }else if(s[i]=='T'){
            cLCT += cLC;
        }
        pL[i+1] = cL;
        pLC[i+1] = cLC;
    }

    for(int i=n-1; i>=0;i--){
        if(s[i] =='T'){
            cT++;
        }else if(s[i]=='C'){
            cCT += cT;
        }
        sT[i+1] = cT;
        sCT[i+1] = cCT;

    }

    int a1 = cLCT + cCT,
        a2 = cLC + cLCT,
        a3 = cLCT;

    for(int i=1;i<n;i++){
        a3 = max(a3,cLCT + pL[i]*sT[i+1]);
    }
    
    return max({a1,a2,a3});
}


int main(){

    string s;
    cout<<"enter string ";
    cin>>s;
    cout<<"ans "<<maxSub(s);

    return 0;
}