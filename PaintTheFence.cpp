#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//SIMPLE COMPUTATION
int paintFence(int n,int k){
    int same=k*1;
    int diff=k*(k-1);
    int total=same+diff;
    for(int i=3;i<=n;i++){
        same=diff;
        diff=total*(k-1);
        total=same+diff;
    }
    return total;
}

//DP
int paintFenceDP(int n,int k){
    int dp[n+1];
    memset(dp,0,sizeof(dp));
    dp[0]=0;
    dp[1]=k;
    dp[2]=k+(k*(k-1));
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-2]+(k-1)*dp[i-1];
    }
    return dp[n];
}

int main()
{
    int n,k;
    cin>>n>>k;
    // cout<<paintFence(n,k);
    cout<<paintFenceDP(n,k);
    return 0;
}
