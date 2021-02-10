#include <iostream>
using namespace std;

//RECURSION
bool targetSum(int *arr,int n,int sum){
    if(sum==0){
        return true;
    }
    if(sum<0){
        return false;
    }
    for(int i=0;i<n;i++){
        if(targetSum(arr,n,sum-arr[i])){
            return true;
        }
    }
    return false;
}

//MEMOIZATION
bool targetSumMod(int *arr,int n,int sum,bool *dp){
    if(sum==0){
        return true;
    }
    if(sum<0){
        return false;
    }
    if(dp[sum]!=false){
        return dp[sum];
    }
    for(int i=0;i<n;i++){
        if(targetSumMod(arr,n,sum-arr[i],dp)){
            dp[sum]=true;
            return true;
        }
    }
    dp[sum]=false;
    return false;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum;
    cin>>sum;
    // cout<<targetSum(arr,n,sum);
    bool dp[sum+1];
    for(int i=0;i<=sum;i++){
        dp[i]=false;
    }
    cout<<targetSumMod(arr,n,sum,dp);
    return 0;
}
