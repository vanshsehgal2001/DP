#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool patternMatching(string x,string y,int m,int n){
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
    string out="";
    int i=m;
    int j=n;
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            out=x[i-1]+out;
            --i;
            --j;
        }
        else if(dp[i-1][j]>dp[i][j-1]){
            --i;
        }
        else{
            --j;
        }
    }
    if(out==x){
        return true;
    }
    return false;
}

int main()
{
    string x,y;
    cin>>x>>y;
    int m=x.size();
    int n=y.size();
    if(patternMatching(x,y,m,n)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
