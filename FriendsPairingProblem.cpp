//FOR CORRECT RESULTS USE LONG LONG INT INSTEAD OF INT

#include <iostream>
#include<bits/stdc++.h>
#include<climits>
using namespace std;

//USING RECURSION
int pairingRec(int *arr,int n){
    if(n<=2){
        return n;
    }
    return pairingRec(arr,n-1)+((n-1)*pairingRec(arr,n-2));   //IF REMAINS SINGLE OR CAN PAIR WITH OTHER N-1 CANDIDATES
}

int pairingMemo(int *arr,int n,int dp[100]){
    if(n<=2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=pairingMemo(arr,n-1,dp)+((n-1)*pairingMemo(arr,n-2,dp));
}

//BOTTOM-UP
int pairingBott(int *arr,int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+(i-1)*dp[i-2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        arr[i]=i+1;
    }
    // cout<<pairingRec(arr,n);
    int dp[100];
    memset(dp,-1,sizeof(dp));
    // cout<<pairingMemo(arr,n,dp);
    cout<<pairingBott(arr,n);
    return 0;
}
