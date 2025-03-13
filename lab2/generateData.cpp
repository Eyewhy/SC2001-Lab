#include <stdlib.h>
#include <time.h>
#include <vector>
#include <stdio.h>

using namespace std;

int RANDMAX = 100;

/**
 * Generates Adjancey Matrix with undirected edges
 * Edges will be granted a random weight between 1 and 100.
 * Any edge that is not valid will be granted a weight of INT_MAX.
 * @param size number of vertices
 * @param edges number of edges
 */
vector<vector<int>> randomGraph(int size, int edges, unsigned int seed=time(NULL)) {
    vector<vector<int>> v(size, vector<int>(size, INT_MAX));
    // generate i edges
    for (int i=0;i<edges;i++) {
        int x=0,y=0;
        // try until a valid edge is generated
        while (x==y || v[x][y] != INT_MAX) {
            x = rand()%size;
            // try until we get x!=y
            for (y=x;y==x;y=rand()%size);
            // check that the edge isn't already filled
        }
        int weight = rand()%RANDMAX + 1;
        v[x][y] = weight;
        v[y][x] = weight;
    }
    return v;
}
void printGraph(vector<vector<int>> v) {
    int n = v.size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<v[i].size();j++) printf("%d,",v[i][j]==INT_MAX ? 0 : v[i][j]);
        printf("\n");
    }
}
void printGraph(vector<vector<pair<int,int>>> v) {
    int n = v.size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<v[i].size();j++) printf("%d,%d ",v[i][j].first, v[i][j].second);
        printf("\n");
    }
}
/**
 * Converts agency matrix to array of adjacency lists
 * @return each pair is in the format (weight, node)
 */
vector<vector<pair<int,int>>> matrixToList(vector<vector<int>> v) {
    int n = v.size();
    vector<vector<pair<int,int>>> v2(n,vector<pair<int,int>>());
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
        if (v[i][j] != INT_MAX) v2[i].push_back({v[i][j],j});
    }
    return v2;
}
