#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfShortestCommonSuperSeq(string x,string y,int m,int n){
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
    int length=dp[m][n];
    return m+n-length;
}


int main()
{
    string x,y;
    cin>>x>>y;
    int m=x.size();
    int n=y.size();
    cout<<lengthOfShortestCommonSuperSeq(x,y,m,n);
    return 0;
}
