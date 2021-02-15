#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int longestRepeatingSubsequence(string x,string y,int m,int n){
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(x[i-1]==y[j-1] && i!=j){
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
    string x;
    cin>>x;
    int m=x.size();
    string y=x;
    int n=y.size();
    cout<<longestRepeatingSubsequence(x,y,m,n);
    return 0;
}
