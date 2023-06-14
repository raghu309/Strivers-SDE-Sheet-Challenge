#include <bits/stdc++.h> 

long long inversions = 0;

void merge(long long *arr, int l, int m, int r) {
    vector<long long> arr1(m-l+1);
    vector<long long> arr2(r-m);

    int idx = l;
    for(auto &el:arr1)
        el = arr[idx++];
    for(auto &el:arr2)
        el = arr[idx++];
    
    int i=0, j=0, k=l;
    while(i<arr1.size() && j<arr2.size()) {
        if(arr1[i] <= arr2[j]) {
            arr[k++] = arr1[i++];
        }else {
            inversions += (arr1.size()-i);
            arr[k++] = arr2[j++];
        }
    }
    while(i<arr1.size()) {
        arr[k++] = arr1[i++];
    }
    while(j<arr2.size()) {
        arr[k++] = arr2[j++];
    }
}

void mergeSort(long long *arr, int l, int r) {
    if(l >= r) {
        return;
    }
    int m = (l+r)/2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

long long getInversions(long long *arr, int n){
    mergeSort(arr, 0, n-1);
    return inversions;
}