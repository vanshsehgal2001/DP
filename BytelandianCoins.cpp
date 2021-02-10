#include <iostream>
#include<vector>
using namespace std;

//SIMPLE RECURSION
int solve(int n){
    if(n<10){
        return n;
    }
    return solve(n/2)+solve(n/3)+solve(n/4);
}

//MEMOIZATION
int solve(int n,int *dp){
    if(n<10){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    int num=solve(n/2,dp)+solve(n/3,dp)+solve(n/4,dp);
    dp[n]=max(n,num);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    // cout<<solve(n)<<endl;
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i]=-1;
    }
    cout<<solve(n,dp);
    return 0;
}
