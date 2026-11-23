# include <bits/stdc++.h>
using namespace std;

vector<int> lamps(vector<pair<int,int>> v, int mx){
        
        vector<int> p(mx+1,0);

        for(auto e:v){
            int l = e.first;
            int r = e.second;

            p[l]++;

            if(r+1<=mx){
                p[r+1]--;
            }
        }

        
        for(int i=1;i<p.size();i++){
            p[i] += p[i-1];
            
        }

        return p;
}



int main(){
    int r;
    cout<<"no of ranges ";
    cin>>r;

    int mx;
    cout<<"max range point ";
    cin>>mx;


    int q;
    cout<<"no of queries ";
    cin>>q;

    vector<pair<int,int>> v(r);
    

    for(int i=0; i<r;i++){
        int l,ri ;
        cout<<"enter L R ";
        cin>>l>>ri;
        v[i].first = l;
        v[i].second = ri;
    }

    vector<int> p = lamps(v,mx);

    for(int i=0;i<q;i++){
        int qq;
        cout<<"enter query ";
        cin>>qq;
        cout<<"lamps "<<p[qq]<<endl;
    }

    return 0;
}