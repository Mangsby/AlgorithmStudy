#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> fishes;
vector<vector<pair<int, int>>> adj;

vector<vector<int>> dijkstra(int n) {
	const int INF = 987654321;
	vector<vector<int>> dist(n + 1, vector<int>(1025, INF));

	dist[0][0] = 0; dist[1][fishes[1]] = 0;
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ 0, { fishes[1], 1 } });
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int u = pq.top().second.second;
		int fish = pq.top().second.first;
		pq.pop();
		if (dist[u][fish] < cost) continue;
		for (auto i : adj[u]) {
			int vfish = fishes[i.second];
			int rfish = (fish | vfish);
			if (dist[i.second][rfish] > cost + i.first) {
				dist[i.second][rfish] = cost + i.first;
				pq.push({ -(cost + i.first), { rfish, i.second } });
			}
		}
	}

	return dist;
}

int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int ncenter, nroad, nfish; cin >> ncenter >> nroad >> nfish;
	fishes = vector<int>(ncenter + 1, 0);
	adj = vector<vector<pair<int, int>>>(ncenter + 1, vector<pair<int, int>>());

	for (int i = 0; i<ncenter; i++) {
		int n; cin >> n;
		for (int j = 0; j<n; j++) {
			int fish; cin >> fish;
			int bit = 0;
			bit = (1 << (fish - 1));
			fishes[i + 1] |= bit;
		}
	}

	for (int i = 0; i<nroad; i++) {
		int u, v, cost; cin >> u >> v >> cost;
		adj[u].push_back({ cost, v });
		adj[v].push_back({ cost, u });
	}

	vector<vector<int>> dist = dijkstra(ncenter);
	for (auto it : dist[ncenter]) {
		cout << it << " ";
	}
	int max = -987654321;
	for (int i = 0; i<(1 << nfish); i++) {
		for (int j = i; j<(1 << nfish); j++) {
			if ((i | j) == (1 << nfish) - 1) {
				int min = dist[ncenter][j] > dist[ncenter][i] ? dist[ncenter][i] : dist[ncenter][j];
				max = max < min ? min : max;
			}
		}
	}

	cout << max;
	return 0;
}
