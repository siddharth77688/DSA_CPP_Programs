#include <bits/stdc++.h>
using namespace std;

int min_dis(vector<vector<int>>& g) {
    int n = g.size();
    int m = g[0].size();
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    
    queue<pair<int, int>> q;
    vector<vector<int>> lvl(n, vector<int>(m, -1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 2) {
                q.push({i, j});
                lvl[i][j] = 0; 
            }
        }
    }
    
    while (!q.empty()) {
        auto [a, b] = q.front();
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int x1 = a + dx[i];
            int y1 = b + dy[i];
            
            if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && lvl[x1][y1] == -1) {
                lvl[x1][y1] = lvl[a][b] + 1;
                
                if (g[x1][y1] == 3) {
                    return lvl[x1][y1]; 
                }
                q.push({x1, y1});
            }
        }
    }
    
    return -1; 
}

int main() {
    vector<vector<int>> g = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 2, 3},
        {0, 0, 0, 0, 0},
        {0, 3, 0, 0, 0},
        {0, 0, 2, 0, 0}
    };
    cout << min_dis(g) << endl; 
    return 0;
}
