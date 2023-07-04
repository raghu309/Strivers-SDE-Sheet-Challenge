#include <bits/stdc++.h> 

int findMinimumCoins(int amount) 
{
    int coins[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int idx = 0;
    int ans = 0;
    while(amount) {
        ans += amount/coins[idx];
        amount %= coins[idx];
        idx++;
    }
    return ans;
}
