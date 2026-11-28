#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(vector<vector<int>>& g, int i, int j, int n, int m, int comp_id) {
    g[i][j] = comp_id;
    for (auto [di, dj] : dir) {
        int ii = i + di;
        int jj = j + dj;
       
        if (0 <= ii && ii < n && 0 <= jj && jj < m && g[ii][jj] == -1) {
            dfs(g, ii, jj, n, m, comp_id);
        }
    }
}

int maxCompo(vector<vector<int>>& g) {
    int n = g.size();
    int m = g[0].size();
    int comp_id = 1;
    unordered_map<int, int> comp_size;

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == -1) {
                dfs(g, i, j, n, m, comp_id);
                comp_id++;
            }
        }
    }

 
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] > 0) {
                comp_size[g[i][j]]++;
                ans = max(ans, comp_size[g[i][j]]);
            }
        }
    }


    for (int i = 0; i < n; i++) {
        unordered_set<int> unique_comps;
        int zeros_in_row = 0;

        for (int j = 0; j < m; j++) {
            if (g[i][j] == 0) {
                zeros_in_row++;
                
                for (auto [di, dj] : dir) {
                    int ii = i + di, jj = j + dj;
                    if (0 <= ii && ii < n && 0 <= jj && jj < m && g[ii][jj] > 0) {
                        unique_comps.insert(g[ii][jj]);
                    }
                }
            } else {
                
                unique_comps.insert(g[i][j]);
            }
        }

        int current_total = zeros_in_row;
        for (int id : unique_comps) {
            current_total += comp_size[id];
        }
        ans = max(ans, current_total);
    }

   
    for (int j = 0; j < m; j++) {
        unordered_set<int> unique_comps;
        int zeros_in_col = 0;

        for (int i = 0; i < n; i++) {
            if (g[i][j] == 0) {
                zeros_in_col++;
                for (auto [di, dj] : dir) {
                    int ii = i + di, jj = j + dj;
                    if (0 <= ii && ii < n && 0 <= jj && jj < m && g[ii][jj] > 0) {
                        unique_comps.insert(g[ii][jj]);
                    }
                }
            } else {
                unique_comps.insert(g[i][j]);
            }
        }

        int current_total = zeros_in_col;
        for (int id : unique_comps) {
            current_total += comp_size[id];
        }
        ans = max(ans, current_total);
    }

    return ans;
}

int main() {
    vector<vector<int>> g = {
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };
    cout << maxCompo(g) << endl; 
    return 0;
}
