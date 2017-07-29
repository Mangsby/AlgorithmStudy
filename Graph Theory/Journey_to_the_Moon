#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std; // }}}

vector<vector<int> > pairs;
vector<bool> visited;
vector<int> memNum;
vector<int> partialSum;
int N, I;
int ccnum = 0;
void explore(int n);
void dfs() {
    for(int i=0; i<N; i++) {
        if(!visited[i]) {
            ccnum++;
            explore(i);
        }
    }
}

void explore(int n) {
    visited[n] = true;
    vector<int>::iterator it;
    memNum[ccnum]++;
    for(it=pairs[n].begin(); it!=pairs[n].end(); it++) {
        if(!visited[*it])
            explore(*it);
    }
}
 
int main()
{ 
    
    cin >> N >> I;
    pairs.reserve(N);
    memNum = vector<int>(N, 0);
    partialSum = vector<int>(N, 0);
    visited = vector<bool>(N, false);
    for (int i = 0; i < I; ++i) {
        int a, b;
        cin >> a >> b;
        pairs[a].push_back(b);
        pairs[b].push_back(a);
    }
 
    long long result = 0;
    dfs();
    
    long long ps = 0;
    for(int i=1; i<=ccnum; i++) {
        ps += memNum[i];
        partialSum[i] = ps;
    }
    for(int i=1; i<ccnum; i++) {
        result += memNum[i] * (partialSum[ccnum] - partialSum[i]);
    }
    /** Write code to compute the result using N,I,pairs **/
    
    
    cout << result << endl;
    return 0;
}
