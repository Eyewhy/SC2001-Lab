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
    int S_MAX = 128;
    int S_TEST = 64;
    int REPEATS = 5;
    /*
    // first, we test various values of s
    ofstream sTest("test_s.csv");
    sTest << "s,run1,comps1,run2,comps2,run3,comps3,run4,comps4,run5,comps5,\n";
    for (int s=2;s<=S_MAX;s++) {
        printf("%d ",s);
        string ss = to_string(s) + ",";
        for (int j=0;j<REPEATS;j++) {
            vector<int> a = randomArray(ARR_SIZE);
            keycomps = 0;
            // start the timer
            auto start = high_resolution_clock::now();
            hybridsort(0,ARR_SIZE-1,s,a,keycomps);
            auto stop = high_resolution_clock::now();
            duration<double, std::milli> ms = stop - start;
            ss += to_string(ms.count()) + "," + to_string(keycomps) + ",";
        }
        sTest << ss + "\n";
    }
    sTest.close();

    // then, we test various values of size.
    ofstream aTest("test_a.csv");
    aTest << "a,hybrid1,hcomps1,merge1,mcomps1,hybrid2,hcomps2,merge2,mcomps2,hybrid3,hcomps3,merge3,mcomps3,hybrid4,hcomps4,merge4,mcomps4,hybrid5,hcomps5,merge5,mcomps5,\n";
    for (int i=1000;i<=10000000;i*=10) {
        string ss = to_string(i) + ",";
        printf("%d ",i);
        for (int j=0;j<REPEATS;j++) {
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
                ss += to_string(ms.count()) + "," + to_string(keycomps) + ",";
            }
        }
        aTest << ss + "\n";
    }
    aTest.close();
    */
    // test varying both
    ofstream xTest("test_x3.csv");
    xTest << "s,a,run1,comps1,run2,comps2,run3,comps3,run4,comps4,run5,comps5,\n";
    for (int s=20;s<=120;s+=1) {
        for (int i=1000;i<=10000000;i*=2.1544) {
            printf("%d,%d ",s,i);
            string ss = to_string(s) + "," + to_string(i) + ",";
            for (int j=0;j<REPEATS;j++) {
                vector<int> a = randomArray(i);
                keycomps = 0;
                // start the timer
                auto start = high_resolution_clock::now();
                hybridsort(0,i-1,s,a,keycomps);
                auto stop = high_resolution_clock::now();
                duration<double, std::milli> ms = stop - start;
                ss += to_string(ms.count()) + "," + to_string(keycomps) + ",";
            }
            xTest << ss + "\n";
        }
    }
}