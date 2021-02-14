#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//RECURSION
int longestCommSubstringRec(string x,string y,int m,int n,int count){
    if(m==0 || n==0){
        return count;
    }
    if(x[m-1]==y[n-1]){
        return longestCommSubstringRec(x,y,m-1,n-1,count+1);
    }
    return max(count,max(longestCommSubstringRec(x,y,m,n-1,0),longestCommSubstringRec(x,y,m-1,n,0)));
}

//MEMOIZATION
int longestCommSubstringMemo(string x,string y,int m,int n,int dp[100][100],int count){
    if(m==0 || n==0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(x[m-1]==y[n-1]){
        return dp[m][n]=longestCommSubstringMemo(x,y,m-1,n-1,dp,count+1);
    }
    return dp[m][n]=max(count,max(longestCommSubstringMemo(x,y,m,n-1,dp,0),longestCommSubstringMemo(x,y,m-1,n,dp,0)));
}

//BOTTOM-UP
int longestCommSubstringBott(string x,string y,int m,int n){
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
                dp[i][j]=0;
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
    // cout<<longestCommSubstringRec(x,y,m,n,0);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    // cout<<longestCommSubstringMemo(x,y,m,n,dp,0);
    cout<<longestCommSubstringBott(x,y,m,n);
    return 0;
}
