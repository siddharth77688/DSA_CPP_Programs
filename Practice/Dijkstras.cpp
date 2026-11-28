#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> dijkstras(    vector<vector<pair<int,int>>>& adj ,   int n ,   int src   ){

        priority_queue< pair<int,int>,  vector<pair<int,int>>,   greater<pair<int,int>> > pq;

        vector<int> dist(n,INT_MAX);

        pq.push({0,src});
        dist[src]=0;

    
        while(!pq.empty()){
            auto [w,v] = pq.top();
            pq.pop();

            if(w >dist[v]) continue;

            for(auto& e:adj[v]){
                auto [w1,n1] = e;

                if(dist[n1] > w+ w1){
                    dist[n1] = w+w1;

                    pq.push({dist[n1],n1});
                }               
            }
        }

        return dist;

}
int main(){
 return 0;
}