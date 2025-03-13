#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include "generateData.cpp"
#include "dijkstra.cpp"

using namespace std::chrono;
using namespace std;

int REPEATS = 5;

int main() {
    /* test: 
    vector<vector<int>> v = {
        {0,4,2,6,8},
        {99,0,99,4,3},
        {99,99,0,1,99},
        {99,1,99,0,3},
        {99,99,99,99,0}
    };
    printGraph(v);
    auto v2 = matrixToList(v);
    printf("Adjacency List:\n");
    printGraph(v2);
    int x = dijstraArr(v);
    int y = dijstraPq(v2);
    printf("x:%d y:%d",x,y);
    */

    
    ofstream test("test.csv");
    test << "i";
    for (int i=1;i<=REPEATS;i++) {
        test << ",a" << i << ",q" << i;
    }
    test << "\n";
    // vary size of graph
    for (int i=10;i<=10000;i*=2.1544) {
        printf("i:%d ",i);
        string ss = to_string(i);
        for (int j=0;j<REPEATS;j++) {
            // generate with i*i/4 edges
            vector<vector<int>> v = randomGraph(i,i*4);
            auto v2 = matrixToList(v);

            auto start = high_resolution_clock::now();
            int x = dijstraArr(v);
            auto stop = high_resolution_clock::now();
            duration<double, std::milli> ms = stop - start;

            start = high_resolution_clock::now();
            int y = dijstraPq(v2);
            stop = high_resolution_clock::now();
            duration<double, std::milli> ms2 = stop - start;
            printf("x:%d y:%d ",x,y);
            ss += "," + to_string(ms.count()) + "," + to_string(ms2.count());
        }
        test << ss + "\n";
    }
    test.close();
    // vary number of edges
    /*
    ofstream test2("test_e.csv");
    test2 << "e";
    for (int i=1;i<=REPEATS;i++) {
        test2 << ",a" << i << ",q" << i;
    }
    test2 << "\n";
    for (int i=10;i<1000000;i*=2.1544) {
        printf("e:%d ",i);
        string ss = to_string(i);
        for (int j=0;j<REPEATS;j++) {
            // generate with i*i/4 edges
            vector<vector<int>> v = randomGraph(2000,i);
            auto v2 = matrixToList(v);

            auto start = high_resolution_clock::now();
            int x = dijstraArr(v);
            auto stop = high_resolution_clock::now();
            duration<double, std::milli> ms = stop - start;

            start = high_resolution_clock::now();
            int y = dijstraPq(v2);
            stop = high_resolution_clock::now();
            duration<double, std::milli> ms2 = stop - start;
            printf("x:%d y:%d ",x,y);
            ss += "," + to_string(ms.count()) + "," + to_string(ms2.count());
        }
        test2 << ss + "\n";
    }
    test2.close();
    
    // vary number of vertices
    ofstream test3("test_v.csv");
    test3 << "v";
    for (int i=1;i<=REPEATS;i++) {
        test3 << ",a" << i << ",q" << i;
    }
    test3 << "\n";
    for (int i=10;i<10000;i*=2.1544) {
        printf("e:%d ",i);
        string ss = to_string(i);
        for (int j=0;j<REPEATS;j++) {
            // generate with i*i/4 edges
            vector<vector<int>> v = randomGraph(i,40);
            auto v2 = matrixToList(v);

            auto start = high_resolution_clock::now();
            int x = dijstraArr(v);
            auto stop = high_resolution_clock::now();
            duration<double, std::milli> ms = stop - start;

            start = high_resolution_clock::now();
            int y = dijstraPq(v2);
            stop = high_resolution_clock::now();
            duration<double, std::milli> ms2 = stop - start;
            printf("x:%d y:%d ",x,y);
            ss += "," + to_string(ms.count()) + "," + to_string(ms2.count());
        }
        test3 << ss + "\n";
    }
    test3.close();

    */
}