#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int combinations(int n,int r,int p){
    if(n<r){
        return 0;
    }
    if(n==r || r==0){
        return 1;
    }
    return (combinations(n-1,r,p)%p+combinations(n-1,r-1,p)%p)%p;
}

//USING DP
int combinationsDP(int n,int r,int p){
    int dp[r+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=min(i,r);j>0;j--){
            dp[j]=(dp[j]+dp[j-1])%p;
        }
    }
    return dp[r];
}

int main()
{
    int n,r,p;
    cin>>n>>r>>p;
    // cout<<combinations(n,r,p);
    cout<<combinationsDP(n,r,p);
    return 0;
}
