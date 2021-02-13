#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>
using namespace std;

int countSubsetSumBott(int *arr,int n,int sum){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            }
        }
    }
    return dp[n][sum];
}

int countSubsetsWithGivenDiff(int *arr,int n,int diff){
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
    }
    int sum=(diff+totalSum)/2;
    return countSubsetSumBott(arr,n,sum);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int diff;
    cin>>diff;
    cout<<countSubsetsWithGivenDiff(arr,n,diff);
    return 0;
}
