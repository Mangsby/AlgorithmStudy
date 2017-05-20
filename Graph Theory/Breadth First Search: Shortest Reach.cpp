#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;



int main() {
    int t;
    cin >> t;
    while(t--) {
        int g, e;
        cin >> g >> e;
        queue<int> q;
        vector<vector<int>> adj(g+1);
        vector<int> dist(g+1,-1);
        while(e--) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        int start;
        cin >> start;
        q.push(start);
        dist[start] = 0;
        while(!q.empty()) {
            int here = q.front();
            q.pop();
            for(int i=0; i < adj[here].size(); i++) {
                int there = adj[here][i];
                if(dist[there] == -1) {
                    q.push(there);
                    dist[there] = dist[here] + 6;
                }
            }
        }
        
        for(int i=1; i<=g; i++) {
            if(i == start) continue;
            cout << dist[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
