#include <vector>
#include <stdio.h>

using namespace std;

/**
 * @param c The capacity of the knapsack
 * @param objects Each object is in the format { weight, profit } 
 * @return The maximum profits 
 */
int knapsack(int c, vector<pair<int,int>> objects) {
    int n = objects.size();
    vector<int> v (c+1,0);
    // i will be the current profit we are calculating
    for (int i=1;i<=c;i++) {
        for (int j=0;j<n;j++) {
            // previous weight before adding the object
            int prev = i-objects[j].first; 
            // skip if we can't fit in 1 of the object
            if (prev < 0) continue;
            v[i] = max(v[i], v[prev]+objects[j].second);
        }
        printf("%d:%d ",i,v[i]);
    }
    return v[c];
}