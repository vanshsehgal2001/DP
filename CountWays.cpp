#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//RECURSION
long long int ways(long long int n,long long int m){
    if(n==0){
        return 0;
    }
    if(n==m){
        return 1;
    }
    if(m>n){
        return 0;
    }
    return ways(n-m,m)+ways(n,m+1);
}

//MEMOIZE
long long int waysMemo(long long int n,long long int m,long long int dp[][100]){
    if(n==0){
        return 0;
    }
    if(n==m){
        return 1;
    }
    if(m>n){
        return 0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    return dp[n][m]=waysMemo(n-m,m,dp)+waysMemo(n,m+1,dp);
}

int main()
{
    long long int n,m;
    cin>>n>>m;
    // cout<<ways(n,m);
    long long int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<waysMemo(n,m,dp);
    return 0;
}
