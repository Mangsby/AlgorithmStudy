#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<bool> visited;
vector<int> degree;
vector<int> parent;
vector< vector<int> > edge;

int dfs(int here) {
    visited[here] = true;
    int sum = 0;
    for(int i=0; i<edge[here].size(); i++) {
        int there = edge[here][i];
        if(visited[there]) continue;
        sum += dfs(there);
    }
    sum++;
    degree[here] = sum;
    return sum;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, m; cin >> n >> m;
    int answer = 0;
    edge = vector< vector<int> >(n, vector<int>());
    degree = vector<int>(n, 0);
    parent = vector<int>(n, -1);
    visited = vector<bool>(n, false);
    for(int i=0; i<m; i++) {
        int u, v; cin >> v >> u;
        edge[u-1].push_back(v-1);
        parent[v-1] = u-1;
    }
    
    dfs(0);
    
    for(int i=n-1; i>=0; i--) {
        if(degree[i] % 2 == 0 && parent[i] != -1) {
            answer++;
            degree[parent[i]] -= degree[i];
        }
    }
    
    cout << answer;
    return 0;
}
