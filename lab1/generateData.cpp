#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

int MAX = INT_MAX-1;

vector<int> randomArray(int size, unsigned int seed=time(NULL)) {
    srand(seed);
    vector<int> v;
    for (int i=0;i<size;i++) {
        v.push_back(rand() + 1);
    }
    return v;
}