#include <bits/stdc++.h> 

void rev(vector<int> &v, int l, int r) {
    while(l < r) {
        swap(v[l++], v[r--]);
    }
}

vector<int> nextPermutation(vector<int> &perm, int n)
{
    int i = n-2;
    while(i >= 0 && perm[i] >= perm[i+1]) {
        i--;
    }
    if(i == -1) {
        rev(perm, 0, n-1);
        return perm;
    }
    int j = n-1;
    while(perm[j] < perm[i]) {
        j--;
    }
    swap(perm[i], perm[j]);
    rev(perm, i+1, n-1);
    return perm;
}