#include <bits/stdc++.h> 
void sort012(int *arr, int n)
{
   int l=0, r=n-1;
   for(int m=0; m<=r;) {
      if(arr[m] == 0) {
         swap(arr[l++], arr[m++]);
      }else if(arr[m] == 2) {
         swap(arr[r--], arr[m]);
      }else {
         m++;
      }
   }
}