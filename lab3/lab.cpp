#include <vector>
#include <stdio.h>
#include "knapsack.cpp"

using namespace std;

int main() {
    vector<pair<int,int>> a = {
        {4,7},
        {6,6},
        {8,9}
    };
    vector<pair<int,int>> b = {
        {5,7},
        {6,6},
        {8,9}
    };
    printf("\na: %d\n",knapsack(14,a));
    printf("\nb: %d\n",knapsack(14,b));
}