#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

void insertsort(int start, int end, vector<int>& arr, long long int& keycomps) {
    for (int i=start;i<=end;i++) {
        for (int j=i;j>start;j--) {
            keycomps++;
            if (arr[j] < arr[j-1]) break;
            swap(arr[j],arr[j-1]);
        }
    }
}

void mergesort(int start, int end, vector<int>& arr, long long int& keycomps) {
    if (start >= end) return;
    int mid = (start+end)/2;
    mergesort(start, mid, arr, keycomps);
    mergesort(mid+1, end, arr, keycomps);
    // do merge
    int m = mid+1;
    for (int n=start;n<=mid && m<=end;n++) {
        keycomps++;
        if (arr[n]<=arr[m]) continue;
        // shift forward
        int t = arr[m];
        for (int i=m;i>n;i--) arr[i] = arr[i-1];
        arr[n] = t;
        mid++;m++;
    }
}

void hybridsort(int start, int end, int& s, vector<int>& arr, long long int& keycomps) {
    // copy of mergesort but calling hybridsort instead
    if (start >= end) return;
    if (end-start+1 <= s) {
        insertsort(start, end, arr, keycomps);
        return;
    }
    int mid = (start+end)/2;
    hybridsort(start, mid, s, arr, keycomps);
    hybridsort(mid+1, end, s, arr, keycomps);
    // do merge
    int m = mid+1;
    for (int n=start;n<=mid && m<=end;n++) {
        keycomps++;
        if (arr[n]<=arr[m]) continue;
        // shift forward
        int t = arr[m];
        for (int i=m;i>n;i--) arr[i] = arr[i-1];
        arr[n] = t;
        mid++;m++;
    }
}