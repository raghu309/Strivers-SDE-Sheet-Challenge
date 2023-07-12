#include <bits/stdc++.h> 
const int N = 1e5+10;

class MH {
    int arr[N];
    int curSz;

    public:
    MH() {
        curSz = 0;
    }

    void push(int x) {
        arr[curSz++] = x;
        int idx = curSz-1;

        while(idx > 0) {
            int parIdx = (idx-1)/2;
            if(arr[parIdx] > arr[idx]) {
                swap(arr[parIdx], arr[idx]);
                idx = parIdx;
            }else {
                break;
            }
        }
    }

    int pop() {
        int rv = arr[0];
        swap(arr[0], arr[curSz-1]);
        curSz--;

        int idx = 0;
        while(idx < curSz) {
            int leftIdx = idx*2+1;
            int rightIdx = idx*2+2;

            if(leftIdx >= curSz)
                break;
            if(rightIdx >= curSz) {
                if(arr[leftIdx] < arr[idx]) {
                    swap(arr[idx], arr[leftIdx]);
                }
                break;
            }
            if(arr[leftIdx] <= arr[rightIdx] && arr[leftIdx] < arr[idx]) {
                swap(arr[idx], arr[leftIdx]);
                idx = leftIdx;
            }else if(arr[rightIdx] <= arr[leftIdx] && arr[rightIdx] < arr[idx]) {
                swap(arr[idx], arr[rightIdx]);
                idx = rightIdx;
            }else {
                break;
            }
        }
        return rv;
    }
};

vector<int> minHeap(int n, vector<vector<int>>& q) {
    MH m;
    vector<int> ans;
    for(auto &v:q) {
        if(v.size()==2) {
            m.push(v[1]);
        }else {
            ans.push_back(m.pop());
        }
    }
    return ans;
}













