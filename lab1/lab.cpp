#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "generateData.cpp"
#include "sorts.cpp"

using namespace std::chrono;
using namespace std;

int main() {
    
    // S is small integer threshold
    long long int keycomps;
    int ARR_SIZE = 100000;
    int S_MAX = 257;
    int S_TEST = 64;
    
    // first, we test various values of s
    ofstream sTest("test_s.csv");
    sTest << "s,run1,run2,run3,run4,run5,\n";
    for (int s=2;s<S_MAX;s++) {
        printf("%d ",s);
        string ss = to_string(s) + ",";
        for (int j=0;j<5;j++) {
            vector<int> a = randomArray(ARR_SIZE);
            keycomps = 0;
            // start the timer
            auto start = high_resolution_clock::now();
            hybridsort(0,ARR_SIZE-1,s,a,keycomps);
            auto stop = high_resolution_clock::now();
            duration<double, std::milli> ms = stop - start;
            ss += to_string(ms.count()) + ",";
        }
        sTest << ss + "\n";
    }
    sTest.close();

    // then, we test various values of size.
    ofstream aTest("test_a.csv");
    aTest << "a,hybrid1,merge1,hybrid2,merge2,hybrid3,merge3,hybrid4,merge4,hybrid5,merge5\n";
    for (int i=1000;i<=10000000;i*=10) {
        string ss = to_string(i) + ",";
        printf("%d ",i);
        for (int j=0;j<5;j++) {
            vector<int> a = randomArray(i);
            for (int j=0;j<2;j++) {
                // copy the array
                vector<int> b = a;
                keycomps = 0;
                // start the timer
                auto start = high_resolution_clock::now();

                if (j%2) {
                    mergesort(0,i-1,b,keycomps);
                } else {
                    hybridsort(0,i-1,S_TEST,b,keycomps);
                }
                auto stop = high_resolution_clock::now();
                duration<double, std::milli> ms = stop - start;
                ss += to_string(ms.count()) + ",";
            }
        }
        aTest << ss + "\n";
    }
    aTest.close();
}