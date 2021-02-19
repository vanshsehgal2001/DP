#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//RECURSION
float ways(long long int n,float prob){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 0;
    }
    if(n==2){
        return prob;
    }
    if(n==3){
        return 1-prob;
    }
    return prob*(ways(n-2,prob)) + (1-prob)*(ways(n-3,prob));
}

//MEMOIZATION
float waysMemo(long long int n,float prob,float *dp){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 0;
    }
    if(n==2){
        return prob;
    }
    if(n==3){
        return 1-prob;
    }
    if(dp[n]!=1.1){
        return dp[n];
    }
    return dp[n]= (prob*(waysMemo(n-2,prob,dp)) + (1-prob)*(waysMemo(n-3,prob,dp)));
}

int main()
{
    long long int n;
    float prob;
    cin>>n;
    cin>>prob;
    // cout<<ways(n,prob);
    float dp[100];
    memset(dp,1.1,sizeof(dp));
    cout<<waysMemo(n,prob,dp);
    return 0;
}
