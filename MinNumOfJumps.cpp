//GREEDY SOL IS ALSO THERE WHICH IS THE MOST OPTIMISED ONE!!!!

#include <iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;

//RECURSIVE
int minNumOfJumpsRec(int *arr,int n,int index){
    if(index>=n-1){
        return 0;
    }
    int ans=INT_MAX;
    int steps=arr[index];
    while(steps>0){
        ans=min(ans,1+minNumOfJumpsRec(arr,n,index+steps));
        steps=steps-1;
    }
    return ans;
}

//DP
int minNumOfJumpsDP(int *arr,int n){
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=INT_MAX;
    }
    dp[0]=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<=(i+arr[i]) && j<n;j++){
            dp[j]=min(dp[j],1+dp[i]);
        }
    }
    return dp[n-1];
}

//GREEDY
int minNumOfJumpsBest(int *arr,int n){
    if(n==1 || arr[0]==0){
        return 0;
    }
    int ans=1;
    int farthest=arr[0];
    int curr=arr[0];
    for(int i=1;i<n;i++){
        if(i==n-1){
            return ans;
        }
        farthest=max(farthest,i+arr[i]);
        if(i==curr){
            ans++;
            curr=farthest;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // cout<<minNumOfJumpsRec(arr,n,0);
    // cout<<minNumOfJumpsDP(arr,n);
    cout<<minNumOfJumpsBest(arr,n);
    return 0;
}
