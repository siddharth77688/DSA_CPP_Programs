#include <bits/stdc++.h>
using namespace std;
// approach 2 sweep line algorithm

void sweep_line(vector<pair<int,int>> v, vector<int> q){

    vector<pair<int,int>> a;

    for(int qq:q){
        a.push_back({qq,1});
    }

    for(auto e:v){
        int l = e.first;
        int r = e.second;

        a.push_back({l,0});
        a.push_back({r,2});
    }

    sort(a.begin(),a.end());

    int c=0;
    for(auto e:a){
        int p = e.second;

        if(p ==0){
            c++;
        }else if( p ==1){
            cout<< "lamps "<<c;
        }else if( p== 2){
            c--;
        }
    }
}

int main(){
    
    int r;
    cout<<"no of ranges ";
    cin>>r;

    int q;
    cout<<"no of queries ";
    cin>>q;

    vector<pair<int,int>> v(r);
    vector<int> qu(q);

    for(int i=0; i<r;i++){
        int l,ri ;
        cout<<"enter L R ";
        cin>>l>>ri;
        v[i].first = l;
        v[i].second = ri;
    }


    for(int i=0;i<q;i++){
     cin>>qu[i];
    }

    sweep_line(v,qu);

    return 0;
}
