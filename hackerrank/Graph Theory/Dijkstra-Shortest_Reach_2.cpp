#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
vector<vector<pair<int,int>>> adj;
vector<int> dijkstra(int n, int s) {
    vector<int> dist;
    dist = vector<int>(n+1, INF);
    dist[0] = 0;
    dist[s] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(dist[u] < cost) continue;
        for(auto i : adj[u]) {
            if(dist[i.first] > dist[u]+i.second) {
                dist[i.first] = dist[u]+i.second;
                pq.push(make_pair(-dist[u]+i.second, i.first));
            }
        }
    }
     
    return dist;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        adj = vector<vector<pair<int,int>>>(n+1, vector<pair<int,int>>());
        for(int i=0; i<m; i++) {
            int u, v, r; cin >> u >> v >> r;
            adj[u].push_back(make_pair(v, r));
            adj[v].push_back(make_pair(u, r));
        }
        int s;
        cin >> s;
        for(auto result : dijkstra(n, s)) {
            if(result) {
                cout << (result==INF? -1 : result) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
