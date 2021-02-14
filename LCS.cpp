#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//RECURSION
int LCSRec(string x,string y,int m,int n){
    if(m==0 || n==0){
        return 0;
    }
    if(x[m-1]==y[n-1]){
        return 1+LCSRec(x,y,m-1,n-1);
    }
    return max(LCSRec(x,y,m,n-1),LCSRec(x,y,m-1,n));
}

//MEMOIZATION
int LCSMemo(string x,string y,int m,int n,int dp[100][100]){
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(x[m-1]==y[n-1]){
        return dp[m][n]=1+LCSMemo(x,y,m-1,n-1,dp);
    }
    return dp[m][n]=max(LCSMemo(x,y,m,n-1,dp),LCSMemo(x,y,m-1,n,dp));
}

//BOTTOM-UP
int LCSBott(string x,string y,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string x,y;
    cin>>x>>y;
    int m=x.size();
    int n=y.size();
    // cout<<LCSRec(x,y,m,n);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    // cout<<LCSMemo(x,y,m,n,dp);
    cout<<LCSBott(x,y,m,n);
    return 0;
}
