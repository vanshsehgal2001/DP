#include <iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s,int i,int j){
    while(i<=j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

//RECURSION
int palindromePartitioningRec(string s,int i,int j){
    if(i>=j || (isPalindrome(s,i,j))){
        return 0;
    }
    int res=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int ans1=palindromePartitioningRec(s,i,k);
        int ans2=palindromePartitioningRec(s,k+1,j);
        int ans=ans1+ans2+1;
        res=min(ans,res);
    }
    return res;
}

//MEMOIZATION
int palindromePartitioningMemo(string s,int i,int j,int dp[100][100]){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(isPalindrome(s,i,j)){
        return 0;
    }
    int res=INT_MAX;
    for(int k=i;k<=j-1;k++){
        int ans1=palindromePartitioningMemo(s,i,k,dp);
        int ans2=palindromePartitioningMemo(s,k+1,j,dp);
        int ans=ans1+ans2+1;
        res=min(ans,res);
    }
    return dp[i][j]=res;
}

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    // cout<<palindromePartitioningRec(s,0,n-1);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<palindromePartitioningMemo(s,0,n-1,dp);
    return 0;
}
