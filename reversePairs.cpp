#include <bits/stdc++.h> 

int merge(int l, int m, int h, vector<int> &nums){
        vector<int> temp;
        int i, j, k, count;
        i = l;
        j = m+1;
        int ans = 0;
        count = 0;
        while(i<=m && j<=h){
            if(nums[i]>2LL*nums[j]){
                j++;
                count++;
            }else{
                ans+=count;
                i++;
            }
        }
        if(i<=m)
            ans+=(m-i+1)*count;
        i = l; j = m+1;k=0;
        while(i<=m && j<=h){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=m)
            temp.push_back(nums[i++]);
        while(j<=h)
            temp.push_back(nums[j++]);
        for(i=l;i<=h;i++){
            nums[i] = temp[k++];
        }
        return ans;
    }
    
    int mergeSort(int l,int h,vector<int> &nums){
        int pair = 0;
        if(l<h){
            int m = (l+h)/2;
            pair+=mergeSort(l, m, nums);
            pair+=mergeSort(m+1, h, nums);
            pair+=merge(l, m, h, nums);
        }
        return pair;
    }


int reversePairs(vector<int> &arr, int n){
	return mergeSort(0, n-1, arr);
	
}











