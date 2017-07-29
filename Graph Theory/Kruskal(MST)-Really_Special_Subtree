#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int kruskal(vector<pair<int, int>>* adj, int n);
    
class disjointSet {
public:
    disjointSet(int n) : parent(n), rank(n, 1) {
        for(int i=0; i<n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    
    void merge(int u, int v) {
        int a = find(u); int b = find(v);
        if(a == b) return;
        if(rank[a] > rank[b]) {
            int t = a;
            a = b;
            b = t;
        }
        parent[a] = b;
        if(rank[a] == rank[b]) rank[b]++;
    }
    
private:
    vector<int> parent, rank;
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n; int m; cin >> n >> m;
    
    vector<pair<int, int>> adj[n+1];
    for(int i=0; i<m; i++) {
        int u, v, cost; cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
    }
    cout << kruskal(adj, n);
    
    return 0;
}

int kruskal(vector<pair<int, int>>* adj, int n) {
    int ret = 0;
    n++;
    
    vector<pair<int, pair<int, int>>> edges;
    for(int u=0; u<n; u++) {
        for(int i=0; i<adj[u].size(); i++) {
            edges.push_back({adj[u][i].second, {u, adj[u][i].first}});
        }
    }
    
    sort(edges.begin(), edges.end());
    
    disjointSet sets(n);
    for(int i=0; i<edges.size(); i++) {
        int cost = edges[i].first;
        int u = edges[i].second.first, v = edges[i].second.second;
        if(sets.find(u) == sets.find(v)) continue;
        sets.merge(u, v);
        ret += cost;
    }
    return ret;
}
