#include <chrono>
#include <vector>
#include "generateData.cpp"
#include "sorts.cpp"

using namespace std::chrono;

int main() {
    
    // S is small integer threshold
int s = 10;
    long long int keycomps;
    /* Getting number of milliseconds as a double. */
    
    for (int i=1000;i<=10000000;i*=10) {
        vector<int> a = randomArray(i);
        for (int j=0;j<2;j++) {
            // copy the array
            vector<int> b = a;
            keycomps = 0;
            // start the timer
            auto start = high_resolution_clock::now();

            if (j%2) {
                printf("Mergesort:  ");
                mergesort(0,i-1,b,keycomps);
            } else {
                printf("Hybridsort: ");
                hybridsort(0,i-1,s,b,keycomps);
            }
            auto stop = high_resolution_clock::now();
            duration<double, std::milli> ms = stop - start;
            printf("%d ints took %f ms and %lld comps\n",i,ms.count(),keycomps);    
        }
    }
}