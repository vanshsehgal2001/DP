#include <iostream>
#include<bits/stdc++.h>
#include<vector>
#include<climits>
using namespace std;

//BOTTOM-UP
int subsetSumBott(int *arr,int n,int sum){
    bool dp[n+1][sum+1];
    memset(dp,false,sizeof(dp));
    for(int i=0;i<=n;i++){
        dp[i][0]=true;    
    }
    for(int i=1;i<=sum;i++){
        dp[0][i]=false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }    
            else{
                dp[i][j]=dp[i-1][j]||dp[i-1][j-arr[i-1]];
            }
        }
    }
    vector<int> temp;
    for(int i=0;i<=sum/2;i++){
        if(dp[n][i]==true){
            temp.push_back(i);
        }
    }
    int ans=INT_MAX;
    for(int i=0;i<temp.size();i++){
        // cout<<temp[i]<<" ";
        ans=min(ans,sum-(2*temp[i]));
    }
    return ans;
}

int minSubsetSumDiff(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return subsetSumBott(arr,n,sum);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<minSubsetSumDiff(arr,n);
    return 0;
}
