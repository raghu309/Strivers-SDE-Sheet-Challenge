#include <bits/stdc++.h>

vector<int> getZarr(const string& str) {
    int n = str.length();
    vector<int> z(n, 0);
    int left = 0, right = 0, k = 0;

    for (int i = 1; i < n; ++i) {
        if (i > right) {
            left = i;
            right = i;
            while (right < n && str[right - left] == str[right]) {
                right++;
            }
            z[i] = right - left;
            right--;
        } else {
            k = i - left;
            if (z[k] < right - i + 1) {
                z[i] = z[k];
            } else {
                left = i;
                while (right < n && str[right - left] == str[right]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
        }
    }

    return z;
}

int zAlgorithm(string s, string p, int n, int m) {
    int res = 0;
    string concat = p + "$" + s;
    int l = concat.length();
    vector<int> z = getZarr(concat);
    
    for (int i = 0; i < l; ++i) {
        if (z[i] == m) {
            res++;
        }
    }
    
    return res;
}