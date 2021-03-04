#include<bits/stdc++.h>
#include<climits>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //SIMPLE APPROACH(WITHOUT DP)
        
        // int profit=0;
        // int buyPrice=INT_MAX;
        // int maxEle=INT_MIN;
        // if(prices.size()==0){
        //     return 0;
        // }
        // for(int i=0;i<prices.size();i++){
        //     if(prices[i]<buyPrice){
        //         buyPrice=prices[i];
        //     }
            // maxEle=max(maxEle,prices[i]-buyPrice);
        // }
        // return maxEle;
        
        //DP SOLUTION
        
        int n=prices.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=0;
        int minEle=prices[0];
        for(int i=2;i<=n;i++){
            if(minEle>prices[i-1]){
                minEle=prices[i-1];
            }
            dp[i]=max(dp[i-1],prices[i-1]-minEle);
        }
        return dp[n];
    }
};
