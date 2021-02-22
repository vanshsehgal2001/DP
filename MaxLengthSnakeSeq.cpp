/*
#include <iostream>
using namespace std;

void maxLengthSnakeSeq(int arr[100][100],int m,int n,int temp[100],int output[100],int &maxlength,int length,int i,int j){
    length++;
    temp[length-1]=arr[i][j];
    if(maxlength<length){
        maxlength=length;
        for(int i=0;i<length;i++){
            output[i]=temp[i];
        }
    }
    if(i<m-1 && abs(arr[i][j]-arr[i+1][j])==1){
        maxLengthSnakeSeq(arr,m,n,temp,output,maxlength,length,i+1,j);
    }
    if(j<n-1 && abs(arr[i][j]-arr[i][j+1])==1){
        maxLengthSnakeSeq(arr,m,n,temp,output,maxlength,length,i,j+1);
    }
    if(i==m-1 && j==n-1){
        return;
    }
}

int main()
{
    int m,n;
    cin>>m>>n;
    int arr[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int temp[100];
    int output[100];
    int maxlength=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            maxLengthSnakeSeq(arr,m,n,temp,output,maxlength,0,i,j);
        }
    }
    for(int i=0;i<maxlength;i++){
        cout<<output[i]<<" ";
    }
    cout<<endl;
    return 0;
}
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void maxLengthSnakeSeq(int arr[100][100],int m,int n,int temp[100],int output[100],int &maxlength,int length,int i,int j){
    length++;
    temp[length-1]=arr[i][j];
    if(maxlength<length){
        maxlength=length;
        for(int i=0;i<length;i++){
            output[i]=temp[i];
        }
    }
    if(i<m-1 && abs(arr[i][j]-arr[i+1][j])==1){
        maxLengthSnakeSeq(arr,m,n,temp,output,maxlength,length,i+1,j);
    }
    if(j<n-1 && abs(arr[i][j]-arr[i][j+1])==1){
        maxLengthSnakeSeq(arr,m,n,temp,output,maxlength,length,i,j+1);
    }
    if(i==m-1 && j==n-1){
        return;
    }
}

void maxLengthSnakeSeqDP(int arr[100][100],int m,int n){
    int dp[m][n];
    memset(dp,0,sizeof(dp));
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                continue;
            }
            if(i>0 && abs(arr[i][j]-arr[i-1][j])==1){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+1);
                ans=max(ans,dp[i][j]);
            }
            if(j>0 && abs(arr[i][j]-arr[i][j-1])==1){
                dp[i][j]=max(dp[i][j],dp[i][j-1]+1);
                ans=max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int m,n;
    cin>>m>>n;
    int arr[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    // int temp[100];
    // int output[100];
    // int maxlength=0;
    // for(int i=0;i<m;i++){
    //     for(int j=0;j<n;j++){
    //         maxLengthSnakeSeq(arr,m,n,temp,output,maxlength,0,i,j);
    //     }
    // }
    // for(int i=0;i<maxlength;i++){
    //     cout<<output[i]<<" ";
    // }
    // cout<<endl;
    maxLengthSnakeSeqDP(arr,m,n);
    return 0;
}
