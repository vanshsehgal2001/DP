#include<iostream>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

//USING RECURSION (VERY BAD!!!!!)

int minNumOfSquaresThatSumNRec(int n){
    if(sqrt(n)-floor(sqrt(n)) == 0){
        return 1;
    }
    if(n<=3){
        return n;
    }

    int ans=n;

    for(int i=1;i<=sqrt(n);i++){
        int temp=pow(i,2);
        ans=min(ans,1+minNumOfSquaresThatSumNRec(n-temp));
    }
    return ans;
}

int minNumOfSquaresThatSumNOpt(int n){
    int dp[n+1];
    memset(dp,0,sizeof(dp));

    for(int i=0;i<=3;i++){
        dp[i]=i;
    }

    for(int i=4;i<=n;i++){
        dp[i]=i;

        for(int j=1;j<=sqrt(i);j++){
            int temp=j*j;
            dp[i]=min(dp[i],1+dp[i-temp]);
        }
    }
    return dp[n];
}

int main(){

    int n;
    cin>>n;
    // cout<<minNumOfSquaresThatSumNRec(n);
    cout<<minNumOfSquaresThatSumNOpt(n);

    return 0;
}
