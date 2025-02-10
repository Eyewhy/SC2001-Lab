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

void merge(vector<int>& arr, long long int& keycomps, int start, int end, int mid) {
    vector<int> v1(arr.begin()+start, arr.begin()+mid+1);
    vector<int> v2(arr.begin()+mid+1, arr.begin()+end+1);
    int s1 = v1.size(), s2 = v2.size();
    int n1=0, n2=0, i=start;
    for (;n1<s1&&n2<s2;i++) {
        keycomps++;
        if (v1[n1] < v2[n2]) arr[i] = v1[n1++];
        else arr[i] = v2[n2++];
    }
    for (;n1<s1;i++,n1++) arr[i] = v1[n1];
    for (;n2<s2;i++,n2++) arr[i] = v2[n2];
}

void mergesort(int start, int end, vector<int>& arr, long long int& keycomps) {
    if (start >= end) return;
    int mid = (start+end)/2;
    mergesort(start, mid, arr, keycomps);
    mergesort(mid+1, end, arr, keycomps);
    // do merge
    merge(arr, keycomps, start, end, mid);
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
    merge(arr, keycomps, start, end, mid);
}
