#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

int nodenum;
void travel(int n) {
    visited[n] = true;
    nodenum++;
    for(int i=0; i<adj[n].size(); i++) {
        if(!visited[adj[n][i]]) {
            travel(adj[n][i]);
        }
    }
}

long long dfs(int n, int clib, int croad) {
    long long res = 0;
    for(int i=1; i<n; i++) {
            nodenum = 0;
        if(!visited[i]) {
            travel(i);
            res += (clib + croad*(nodenum-1));
        }
    }
    
    return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int q; cin >> q;
    while(q--) {
        int n, m;
        long long clib, croad; cin >> n >> m >> clib >> croad;
        adj = vector<vector<int>>(n+1, vector<int>());
        visited = vector<bool>(n+1, false);
        for(int i=0; i<m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        if(clib <= croad) { 
            cout << clib*n << endl;
            continue;
        }
        
        cout << dfs(n+1, clib, croad) << endl;
    }
    return 0;
}
