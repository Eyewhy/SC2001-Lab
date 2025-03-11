#include <stdlib.h>
#include <vector>
#include <stdio.h>
#include <queue>

using namespace std;

int dijstraArr(vector<vector<int>> v) {
    int n = v.size();
    vector<int> d(n,INT_MAX); // a value of INT_MAX represents not visited.
    vector<bool> s(n,false);
    // not implementing pi as there is no need to trace back the path.

    d[0] = 0; // set the starting point as 0.
    while (true) {
        // find the next node to explore
        int mind=INT_MAX,next=-1;
        for (int i=0;i<n;i++) {
            if (!s[i] && d[i]<mind) {
                next = i;
                mind = d[i];
            }
        }
        if (next == -1) break; // no more nodes to explore.

        // iterate the agencency matrix
        for (int i=0;i<n;i++) {
            if (v[next][i] == INT_MAX) continue;
            d[i] = min(v[next][i]+d[next], d[i]);
        }
        // set visited
        s[next] = true;
    }
    return d[n-1];
}

int dijstraPq(vector<vector<pair<int,int>>> v) {
    int n = v.size();
    vector<bool> s(n,false);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> p;
    p.push({0,0}); // set starting point as 0.
    while (!p.empty()) {
        pair<int,int> cur = p.top(); // first is weight, second is node.
        p.pop();
        if (cur.second == n-1) return cur.first; // visited last node.
        if (s[cur.second]) continue; // node already visited.

        int m = v[cur.second].size();
        for(int i=0;i<m;i++) {
            // first is weight, second is node.
            // for weight, add current weight to weight in adj list.
            // for node, it's just the node in the adj list.
            p.push({cur.first+v[cur.second][i].first, v[cur.second][i].second});
        }
        s[cur.second] = true;
    }
    return INT_MAX;
}
