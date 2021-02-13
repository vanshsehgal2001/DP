#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//BOTTOM-UP
bool subsetSumBott(int *arr,int n,int sum){
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
    return dp[n][sum];
}

bool equalSumPart(int *arr,int n){
    int s=0;
    for(int i=0;i<n;i++){
        s+=arr[i];
    }
    if(s%2!=0){
        return false;
    }
    return subsetSumBott(arr,n,s/2);
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(equalSumPart(arr,n)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
